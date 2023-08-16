/*
    title: MSPI Driver Private 
    author: m.nour
    last update: 30/12/22
*/
#ifndef _MSPI_PRIVATE_H
#define _MSPI_PRIVATE_H

    #define SPCR *((u8*)0x2d)
    #define SPSR *((u8*)0x2e)
    #define SPDR *((volatile u8*)0x2f)

    typedef enum spcr
    {
        spr0,
        spr1,
        cpha,
        cpol,
        mstr,
        dord,
        spe,
        spie
    }spcr;
    
    typedef enum spsr
    {
        spi2x,
        wcol = 6,
        spif
    }spsr;

#endif