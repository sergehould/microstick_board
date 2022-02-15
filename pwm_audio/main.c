/* 
 * File:   main.c for lab 5
 * 
 * Author       Date            Description
 * 
 * 
 * Note: every lab you must comment on your achievement of the week
 */

#include "util.h"
#include <stdio.h>
#include <xc.h>
#include "initBoard.h"
#include <sys/attribs.h>
#include "pwm.h"
#include <math.h>
#include "config.h"
#include "console.h"



int main(void) {

    Uart2_init();
    init_heartbeat();
    set_stdio(C_UART2);
    printf("Starting\n");

    while(1){
        heartbeat();
    }
    return 0;
}



