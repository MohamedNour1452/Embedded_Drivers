/*
title: 7 Seg Driver Header
author:M.Nour
version: 0
date:18/11/2022
*/
#ifndef _H7SEGHEADER_H
#define _H7SEGHEADER_H

#include "L_stdu.h"
#include "L_bitmath.h"
#include "util/delay.h"
#include "MdioHeader.h"

#define SSOFF 0xFF
   
    void SSegInit();
    void SetDPVal(u8 ARGDPValueU8);
    void Set7segVal(u8 ARG7seg1ValueU8, u8 ARG7seg2ValueU8);

#endif