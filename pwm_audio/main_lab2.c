/* 
 * File:   main.c for lab 2
 * 
 * Author       Date            Description
 * 
 * 
 * Note: for every lab you must comment on your achievement of the week
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

extern int sec;

int main(void) {
    uart2_init(115200);
    heartbeat_init();
    set_stdio(C_UART2);
    printf("Starting\n");

    while(1){
        
        heartbeat();
    }
    return 0;
}



