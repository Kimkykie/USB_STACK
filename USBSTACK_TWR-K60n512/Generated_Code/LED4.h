/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : LED4.h
**     Project     : USBSTACK
**     Processor   : MK60DN512ZVLQ10
**     Component   : LED
**     Version     : Component 01.063, Driver 01.00, CPU db: 3.00.001
**     Repository  : My Components
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-09-07, 23:22, # CodeGen: 0
**     Abstract    :
**          This component implements a universal driver for a single LED.
**     Settings    :
**          Component name                                 : LED4
**          Turned On with initialization                  : no
**          HW Interface                                   : 
**            Anode on port side, HIGH is ON               : no
**            On/Off                                       : Enabled
**              Pin                                        : LEDpin
**            PWM                                          : Disabled
**          Shell                                          : Disabled
**     Contents    :
**         Init       - void LED4_Init(void);
**         Deinit     - void LED4_Deinit(void);
**         On         - void LED4_On(void);
**         Off        - void LED4_Off(void);
**         Neg        - void LED4_Neg(void);
**         Get        - byte LED4_Get(void);
**         Put        - void LED4_Put(byte val);
**         SetRatio16 - void LED4_SetRatio16(word ratio);
**
**     License   : Open Source (LGPL)
**     Copyright : Erich Styger, 2013, all rights reserved.
**     Web       : www.mcuoneclipse.com
**     This an open source software implementing a driver using Processor Expert.
**     This is a free software and is opened for education, research and commercial developments under license policy of following terms:
**     * This is a free software and there is NO WARRANTY.
**     * No restriction on use. You can use, modify and redistribute it for personal, non-profit or commercial product UNDER YOUR RESPONSIBILITY.
**     * Redistributions of source code must retain the above copyright notice.
** ###################################################################*/
/*!
** @file LED4.h
** @version 01.00
** @brief
**          This component implements a universal driver for a single LED.
*/         
/*!
**  @addtogroup LED4_module LED4 module documentation
**  @{
*/         

#ifndef __LED4_H
#define __LED4_H

/* MODULE LED4. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "LEDpin4.h"

#include "Cpu.h"

#define LED4_ClrVal()    LEDpin4_ClrVal() /* put the pin on low level */
#define LED4_SetVal()    LEDpin4_SetVal() /* put the pin on high level */
#define LED4_SetInput()  LEDpin4_SetInput() /* use the pin as input pin */
#define LED4_SetOutput() LEDpin4_SetOutput() /* use the pin as output pin */

#define LED4_PARSE_COMMAND_ENABLED  0 /* set to 1 if method ParseCommand() is present, 0 otherwise */


#define LED4_On() LEDpin4_ClrVal()
/*
** ===================================================================
**     Method      :  LED4_On (component LED)
**     Description :
**         This turns the LED on.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define LED4_Off() LEDpin4_SetVal()
/*
** ===================================================================
**     Method      :  LED4_Off (component LED)
**     Description :
**         This turns the LED off.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define LED4_Neg() LEDpin4_NegVal()
/*
** ===================================================================
**     Method      :  LED4_Neg (component LED)
**     Description :
**         This negates/toggles the LED
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define LED4_Get() (!(LEDpin4_GetVal()))
/*
** ===================================================================
**     Method      :  LED4_Get (component LED)
**     Description :
**         This returns logical 1 in case the LED is on, 0 otherwise.
**     Parameters  : None
**     Returns     :
**         ---             - Status of the LED (on or off)
** ===================================================================
*/

#define LED4_Init() LED4_Off()
/*
** ===================================================================
**     Method      :  LED4_Init (component LED)
**     Description :
**         Performs the LED driver initialization.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define LED4_Put(val)  ((val) ? LED4_On() : LED4_Off())
/*
** ===================================================================
**     Method      :  LED4_Put (component LED)
**     Description :
**         Turns the LED on or off.
**     Parameters  :
**         NAME            - DESCRIPTION
**         val             - value to define if the LED has to be on or
**                           off.
**     Returns     : Nothing
** ===================================================================
*/

void LED4_Deinit(void);
/*
** ===================================================================
**     Method      :  LED4_Deinit (component LED)
**     Description :
**         Deinitializes the driver
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void LED4_SetRatio16(word ratio);
/*
** ===================================================================
**     Method      :  LED4_SetRatio16 (component LED)
**     Description :
**         Method to specify the duty cycle. If using a PWM pin, this
**         means the duty cycle is set. For On/off pins, values smaller
**         0x7FFF means off, while values greater means on.
**     Parameters  :
**         NAME            - DESCRIPTION
**         ratio           - Ratio value, where 0 means 'off' and
**                           0xffff means 'on'
**     Returns     : Nothing
** ===================================================================
*/

/* END LED4. */

#endif
/* ifndef __LED4_H */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
