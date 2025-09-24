#include "defines.h"

void alu(int rs1_rdata, int rs2_rdata, int imm_use, int imm, ALU_OP alu_op, int *rd_wdata)
{
    int alu_a, alu_b;
    switch (alu_op) {
        case addi_op: //addi
            alu_a = rs1_rdata;
            alu_b = imm_use ? imm : rs2_rdata;
            *rd_wdata = alu_a + alu_b;
            break;
        default:
            break;
    }
}

