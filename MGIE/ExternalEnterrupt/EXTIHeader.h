/*
title: External Interrupt Driver Header
author:M.Nour
version: 0
date:2/12/2022
*/

#ifndef _EXTIHEADER_H
#define _EXTIHEADER_H

#include "L_stdu.h"
#include "L_bitmath.h"

#define INT0 6
#define INT1 7
#define INT2 5
#define RISING_EDGE 0x77
#define FALLING_EDGE 0x13
#define EXTINT_LOW 0x10
#define ANY 0xff
#define OFF 0x00

void SetEXINTTrigState(u8 ARGSetEXINTpinU8, u8 ARGSetTrigStateU8);
void SetEXTINTFunction(u8 ARGSetEXTINTpinU8, void (*ARGSetPtrToFunction)());
u8 GetEXINTFlag();

#endif