/*
    title: Timer1 Driver Header
    author: M.nour
    last update: 16/12/21
*/
#ifndef _MTIMER1HEADER_H
#define _MTIMER1HEADER_H

#include "L_bitmath.h"
#include "L_stdu.h"

#define MTIMER1_NORMAL_MODE 0
#define MTIMER1_PHASE_CORRECT_MODE 1 
#define MTIMER1_COMPARE_MATCH 2     
#define MTIMER1_FAST_PWM_MODE 3

#define MTIMER1_OFF 0
#define MTIMER1_ON 1
#define MTIMER1_CLK 1
#define MTIMER1_CLK_DIV8 2
#define MTIMER1_CLK_DIV64 3
#define MTIMER1_CLK_DIV256 4
#define MTIMER1_CLK_DIV1024 5
#define MTIMER1_EXTERNAL_FALLING 6
#define MTIMER1_EXTERNAL_RISING 7

#define MTIMER1_OC1_DISCONNECTED 0 
#define MTIMER1_OC1_TOGGLE 1
#define MTIMER1_OC1_CLEAR 2
#define MTIMER1_OC1_SET 3

#define MTIMER1_OC1_NOT_INVERTED 2
#define MTIMER1_OC1_INVERTED  3

#define MTIMER1_OVER_FLOW_FLAG 1
#define MTIMER1_COMPARE_MATCH_B_FLAG 2
#define MTIMER1_COMPARE_MATCH_A_FLAG 4
#define MTIMER1__INPUTCAPTURE_FLAG 8

#define MTIMER1_OVER_FLOW_INT 1
#define MTIMER1_COMPARE_MATCH_B_INT 2
#define MTIMER1_COMPARE_MATCH_A_INT 4
#define MTIMER1__INPUTCAPTURE_INT 8

#define MTIMER1_MAX 0xffff
#define MTIMER1_BOTTOM 0x0000

void SelectTimer1Mode(u8 ARGSetTimer1ModeU8);
void ConfigTimer1Clock(u8 ARGSetTimer1ConfigU8);
void SetTimer1OutputMode(u8 ARGTimer1OutputModeAU8, u8 ARGTimer1OutputModeBU8);
u16 ReadTimer1();
void WriteTimer1(u16 ARGSetTimer1ValueU8);
void SetTimer1CompareValueA(u16 ARGSetTimer1CompareValueAU8);
void SetTimer1CompareValueB(u16 ARGSetTimer1CompareValueBU8);
void SetTimer1Interrrupt(u8 ARGSetTimer1OverFlowInterruptOnOffU8, u8 ARGSetTimer1CompareMatchAInterruptOnOffU8, u8 ARGSetTimer1CompareMatchBInterruptOnOffU8, u8 ARGSetTimer1InputCaptureU8);
u8 ReadTimer1Flags();
void SetSetTimer1INFunction(u8 ARGSetTimer1INTScU8, void (*ARGSetPtrToFunction)());


#endif
