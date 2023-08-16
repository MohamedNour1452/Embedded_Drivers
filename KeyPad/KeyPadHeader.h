/*
title: KeyPad Driver header
author:M.Nour
version: 0
date:19/11/2022
*/
 
 #ifndef _KEYPADHEADER_H
 #define _KEYPADHEADER_H
 
    #include "L_bitmath.h"
    #include "L_stdu.h"
    #include "MdioHeader.h"

    void KeyPadInit(u8 ARGPortNameU8);
    u8 ReadKeypadVal(void);
    
 #endif