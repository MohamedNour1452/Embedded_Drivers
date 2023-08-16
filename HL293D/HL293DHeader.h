/*
    title: L293(H bridge) Driver Header
    author: M.nour
    last update: 23/12/21
*/
#ifndef _HL293D_HEADER_H
#define _HL293D_HEADER_H

#include "L_bitmath.h"
#include "L_stdu.h"
#include "MdioHeader.h"
#include "Mtimer1Header.h"

    #define L293_FORWARD 0Xff
    #define L293_BACKWARD 0X00
    #define L293_MOTORA 0Xff
    #define L293_MOTORB 0X00

    void L293DInit();
    void L293DSetMotorDir(u8 ARGSetMotorU8, u8 ARGSetMotorDirU8);
    void L293DSetMotorSpeed(u8 ARGSetMotorU8, f32 ARGSetMotorSpeed_0_100F32);

#endif
