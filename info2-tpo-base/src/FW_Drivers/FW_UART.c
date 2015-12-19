/*
 * FW_UART.c
 *
 *  Created on: Nov 2, 2015
 *      Author: Catan
 */
#include "Aplicacion.h"



extern volatile uint8_t enviando;
extern volatile uint8_t enviando0;

void UART1_IRQHandler (void)
{

	uint8_t iir;
	int dato;

	do
	{
		//IIR es reset por HW, una vez que lo lei se resetea.
		iir = U1IIR;

		if ( iir & 0x06 ) //Error
				{

				}

		if ( iir & 0x04 ) //Data ready
		{
			dato=U1RBR;
			PushRx(dato);
		}

		if ( iir & 0x02 ) //THRE
		{
			dato=PopTx();
			if(dato!=-1)
			{
				U1THR=dato;
			}



			else
				enviando = 0;  //aviso que terminé de transmitir.
			}
	}
	while( ! ( iir & 0x01 ) ); /* me fijo si cuando entre a la ISR habia otra
						     	int. pendiente de atencion: b0=1 (ocurre unicamente si dentro del mismo
								espacio temporal lleguan dos interrupciones a la vez) */
}

void UART0_IRQHandler (void)
{

	uint8_t iir;
	int dato;

	do
	{
		//IIR es reset por HW, una vez que lo lei se resetea.
		iir = U0IIR;

		if ( iir & 0x06 ) //Error
				{

				}

		if ( iir & 0x04 ) //Data ready
		{
			dato=U0RBR;
			PushRx0(dato);
		}

		if ( iir & 0x02 ) //THRE
		{
			dato=PopTx0();
			if(dato!=-1)
			{
				U0THR=dato;
			}



			else
				enviando0 = 0;  //aviso que terminé de transmitir.
			}
	}
	while( ! ( iir & 0x01 ) ); /* me fijo si cuando entre a la ISR habia otra
						     	int. pendiente de atencion: b0=1 (ocurre unicamente si dentro del mismo
								espacio temporal lleguan dos interrupciones a la vez) */
}

