/*
    title: I2C Driver Private
    author: m.nour
    last update: 31/12/22
*/

#ifndef _M_I2CPRIVATE_H
#define _M_I2CPRIVATE_H

    #define I2C_GETSTATUS(REG) (REG >> 3)

    #define TWBR *((u8*)0x20)
    #define TWCR *((u8*)0x56)
    #define TWSR *((u8*)0x21)
    #define TWDR *((u8*)0x23)
    #define TWAR *((u8*)0x22)

    #define F_CPU 16000000

    #define I2C_READBIT 0
    #define I2C_WRITEBIT 1

    typedef enum twcr
    {
        twie,
        twen = 2,
        twwc,
        twsto,
        twsta,
        twea,
        twint
    }twcr;

    #define I2C_START 0x08
    #define I2C_START_REP 0x10
    #define I2C_LOST 0x38

    #define ADDRESS_WRITE_ACK 0x18
    #define ADDRESS_WRITE_NOTACK 0x20
    #define DATA_WRITE_ACK 0x28
    #define DATA_WRITE_NOTACK 0x30
    

    #define ADDRESS_READ_ACK 0x40
    #define ADDRESS_READ_NOTACK 0x48
    #define DATA_READ_ACK 0x50
    #define DATA_READ_NOTACK 0x58
    
#endif