/*
title: DIO Driver private
author:M.Nour
version: 0
date:12/11/2022
*/
#include "MdioHeader.h"
#include "MdioPrivate.h"



void SetPortDir(u8 ARGPortNameU8,u8 ARGPortDirU8)
{
    switch (ARGPortNameU8)
    {
    case PA:
         PORTA->ddr=ARGPortDirU8;
        break;
    case PB:
        PORTB->ddr=ARGPortDirU8;
        break;
    case PC:
        PORTC->ddr=ARGPortDirU8;
        break;
    case PD:
        PORTD->ddr=ARGPortDirU8;
        break;
    default:
        break;
    }
    return;
}
void SetPortValue(u8 ARGPortNameU8,u8 ARGPortValue)
{
    switch (ARGPortNameU8)
    {
    case PA:
         PORTA->port=ARGPortValue;
        break;
    case PB:
        PORTB->port=ARGPortValue;
        break;
    case PC:
        PORTC->port=ARGPortValue;
        break;
    case PD:
        PORTD->port=ARGPortValue;
        break;
    default:
        break;
    }
    return;
}
u8 ReadPortValue(u8 ARGPortNameU8)
{
    switch (ARGPortNameU8)
    {
    case PA:
        return PORTA->pin;
        break;
    case PB:
        return PORTB->pin;
        break;
    case PC:
        return PORTC->pin;
        break;
    case PD:
        return PORTD->pin;
        break;
    default:
        break;
    }
    return 0;
}
void SetPinDir(u8 ARGPortNameU8,u8 ARGPinNumU8,u8 ARGPinDirU8)
{
    switch(ARGPinDirU8){
        case INPUT:
            switch (ARGPortNameU8)
            {
            case PA:
                CLEAR_BIT(PORTA->ddr,ARGPinNumU8);
                break;
            case PB:
                CLEAR_BIT(PORTB->ddr,ARGPinNumU8);
                break;
            case PC:
                CLEAR_BIT(PORTC->ddr,ARGPinNumU8);
                break;
            case PD:
                CLEAR_BIT(PORTD->ddr,ARGPinNumU8);
                break;
            default:
                break;
            }
        case OUTPUT:
            switch (ARGPortNameU8)
            {
            case PA:
                SET_BIT(PORTA->ddr,ARGPinNumU8);
                break;
            case PB:
                SET_BIT(PORTB->ddr,ARGPinNumU8);
                break;
            case PC:
                SET_BIT(PORTC->ddr,ARGPinNumU8);
                break;
            case PD:
                SET_BIT(PORTD->ddr,ARGPinNumU8);
                break;
            default:
                break;
            }
    }  
    return;   
}
void SetPinValue(u8 ARGPortNameU8,u8 ARGPinNumU8,u8 ARGPinValueU8)
{
    switch(ARGPinValueU8){
        case LOW:
            switch (ARGPortNameU8)
            {
            case PA:
                CLEAR_BIT(PORTA->port,ARGPinNumU8);
                break;
            case PB:
                CLEAR_BIT(PORTB->port,ARGPinNumU8);
                break;
            case PC:
                CLEAR_BIT(PORTC->port,ARGPinNumU8);
                break;
            case PD:
                CLEAR_BIT(PORTD->port,ARGPinNumU8);
                break;
            default:
                break;
            }
            break;
        case HIGH:
            switch (ARGPortNameU8)
            {
            case PA:
                SET_BIT(PORTA->port,ARGPinNumU8);
                break;
            case PB:
                SET_BIT(PORTB->port,ARGPinNumU8);
                break;
            case PC:
                SET_BIT(PORTC->port,ARGPinNumU8);
                break;
            case PD:
                SET_BIT(PORTD->port,ARGPinNumU8);
                break;
            default:
                break;
            }
            break;
    }

   return;         
}
u8 ReadPinValue(u8 ARGPortNameU8,u8 ARGPinNumU8)
{
    switch (ARGPortNameU8)
    {
    case PA:
        return GET_BIT(PORTA->port,ARGPinNumU8);
        break;
    case PB:
        return GET_BIT(PORTB->port,ARGPinNumU8);
        break;
    case PC:
       return GET_BIT(PORTC->port,ARGPinNumU8);
        break;
    case PD:
       return GET_BIT(PORTD->port,ARGPinNumU8);
        break;
    default:
        break;
    }
    return 0;
}