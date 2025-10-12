#include "defines.h"

void vga(int offset, int wdata, int we, int *addr)
{
    if(we) addr[offset >> 2] = wdata;
}
