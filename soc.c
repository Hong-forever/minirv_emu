#include "defines.h"
#include <unistd.h>
int main(int argc, char *argv[])
{
    int rst = 0;
    int dbg = 0;
    int vga_mem[VGA_DEPTH] = {0};

    while(1)
    {
        cpu(rst, &dbg, vga_mem);
//        sleep(1);
        if(dbg) break;
    }

#if MODE==VGA
    while(1)
    {
    	display(vga_mem);
    }
#endif

    return 0;
}
