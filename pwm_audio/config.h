/* 
 * File:   public.h
 * Author: sh
 *
 * Created on December 14, 2021, 11:54 AM
 */

#ifndef PUBLIC_H
#define	PUBLIC_H

#ifdef	__cplusplus
extern "C" {
#endif

 /* Add common macros here*/
//#define DEBUG
#if defined DEBUG
    #define MAX   56448
#else
    #define MAX   393693
#endif


#ifdef	__cplusplus
}
#endif

#endif	/* PUBLIC_H */

