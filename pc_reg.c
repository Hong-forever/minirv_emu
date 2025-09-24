#include "defines.h"


int pc_reg(int rst, int jump_flag, int jump_addr)
{
    static int pc = -4;

    if(rst) {
        pc = -4;
    }
    else if(jump_flag) {
        pc = jump_addr;
    }
    else {
        pc = pc + 4;
    }


    return pc;
}
