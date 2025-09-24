#include "defines.h"

static int ram_mem[RAM_DEPTH] = {0};

int ram(int addr, int wdata, int we, int mask)
{
    if(we) {
        ram_mem[addr >> 2] = (wdata & mask) | (ram_mem[addr >> 2] & ~mask);
    }
    return ram_mem[addr >> 2];
}
