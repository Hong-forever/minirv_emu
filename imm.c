#include "defines.h"

int imm_func(int inst, IMM_TYPE imm_type)
{
    int imm_value = 0;
    switch(imm_type)
    {
        case imm_i:
            imm_value = extract_imm_i(inst);
            break;
        
        case imm_s:
            imm_value = extract_imm_s(inst);
            break;

        case imm_u:
            imm_value = extract_imm_u(inst);
            break;

        case imm_j:
            imm_value = extract_imm_j(inst);
            break;
 
        case imm_b:
            imm_value = extract_imm_b(inst);
            break;
    }

    return imm_value;
}
