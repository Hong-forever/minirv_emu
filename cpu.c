#include "defines.h"


void cpu(int rst)
{
    int pc = 0;
    int inst = 0;
    int jump_flag = 0;
    int jump_addr = 0;
    int rd = 0;
    int rs1 = 0;
    int rs2 = 0;
    int imm_use = 0;
    int imm = 0;
    int alu_op = 0;
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

    printf("pc = %x, inst = %x\n", pc, inst);

    dec(inst, &rd, &rs1, &rs2, &imm_use, &imm, &alu_op, &rd_we, &jump_flag, &ls_read, &ls_write, &ls_type);

    gpr(0, 0, 0, rs1, rs2, &rs1_rdata, &rs2_rdata);

    alu(rs1_rdata, rs2_rdata, alu_op, &rd_wdata);

    dbus_rdata = ram(dbus_addr, 0, 0, 0);

    lsu(ls_type, ls_addr, dbus_rdata, &dbus_data_rd, &dbus_mask);
    
    dbus_wdata = rs2_rdata;

    ram(dbus_addr, dbus_wdata, dbus_we, dbus_mask);

    gpr(rd, rd_we, rd_wdata, 0, 0, &rd_wdata, &rd_wdata);
}
