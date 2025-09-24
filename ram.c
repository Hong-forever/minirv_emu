#include "defines.h"

static int ram_mem[RAM_DEPTH] = {0};

int ram(int addr, int wdata, int we, int mask)
{
    if(we) {
        ram_mem[addr >> 2] = (wdata & mask) | (ram_mem[addr >> 2] & ~mask);
#if DEBUG
    printf("addr: %08x\nwdata: %08x\nmask: %08x\nram_mem: %08x\n", addr>>2, wdata, mask, ram_mem[addr >> 2]);
#endif
    }
    return ram_mem[addr >> 2];
}
