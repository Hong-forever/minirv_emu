#include "defines.h"
#include <unistd.h>
int main(int argc, char *argv[])
{
    int rst = 0;
    int dbg = 0;

    while(1)
    {
        cpu(rst, &dbg);
//        sleep(1);
        if(dbg) break;
    }

    return 0;
}
