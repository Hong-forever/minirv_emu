#include "defines.h"

void alu(int rs1_rdata, int rs2_rdata, int imm_use, int imm, int pc, int *memory_addr, int *jump_addr, ALU_OP alu_op, int *rd_wdata)
{
    int alu_a, alu_b;
    switch (alu_op) {
        case addi_op: //addi
            alu_a = rs1_rdata;
            alu_b = imm_use ? imm : rs2_rdata;
            *rd_wdata = alu_a + alu_b;
            break;

        case jalr_op: //jalr
            alu_a = pc;
            alu_b = 4;
            *rd_wdata = alu_a + alu_b;
            *jump_addr = rs1_rdata + imm;
            break;

        case add_op: //add
            alu_a = rs1_rdata;
            alu_b = rs2_rdata;
            *rd_wdata = alu_a + alu_b;
            break;

        case lui_op: //lui
            alu_a = imm;
            *rd_wdata = alu_a;

        default:
            break;
    }
    *memory_addr = rs1_rdata + imm;
}

