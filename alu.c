#include "defines.h"

void alu(int alu_a, int alu_b, int alu_op, int *rd_wdata)
{
    switch (alu_op) {
        case 1:
            *rd_wdata = alu_a + alu_b;
            break;
        default:
            break;
    }
}

