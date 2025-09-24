#include "defines.h"

void dec(int inst, int *rd, int *rs1, int *rs2, 
         int *imm_use, int *imm, int *alu_op, int *rd_we, 
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
        case 19:
            switch (dec.funct3) {
                case 0: // addi
                    *imm_use = 1;
                    *imm = extract_imm_i(inst);
                    *alu_op = 1;
                    *rd_we = 1;
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
}

