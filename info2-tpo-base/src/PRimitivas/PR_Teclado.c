/*
 * PR_Teclado.c
 *
 *  Created on: 1/8/2015
 *      Author: emmaotm
 */

#include <RegsLPC1769.h>
#include <Teclado.h>
//#include "Aplicacion.h"

extern volatile uint8_t	Buff_Key;


uint8_t GetKey (void)
{
	uint8_t Tecla = NO_KEY;

	Tecla = Buff_Key;			// Leo la Tecla.

	Buff_Key = NO_KEY;			// Limpio el Buffer.

	return Tecla;				// Retorno el Código de la Tecla.
}


void validar_tecla(uint8_t * tecla)
{
	if(*(tecla)== T_AD)
			return;
	if(*(tecla)== T_ATR)
			return;
	if(*(tecla)== T_DER)
			return;
	if(*(tecla)== T_IZQ)
			return;
	if(*(tecla)== T_STOP)
			return;
	if(*(tecla)== NO_KEY)
			return;
	else
		*(tecla)=NO_KEY;
}
