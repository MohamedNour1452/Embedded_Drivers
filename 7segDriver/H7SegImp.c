/*
title: 7 Seg Driver imp
version: 0
date:18/11/2022
*/


#include "H7SegHeader.h"
   
    void SSegInit()
    {
        // setting data pins direction to output 
        SetPinDir(PA,pin4,OUTPUT); 
        SetPinDir(PA,pin5,OUTPUT);
        SetPinDir(PA,pin6,OUTPUT);
        SetPinDir(PA,pin7,OUTPUT);
        SetPinDir(PB,pin3,OUTPUT);
        // setting their initial value to zero
        SetPinValue(PA,pin4,LOW); 
        SetPinValue(PA,pin5,LOW);
        SetPinValue(PA,pin6,LOW);
        SetPinValue(PA,pin7,LOW);
        SetPinValue(PB,pin3,LOW);  
        // setting control pins direction to output
        SetPinDir(PB,pin1,OUTPUT);
        SetPinDir(PB,pin2,OUTPUT);
        SetPinDir(PB,pin1,LOW);
        SetPinDir(PB,pin2,LOW);
        return;
    }

    void SetDPVal(u8 ARGDPValueU8)
    {   // setting decimal point to on or off using high and low macros implemented in mdio driver
        SetPinValue(PB, pin3, ARGDPValueU8);   
        return;
    }

    void Set7segVal(u8 ARG7seg1ValueU8, u8 ARG7seg2ValueU8)
    {    
        SetPinValue(PB,pin1,LOW);
        ARG7seg1ValueU8 = ARG7seg1ValueU8 > 9 ? SSOFF : ARG7seg1ValueU8;

        SetPinValue(PB, pin2, SSOFF == ARG7seg1ValueU8 ? LOW : HIGH);
        SetPinValue(PA, pin4, GET_BIT(ARG7seg1ValueU8,0) ? HIGH : LOW); 
        SetPinValue(PA, pin5, GET_BIT(ARG7seg1ValueU8,1) ? HIGH : LOW);
        SetPinValue(PA, pin6, GET_BIT(ARG7seg1ValueU8,2) ? HIGH : LOW);
        SetPinValue(PA, pin7, GET_BIT(ARG7seg1ValueU8,3) ? HIGH : LOW);
        _delay_ms(5);

        SetPinValue(PB,pin2,LOW);
        ARG7seg2ValueU8 = ARG7seg2ValueU8 > 9 ? SSOFF : ARG7seg2ValueU8;

        SetPinValue(PB, pin1, SSOFF == ARG7seg2ValueU8 ? LOW : HIGH);
        SetPinValue(PA, pin4, GET_BIT(ARG7seg2ValueU8,0)? HIGH : LOW); 
        SetPinValue(PA, pin5, GET_BIT(ARG7seg2ValueU8,1)? HIGH : LOW);
        SetPinValue(PA, pin6, GET_BIT(ARG7seg2ValueU8,2)? HIGH : LOW);
        SetPinValue(PA, pin7, GET_BIT(ARG7seg2ValueU8,3)? HIGH : LOW);
        _delay_ms(5);

        SetPinValue(PB,pin1,LOW);
        SetPinValue(PB,pin2,LOW);
        return;
    }

