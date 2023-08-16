/*
    title: Timer0 Driver Private
    author: M.nour
    last update: 9/12/21
*/
#ifndef _MTIMER0PRIVATE_H
#define _MTIMER0PRIVATE_H

#define TCCR0 *((u8*)0x53)
#define TCNT0 *((volatile u8*)0x52)
#define OCR0 *((u8*)0x5c)
#define TIMSK *((u8*)0x59)
#define TIFR *((volatile u8*)0x58)

typedef enum TCCR0Bits
{
    CS00,
    CS01,
    CS02,
    WGM01,
    COM00,
    COM01,
    WGM00,
    FOC0    
}TCCR0Bits;

typedef enum TIMSKBits
{
    TOIE0,
    OCIE0
}TIMSKBits;

typedef enum TIFRBits
{
    TOV0,
    OCF0
}TIFRBits;

#endif