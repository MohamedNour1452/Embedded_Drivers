/*
    title: I2C Driver Header
    author: m.nour
    last update: 31/12/22
*/

#ifndef _M_I2CHEADER_H
#define _M_I2CHEADER_H

    #include "L_bitmath.h"
    #include "L_stdu.h"
    #include "../MdioDriver/MdioHeader.h"
    
    #define I2C_MAXSPEED 300000
    #define I2C_DEFAULTSPEED 150000
    #define I2C_MINSPEED 10000

    void I2Cconfig(u8 ARGSetClkU8); 
    u8 WriteI2C(u8 ARGI2CAddressU8, u8 ARGI2CDataU8);
    u8 ReadI2C(u8 ARGI2CAddressU8);

#endif