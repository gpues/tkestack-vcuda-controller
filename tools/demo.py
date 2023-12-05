import os

# os.environ['TF2_BEHAVIOR'] = '1'
os.environ['LOGGER_LEVEL'] = '9'
# os.environ['LD_LIBRARY_PATH'] = '/tf/test/'
import tensorflow as tf

tf.compat.v1.enable_eager_execution()

# tf.compat.v1.disable_eager_execution()

tf.config.set_soft_device_placement(False)
tf.debugging.set_log_device_placement(True)
import numpy as np


class ProdLayer(tf.keras.layers.Layer):
    def __init__(self, name):
        super(ProdLayer, self).__init__()
        self.w = tf.keras.backend.variable(0.01, name='var_' + name)

    def call(self, x):
        return x * self.w


class SumLayer(tf.keras.layers.Layer):
    def __init__(self):
        super(SumLayer, self).__init__()

    def call(self, x1, x2):
        return x1 + x2


# mirrored_strategy = tf.distribute.MirroredStrategy(devices=["/gpu:0", "/gpu:1"])
mirrored_strategy = tf.distribute.MirroredStrategy()


class EmbeddingModel(tf.keras.Model):
    def __init__(self):
        super(EmbeddingModel, self).__init__()

        # place w1 on GPU 0 and create the layer
        with tf.device('/gpu:0'):
            self.L1 = ProdLayer('w1')

        # place w2 on GPU 0 and create the layer
        with tf.device('/gpu:1'):
            self.L2 = ProdLayer('w2')

        # place w3 on both GPU0 and GPU1 using mirrored scope. Can I do this?
        with mirrored_strategy.scope():
            self.w3 = tf.keras.backend.variable(0.01, name='var_w3')

        # may be do this on CPU? But for now let it perform this on GPU0
        with tf.device('/gpu:0'):
            self.L3 = SumLayer()

    def call(self, input_layer):
        # w1 is on GPU0, w2 is on GPU1 and w3 is placed using mirrored scope on both GPUs
        # y1 = w1 * x + w3
        with tf.device('/gpu:0'):
            y1 = self.L1(input_layer) + self.w3

        # y2 = w2 * x + w3
        with tf.device('/gpu:1'):
            y2 = self.L2(input_layer) + self.w3

        # y = y1 + y2 (i.e. w1 * x + w2 * x + 2 * w3)
        with tf.device('/gpu:0'):
            y_hat = self.L3(y1, y2)

        return y_hat


def myLoss(y, y_hat):
    return (y_hat - y) * (y_hat - y)


with mirrored_strategy.scope():
    model = EmbeddingModel()
    model.compile(tf.optimizers.Adam(lr=0.0001),
                  loss=myLoss)

train_dataset = np.random.choice(100, size=(1000,))
time.sleep(1999999999)
model.fit(
    x=train_dataset.astype(np.float32),
    y=train_dataset.astype(np.float32),
    batch_size=1000,
    epochs=10, shuffle=False, verbose=True
)
