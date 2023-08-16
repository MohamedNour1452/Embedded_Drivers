/*
    title: Timer0 Driver imp
    author: M.nour
    last update: 10/12/21
*/

#include "Mtimer1Header.h"
#include "Mtimer1Private.h"

void (*SetPtrToFunctionInCap)();
void (*SetPtrToFunctionCTCA)();
void (*SetPtrToFunctionCTCB)();
void (*SetPtrToFunctionOF)();

void SelectTimer1Mode(u8 ARGSetTimer1ModeU8)
{
    switch (ARGSetTimer1ModeU8)
    {
    case MTIMER1_NORMAL_MODE:
        CLEAR_BIT(TCCR1A, WGM10);
        CLEAR_BIT(TCCR1A, WGM11);
        CLEAR_BIT(TCCR1B, WGM12);
        CLEAR_BIT(TCCR1B, WGM13);
        break;
    case MTIMER1_PHASE_CORRECT_MODE:
        SET_BIT(TCCR1A, WGM10);
        SET_BIT(TCCR1A, WGM11);
        CLEAR_BIT(TCCR1B, WGM12);
        SET_BIT(TCCR1B, WGM13);
        break;
    case MTIMER1_COMPARE_MATCH:
        CLEAR_BIT(TCCR1A, WGM10);
        CLEAR_BIT(TCCR1A, WGM11);
        SET_BIT(TCCR1B, WGM12);
        CLEAR_BIT(TCCR1B, WGM13);
        break;
    case MTIMER1_FAST_PWM_MODE:
        CLEAR_BIT(TCCR1A, WGM10);
        SET_BIT(TCCR1A, WGM11);
        SET_BIT(TCCR1B, WGM12);
        SET_BIT(TCCR1B, WGM13);
        break;
    default:
        break;
    }
    return;
}
void ConfigTimer1Clock(u8 ARGSetTimer0ConfigU8)
{
    switch (ARGSetTimer0ConfigU8)
    {
    case MTIMER1_OFF:
        CLEAR_BIT(TCCR1B, CS10);
        CLEAR_BIT(TCCR1B, CS11);
        CLEAR_BIT(TCCR1B, CS12);
        break;
    case MTIMER1_CLK:
        SET_BIT(TCCR1B, CS10);
        CLEAR_BIT(TCCR1B, CS11);
        CLEAR_BIT(TCCR1B, CS12);
        break;
    case MTIMER1_CLK_DIV8:
        CLEAR_BIT(TCCR1B, CS10);
        SET_BIT(TCCR1B, CS11);
        CLEAR_BIT(TCCR1B, CS12);
        break;
    case MTIMER1_CLK_DIV64:
        SET_BIT(TCCR1B, CS10);
        SET_BIT(TCCR1B, CS11);
        CLEAR_BIT(TCCR1B, CS12);
        break;
    case MTIMER1_CLK_DIV256:
        CLEAR_BIT(TCCR1B, CS10);
        CLEAR_BIT(TCCR1B, CS11);
        SET_BIT(TCCR1B, CS12);
        break;
    case MTIMER1_CLK_DIV1024:
        SET_BIT(TCCR1B, CS10);
        CLEAR_BIT(TCCR1B, CS11);
        SET_BIT(TCCR1B, CS12);
        break;
    case MTIMER1_EXTERNAL_FALLING:
        CLEAR_BIT(TCCR1B, CS10);
        SET_BIT(TCCR1B, CS11);
        SET_BIT(TCCR1B, CS12);
        break;
    case MTIMER1_EXTERNAL_RISING:
        SET_BIT(TCCR1B, CS10);
        SET_BIT(TCCR1B, CS11);
        SET_BIT(TCCR1B, CS12);
        break;
    default:
        break;
    }
    return;
}
void SetTimer1OutputMode(u8 ARGTimer1OutputModeAU8, u8 ARGTimer1OutputModeBU8)
{
    switch (ARGTimer1OutputModeAU8)
    {
    case MTIMER1_OC1_DISCONNECTED:
        CLEAR_BIT(TCCR1A, COM1A0);
        CLEAR_BIT(TCCR1A, COM1A1);
        break;
    case MTIMER1_OC1_TOGGLE:
        SET_BIT(TCCR1A, COM1A0);
        CLEAR_BIT(TCCR1A, COM1A1);
        break;
    case MTIMER1_OC1_CLEAR:
        CLEAR_BIT(TCCR1A, COM1A0);
        SET_BIT(TCCR1A, COM1A1);
        break;
    case MTIMER1_OC1_SET:
        SET_BIT(TCCR1A, COM1A0);
        SET_BIT(TCCR1A, COM1A1);
        break;
    default:
        break;
    }
    switch (ARGTimer1OutputModeBU8)
    {
    case MTIMER1_OC1_DISCONNECTED:
        CLEAR_BIT(TCCR1A, COM1B0);
        CLEAR_BIT(TCCR1A, COM1B1);
        break;
    case MTIMER1_OC1_TOGGLE:
        SET_BIT(TCCR1A, COM1B0);
        CLEAR_BIT(TCCR1A, COM1B1);
        break;
    case MTIMER1_OC1_CLEAR:
        CLEAR_BIT(TCCR1A, COM1B0);
        SET_BIT(TCCR1A, COM1B1);
        break;
    case MTIMER1_OC1_SET:
        SET_BIT(TCCR1A, COM1B0);
        SET_BIT(TCCR1A, COM1B1);
        break;
    default:
        break;
    }
    return;
}
u16 ReadTimer1()
{
    return TCNT1L | TCNT1H << 8;
}
void WriteTimer1(u16 ARGSetTimer1ValueU8)
{
    TCNT1L = (u8)(ARGSetTimer1ValueU8 & 0x00ff);
    TCNT1H = (u8)(ARGSetTimer1ValueU8 & 0xff00);
    return;
}
void SetTimer1CompareValueA(u16 ARGSetTimer1CompareValueAU8)
{
    OCR1AL = (ARGSetTimer1CompareValueAU8 & 0x00ff);
    OCR1AH = (ARGSetTimer1CompareValueAU8 & 0xff00);
    return;
}
void SetTimer1CompareValueB(u16 ARGSetTimer1CompareValueBU8)
{
    OCR1BL = (ARGSetTimer1CompareValueBU8 & 0x00ff);
    OCR1BH = (ARGSetTimer1CompareValueBU8 & 0xff00);
    return;
}
void SetTimer1Interrrupt(u8 ARGSetTimer1OverFlowInterruptOnOffU8, u8 ARGSetTimer1CompareMatchAInterruptOnOffU8, u8 ARGSetTimer1CompareMatchBInterruptOnOffU8, u8 ARGSetTimer1InputCaptureU8)
{
    switch (ARGSetTimer1OverFlowInterruptOnOffU8)
    {
    case MTIMER1_ON:
        SET_BIT(TIMSK, TOIE1);
        break;
    case MTIMER1_OFF:
        CLEAR_BIT(TIMSK, TOIE1);
        break;
    default:
        break;
    }
    switch (ARGSetTimer1CompareMatchAInterruptOnOffU8)
    {
    case MTIMER1_ON:
        SET_BIT(TIMSK, OCIE1A);
        break;
    case MTIMER1_OFF:
        CLEAR_BIT(TIMSK, OCIE1A);
        break;
    default:
        break;
    }
    switch (ARGSetTimer1CompareMatchBInterruptOnOffU8)
    {
    case MTIMER1_ON:
        SET_BIT(TIMSK, OCIE1B);
        break;
    case MTIMER1_OFF:
        CLEAR_BIT(TIMSK, OCIE1B);
        break;
    default:
        break;
    }
    switch (ARGSetTimer1InputCaptureU8)
    {
    case MTIMER1_ON:
        SET_BIT(TIMSK, TICIE1);
        break;
    case MTIMER1_OFF:
        CLEAR_BIT(TIMSK, TICIE1);
        break;
    default:
        break;
    }
    return;
}
u8 ReadTimer1Flags()
{
    u8 flag = GET_BIT(TIFR, TOV1) | GET_BIT(TIFR, OCF1B) << 1 | GET_BIT(TIFR, OCF1A) << 2 | GET_BIT(TIFR, ICF1) << 3;
    SET_BIT(TIFR, TOV1);
    SET_BIT(TIFR, OCF1B);
    SET_BIT(TIFR, OCF1A);
    SET_BIT(TIFR, ICF1);
    return flag;
}
void SetSetTimer1INFunction(u8 ARGSetTimer1INTScU8, void (*ARGSetPtrToFunction)())
{

    switch (ARGSetTimer1INTScU8)
    {
    case MTIMER1__INPUTCAPTURE_INT:
        SetPtrToFunctionInCap = ARGSetPtrToFunction;
        break;
    case MTIMER1_COMPARE_MATCH_A_INT:
        SetPtrToFunctionCTCA = ARGSetPtrToFunction;
        break;
    case MTIMER1_COMPARE_MATCH_B_INT:
        SetPtrToFunctionCTCB = ARGSetPtrToFunction;
        break;
    case MTIMER1_OVER_FLOW_INT:
        SetPtrToFunctionOF = ARGSetPtrToFunction;
        break;

    default:
        break;
    }
}
void __vector_6(void) __attribute__((signal, used));
void __vector_6(void)
{
    SetPtrToFunctionInCap();
}

void __vector_7(void) __attribute__((signal, used));
void __vector_7(void)
{
    SetPtrToFunctionCTCA();
}

void __vector_8(void) __attribute__((signal, used));
void __vector_8(void)
{
    SetPtrToFunctionCTCB();
}

void __vector_9(void) __attribute__((signal, used));
void __vector_9(void)
{
    SetPtrTounctionOF();
}
