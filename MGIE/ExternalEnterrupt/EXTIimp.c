/*
title: External Interrupt Driver Implimintation
author:M.Nour
version: 0
date:2/12/2022
*/

#include "EXTIHeader.h"
#include "EXTIPrivate.h"

void (*PtrToFunVec1)() = (void*)0;
void (*PtrToFunVec2)() = (void*)0;
void (*PtrToFunVec3)() = (void*)0;

void SetEXINTTrigState(u8 ARGSetEXINTpinU8, u8 ARGSetTrigStateU8)
{   
    SET_BIT(*GICR,ARGSetEXINTpinU8);
    switch (ARGSetTrigStateU8)
    {
    case RISING_EDGE:
        switch (ARGSetEXINTpinU8)
        {
        case INT0:
            SET_BIT(*MCUCR, ISC00);
            SET_BIT(*MCUCR, ISC01);
            break;
        case INT1:
            SET_BIT(*MCUCR, ISC10);
            SET_BIT(*MCUCR, ISC11);
            break;
        case INT2:
            SET_BIT(*MCUCSR, ISC2);
            break;
        default:
            break;
        }
        break;
    case FALLING_EDGE:
        switch (ARGSetEXINTpinU8)
        {
        case INT0:
            CLEAR_BIT(*MCUCR, ISC00);
            SET_BIT(*MCUCR, ISC01);
            break;
        case INT1:
            CLEAR_BIT(*MCUCR, ISC10);
            SET_BIT(*MCUCR, ISC11);
            break;
        case INT2:
            CLEAR_BIT(*MCUCSR, ISC2);
            break;
        default:
            break;
        }
        break;
    case ANY:
        switch (ARGSetEXINTpinU8)
        {
        case INT0:
            SET_BIT(*MCUCR, ISC00);
            CLEAR_BIT(*MCUCR, ISC01);
            break;
        case INT1:
            SET_BIT(*MCUCR, ISC10);
            CLEAR_BIT(*MCUCR, ISC11);
            break;
        case INT2:
            SET_BIT(*MCUCSR, ISC2);
            break;
        default:
            break;
        }
        break;
    case EXTINT_LOW:
        switch (ARGSetEXINTpinU8)
        {
        case INT0:
            CLEAR_BIT(*MCUCR, ISC00);
            CLEAR_BIT(*MCUCR, ISC01);
            break;
        case INT1:
            CLEAR_BIT(*MCUCR, ISC10);
            CLEAR_BIT(*MCUCR, ISC11);
            break;
        case INT2:
            CLEAR_BIT(*MCUCR, ISC2);
            break;
        default:
            break;
        }
        break;
    case OFF:
        CLEAR_BIT(*GICR , ARGSetEXINTpinU8);
        break;
    default:
        break;
    }
    return;
}
void SetEXTINTFunction(u8 ARGSetEXTINTpinU8, void (*ARGSetPtrToFunction)())
{
    switch (ARGSetEXTINTpinU8)
    {
    case INT0:
        PtrToFunVec1 = ARGSetPtrToFunction;
        break;
    case INT1:
        PtrToFunVec2 = ARGSetPtrToFunction;
        break;
    case INT2:
        PtrToFunVec3 = ARGSetPtrToFunction;
        break;
    default:
        break;
    }
    return;
}
u8 GetEXINTFlag();


void __vector__1(void) __attribute__((signal,used));
void __vector__1(void)
{
    PtrToFunVec1();
}

void __vector__2(void) __attribute__((signal,used));
void __vector__2(void)
{
    PtrToFunVec2();
}

void __vector__3(void) __attribute__((signal,used));
void __vector__3(void)
{
    PtrToFunVec3();    
}