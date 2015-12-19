/*
 * DR_Display.c
 *
 *  Created on: 2/8/2015
 *      Author: emmaotm
 */

#include "Aplicacion.h"

extern volatile uint8_t Buff_Display[];

void BarridoDisplay7Seg (void)
{
	uint8_t auxiliar;

	static uint8_t digito = 0;

	auxiliar = Buff_Display[digito];

	SetPIN (BCD_A, (auxiliar & ((uint8_t)0x01)) );
	SetPIN (BCD_B, ((auxiliar>>1) & ((uint8_t)0x01)) );
	SetPIN (BCD_C, ((auxiliar>>2) & ((uint8_t)0x01)) );
	SetPIN (BCD_D, ((auxiliar>>3) & ((uint8_t)0x01)) );

	if ( !digito )
	{
		SetPIN (RST, ON);

		SetPIN (RST, OFF);
	}

	else
	{
		SetPIN (CLK, ON);

		SetPIN (CLK, OFF);
	}




	digito++;

	digito = digito % DIGITOS;
}

void ApagarDisplay (void)
{
	SetPIN (BCD_A, ON); SetPIN (BCD_B, ON);
	SetPIN (BCD_C, ON); SetPIN (BCD_D, ON);
	SetPIN (seg_dp, OFF);
}


