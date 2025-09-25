#include "defines.h"

int rom(int addr)
{
    static int rom_mem[ROM_DEPTH] = {0};
    
    if(rom_mem[0] == 0) {
        FILE *file = fopen("inst.data", "r");
        if(file == NULL) printf("Error read\n");


        int count = 0;

        while(fscanf(file, "%x", &rom_mem[count]) == 1 && count < ROM_DEPTH)
        count++;

        fclose(file);
    }
    return rom_mem[addr >> 2];
}
