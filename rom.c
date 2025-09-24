#include "defines.h"

static int rom_mem[ROM_DEPTH] = {0};

int rom(int addr)
{
    return rom_mem[addr >> 2];
}
