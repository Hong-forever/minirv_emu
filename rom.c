#include "defines.h"

static int rom_mem[ROM_DEPTH] = {
0x72300093,
0x00108133,
0x001351b7,
0x00418267
};

int rom(int addr)
{
    return rom_mem[addr >> 2];
}
