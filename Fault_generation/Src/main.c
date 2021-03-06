/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#include <stdint.h>
#include<stdio.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	//1. Enable all configurable faults such as mem fault, bus faults, usage faults

	uint32_t *pSHCSR=(uint32_t *)0xE000ED24;

	*pSHCSR |= (1<<16); // to enable mem manage
	*pSHCSR |= (1<<17); // to enable bus manage
	*pSHCSR |= (1<<18); // to enable usage manage



	//3. lets force the processor to execute undefined instruction
	uint32_t *pSRAM=(uint32_t *)0x20001000;
	*pSRAM=0xFFFFFFFF;

	void (*fun_address)(void);
	fun_address= (void *) ((uint32_t)pSRAM+1);

	fun_address();
	//4. Analyze the fault
    /* Loop forever */
	for(;;);
}

//2. Implement the fault handlers
__attribute__((naked)) void UsageFault_Handler(void)
{
	//saving stack base via stack value
	__asm ("MRS r0,MSP");
	__asm("b UsageFault_Handler_c");
}

void UsageFault_Handler_c(uint32_t *pBasestackframe)
{
	uint32_t *pUFSR=(uint32_t*)0xE000ED2A;
	printf("Exception Fault: Usage Fault\n");
	printf("UFSR= %lx \n", (*pUFSR) & 0xFFFF);
	printf("Basestackframe=%p",pBasestackframe);
	printf("Reg R0=%lx",pBasestackframe[0]);
	printf("Reg R1=%lx",pBasestackframe[1]);
	printf("Reg R2=%lx",pBasestackframe[2]);
	printf("Reg R3=%lx",pBasestackframe[3]);
	printf("Reg R12=%lx",pBasestackframe[4]);
	printf("Reg LR=%lx",pBasestackframe[5]);
	printf("Reg PC=%lx",pBasestackframe[6]);
	printf("Reg XPSR=%lx",pBasestackframe[7]);
	while(1);
}

void BusFault_Handler(void)
{
	printf("Exception Fault: Bus Fault\n");
	while(1);
}

void MemManage_Handler(void)
{
	printf("Exception Fault: Mem Fault\n");
	while(1);
}

void HardFault_Handler(void)
{
	printf("Exception Fault: Hard Fault\n");
	while(1);
}
