#include "defines.h"

void dec(int inst, int *rd, int *rs1, int *rs2, 
         int *imm_use, IMM_TYPE *imm_type, ALU_OP *alu_op, int *rd_we, 
         int *jump_flag, int *ls_read, int *ls_write, LS_TYPE *ls_type, int *dbg)
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
        case 51: //r type
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
        case 3:  //load
            switch (dec.funct3) {
                case 2: //lw
                    *imm_use = 1;
                    *imm_type = imm_i;
                    *rd_we = 1;
                    *ls_read = 1;
                    *ls_type = lw_type;
                    break;
                case 4: //lbu
                    *imm_use = 1;
                    *imm_type = imm_i;
                    *rd_we = 1;
                    *ls_read = 1;
                    *ls_type = lbu_type;
                    break;
                default:
                    break;
            }
            break;
        case 35:  //store
            switch (dec.funct3) {
                case 0: //sb
                    *imm_use = 1;
                    *imm_type = imm_s;
                    *ls_write = 1;
                    *ls_type = sb_type;
                    break;
                case 2: //sw
                    *imm_use = 1;
                    *imm_type = imm_s;
                    *ls_write = 1;
                    *ls_type = sw_type;
                    break;
                default:
                    break;
            }
        default:
            break;
    }

    if(inst == 0x00100073)
        *dbg = 1;
}

