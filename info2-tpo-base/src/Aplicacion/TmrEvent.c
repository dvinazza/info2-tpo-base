/*
 * TmrEvent.c
 *
 *  Created on: Nov 30, 2015
 *      Author: Catan
 */
#include "Aplicacion.h"

extern volatile uint8_t Eventos;
extern volatile uint8_t TmrRun[TIMERS];
extern volatile uint8_t estado_p;
extern volatile uint8_t estado_m;
extern volatile uint8_t mensaje;

void TmrEvent(void)
{
	uint8_t j;

	for(j=0x01; j; j<<=1)
		switch (Eventos & j)
		{
		case 0x01:
			mensaje=MSJ_STOP;
			estado_m=PROCESAR;
			estado_p=ESPERA;
			Eventos &= ~j;
			break;
		}
}


