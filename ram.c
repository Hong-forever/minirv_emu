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

int ram(int addr, int wdata, int we, int mask)
{

    static int ram_mem[RAM_DEPTH] = {0};
    if(ram_mem[0] == 0){
        FILE *file = fopen(MEM_DATA, "r");
        if(file == NULL) printf("Error read\n");
    
    
        int count = 0;
    
        while(fscanf(file, "%x", &ram_mem[count]) == 1 && count < RAM_DEPTH)
            count++;
    
        fclose(file);
    }
    if(we) {
        ram_mem[addr >> 2] = (wdata & mask) | (ram_mem[addr >> 2] & ~mask);
#if DEBUG
    printf("addr: %08x\nwdata: %08x\nmask: %08x\nram_mem: %08x\n", addr>>2, wdata, mask, ram_mem[addr >> 2]);
#endif
    }
    return ram_mem[addr >> 2];
}
