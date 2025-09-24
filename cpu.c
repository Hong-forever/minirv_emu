#include "defines.h"


void cpu(int rst)
{
    int pc = 0;
    int inst = 0;
    static int jump_flag = 0;
    static int jump_addr = 0;
    int rd = 0;
    int rs1 = 0;
    int rs2 = 0;
    int imm_use = 0;
    int imm = 0;
    IMM_TYPE imm_type = 0;
    ALU_OP alu_op = 0;
    int rd_we = 0;
    int ls_read = 0;
    int ls_write = 0;
    int ls_type = 0;
    int ls_addr = 0;

    int rs1_rdata = 0;
    int rs2_rdata = 0;
    int rd_wdata = 0;
    int dbus_data_rd = 0;
    int dbus_mask = 0;
    int dbus_we = 0;
    int dbus_addr = 0;
    int dbus_wdata = 0;
    int dbus_rdata = 0;

    pc = pc_reg(rst, jump_flag, jump_addr);
    inst = rom(pc);

    printf("if_stage:-------------------------\n");
    printf("pc = %x, inst = %x\n", pc, inst);
    printf("end-------------------------------\n");

    dec(inst, &rd, &rs1, &rs2, &imm_use, &imm, &imm_type, &alu_op, &rd_we, &jump_flag, &ls_read, &ls_write, &ls_type);

    printf("id_stage:-------------------------\n");
    printf("rd = %d, rd_we = %d, alu_op = %d, imm_use = %d\n", rd, rd_we, alu_op, imm_use);
    printf("end-------------------------------\n");


    gpr(0, 0, 0, rs1, rs2, &rs1_rdata, &rs2_rdata);

    printf("gpr_reg:-------------------------\n");
    printf("rs1 = %d rs1_rdata = %x\n", rs1, rs1_rdata);

    printf("rs2 = %d rs2_rdata = %x\n", rs2, rs2_rdata);
    printf("end-------------------------------\n");

    imm = imm_func(inst, imm_type);        
    alu(rs1_rdata, rs2_rdata, imm_use, imm, pc, &jump_addr, alu_op, &rd_wdata);

    printf("ex_stage:-------------------------\n");
    printf("rd = %d, rd_we = %d, rd_wdata = %x\n", rd, rd_we, rd_wdata);
    printf("end-------------------------------\n");

    dbus_rdata = ram(dbus_addr, 0, 0, 0);

    printf("ls_stage:-------------------------\n");
    printf("dbus_rdata = %x\n", dbus_rdata);
    printf("end-------------------------------\n");

    lsu(ls_type, ls_addr, dbus_rdata, &dbus_data_rd, &dbus_mask);
    
    dbus_wdata = rs2_rdata;

    ram(dbus_addr, dbus_wdata, dbus_we, dbus_mask);

    gpr(rd, rd_we, rd_wdata, 0, 0, &rd_wdata, &rd_wdata);
}
