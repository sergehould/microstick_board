#include <xc.h>
#include <sys/attribs.h>
//#include <stdio.h>

/* Prolog header needed here */
void __ISR( _TIMER_2_VECTOR, IPL1SOFT) T2InterruptHandler( void){
    
   
}

/* Prolog header needed here */
void timer2_init( void){
// Initializes and enables Timer2
    T2CONbits.TON = 0; // Disable Timer
    T2CONbits.TCS = 0; // Select internal instruction cycle clock
    T2CONbits.TGATE = 0; // Disable Gated Timer mode
    //    TCKPS<2:0>: Timer Input Clock Prescale Select bits(3)
    //111 = 1:256 prescale value
    //110 = 1:64 prescale value
    //101 = 1:32 prescale value
    //100 = 1:16 prescale value
    //011 = 1:8 prescale value
    //010 = 1:4 prescale value
    //001 = 1:2 prescale value
    //000 = 1:1 prescale value
    //T2CONbits.TCKPS = 0b111; // Select 1:256 Prescaler
    //T2CONbits.TCKPS = 0b110; // Select 1:64 Prescaler
    //T2CONbits.TCKPS = 0b011; // Select 1:8 Prescaler
    T2CONbits.TCKPS = 0b000; // Select 1:1 Prescaler
    TMR2 = 0x00; // Clear timer register
    PR2 = 0xfff;
    __builtin_disable_interrupts();   // disable interrupts
    IPC2bits.T2IP = 0x01; // Set Timer 2 Interrupt Priority Level
    INTCONbits.MVEC=1;
    IEC0bits.T2IE = 1; // Enable Timer 2 interrupt
    __builtin_enable_interrupts();   // enable interrupts
    T2CONbits.TON = 1; // Start Timer 
    IFS0bits.T2IF = 1; // Sets Timer 2 Interrupt Flag so the ISR is called right away
} // init