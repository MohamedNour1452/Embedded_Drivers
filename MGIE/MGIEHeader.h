/*
title: GIE Driver Header
author:M.Nour
version: 0
date:2/12/2022
*/

#ifndef _MGIEHEADER_H
#define _MGIEHEADER_H

#include "L_bitmath.h"
#include "L_stdu.h"

#define MGIEHIGH 0xFF
#define MGIELOW 0x00


void SetGlobalInterruptEnableBit(u8 ARGGIEBitValueU8);

#endif