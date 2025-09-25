#include "defines.h"


static const char *reg_name[GPR_NUM] = 
{
    "zero", "ra", "sp", "gp", "tp", "t0", "t1", "t2", 
    "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5", 
    "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7", 
    "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

static int reg[GPR_NUM] = {0};

void gpr(int waddr, int wen, int wdata, int raddr1, int raddr2, int *rdata1, int *rdata2, int dbg)
{
    if(wen && waddr != 0 && waddr < GPR_NUM) {
        reg[waddr] = wdata;

#if DEBUG
        for(int i = 0; i < GPR_NUM; i++)
        {
            printf("reg[%d], %s = %08x\n", i, reg_name[i], reg[i]); // DEBUG
        }
#endif

    } 
    else if (wen && waddr >= GPR_NUM) {
        printf("Error: Write address out of range\n");
    }
    else {
        reg[0] = 0;
    } 

    if(raddr1 < GPR_NUM) {
        *rdata1 = reg[raddr1];
    }
    else {
        printf("Error: Read address out of range\n");
    }
    
    if(raddr2 < GPR_NUM) {
        *rdata2 = reg[raddr2];
    }
    else {
        printf("Error: Read address out of range\n");
    }
    if(dbg) {
        if(reg[10] == 0)
            printf("TEST PASS!\n");
        else
            printf("FAIL!\n");
    }
}
