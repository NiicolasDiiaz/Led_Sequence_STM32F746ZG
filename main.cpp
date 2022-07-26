#include <stdio.h>
#include "STM32F7xx.h"


int main (void)
{
	int i=0;
	int time=500000;
	
	//CONFIGURACION "CLOCK"
		
	RCC->AHB1ENR = 0x6; //prender clock del puerto B y C
	
	//CONFIGURACION DE PINES PUERTO F
	
	GPIOC->MODER=0x0555555; //PTB0-PTB7-PTB14->OUTPUT
	GPIOC->OTYPER=0; //PUSH PULL->PTB0-PTB7-PTB14
	GPIOC->OSPEEDR=0x1555; //MEDIUM SPEED ->PTB0-PTB7-PTB14
	GPIOC->PUPDR=0x1; //PULL-UP->PTB0-PTB7-PTB14
	
	GPIOB->MODER = 0x10004001;
	GPIOB->OTYPER = 0;
	GPIOB->OSPEEDR = 0x10004001;
	GPIOB->PUPDR = 0x10004001;


	while(1){
		if((GPIOC->IDR & 0x2000) == 0x2000){
		GPIOB->ODR |= (1UL << 0);
		for (i=0; i<time; i++);
		GPIOB->ODR &= ~(1UL << 0);
		for (i=0; i<time; i++);
		}
		else{
		GPIOB->ODR |= (1UL << 7);
		for (i=0; i<time; i++);
		GPIOB->ODR &= ~(1UL << 7);
		for (i=0; i<time; i++);
	}
}
}