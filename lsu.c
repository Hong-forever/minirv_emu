#include "defines.h"

void lsu(LS_TYPE ls_type, int ls_addr, int ls_rdata,
    int *dbus_data_rd, int *dbus_mask)
{
    int shift_amount = ls_addr & 0x3;
    switch (ls_type) {
        case lw_type: // lw
            *dbus_data_rd = ls_rdata;
            break;
        case lbu_type: // lbu
            switch(shift_amount) {
                case 0:
                    *dbus_mask = 0xFF;
                    break;
                case 1:
                    *dbus_mask = 0xFF00;
                    break;
                case 2:
                    *dbus_mask = 0xFF0000;
                    break;
                case 3:
                    *dbus_mask = 0xFF000000;
                    break;
                default:
                    *dbus_mask = 0;
                    break;
            }
            *dbus_data_rd = ls_rdata & *dbus_mask >> (shift_amount * 8);
            break; 
        case sb_type: // sb
            switch(shift_amount) {
                case 0:
                    *dbus_mask = 0xFF;
                    break;
                case 1:
                    *dbus_mask = 0xFF00;
                    break;
                case 2:
                    *dbus_mask = 0xFF0000;
                    break;
                case 3:
                    *dbus_mask = 0xFF000000;
                    break;
                default:
                    *dbus_mask = 0;
                    break;
            }
            break;
        case sw_type: // sw
            *dbus_mask = 0xFFFFFFFF;
            break;

        default:
            break;
    }

}
