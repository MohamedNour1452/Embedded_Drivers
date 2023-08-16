 /*
    title: MEXTI Driver header
    author: a7
    company: amit
    version: 0
    date: 2/12/22
 */

#ifndef _MEXTIE_HEADER_H
#define _MEXTIE_HEADER_H

    #include "L_bitmath.h"
    #include "L_stdu.h"

    #define INT0 6
    #define INT1 7
    #define INT2 5

    #define RISING_EDGE 0x77
    #define FALLING_EDGE 0x13
    #define MEXTI_LOW 0x10
    #define ANY 0xff
    #define OFF 0x00

    void SetEXINTTriggState(u8 ARGSetEXINTpinU8,u8 ARGSetEXINTTiggState);
    void SetEXINTFunction(u8 ARGSetEXINTpinU8, void (*ARGSetPtrToFunction)());
    u8 GetEXINTFlags();

#endif