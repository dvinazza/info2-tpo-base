/*
 * DR_UART.c
 *
 *  Created on: Nov 2, 2015
 *      Author: Catan
 */
#include "Aplicacion.h"


// UART1
extern volatile uint8_t bufferTx[TOPE];
extern volatile uint8_t bufferRx[TOPE];
extern volatile uint8_t inx_out;
extern volatile uint8_t inx_in;
extern volatile uint8_t outx_out;
extern volatile uint8_t outx_in;
extern volatile uint8_t enviando;



//UART0

extern volatile uint8_t bufferTx0[TOPE];
extern volatile uint8_t bufferRx0[TOPE];
extern volatile uint8_t inx0_out;
extern volatile uint8_t inx0_in;
extern volatile uint8_t outx0_out;
extern volatile uint8_t outx0_in;
extern volatile uint8_t enviando0;

//--------------------------------------------------------------------------------------------------------------------------------


//UART 1 funciones
void PushTx(uint8_t dato)
{
		bufferTx[outx_in] = dato;
		outx_in++;	//guardo en buffer e incremento índice
			outx_in %= TOPE;					//garantizo el buffer circular
			if (!enviando) 		//si no estoy enviando....fuerzo la Tx.
			{
				enviando=1;
				U1THR = bufferTx[outx_out];

				outx_out++;
				outx_out=outx_out % TOPE;
			}
}



int PopTx(void)
{
	int aux=-1;
	if(outx_in!=outx_out)
	{
		aux=bufferTx[outx_out];
		outx_out++;
		outx_out=outx_out % TOPE;
	}
return aux;
}

void PushRx(uint8_t dato)
{
			bufferRx[inx_in] = dato;
			inx_in++;	//guardo en buffer e incremento índice
			inx_in %= TOPE;					//garantizo el buffer circular


}

int PopRx(void)
{
	int aux=-1;
	if(inx_in!=inx_out)
	{
		aux=bufferRx[inx_out];
		inx_out++;
		inx_out=inx_out % TOPE;
	}
return aux;
}

// UART 0 funciones
void PushTx0(uint8_t dato)
{
		bufferTx0[outx0_in] = dato;
		outx0_in++;	//guardo en buffer e incremento índice
			outx0_in %= TOPE;					//garantizo el buffer circular
			if (!enviando0) 		//si no estoy enviando....fuerzo la Tx.
			{
				enviando=1;
				U0THR = bufferTx0[outx0_out];

				outx0_out++;
				outx0_out=outx0_out % TOPE;
			}
}



int PopTx0(void)
{
	int aux=-1;
	if(outx0_in!=outx0_out)
	{
		aux=bufferTx0[outx0_out];
		outx0_out++;
		outx0_out=outx0_out % TOPE;
	}
return aux;
}

void PushRx0(uint8_t dato)
{
			bufferRx0[inx0_in] = dato;
			inx0_in++;	//guardo en buffer e incremento índice
			inx0_in %= TOPE;					//garantizo el buffer circular


}

int PopRx0(void)
{
	int aux=-1;
	if(inx0_in!=inx0_out)
	{
		aux=bufferRx0[inx0_out];
		inx0_out++;
		inx0_out=inx0_out % TOPE;
	}
return aux;
}
