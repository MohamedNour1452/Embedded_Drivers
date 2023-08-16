/*
    title: Timer1 Driver Private
    author: M.nour
    last update: 16/12/21
*/
#ifndef _MTIMER1PRIVATE_H
#define _MTIMER1PRIVATE_H

#define TCCR1A *((u8*)0x4f)
#define TCCR1B *((u8*)0x4e)
#define TCNT1H *((volatile u8*)0x4d)
#define TCNT1L *((volatile u8*)0x4c)
#define OCR1AH *((u8*)0x4b)
#define OCR1AL *((u8*)0x4a)
#define OCR1BH *((u8*)0x49)
#define OCR1BL *((u8*)0x48)
#define ICR1H *((u8*)0x47)
#define ICR1L *((u8*)0x46)
#define TIMSK *((u8*)0x59)
#define TIFR *((volatile u8*)0x58)

typedef enum tccr1a
{
    WGM10,
    WGM11,
    FOC1B,
    FOC1A,
    COM1B0,
    COM1B1,
    COM1A0,
    COM1A1
}tccr1a;
typedef enum tccr1b
{
    CS10,
    CS11,
    CS12,
    WGM12,
    WGM13,
    ICES1 = 6,
    ICNC1
}tccr1b;
typedef enum timsk
{
    TOIE1 = 2,
    OCIE1A,
    OCIE1B,
    TICIE1
}timsk;

typedef enum tifr
{
    TOV1 = 2,
    OCF1A,
    OCF1B,
    ICF1
}tifr;

#endif