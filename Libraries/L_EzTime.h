/*
    title: EzTime library
    author: mohamed.nour
    version: 2
    last update: 17/12/2022
*/

#ifndef _L_EZTIME_H_
#define _L_EZTIME_H_

#define MSEC2TICKs(desiredTime, Prescaler, topValue, clkValue) (((desiredTime)*(clkValue))/((topValue)*(Prescaler)))
#endif