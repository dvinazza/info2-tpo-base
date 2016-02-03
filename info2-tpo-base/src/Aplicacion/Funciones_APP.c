/*
 * Funciones_APP.c
 *
 *  Created on: Dec 22, 2015
 *      Author: Catan
 */
#include "Aplicacion.h"

extern volatile uint8_t tecla;


void cargar_entradapc(uint8_t * entrada_pc)
{
	if(*entrada_pc == '1')
		tecla=T_STOP;
	if(*entrada_pc== '2')
		tecla=T_AD;
	if(*entrada_pc == '3')
		tecla=T_ATR;
	if(*entrada_pc== '4')
		tecla=T_IZQ;
	if(*entrada_pc == '5')
		tecla=T_DER;
	if(*entrada_pc== '6')
		tecla=NO_KEY;
}

