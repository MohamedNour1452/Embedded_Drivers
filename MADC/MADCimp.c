/*
title: ADC Driver imp
author:M.Nour
version: 0
date:3/12/2022

*/

#include "MADCHeader.h"
#include "MADCPrivate.h"

void SetADCEnable(u8 ARGSetADCEnableU8)
{
    switch (ARGSetADCEnableU8)
    {
    case ADC_ON:
        SET_BIT(*ADCSRA, aden);
        break;
    case ADC_OFF :
        CLEAR_BIT(*ADCSRA, aden);
        break;
    default:
        break;
    }
    return;
}
void SetADCconfig(u8 ARGSetADCAutoTriggerEnableU8, u8 ARGSetADCRefU8)
{   
    CLEAR_BIT(*ADCSRA, adps0);
    SET_BIT(*ADCSRA, adps1);
    CLEAR_BIT(*ADCSRA, adps2);
    switch (ARGSetADCAutoTriggerEnableU8)
    {
    case ADC_ON:
        SET_BIT(*ADCSRA, adsc);
        break;
    case ADC_OFF:
        CLEAR_BIT(*ADCSRA, adsc);
        break;
    default:
        break;
    }    
    switch (ARGSetADCRefU8)
    {
    case AVCC:
        SET_BIT(*ADCMUX, refs0);
        CLEAR_BIT(*ADCMUX, refs1);
        break;
    case INTERNAL:
        SET_BIT(*ADCMUX, refs0);
        SET_BIT(*ADCMUX, refs1);
        break;
    default:
        break;
    }
    
    return;
}
u16 ReadADC(u8 ARGSETADCSourceU8)
{
    switch (ARGSETADCSourceU8)
    {
    case adc0:
        CLEAR_BIT(*ADCMUX, mux0);
        CLEAR_BIT(*ADCMUX, mux1);
        CLEAR_BIT(*ADCMUX, mux2);
        CLEAR_BIT(*ADCMUX, mux3);
        CLEAR_BIT(*ADCMUX, mux4);
        break;
    case adc1:
        SET_BIT(*ADCMUX, mux0);
        CLEAR_BIT(*ADCMUX, mux1);
        CLEAR_BIT(*ADCMUX, mux2);
        CLEAR_BIT(*ADCMUX, mux3);
        CLEAR_BIT(*ADCMUX, mux4);
        break;
    case adc2:
        CLEAR_BIT(*ADCMUX, mux0);
        SET_BIT(*ADCMUX, mux1);
        CLEAR_BIT(*ADCMUX, mux2);
        CLEAR_BIT(*ADCMUX, mux3);
        CLEAR_BIT(*ADCMUX, mux4);
        break;
    case adc3:
        SET_BIT(*ADCMUX, mux0);
        SET_BIT(*ADCMUX, mux1);
        CLEAR_BIT(*ADCMUX, mux2);
        CLEAR_BIT(*ADCMUX, mux3);
        CLEAR_BIT(*ADCMUX, mux4);
        break;
    case adc4:
        CLEAR_BIT(*ADCMUX, mux0);
        CLEAR_BIT(*ADCMUX, mux1);
        SET_BIT(*ADCMUX, mux2);
        CLEAR_BIT(*ADCMUX, mux3);
        CLEAR_BIT(*ADCMUX, mux4);
        break;
    case adc5:
        SET_BIT(*ADCMUX, mux0);
        CLEAR_BIT(*ADCMUX, mux1);
        SET_BIT(*ADCMUX, mux2);
        CLEAR_BIT(*ADCMUX, mux3);
        CLEAR_BIT(*ADCMUX, mux4);
        break;
    case adc6:
        CLEAR_BIT(*ADCMUX, mux0);
        SET_BIT(*ADCMUX, mux1);
        SET_BIT(*ADCMUX, mux2);
        CLEAR_BIT(*ADCMUX, mux3);
        CLEAR_BIT(*ADCMUX, mux4);
        break;
    case adc7:
        SET_BIT(*ADCMUX, mux0);
        SET_BIT(*ADCMUX, mux1);
        SET_BIT(*ADCMUX, mux2);
        CLEAR_BIT(*ADCMUX, mux3);
        CLEAR_BIT(*ADCMUX, mux4);
        break;
    case BANDGAP1V22:
        CLEAR_BIT(*ADCMUX, mux0);
        SET_BIT(*ADCMUX, mux1);
        SET_BIT(*ADCMUX, mux2);
        SET_BIT(*ADCMUX, mux3);
        SET_BIT(*ADCMUX, mux4);
        break;
    case GND:
        SET_BIT(*ADCMUX, mux0);
        SET_BIT(*ADCMUX, mux1);
        SET_BIT(*ADCMUX, mux2);
        SET_BIT(*ADCMUX, mux3);
        SET_BIT(*ADCMUX, mux4);
        break;
    default:
        break;
    }
    
    SET_BIT(*ADCSRA, adsc);
    _delay_ms(1);

    return ( *ADCL | (*ADCH << 8));  

}
