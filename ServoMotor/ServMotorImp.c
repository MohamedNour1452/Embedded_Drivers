/*
    title: Servo Motor Driver implementation
    author: m.nour
    last update: 24/1/22
*/
#include "ServoMotorHeader.h"

void ServoInit()
{   
    SetPinDir(PD,pin5,OUTPUT);
    SelectTimer1Mode(MTIMER1_FAST_PWM_MODE);
    ConfigTimer1Clock(MTIMER1_CLK_DIV256);
    SetTimer1OutputMode(MTIMER1_OC1_NOT_INVERTED,MTIMER1_OC1_DISCONNECTED);
    SetTimer1CompareValueA(16000000/(50*256));
    return;
}
void SetServo(u8 ARGSetServoValU8)
{
    ARGSetServoValU8 =  ARGSetServoValU8 > 180 ? 180 :ARGSetServoValU8; 
    u8 x;
    x = (ARGSetServoValU8 + 180)/180;
    u16 frequency;
    frequency = MSEC2TICKs(x, 256, 50, 256);
    SetTimer1CompareValueA(frequency);
    return;
}