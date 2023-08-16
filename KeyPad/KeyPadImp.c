/*
title: KeyPad Driver implimintation
author:M.Nour
version: 0
date:19/11/2022
*/

#include "KeyPadPrivate.h"
#include "KeyPadHeader.h"
u8 KeypadPortU8 = 0xff;
void KeyPadInit(u8 ARGPortNameU8)
{   
    KeypadPortU8=ARGPortNameU8;
    // set lower half of portX to input and enable pull up resistor page 50 in data sheet 
    SetPinDir(ARGPortNameU8, pin0, INPUT);
    SetPinDir(ARGPortNameU8, pin1, INPUT);
    SetPinDir(ARGPortNameU8, pin2, INPUT);
    SetPinDir(ARGPortNameU8, pin3, INPUT);
    SetPinValue(ARGPortNameU8, pin0, HIGH);
    SetPinValue(ARGPortNameU8, pin1, HIGH);
    SetPinValue(ARGPortNameU8, pin2, HIGH);
    SetPinValue(ARGPortNameU8, pin3, HIGH);
    // set higher half of portX to output and set it to zero page 50 in data sheet 
    SetPinDir(ARGPortNameU8, pin4, OUTPUT);
    SetPinDir(ARGPortNameU8, pin5, OUTPUT);
    SetPinDir(ARGPortNameU8, pin6, OUTPUT);
    SetPinDir(ARGPortNameU8, pin7, OUTPUT);
    SetPinValue(ARGPortNameU8, pin4, LOW);
    SetPinValue(ARGPortNameU8, pin5, LOW);
    SetPinValue(ARGPortNameU8, pin6, LOW);
    SetPinValue(ARGPortNameU8, pin7, LOW);
    return;
}
u8 ReadKeypadVal(void)
{   
    u8 state = 0;
    if (0xff == KeypadPortU8)
    {
        return -1;
    }
    else{}
    // set lower half of portX to input and enable pull up resistor page 50 in data sheet 
    SetPinDir(KeypadPortU8, pin0, INPUT);
    SetPinDir(KeypadPortU8, pin1, INPUT);
    SetPinDir(KeypadPortU8, pin2, INPUT);
    SetPinDir(KeypadPortU8, pin3, INPUT);
    SetPinValue(KeypadPortU8, pin0, HIGH);
    SetPinValue(KeypadPortU8, pin1, HIGH);
    SetPinValue(KeypadPortU8, pin2, HIGH);
    SetPinValue(KeypadPortU8, pin3, HIGH);
    // set higher half of portX to output and set it to zero page 50 in data sheet 
    SetPinDir(KeypadPortU8, pin4, OUTPUT);
    SetPinDir(KeypadPortU8, pin5, OUTPUT);
    SetPinDir(KeypadPortU8, pin6, OUTPUT);
    SetPinDir(KeypadPortU8, pin7, OUTPUT);
    SetPinValue(KeypadPortU8, pin4, LOW);
    SetPinValue(KeypadPortU8, pin5, LOW);
    SetPinValue(KeypadPortU8, pin6, LOW);
    SetPinValue(KeypadPortU8, pin7, LOW);
    state += ReadPinValue(KeypadPortU8,pin0) << pin0;
    state += ReadPinValue(KeypadPortU8,pin1) << pin1;
    state += ReadPinValue(KeypadPortU8,pin2) << pin2;
    state += ReadPinValue(KeypadPortU8,pin3) << pin3;
 // set lower half of portX to output and set it to zero page 50 in data sheet 
    SetPinDir(KeypadPortU8, pin0, OUTPUT);
    SetPinDir(KeypadPortU8, pin1, OUTPUT);
    SetPinDir(KeypadPortU8, pin2, OUTPUT);
    SetPinDir(KeypadPortU8, pin3, OUTPUT);
    SetPinValue(KeypadPortU8, pin0, LOW);
    SetPinValue(KeypadPortU8, pin1, LOW);
    SetPinValue(KeypadPortU8, pin2, LOW);
    SetPinValue(KeypadPortU8, pin3, LOW);
    // set higher half of portX to input and enable pull up resistor page 50 in data sheet 
    SetPinDir(KeypadPortU8, pin4, INPUT);
    SetPinDir(KeypadPortU8, pin5, INPUT);
    SetPinDir(KeypadPortU8, pin6, INPUT);
    SetPinDir(KeypadPortU8, pin7, INPUT);
    SetPinValue(KeypadPortU8, pin4,HIGH);
    SetPinValue(KeypadPortU8, pin5,HIGH);
    SetPinValue(KeypadPortU8, pin6,HIGH);
    SetPinValue(KeypadPortU8, pin7,HIGH);

    state += ReadPinValue(KeypadPortU8,pin4) << pin4;
    state += ReadPinValue(KeypadPortU8,pin5) << pin5;
    state += ReadPinValue(KeypadPortU8,pin6) << pin6;
    state += ReadPinValue(KeypadPortU8,pin7) << pin7;

    switch (state)
    {
    case key0:
        return 0;
        break;
    case key1:
        return 1;
        break;
    case key2:
        return 2;
        break;
    case key3:
        return 3;
        break;
    case key4:
        return 4;
        break;
    case key5:
        return 5;
        break;
    case key6:
        return 6;
        break;
    case key7:
        return 7;
        break;
    case key8:
        return 8;
        break;
    case key9:
        return 9;
        break;
     case keya:
        return 'A';
        break;
     case keyb:
        return 'B';
        break;
     case keyc:
        return 'C';
        break;
     case keyd:
        return 'D';
        break;
     case keyhash:
        return '#';
        break;
     case keystar:
        return '*';
        break;
    default:
    return 0;
        break;
    }
    return 0;

}