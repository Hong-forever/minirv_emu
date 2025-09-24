#include "defines.h"

#define INST_NUM 8
int main(int argc, char *argv[])
{
    int rst = 0;

    for(int i=0; i<INST_NUM; i++)
    {
        printf("\ninst %d: \n", i);
        cpu(rst);
    }

    return 0;
}
