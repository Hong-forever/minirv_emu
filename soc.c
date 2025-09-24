#include "defines.h"

#define INST_NUM 2
int main(int argc, char *argv[])
{
    int rst = 0;

    for(int i=0; i<INST_NUM+1; i++)
    {
        cpu(rst);
    }

    return 0;
}
