/*
title: DIO Driver header
author:M.Nour
version: 0
date:12/11/2022

*/

#ifndef _MDIO_HEADER_H
#define _MDIO_HEADER_H

#include "L_stdu.h"
#include "L_bitmath.h"

#define INPUT 0x00
#define OUTPUT 0xff
#define LOW  0x00
#define HIGH 0xff
#define LOWER_NIPPLE_INPUT 0x01
#define LOWER_NIPPLE_OUTPUT 0x02
#define HIGHER_NIPPLE_INPUT 0x03
#define HIGHER_NIPPLE_OUTPUT 0x04
#define INPUT_PULLUP 0x05
#define LOWER_NIPPLE_INPUT_PULLUP 0x06
#define HIGHER_NIPPLE_INPUT_PULLUP 0x07
#define LOWER_NIPPLE_LOW 0x08
#define HIGHER_NIPPLE_LOW 0x09
#define LOWER_NIPPLE_HIGH 0x10
#define HIGHER_NIPPLE_HIGH 0x11

#define PA 0
#define PB 1
#define PC 2
#define PD 3  

typedef enum pins
{
    pin0,
    pin1,
    pin2,
    pin3,
    pin4,
    pin5,
    pin6,
    pin7,
}pins;

void SetPortDir(u8 ARGPortNameU8,u8 ARGPortDirU8);
void SetPortValue(u8 ARGPortNameU8,u8 ARGPortValueU8);
u8 ReadPortValue(u8 ARGPortNameU8);
void SetPinDir(u8 ARGPortNameU8,u8 ARGPinNumU8,u8 ARGPinDirU8);
void SetPinValue(u8 ARGPortNameU8,u8 ARGPinNumU8,u8 ARGPinValueU8);
u8 ReadPinValue(u8 ARGPinNameU8,u8 ARGPinNumU8);
void TogglePort(u8 ARGPortNameU8);
void TogglePin(u8 ARGPortNameU8, u8 ARGPinNumU8);

#endif