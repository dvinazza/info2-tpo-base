/*
 hj * FW_InitUART.c
 *
 *  Created on: Nov 2, 2015
 *      Author: Catan
 */
#include "Aplicacion.h"


void InitUART1 (void)
{
	//1.- Registro PCONP (0x400FC0C4) - bit 4 en 1 prende la UART1:
	PCONP |= (0x01<<4);
	//2.- Registro PCLKSEL0 (0x400FC1A8) - bits 6 y 7 en 0 seleccionan que el clk de la UART0 sea CCLK/4:
	PCLKSEL0 &= ~(0x03<<8);	//con un CCLOK=100Mhz, nos queda PCLOCK=25Mhz
	//3.- Registro U1LCR (0x4001000C) - transmision de 8 bits, 1 bit de stop, sin paridad, sin break cond, DLAB = 1:
	U1LCR = 0x83;
	//4.- Registros U1DLL (0x40010000) y U1DLM (0x40010004) - 9600 baudios:
	U1DLM = 0;
	U1DLL = 0xA3;//0xA3 para 9600
	//5.- Registros PINSEL0 (0x4002C000) y PINSEL1 (0x4002C004) - habilitan las funciones especiales de los pines:
	//TX1D : PIN ??	->
	SetPINSEL(TX1,PINSEL_FUNC1);
	//RX1D : PIN ??	-> 		7
	SetPINSEL(RX1,PINSEL_FUNC1);
	//6.- Registro U1LCR, pongo DLAB en 0:
	U1LCR = 0x03;

	//7. Habilito las interrupciones (En la UART -IER- y en el NVIC -ISER)
	U1IER = 0x03;
	ISER0 |= (1<<6);

	//1.- Registro PCONP (0x400FC0C4) - bit 3 en 1 prende la UART:
	/*        PCONP |= 0x01<<3;

	        //2.- Registro PCLKSEL0 (0x400FC1A8) - bits 6 y 7 en 0 seleccionan que el clk de la UART0 sea CCLK/4:
	        PCLKSEL0 &= ~(0x03<<6); //con un CCLOK=100Mhz, nos queda PCLOCK=25Mhz

	        //3.- Registro U1LCR (0x4001000C) - transmision de 8 bits, 1 bit de stop, sin paridad, sin break cond, DLAB = 1:
	        U1LCR = 0x00000083;

	        //3.- Registro U1LCR (0x4001000C) - transmision de 8 bits, 1 bit de stop, con paridad, sin break cond, DLAB = 1:
	        //U1LCR = 0x9B;

	        //3.- Registro U1LCR (0x4001000C) - transmision de 8 bits, 2 bit de stop, sin paridad, sin break cond, DLAB = 1:
	        //U1LCR = 0x87;


	        //4.- Registros U1DLL (0x40010000) y U1DLM (0x40010004) - 9600 baudios:
	        U1DLM = 0;
	        U1DLL = 0xA3;//0xA3 para 9600
	        //5.- Registros PINSEL0 (0x4002C000) y PINSEL1 (0x4002C004) - habilitan las funciones especiales de los pines:
	        //TX1D : PIN ?? ->              P0[2]   -> PINSEL0: 04:05
	        SetPINSEL(TX1,PINSEL_FUNC1);
	        //RX1D : PIN ?? ->              P0[3]   -> PINSEL1: 06:07
	        SetPINSEL(RX1,PINSEL_FUNC1);

	        //6.- Registro U1LCR, pongo DLAB en 0:
	        U1LCR = 0x03;

	        //6.- Registro U1LCR, pongo DLAB en 0:
	        //U1LCR = 0x1B;

	        //6.- Registro U1LCR, pongo DLAB en 0:
	        //U1LCR = 0x07;

	        //7. Habilito las interrupciones (En la UART -IER- y en el NVIC -ISER)
	        U1IER = 0x03;

	        ISER0 |= (1<<6);*/
}

void InitUART0(void)
{
	//1.- Registro PCONP (0x400FC0C4) - bit 3 en 1 prende la UART:
		        PCONP |= 0x01<<3;

		        //2.- Registro PCLKSEL0 (0x400FC1A8) - bits 6 y 7 en 0 seleccionan que el clk de la UART0 sea CCLK/4:
		        PCLKSEL0 &= ~(0x03<<6); //con un CCLOK=100Mhz, nos queda PCLOCK=25Mhz

		        //3.- Registro U1LCR (0x4001000C) - transmision de 8 bits, 1 bit de stop, sin paridad, sin break cond, DLAB = 1:
		        U0LCR = 0x00000083;

		        //3.- Registro U1LCR (0x4001000C) - transmision de 8 bits, 1 bit de stop, con paridad, sin break cond, DLAB = 1:
		        //U1LCR = 0x9B;

		        //3.- Registro U1LCR (0x4001000C) - transmision de 8 bits, 2 bit de stop, sin paridad, sin break cond, DLAB = 1:
		        //U1LCR = 0x87;


		        //4.- Registros U1DLL (0x40010000) y U1DLM (0x40010004) - 9600 baudios:
		        U0DLM = 0;
		        U0DLL = 0xA3;//0xA3 para 9600
		        //5.- Registros PINSEL0 (0x4002C000) y PINSEL1 (0x4002C004) - habilitan las funciones especiales de los pines:
		        //TX1D : PIN ?? ->              P0[2]   -> PINSEL0: 04:05
		        SetPINSEL(TX0,PINSEL_FUNC1);
		        //RX1D : PIN ?? ->              P0[3]   -> PINSEL1: 06:07
		        SetPINSEL(RX0,PINSEL_FUNC1);

		        //6.- Registro U1LCR, pongo DLAB en 0:
		        U0LCR = 0x03;

		        //6.- Registro U1LCR, pongo DLAB en 0:
		        //U1LCR = 0x1B;

		        //6.- Registro U1LCR, pongo DLAB en 0:
		        //U1LCR = 0x07;

		        //7. Habilito las interrupciones (En la UART -IER- y en el NVIC -ISER)
		        U0IER = 0x03;

		        ISER0 |= (1<<5);

}
