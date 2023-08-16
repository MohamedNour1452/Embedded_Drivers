 /*
    title: MEXTI Driver private
    author: a7
    company: amit
    version: 0
    date: 2/12/22
 */

#ifndef _MEXTIE_PRIVATE_H
#define _MEXTIE_PRIVATE_H

    #define GICR ((u8*)0x5B)
    #define MCUCR ((u8*)0x55)
    #define MCUCSR ((u8*)0x54)
    #define GIFR ((volatile u8*)0x5a)
    #define ISC00 0
    #define ISC01 1
    #define ISC10 2
    #define ISC11 3
    #define ISC2 6
    #define INTF0 6
    #define INTF1 7
    #define INTF2 5


#endif