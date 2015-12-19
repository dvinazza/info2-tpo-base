/*
 * PR_Display7Seg.c
 *
 *  Created on: 1/8/2015
 *      Author: emmaotm
 */

#include "Aplicacion.h"

extern volatile uint8_t Buff_Display [];


void Display (uint16_t val, uint8_t pos)
{
	uint8_t aux1, aux2[2], aux3[3];

	uint8_t i;

	switch ( pos )
	{
		case DSP0:
			aux1 = val;

			TICKINT = OFF;
			Buff_Display[0] = aux1;
			TICKINT = ON;
			break;

		case DSP1:
			aux2[0] = val%10;
			val = val/10;
			aux2[1] = val;

			TICKINT = OFF;
			Buff_Display[1] = aux2[1];
			Buff_Display[2] = aux2[0];
			TICKINT = ON;
			break;

		case DSP2:
			for (i=0; i<3; i++)
			{
				aux3[i] = val%10;
				val = val/10;
			}

			TICKINT = OFF;
			Buff_Display[3] = aux3[2];
			Buff_Display[4] = aux3[1];
			Buff_Display[5] = aux3[0];
			TICKINT = ON;
			break;
	}
}
