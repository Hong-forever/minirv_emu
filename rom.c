#include "defines.h"

#if MODE==MEM
    #define MEM_DATA "mem.data"
#elif MODE==SUM
    #define MEM_DATA "sum.data"
#elif MODE==VGA
    #define MEMMEM_DATA"vga.data"
#else
    #define MEM_DATA "inst.data"
#endif

int rom(int addr)
{
    static int rom_mem[ROM_DEPTH] = {0};
    
    if(rom_mem[0] == 0) {
        FILE *file = fopen(MEM_DATA, "r");
        if(file == NULL) printf("Error read\n");


        int count = 0;

        while(fscanf(file, "%x", &rom_mem[count]) == 1 && count < ROM_DEPTH)
        count++;

        fclose(file);
    }
    return rom_mem[addr >> 2];
}
