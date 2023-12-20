# import os
#
# with open('./src/cuda/memory.c', 'r', encoding='utf8') as f:
#     data = f.read()
# for cd, dirs, files in os.walk('./mem'):
#     for file in files:
#         print(file[:-3])
#         if file[:-3] + '(' in data:
#             os.remove(os.path.join(cd, file))


aa = []
with open('/Users/acejilam/Desktop/123/vcuda-controller/src/cuda_originals.c', 'r', encoding='utf8') as f:
    datas = f.read().split('\n')

for item in aa:
    for x in datas:
        if item + '(' in x:
            print(x.strip(' {') + ';')
            break
