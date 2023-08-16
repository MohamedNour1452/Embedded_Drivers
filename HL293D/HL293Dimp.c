/*
    title: L293(H bridge) Driver imp
    author: M.nour
    last update: 23/12/21
*/
#include "HL293DHeader.h"

void L293DInit()
{
    SetPinDir(PD, pin4, OUTPUT);
    SetPinDir(PD, pin4, OUTPUT);
    
    SetPinDir(PC, pin3, OUTPUT);
    SetPinDir(PC, pin4, OUTPUT);
    SetPinDir(PC, pin5, OUTPUT);
    SetPinDir(PC, pin6, OUTPUT);

    SelectTimer1Mode(MTIMER1_FAST_PWM_MODE);
    SetTimer1OutputMode(MTIMER1_OC1_NOT_INVERTED, MTIMER1_OC1_NOT_INVERTED);
    SetTimer1CompareValueA(MTIMER1_MAX);
    SetTimer1CompareValueB(MTIMER1_MAX);
    ConfigTimer1Clock(MTIMER1_CLK_DIV64);
}

void L293DSetMotorDir(u8 ARGSetMotorU8, u8 ARGSetMotorDirU8)
{
    switch (ARGSetMotorU8)
    {
    case L293_MOTORA:
        switch (ARGSetMotorDirU8)
        {
        case L293_FORWARD:
            SetPinValue(PC, pin3, HIGH);
            SetPinValue(PC, pin4, LOW);
            break;
        case L293_BACKWARD:
            SetPinValue(PC, pin3, LOW);
            SetPinValue(PC, pin4, HIGH);
            break;
        default:
            break;
        }
        break;
     case L293_MOTORB:
        switch (ARGSetMotorDirU8)
        {
        case L293_FORWARD:
            SetPinValue(PC, pin5, HIGH);
            SetPinValue(PC, pin6, LOW);
            break;
        case L293_BACKWARD:
            SetPinValue(PC, pin5, LOW);
            SetPinValue(PC, pin6, HIGH);
            break;
        default:
            break;
        }
    default:
        break;
    }
}

void L293DSetMotorSpeed(u8 ARGSetMotorU8, f32 ARGSetMotorSpeed_0_100F32)
{
    switch (ARGSetMotorU8)
    {
    case L293_MOTORA:
        SetTimer1CompareValueA((u16)ARGSetMotorSpeed_0_100F32*655.0); // max/100
        break;
    case L293_MOTORB:
        SetTimer1CompareValueB((u16)ARGSetMotorSpeed_0_100F32*655.0); // max/100
        break;
    default:
        break;
    }
}