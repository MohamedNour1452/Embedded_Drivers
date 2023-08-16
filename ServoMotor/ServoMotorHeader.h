/*
    title: Servo Motor Driver Header
    author: m.nour
    last update: 24/1/22
*/

#ifndef SERVO_MOTOR_HEADER_H
#define SERVO_MOTOR_HEADER_H

#include "../MTimer1/MTimer1Header.h"
#include "../MdioDriver/MdioHeader.h"
#include "../Libraries/L_EzTime.h"

void ServoInit();
void SetServo(u8 ARGSetServoValU8);

#endif