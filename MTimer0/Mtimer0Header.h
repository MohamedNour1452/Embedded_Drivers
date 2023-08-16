/*
    title: Timer0 Driver Header
    author: M.nour
    last update: 10/12/21
*/
#ifndef _MTIMER0HEADER_H
#define _MTIMER0HEADER_H

#include "L_bitmath.h"
#include "L_stdu.h"

#define MTIMER0_NORMAL_MODE 0
#define MTIMER0_PHASE_CORRECT_MODE 1 
#define MTIMER0_COMPARE_MATCH 2     
#define MTIMER0_FAST_PWM_MODE 3

#define MTIMER0_OFF 0
#define MTIMER0_ON 1
#define MTIMER0_CLK 1
#define MTIMER0_CLK_DIV8 2
#define MTIMER0_CLK_DIV64 3
#define MTIMER0_CLK_DIV256 4
#define MTIMER0_CLK_DIV1024 5
#define MTIMER0_EXTERNAL_FALLING 6
#define MTIMER0_EXTERNAL_RISING 7

#define MTIMER0_OC0_DISCONNECTED 0 
#define MTIMER0_OC0_TOGGLE 1
#define MTIMER0_OC0_CLEAR 2
#define MTIMER0_OC0_SET 3

#define MTIMER0_OC0_NOT_INVERTED 2
#define MTIMER0_OC0_INVERTED  3

#define MTIMER0_OVER_FLOW_FLAG 1
#define MTIMER0_COMPARE_MATCH_FLAG 2
#define MTIMER0_ALL_FLAGS 3

#define MTIMER0_OVER_FLOW_INT 1
#define MTIMER0_COMPARE_MATCH_INT 2

void SelectTimer0Mode(u8 ARGSetTimer0ModeU8);
void ConfigTimer0Clock(u8 ARGSetTimer0ConfigU8);
void SetTimer0OutputMode(u8 ARGTimer0OutputModeU8);
u8 ReadTimer0();
void WriteTimer0(u8 ARGSetTimer0ValueU8);
void SetTimer0CompareValue(u8 ARGSetTimer0CompareValueU8);
void SetTimer0Interrrupt(u8 ARGSetTimer0OverFlowInterruptOnOffU8, u8 ARGSetTimer0CompareMatchInterruptOnOffU8);
u8 ReadTimer0Flags();
void SetSetTimer0INFunction(u8 ARGSetTimer0INTScU8, void (*ARGSetPtrToFunction)());
#endif
