#include "defines.h"

static int rom_mem[ROM_DEPTH] = {
0x980650b7,
0x72308093,
0x00100023,
0x00100123,
0x00102223,
0x00004183,
0x00404203,
0x00402283
};

int rom(int addr)
{
    return rom_mem[addr >> 2];
}
