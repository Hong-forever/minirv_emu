#include <am.h>
#include <klib-macros.h>

void display(int vga_mem[]) 
{
    int w = io_read(AM_GPU_CONFIG).width;
    int h = io_read(AM_GPU_CONFIG).height;
    
    int vw = 256;
    int vh = 256;
    
    int start_x = (w - vw)/2;
    int start_y = (h - vh)/2;
  
    io_write(AM_GPU_FBDRAW, start_x, start_y, vga_mem, vw, vh, false);
    
    io_write(AM_GPU_FBDRAW, 0, 0, NULL, 0, 0, true);    
}
