/*
title: GIE Driver imp
author:M.Nour
version: 0
date:2/12/2022
*/

#include "MGIEHeader.h"
#include "MGIEPrivate.h"

void SetGlobalInterruptEnableBit(u8 ARGGIEBitValueU8)
{
    switch (ARGGIEBitValueU8)
    {
    case MGIEHIGH:
        SET_BIT(*SREG,GIEBit);
        break;
    case MGIELOW:
        CLEAR_BIT(*SREG,GIEBit);
        break;
    default:
        break;
    }
    return;
}