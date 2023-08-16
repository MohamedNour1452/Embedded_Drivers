/*
    title: I2C Driver imp
    author: m.nour
    last update: 31/12/22
*/

#include "MI2CHeader.h"
#include "MI2CPrivate.h"

void I2Cconfig(u8 ARGSetClkU8)
{
   SetPinDir(PC, pin0, OUTPUT);
   SetPinDir(PC, pin1, OUTPUT);
   TWBR = (F_CPU/(8*ARGSetClkU8))-1;
   SET_BIT(TWCR, twen);
}
u8 WriteI2C(u8 ARGI2CAddressU8, u8 ARGI2CDataU8)
{
    SET_BIT(TWCR, twsta);
    while (0 == GET_BIT(TWCR, twint))
    {
        asm('NOP');
    }
    if(I2C_GETSTATUS(TWCR) != I2C_START)
    {
        return 0;
    }
    else
    {
        TWDR = ARGI2CAddressU8 << 1 | I2C_WRITEBIT;
        CLEAR_BIT(TWCR, twsta);
        SET_BIT(TWCR, twint);
        while (0 == GET_BIT(TWCR, twint))
        {
            asm('NOP');
        }
        if(I2C_GETSTATUS(TWCR) != ADDRESS_WRITE_ACK)
        {
            return 0;
        }
        else
        {
            TWDR = ARGI2CDataU8;
            SET_BIT(TWCR, twint);
            while (0 == GET_BIT(TWCR, twint))
            {
                asm('NOP');
            }
            if(I2C_GETSTATUS(TWCR) != DATA_WRITE_ACK)
            {
                return 0;
            }
            else
            {
                SET_BIT(TWCR, twsto);
                SET_BIT(TWCR, twint);
                return 1;
            } 
        }
    }
    return 0;
}
u8 ReadI2C(u8 ARGI2CAddressU8)
{
    SET_BIT(TWCR, twsta);
    while (0 == GET_BIT(TWCR, twint))
    {
        asm('NOP');
    }
    if(I2C_GETSTATUS(TWCR) != I2C_START)
    {
        return 0;
    }
    else
    {
        TWDR = ARGI2CAddressU8 << 1 | I2C_READBIT;
        CLEAR_BIT(TWCR, twsta);
        SET_BIT(TWCR, twint);
        while (0 == GET_BIT(TWCR, twint))
        {
            asm('NOP');
        }
        if(I2C_GETSTATUS(TWCR) != ADDRESS_READ_ACK)
        {
            return 0;
        }
        else
        {
            SET_BIT(TWCR, twint);
            while (0 == GET_BIT(TWCR, twint))
            {
                asm('NOP');
            }
            if(I2C_GETSTATUS(TWCR) != DATA_READ_ACK)
            {
                return 0;
            }
            else
            {
                SET_BIT(TWCR, twsto);
                SET_BIT(TWCR, twint);
                return TWDR;
            } 
        }
    }
    return 0;
}
    
    