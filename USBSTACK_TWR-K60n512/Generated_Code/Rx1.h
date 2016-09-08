/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : Rx1.h
**     Project     : USBSTACK
**     Processor   : MK60DN512ZVLQ10
**     Component   : RingBuffer
**     Version     : Component 01.039, Driver 01.00, CPU db: 3.00.001
**     Repository  : My Components
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-09-07, 23:22, # CodeGen: 0
**     Abstract    :
**         This component implements a ring buffer for different integer data type.
**     Settings    :
**          Component name                                 : Rx1
**          Reentrant                                      : yes
**          Critical Section                               : CS2
**          Buffer Size                                    : 1
**          Element Size                                   : 1 Byte
**     Contents    :
**         Clear           - void Rx1_Clear(void);
**         Put             - uint8_t Rx1_Put(Rx1_ElementType elem);
**         Get             - uint8_t Rx1_Get(Rx1_ElementType *elemP);
**         Peek            - uint8_t Rx1_Peek(Rx1_BufSizeType index, Rx1_ElementType *elemP);
**         NofElements     - Rx1_BufSizeType Rx1_NofElements(void);
**         NofFreeElements - Rx1_BufSizeType Rx1_NofFreeElements(void);
**         Deinit          - void Rx1_Deinit(void);
**         Init            - void Rx1_Init(void);
**
**     License   :  Open Source (LGPL)
**     Copyright : (c) Copyright Erich Styger, 2014, all rights reserved.
**     Web: http://www.mcuoneclipse.com
**     This an open source software of an embedded component for Processor Expert.
**     This is a free software and is opened for education,  research  and commercial developments under license policy of following terms:
**     * This is a free software and there is NO WARRANTY.
**     * No restriction on use. You can use, modify and redistribute it for personal, non-profit or commercial product UNDER YOUR RESPONSIBILITY.
**     * Redistributions of source code must retain the above copyright notice.
** ###################################################################*/
/*!
** @file Rx1.h
** @version 01.00
** @brief
**         This component implements a ring buffer for different integer data type.
*/         
/*!
**  @addtogroup Rx1_module Rx1 module documentation
**  @{
*/         

#ifndef __Rx1_H
#define __Rx1_H

/* MODULE Rx1. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "CS2.h"

#include "Cpu.h"


#define Rx1_BUF_SIZE    1   /* number of elements in the buffer */
#define Rx1_ELEM_SIZE   1  /* size of a single element in bytes */
#define Rx1_IS_REENTRANT   1  /* 1: Critical section used for accessing shared data, 0 otherwise */
#if Rx1_ELEM_SIZE==1
  typedef uint8_t Rx1_ElementType; /* type of single element */
#elif Rx1_ELEM_SIZE==2
  typedef uint16_t Rx1_ElementType; /* type of single element */
#elif Rx1_ELEM_SIZE==4
  typedef uint32_t Rx1_ElementType; /* type of single element */
#else
  #error "illegal element type size in properties"
#endif
#if Rx1_BUF_SIZE<256
  typedef uint8_t Rx1_BufSizeType; /* up to 255 elements (index 0x00..0xff) */
#else
  typedef uint16_t Rx1_BufSizeType; /* more than 255 elements, up to 2^16 */
#endif

uint8_t Rx1_Put(Rx1_ElementType elem);
/*
** ===================================================================
**     Method      :  Rx1_Put (component RingBuffer)
**     Description :
**         Puts a new element into the buffer
**     Parameters  :
**         NAME            - DESCRIPTION
**         elem            - New element to be put into the buffer
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t Rx1_Get(Rx1_ElementType *elemP);
/*
** ===================================================================
**     Method      :  Rx1_Get (component RingBuffer)
**     Description :
**         Removes an element from the buffer
**     Parameters  :
**         NAME            - DESCRIPTION
**       * elemP           - Pointer to where to store the received
**                           element
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

Rx1_BufSizeType Rx1_NofElements(void);
/*
** ===================================================================
**     Method      :  Rx1_NofElements (component RingBuffer)
**     Description :
**         Returns the actual number of elements in the buffer.
**     Parameters  : None
**     Returns     :
**         ---             - Number of elements in the buffer.
** ===================================================================
*/

void Rx1_Init(void);
/*
** ===================================================================
**     Method      :  Rx1_Init (component RingBuffer)
**     Description :
**         Initializes the data structure
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

Rx1_BufSizeType Rx1_NofFreeElements(void);
/*
** ===================================================================
**     Method      :  Rx1_NofFreeElements (component RingBuffer)
**     Description :
**         Returns the actual number of free elements/space in the
**         buffer.
**     Parameters  : None
**     Returns     :
**         ---             - Number of elements in the buffer.
** ===================================================================
*/

void Rx1_Clear(void);
/*
** ===================================================================
**     Method      :  Rx1_Clear (component RingBuffer)
**     Description :
**         Clear (empty) the ring buffer.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

uint8_t Rx1_Peek(Rx1_BufSizeType index, Rx1_ElementType *elemP);
/*
** ===================================================================
**     Method      :  Rx1_Peek (component RingBuffer)
**     Description :
**         Returns an element of the buffer without removiing it.
**     Parameters  :
**         NAME            - DESCRIPTION
**         index           - Index of element. 0 peeks the top
**                           element, 1 the next, and so on.
**       * elemP           - Pointer to where to store the received
**                           element
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

#define Rx1_Deinit() \
   /* nothing to deinitialize */
/*
** ===================================================================
**     Method      :  Rx1_Deinit (component RingBuffer)
**     Description :
**         Driver de-initialization
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

/* END Rx1. */

#endif
/* ifndef __Rx1_H */
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
