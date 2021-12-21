/*
 * main.h
 *
 *  Created on: 13-Jul-2021
 *      Author: Krunal
 */

#ifndef MAIN_H_
#define MAIN_H_

// memory calculation
#define TASK_STACK_SIZE  1024U
#define SCHED_STACK_SIZE  1024U

#define SRAM_START 0x20000000U
#define SRAM_SIZE ((128)*(1024))
#define SRAM_END ((SRAM_START)+(SRAM_SIZE))


#define T1_STACK_START 		SRAM_END
#define T2_STACK_START 		((T1_STACK_START)-(TASK_STACK_SIZE)) // ((SRAM_END)-(1*TASK_STACK_SIZE))
#define T3_STACK_START 		((T2_STACK_START)-(TASK_STACK_SIZE)) // ((SRAM_END)-(2*TASK_STACK_SIZE))
#define T4_STACK_START 		((T3_STACK_START)-(TASK_STACK_SIZE)) // ((SRAM_END)-(3*TASK_STACK_SIZE))
#define IDLE_STACK_START    ((T4_STACK_START)-(SCHED_STACK_SIZE)) // ((SRAM_END)-(4*TASK_STACK_SIZE))
#define SCHED_STACK_START	((IDLE_STACK_START)-(SCHED_STACK_SIZE)) // ((SRAM_END)-(5*TASK_STACK_SIZE))

#define HSI_CLK 16000000U
#define SYSTICK_TIM_CLK HSI_CLK
#define TICK_HZ 1000U

#define MAX_TASKS 5
#define DUMMY_XPSR 0x01000000U

#define TASK_READY_STATE 0x00
#define TASK_BLOCKED_STATE 0xFF

#define INTERRUPT_DISABLE() do{__asm volatile("MOV R0,0x01");__asm volatile("MSR PRIMASK,R0");}while(0)
#define INTERRUPT_ENABLE() do{__asm volatile("MOV R0,0x00");__asm volatile("MSR PRIMASK,R0");}while(0)

#endif /* MAIN_H_ */
