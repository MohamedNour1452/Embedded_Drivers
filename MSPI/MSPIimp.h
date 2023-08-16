/*
    title: MSPI Driver imp
    author: m.nour
    last update: 30/12/22
*/

    #include "MSPIHeader.h" 
    #include "MSPIPrivate.h"

    void ConfigSPI(u8 ARGSetDataDirU8, u8 ARGSetMasterOrSLaveU8, u8 ARGSetClockU8)
    {
        switch (ARGSetDataDirU8)
        {
        case SPI_ORDERED:
            SET_BIT(SPCR, dord);
            break;
        case SPI_REVERSED:
            CLEAR_BIT(SPCR, dord);
            break;
        default:
            break;
        }
        switch (ARGSetMasterOrSLaveU8)
        {
        case SPI_MASTER:
            SET_BIT(SPCR, mstr);
            SetPinDir(PB, pin5, OUTPUT);
            SetPinDir(PB, pin6, INPUT);
            SetPinDir(PB, pin7, OUTPUT);
            break;
        case SPI_SLAVE:
            CLEAR_BIT(SPCR, mstr);
            SetPinDir(PB, pin4, INPUT_PULLUP);
            SetPinDir(PB, pin5, INPUT);
            SetPinDir(PB, pin6, OUTPUT);
            SetPinDir(PB, pin7, INPUT);
            break;
        default:
            break;
        }
        switch (ARGSetClockU8)
        {
        case SPI_CLK_DIV2:
            CLEAR_BIT(SPCR, spr0);
            CLEAR_BIT(SPCR, spr1);
            SET_BIT(SPSR, spi2x);
            break;
        case SPI_CLK_DIV4:
            CLEAR_BIT(SPCR, spr0);
            CLEAR_BIT(SPCR, spr1);
            CLEAR_BIT(SPSR, spi2x);
            break;
        case SPI_CLK_DIV8:
            SET_BIT(SPCR, spr0);
            CLEAR_BIT(SPCR, spr1);
            SET_BIT(SPSR, spi2x);
            break;
        case SPI_CLK_DIV16:
            SET_BIT(SPCR, spr0);
            CLEAR_BIT(SPCR, spr1);
            CLEAR_BIT(SPSR, spi2x);
            break;
        default:
            break;
        }
        SET_BIT(SPCR, spe);
        return;
    }
    
    u8 transiveSPI(u8 ARGSPIdataU8)
    {
        SPDR = ARGSPIdataU8;
        while (0 == GET_BIT(SPSR, spif))
        {
            asm("NOP");
        }
        return SPDR;
    }