/* jsdec pseudo code output */
/* /Users/acejilam/Desktop/nvidia-smi @ 0x4121d0 */
#include <stdint.h>

uint64_t Failed_to_query_device_index_4121d0 (void) {
    uint64_t var_8h;
    void * ptr;
    int64_t var_1ch;
    size_t nmeb;
    int64_t var_30h;
    int64_t var_34h;
    int64_t var_38h;
    int64_t var_40h;
    int64_t var_48h;
    int64_t var_50h;
    int64_t var_58h;
    int64_t var_60h;
    int64_t var_68h;
    int64_t var_70h;
    int64_t var_78h;
    int64_t var_80h;
    int64_t var_90h;
    rbx = rdi;
    rsi = &var_34h;
    nmeb = 0x3e8;
    var_38h = rdi;
    eax = nvmlDeviceIsMigDeviceHandle_4480a0 ();
    if (eax != 0) {
        goto label_4;
    }
    edx = var_34h;
    if (edx != 0) {
        goto label_11;
    }
label_3:
    rdi = var_38h;
    rsi = &var_30h;
    eax = nvmlDeviceGetIndex_442f60 ();
    if (eax != 0) {
        edi = eax;
        esi = "Failed to query device index\n";
        eax = 0;
        vfprintf_41c450 ();
    }
    edi = nmeb;
    esi = 0x1020;
    rax = calloc ();
    r14 = rax;
    ptr = rax;
    if (rax == 0) {
        goto label_4;
    }
    rdx = &nmeb;
    rsi = rax;
    rdi = rbx;
    eax = calloc_40c2c0 ();
    if (eax != 0) {
        goto label_12;
    }
    ebx = nmeb;
    eax = var_30h;
    var_1ch = eax;
    if (ebx == 0) {
        goto label_13;
    }
    edx = rbx - 1;
    rcx = ptr;
    r13 = 0x20203e4e3c20207c;
    r14 = 0x433c20203e473c20;
    rax = rdx;
    rax <<= 7;
    rbp = rcx + 0x20;
    rax += rdx;
    rax <<= 5;
    rax = rcx + rax + 0x1040;
    var_8h = rax;
label_2:
    rax = 0x204449503c20203e;
    rdx = 0x20543c20203e2020;
    var_50h = rax;
    var_58h = rdx;
    rax = 0x4e503c20203e2020;
    rdx = 0x2020202020454d41;
    __asm ("movdqa xmm0, xmmword [0x00454c90]");
    var_60h = rax;
    var_68h = rdx;
    rax = 0x2020202020202020;
    rdx = 0x2020202020202020;
    var_40h = r13;
    var_48h = r14;
    var_70h = rax;
    var_78h = rdx;
    var_80h = xmm0;
    var_90h = 0;
    if (rbp == 0) {
        goto label_14;
    }
    r12 = rbp;
    r15d = *(rbp);
    if (r15b != 0x20) {
        goto label_15;
    }
    do {
        r12++;
        r15d = *(r12);
    } while (r15b == 0x20);
label_15:
    rdi = r12;
    rax = strlen ();
    rbx = rax;
    if (r15b == 0) {
        goto label_10;
    }
    rax = r12 + rax - 1;
    if (rax > r12) {
        goto label_16;
    }
    goto label_17;
    do {
        rax--;
        if (rax == r12) {
            goto label_17;
        }
label_16:
    } while (*(rax) == 0x20);
label_17:
    *((rax + 1)) = 0;
    rdi = r12;
    rax = strlen ();
    rbx = rax;
label_10:
    rax = &var_40h;
    do {
label_0:
        esi = "<PNAME";
        rdi = rax;
        rax = strstr ();
        esi = 0x3e;
        r15 = rax;
        rdi = rax;
        rax = strchr ();
        rdx = r15 + 6;
        if (rax <= rdx) {
            goto label_18;
        }
        if (*((r15 + 6)) == 0x20) {
            goto label_19;
        }
    } while (1);
label_1:
    if (*(rdx) != 0x20) {
        goto label_0;
    }
label_19:
    rdx++;
    if (rax != rdx) {
        goto label_1;
    }
label_5:
    if (rbx != 0) {
        rdx -= r15;
        rcx = r12;
        rax = rdx + 1;
        if (rax < rbx) {
            rbx -= rax;
            eax = 0x2e2e;
            rcx = r12 + rbx;
            *(rcx) = ax;
            *((rcx + 2)) = 0x2e;
        }
        rdi = &var_40h;
        eax = 0;
        edx = 0x4543ba;
        esi = "<PNAME";
        eax = strlen_4111d0 ();
        ecx = var_1ch;
        rdi = &var_40h;
        eax = 0;
        edx = 0x4542a1;
        esi = 0x45429e;
        eax = strlen_4111d0 ();
        ecx = *((rbp - 8));
        if (ecx == 0xffffffff) {
            goto label_20;
        }
        rdi = &var_40h;
        edx = 0x4543a0;
        esi = 0x45439d;
        eax = 0;
        eax = strlen_4111d0 ();
label_9:
        ecx = *((rbp - 4));
        if (ecx == 0xffffffff) {
            goto label_21;
        }
        rdi = &var_40h;
        edx = 0x4543a0;
        esi = 0x4543a4;
        eax = 0;
        eax = strlen_4111d0 ();
label_8:
        ecx = *((rbp - 0x18));
        rdi = &var_40h;
        eax = 0;
        edx = 0x4543a7;
        esi = "<PID";
        strlen_4111d0 ();
        eax = *((rbp - 0x20));
        ecx = 0x451ede;
        if (eax == 1) {
            goto label_22;
        }
        ecx = 0x4527f0;
        if (eax == 2) {
            goto label_22;
        }
        ecx = 0x4527ee;
        if (eax == 3) {
            goto label_22;
        }
        ecx = 0x4527e8;
        if (eax == 5) {
            goto label_22;
        }
        if (eax == 7) {
            goto label_23;
        }
        rcx = *((rbp - 0x10));
        if (rcx == -1) {
            goto label_24;
        }
label_6:
        rdi = &var_40h;
        rcx >>= 0x14;
        edx = 0x45430b;
        esi = "<PMEM";
        eax = 0;
        eax = strlen_4111d0 ();
label_7:
        eax = 0;
        fcn_004074f0 (0x4543ba, var_40h, rdx, rcx, r8, r9);
    }
    rbp += 0x1020;
    if (var_8h != rbp) {
        goto label_2;
    }
    ebx = nmeb;
label_13:
    rdi = ptr;
    eax = free ();
    eax = 0;
    al = (ebx != 0) ? 1 : 0;
    goto label_25;
label_12:
    rdi = r14;
    rax = free ();
label_4:
    eax = 0;
label_25:
    return rax;
label_11:
    rsi = &var_38h;
    rdi = rbx;
    eax = nvmlDeviceGetDeviceHandleFromMigDeviceHandle_4484d0 ();
    if (eax == 0) {
        goto label_3;
    }
    goto label_4;
label_18:
    rdx = rax;
    goto label_5;
label_23:
    ecx = "M+C+G";
label_22:
    rdi = &var_40h;
    eax = 0;
    edx = 0x4542ee;
    esi = 0x4543b0;
    eax = strlen_4111d0 ();
    rcx = *((rbp - 0x10));
    if (rcx != -1) {
        goto label_6;
    }
label_24:
    rdi = &var_40h;
    edx = 0x470238;
    esi = "<PMEM";
    eax = 0;
    eax = strlen_4111d0 ();
    goto label_7;
label_21:
    rdi = &var_40h;
    ecx = 0x470238;
    edx = 0x4543ba;
    esi = 0x4543a4;
    eax = 0;
    eax = strlen_4111d0 ();
    goto label_8;
label_20:
    rdi = &var_40h;
    ecx = 0x470238;
    edx = 0x4543ba;
    esi = 0x45439d;
    eax = 0;
    strlen_4111d0 ();
    goto label_9;
label_14:
    edi = 0;
    r12d = 0;
    rax = strlen ();
    rbx = rax;
    goto label_10;
}
