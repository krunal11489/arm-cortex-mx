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

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	__asm volatile("ldr r0,=#0x20001000");
	__asm volatile("ldr r1,=#0x20001004");
	__asm volatile("ldr r2,[r0]");
	__asm volatile("ldr r3,[r1]");
	__asm volatile("add r3,r3,r2");
	__asm volatile("str r3,[r0]");
    /* Loop forever */
	for(;;);
}
