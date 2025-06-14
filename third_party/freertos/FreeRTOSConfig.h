// @nolint

/*
    FreeRTOS V7.1.0 - Copyright (C) 2011 Real Time Engineers Ltd.


    ***************************************************************************
     *                                                                       *
     *    FreeRTOS tutorial books are available in pdf and paperback.        *
     *    Complete, revised, and edited pdf reference manuals are also       *
     *    available.                                                         *
     *                                                                       *
     *    Purchasing FreeRTOS documentation will not only help you, by       *
     *    ensuring you get running as quickly as possible and with an        *
     *    in-depth knowledge of how to use FreeRTOS, it will also help       *
     *    the FreeRTOS project to continue with its mission of providing     *
     *    professional grade, cross platform, de facto standard solutions    *
     *    for microcontrollers - completely free of charge!                  *
     *                                                                       *
     *    >>> See http://www.FreeRTOS.org/Documentation for details. <<<     *
     *                                                                       *
     *    Thank you for using FreeRTOS, and thank you for your support!      *
     *                                                                       *
    ***************************************************************************


    This file is part of the FreeRTOS distribution.

    FreeRTOS is free software; you can redistribute it and/or modify it under
    the terms of the GNU General Public License (version 2) as published by the
    Free Software Foundation AND MODIFIED BY the FreeRTOS exception.
    >>>NOTE<<< The modification to the GPL is included to allow you to
    distribute a combined work that includes FreeRTOS without being obliged to
    provide the source code for proprietary components outside of the FreeRTOS
    kernel.  FreeRTOS is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
    more details. You should have received a copy of the GNU General Public
    License and the FreeRTOS license exception along with FreeRTOS; if not it
    can be viewed here: http://www.freertos.org/a00114.html and also obtained
    by writing to Richard Barry, contact details for whom are available on the
    FreeRTOS WEB site.

    1 tab == 4 spaces!

    http://www.FreeRTOS.org - Documentation, latest information, license and
    contact details.

    http://www.SafeRTOS.com - A version that is certified for use in safety
    critical systems.

    http://www.OpenRTOS.com - Commercial support, development, porting,
    licensing and training services.
*/

#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

/*-----------------------------------------------------------
 * Application specific definitions.
 *
 * These definitions should be adjusted for your particular hardware and
 * application requirements.
 *
 * THESE PARAMETERS ARE DESCRIBED WITHIN THE 'CONFIGURATION' SECTION OF THE
 * FreeRTOS API DOCUMENTATION AVAILABLE ON THE FreeRTOS.org WEB SITE.
 *
 * See http://www.freertos.org/a00110.html.
 *----------------------------------------------------------*/

#include "drivers/rtc.h"

#define CMSIS_COMPATIBLE
#include <mcu.h>

extern uint32_t SystemCoreClock;

#define configUSE_PREEMPTION     1
#define configUSE_IDLE_HOOK      0
#define configUSE_TICK_HOOK      0
#define configCPU_CLOCK_HZ       ((unsigned long)SystemCoreClock)
#define configTICK_RATE_HZ       ((TickType_t)RTC_TICKS_HZ)
#define configMAX_PRIORITIES     ((unsigned portBASE_TYPE)5)
#define configMINIMAL_STACK_SIZE ((unsigned short)196)
#define configTOTAL_HEAP_SIZE    ((size_t)(30 * 1024))
#define configMAX_TASK_NAME_LEN  (16)
#define configUSE_TRACE_FACILITY 0
#define configUSE_16_BIT_TICKS   0
#define configIDLE_SHOULD_YIELD  1
#define configUSE_TICKLESS_IDLE  2   // Use STOP mode
#define configUSE_STATS_FORMATTING_FUNCTIONS 1

#ifdef FREERTOS_FIRST_MPU_REGION
#define configFIRST_MPU_REGION FREERTOS_FIRST_MPU_REGION
#endif
#ifdef FREERTOS_LAST_MPU_REGION
#define configLAST_MPU_REGION FREERTOS_LAST_MPU_REGION
#endif

#define configUSE_TIMERS FREERTOS_USE_TIMERS
#define configTIMER_TASK_PRIORITY (configMAX_PRIORITIES - 1)
#define configTIMER_QUEUE_LENGTH 32
#define configTIMER_TASK_STACK_DEPTH (256 + 64)

/* Co-routine definitions. */
#define configUSE_CO_ROUTINES 		0
#define configMAX_CO_ROUTINE_PRIORITIES ( 2 )

