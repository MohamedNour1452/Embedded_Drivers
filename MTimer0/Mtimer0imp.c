/*
    title: Timer0 Driver imp
    author: M.nour
    last update: 10/12/21
*/

#include "Mtimer0Header.h"
#include "Mtimer0Private.h"

void(*SetPtrTounctionOF)();
void(*SetPtrTounctionCTC)();

void SelectTimer0Mode(u8 ARGSetTimer0ModeU8)
{
    switch (ARGSetTimer0ModeU8)
    {
    case MTIMER0_NORMAL_MODE:
        CLEAR_BIT(TCCR0, WGM00);
        CLEAR_BIT(TCCR0, WGM01);
        break;
    case MTIMER0_PHASE_CORRECT_MODE:
        SET_BIT(TCCR0, WGM00);
        CLEAR_BIT(TCCR0, WGM01);
        break;
    case MTIMER0_COMPARE_MATCH:
        CLEAR_BIT(TCCR0, WGM00);
        SET_BIT(TCCR0, WGM01);
        break;
    case MTIMER0_FAST_PWM_MODE:
        SET_BIT(TCCR0, WGM00);
        SET_BIT(TCCR0, WGM01);
        break;
    default:
        break;
    }
    return;
}
void ConfigTimer0Clock(u8 ARGSetTimer0ConfigU8)
{
    switch (ARGSetTimer0ConfigU8)
    {
    case MTIMER0_OFF :
        CLEAR_BIT(TCCR0, CS00);
        CLEAR_BIT(TCCR0, CS01);
        CLEAR_BIT(TCCR0, CS02);
        break;
    case MTIMER0_CLK :
        SET_BIT(TCCR0, CS00);
        CLEAR_BIT(TCCR0, CS01);
        CLEAR_BIT(TCCR0, CS02);
        break;
    case MTIMER0_CLK_DIV8 :
        CLEAR_BIT(TCCR0, CS00);
        SET_BIT(TCCR0, CS01);
        CLEAR_BIT(TCCR0, CS02);
        break;
    case MTIMER0_CLK_DIV64 :
        SET_BIT(TCCR0, CS00);
        SET_BIT(TCCR0, CS01);
        CLEAR_BIT(TCCR0, CS02);
        break;
    case MTIMER0_CLK_DIV256 :
        CLEAR_BIT(TCCR0, CS00);
        CLEAR_BIT(TCCR0, CS01);
        SET_BIT(TCCR0, CS02);
        break;
    case MTIMER0_CLK_DIV1024 :
        SET_BIT(TCCR0, CS00);
        CLEAR_BIT(TCCR0, CS01);
        SET_BIT(TCCR0, CS02);
        break;
    case MTIMER0_EXTERNAL_FALLING :
        CLEAR_BIT(TCCR0, CS00);
        SET_BIT(TCCR0, CS01);
        SET_BIT(TCCR0, CS02);
        break;
    case MTIMER0_EXTERNAL_RISING:
        SET_BIT(TCCR0, CS00);
        SET_BIT(TCCR0, CS01);
        SET_BIT(TCCR0, CS02);
        break;
    default:
        break;
    }
    return;
}
void SetTimer0OutputMode(u8 ARGTimer0OutputModeU8)
{
    switch (ARGTimer0OutputModeU8)
    {
    case MTIMER0_OC0_DISCONNECTED:
        CLEAR_BIT(TCCR0, COM00);
        CLEAR_BIT(TCCR0, COM01);
        break;
    case MTIMER0_OC0_TOGGLE:
        SET_BIT(TCCR0, COM00);
        CLEAR_BIT(TCCR0, COM01);
        break;
    case MTIMER0_OC0_CLEAR:
        CLEAR_BIT(TCCR0, COM00);
        SET_BIT(TCCR0, COM01);
        break;
    case MTIMER0_OC0_SET:
        SET_BIT(TCCR0, COM00);
        SET_BIT(TCCR0, COM01);
        break;
    default:
        break;
    }
    return;
}
u8 ReadTimer0()
{
    return TCNT0;
}
void WriteTimer0(u8 ARGSetTimer0ValueU8)
{
    TCNT0 = ARGSetTimer0ValueU8;
    return;
}
void SetTimer0CompareValue(u8 ARGSetTimer0CompareValueU8)
{
    OCR0 = ARGSetTimer0CompareValueU8;
    return;
}
void SetTimer0Interrrupt(u8 ARGSetTimer0OverFlowInterruptOnOffU8, u8 ARGSetTimer0CompareMatchInterruptOnOffU8)
{
    switch (ARGSetTimer0OverFlowInterruptOnOffU8)
    {
    case MTIMER0_ON:
        SET_BIT(TIMSK, TOIE0);
        break;
    case MTIMER0_OFF:
        CLEAR_BIT(TIMSK, TOIE0);
        break;
    default:
        break;
    }
    switch (ARGSetTimer0CompareMatchInterruptOnOffU8)
    {
    case MTIMER0_ON:
        SET_BIT(TIMSK, OCIE0);
        break;
    case MTIMER0_OFF:
        CLEAR_BIT(TIMSK, OCIE0);
        break;
    default:
        break;
    }
    return;
}
u8 ReadTimer0Flags()
{   
    u8 flag =   GET_BIT(TIFR, OCF0) << 1| GET_BIT(TIFR, TOV0);
    SET_BIT(TIFR, TOV0);
    SET_BIT(TIFR, OCF0);
    return flag;
}

void SetSetTimer0INFunction(u8 ARGSetTimer0INTScU8, void (*ARGSetPtrToFunction)())
{

    switch (ARGSetTimer0INTScU8)
    {
        case MTIMER0_COMPARE_MATCH_INT:
            SetPtrTounctionCTC = ARGSetPtrToFunction;
        break;

        case MTIMER0_OVER_FLOW_INT:
            SetPtrTounctionOF = ARGSetPtrToFunction;
        break;

        default:
        break;
    }

}
void __vector_10(void)__attribute__((signal,used));
void __vector_10(void)
{
    SetPtrTounctionCTC();
}

void __vector_11(void)__attribute__((signal,used));
void __vector_11(void)
{
    SetPtrTounctionOF();
}

