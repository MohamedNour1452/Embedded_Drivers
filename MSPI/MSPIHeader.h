/*
    title: MSPI Driver Header
    author: m.nour
    last update: 30/12/22
*/
#ifndef _MSPI_HEADER_H
#define _MSPI_HEADER_H

#include "L_bitmath.h"      
#include "L_stdu.h"
#include "../MdioDriver/MdioHeader.h"

    #define SPI_ORDERED 0
    #define SPI_REVERSED 1
    
    #define SPI_MASTER 2
    #define SPI_SLAVE 3
    
    #define SPI_CLK_DIV2 4
    #define SPI_CLK_DIV4 5
    #define SPI_CLK_DIV8 6
    #define SPI_CLK_DIV16 7

    void ConfigSPI(u8 ARGSetDataDirU8, u8 ARGSetMasterOrSLaveU8, u8 ARGSetClockU8);
    u8 TransiveSPI(u8 ARGSPIdataU8);
#endif