#ifndef DEFINES_H
#define DEFINES_H

#include <stdio.h>

#define DEBUG 1

#define GPR_NUM 32

#define ROM_DEPTH 1024
#define RAM_DEPTH 1024

typedef enum {
    imm_i, imm_s, imm_b, imm_u, imm_j
} IMM_TYPE;

typedef enum {
    addi_op=1, jalr_op, add_op 
} ALU_OP;

typedef struct {
    int opcode;
    int rd;
    int rs1;
    int rs2;
    int funct3;
    int funct7;
} dec_t;


int sign_extend(int value, int bits);
int extract_imm_i(int inst);
int extract_imm_s(int inst);
int extract_imm_b(int inst);
int extract_imm_u(int inst);
int extract_imm_j(int inst);

int rom(int addr);
int ram(int addr, int wdata, int we, int mask);

int pc_reg(int rst, int jump_flag, int jump_addr);

void dec(int inst, int *rd, int *rs1, int *rs2,int *imm_use, int *imm, IMM_TYPE *imm_type, ALU_OP *alu_op, int *rd_we,int *jump_flag, int *ls_read, int *ls_write, int *ls_type);

void gpr(int waddr, int wen, int wdata, int raddr1, int raddr2, int *rdata1, int *rdata2);

int imm_func(int inst, IMM_TYPE imm_type);

void alu(int rs1_rdata, int rs2_rdata, int imm_use, int imm, int pc, int *jump_addr, ALU_OP alu_op, int *rd_wdata);

void lsu(int ls_type, int ls_addr, int ls_rdata, int *dbus_data_rd, int *dbus_mask);

void cpu(int rst);
#endif
