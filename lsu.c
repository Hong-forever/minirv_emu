#include "defines.h"

void lsu(int ls_type, int ls_addr, int ls_rdata,
    int *dbus_data_rd, int *dbus_mask)
{
    int shift_amount = ls_addr & 0x3;
    switch (ls_type) {
        case 0: // lw
            *dbus_data_rd = ls_rdata;
            break;
        case 1: // lbu
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
    
        case 2: // sb
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

        case 3: // sw
            *dbus_mask = 0xFFFFFFFF;
            break;

        default:
            break;
    }

}