#define configUSE_MUTEXES				0
#define configUSE_COUNTING_SEMAPHORES 	1
#define configUSE_ALTERNATIVE_API 		0
#define configCHECK_FOR_STACK_OVERFLOW	2
#define configUSE_RECURSIVE_MUTEXES		0
#define configQUEUE_REGISTRY_SIZE		0
#define configGENERATE_RUN_TIME_STATS	0
#define configUSE_NEWLIB_REENTRANT      0
#define configUSE_QUEUE_SETS            1
#define configUSE_LIGHT_MUTEXES         1
#define configUSE_RECURSIVE_LIGHT_MUTEXES 1
#define configUSE_TASK_NOTIFICATIONS    0
#define configENABLE_BACKWARD_COMPATIBILITY 0

/* Thread local storage for syscall information */
#define configNUM_THREAD_LOCAL_STORAGE_POINTERS 2

/* Set the following definitions to 1 to include the API function, or zero
to exclude the API function. */

#define INCLUDE_vTaskPrioritySet               1
#define INCLUDE_uxTaskPriorityGet              1
#define INCLUDE_vTaskDelete                    1
#define INCLUDE_vTaskCleanUpResources          0
#define INCLUDE_xTaskGetCurrentTaskHandle      1
#define INCLUDE_vTaskSuspend                   1
#define INCLUDE_vTaskDelayUntil                1
#define INCLUDE_vTaskDelay                     1
#define INCLUDE_eTaskGetState                  1
#define INCLUDE_xQueueGetMutexHolder           1
#define INCLUDE_pcTaskGetTaskName              1
#define INCLUDE_xTimerGetTimerDaemonTaskHandle 1
#define INCLUDE_xTaskGetSchedulerState         1
#define INCLUDE_uxTaskGetStackHighWaterMark    1
#define INCLUDE_xTaskGetIdleTaskHandle         1

/* This is the raw value as per the Cortex-M3 NVIC.  Values can be 255
(lowest) to 0 (1?) (highest). */
#define configKERNEL_INTERRUPT_PRIORITY      255
#define configMAX_SYSCALL_INTERRUPT_PRIORITY 191 /* equivalent to 0xb0, or priority 11. */


/* This is the value being used as per the ST library which permits 16
priority values, 0 to 15.  This must correspond to the
configKERNEL_INTERRUPT_PRIORITY setting.  Here 15 corresponds to the lowest
NVIC value of 255. */
#define configLIBRARY_KERNEL_INTERRUPT_PRIORITY 15


#define xPortSysTickHandler SysTick_Handler
#define xPortPendSVHandler  PendSV_Handler
#define vPortSVCHandler     SVC_Handler


/* Set this to add error checking code to the entry of each FreeRTOS function to ensure that the
   caller is in the correct state to make the call (ISR priority, critical section, etc.) */
#if !RELEASE
#define configCHECK_CALL_SAFETY 1
#else
#define configCHECK_CALL_SAFETY 0
#endif

/*-----------------------------------------------------------
 * Macros required to setup the timer for the run time stats.
 *-----------------------------------------------------------*/
/* The run time stats time base just uses the existing high frequency timer
test clock.  All these macros do is clear and return the high frequency
interrupt count respectively. */
//extern unsigned long ulRunTimeStatsClock;
//#define portCONFIGURE_TIMER_FOR_RUN_TIME_STATS() ulRunTimeStatsClock = 0
//#define portGET_RUN_TIME_COUNTER_VALUE() ulRunTimeStatsClock

#include "system/passert.h"
#define configASSERT( x ) \
  PBL_ASSERT(x, "FreeRTOS assert at " __FILE_NAME__ ":%d", __LINE__);

#if configCHECK_CALL_SAFETY
  #include "mcu/interrupts.h"
  bool vPortInCritical( void );
  #define configASSERT_SAFE_TO_CALL_FREERTOS_API()            \
    configASSERT(!vPortInCritical() && !mcu_state_is_isr())

  #define configASSERT_SAFE_TO_CALL_WAIT_FREERTOS_API(xTicksToWait)            \
    configASSERT((!vPortInCritical() || (vPortInCritical() && xTicksToWait == 0U)) && !mcu_state_is_isr())

  #define configASSERT_SAFE_TO_CALL_FREERTOS_FROMISR_API()            \
    configASSERT(!mcu_state_is_isr() || mcu_state_get_isr_priority() >= (configMAX_SYSCALL_INTERRUPT_PRIORITY >> (8U - __NVIC_PRIO_BITS)))

#else
  #define configASSERT_SAFE_TO_CALL_FREERTOS_API()           
  #define configASSERT_SAFE_TO_CALL_WAIT_FREERTOS_API(xTicksToWait)
  #define configASSERT_SAFE_TO_CALL_FREERTOS_FROMISR_API()

#endif


#endif /* FREERTOS_CONFIG_H */
