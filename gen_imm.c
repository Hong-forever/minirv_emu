#include "defines.h"


// 符号扩展函数
int sign_extend(int value, int bits) {
    int sign_bit = (value >> (bits - 1)) & 0x1;

    int mask = sign_bit ? (~0 << bits) : 0;
    return mask | value;
}

// 提取各种类型的立即数
int extract_imm_i(int inst) {
    int imm = (inst >> 20) & 0xFFF;
    return sign_extend(imm, 12);
}

int extract_imm_s(int inst) {
    int imm_11_5 = (inst >> 25) & 0x7F;
    int imm_4_0 = (inst >> 7) & 0x1F;
    int imm = (imm_11_5 << 5) | imm_4_0;
    return sign_extend(imm, 12);
}

int extract_imm_b(int inst) {
    int imm_12 = (inst >> 31) & 0x1;
    int imm_11 = (inst >> 7) & 0x1;
    int imm_10_5 = (inst >> 25) & 0x3F;
    int imm_4_1 = (inst >> 8) & 0xF;
    int imm = (imm_12 << 12) | (imm_11 << 11) | (imm_10_5 << 5) | (imm_4_1 << 1);
    return sign_extend(imm, 13);
}

int extract_imm_u(int inst) {
    int imm = inst & 0xFFFFF000;  // 高20位
    return imm;  // U-type已经是正确符号扩展的
}

int extract_imm_j(int inst) {
    int imm_20 = (inst >> 31) & 0x1;
    int imm_19_12 = (inst >> 12) & 0xFF;
    int imm_11 = (inst >> 20) & 0x1;
    int imm_10_1 = (inst >> 21) & 0x3FF;
    int imm = (imm_20 << 20) | (imm_19_12 << 12) | (imm_11 << 11) | (imm_10_1 << 1);
    return sign_extend(imm, 21);
}
