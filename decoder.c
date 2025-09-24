#include "defines.h"

void dec(int inst, int *rd, int *rs1, int *rs2, 
         int *imm_use, IMM_TYPE *imm_type, ALU_OP *alu_op, int *rd_we, 
         int *jump_flag, int *ls_read, int *ls_write, int *ls_type)
{
    dec_t dec;
    dec.opcode = (inst) & 0x7F;
    dec.rd = (inst >> 7) & 0x1F;
    dec.rs1 = (inst >> 15) & 0x1F;
    dec.rs2 = (inst >> 20) & 0x1F;
    dec.funct3 = (inst >> 12) & 0x07;
    dec.funct7 = (inst >> 25) & 0x7F;


    *rd = dec.rd;
    *rs1 = dec.rs1;
    *rs2 = dec.rs2;

    switch (dec.opcode) {
        case 19:  //i type
            switch (dec.funct3) {
                case 0: // addi
                    *imm_use = 1;
                    *alu_op = addi_op;
                    *rd_we = 1;
                    *imm_type = imm_i;
                    break;
                default:
                    break;
            }
            break;
        case 51:
            switch (dec.funct3) {
                case 0: //add
                    *alu_op = add_op;
                    *rd_we = 1;
                    break;
                default:
                    break;
            }
            break;
        case 55:  //lui  
            *alu_op = lui_op;
            *rd_we = 1;
            *imm_use = 1;
            *imm_type = imm_u;
            break;
        case 103:  //jalr
            *imm_use = 1;
            *alu_op = jalr_op;
            *rd_we = 1;
            *imm_type = imm_i;
            *jump_flag = 1;
            break;

        default:
            break;
    }
}

