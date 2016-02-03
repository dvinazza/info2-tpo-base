/*
 * DR_Teclado.c
 *
 *  Created on: 1/8/2015
 *      Author: emmaotm
 */

#include "Aplicacion.h"

extern volatile uint8_t Buff_Key;


uint8_t TecladoHW (void)
{
	uint8_t Codigo = NO_KEY;

	SetPIN(FILA0, ON); SetPIN(FILA1, OFF); SetPIN(FILA2, OFF); SetPIN(FILA3, OFF);
	SetPIN(FILA0, ON); SetPIN(FILA1, OFF); SetPIN(FILA2, OFF); SetPIN(FILA3, OFF);
	SetPIN(FILA0, ON); SetPIN(FILA1, OFF); SetPIN(FILA2, OFF); SetPIN(FILA3, OFF);

	if ( GetPIN(COLUMNA0, ACTIVO_ALTO) )
		return SW4;

	if ( GetPIN(COLUMNA1, ACTIVO_ALTO) )
		return SW5;


	SetPIN(FILA0, OFF); SetPIN(FILA1, ON); SetPIN(FILA2, OFF); SetPIN(FILA3, OFF);
	SetPIN(FILA0, OFF); SetPIN(FILA1, ON); SetPIN(FILA2, OFF); SetPIN(FILA3, OFF);
	SetPIN(FILA0, OFF); SetPIN(FILA1, ON); SetPIN(FILA2, OFF); SetPIN(FILA3, OFF);

	if ( GetPIN(COLUMNA0, ACTIVO_ALTO) )
		return SW1;

	if ( GetPIN(COLUMNA1, ACTIVO_ALTO) )
		return SW8;


	SetPIN(FILA0, OFF); SetPIN(FILA1, OFF); SetPIN(FILA2, ON); SetPIN(FILA3, OFF);
	SetPIN(FILA0, OFF); SetPIN(FILA1, OFF); SetPIN(FILA2, ON); SetPIN(FILA3, OFF);
	SetPIN(FILA0, OFF); SetPIN(FILA1, OFF); SetPIN(FILA2, ON); SetPIN(FILA3, OFF);

	if ( GetPIN(COLUMNA0, ACTIVO_ALTO) )
		return SW3;

	if ( GetPIN(COLUMNA1, ACTIVO_ALTO) )
		return SW6;

	SetPIN(FILA0, OFF); SetPIN(FILA1, OFF); SetPIN(FILA2, OFF); SetPIN(FILA3, ON);
	SetPIN(FILA0, OFF); SetPIN(FILA1, OFF); SetPIN(FILA2, OFF); SetPIN(FILA3, ON);
	SetPIN(FILA0, OFF); SetPIN(FILA1, OFF); SetPIN(FILA2, OFF); SetPIN(FILA3, ON);

	if ( GetPIN(COLUMNA0, ACTIVO_ALTO) )
		return SW2;

	if ( GetPIN(COLUMNA1, ACTIVO_ALTO) )
		return SW7;


	if ( GetPIN(KEY3, ACTIVO_BAJO) )
	if ( GetPIN(KEY3, ACTIVO_BAJO) )
	if ( GetPIN(KEY3, ACTIVO_BAJO) )
		return SW9;


	if ( GetPIN(KEY2, ACTIVO_BAJO) )
	if ( GetPIN(KEY2, ACTIVO_BAJO) )
	if ( GetPIN(KEY2, ACTIVO_BAJO) )
		return SW10;


	if ( GetPIN(KEY1, ACTIVO_BAJO) )
	if ( GetPIN(KEY1, ACTIVO_BAJO) )
	if ( GetPIN(KEY1, ACTIVO_BAJO) )
		return SW11;


	if ( GetPIN(KEY0, ACTIVO_BAJO) )
	if ( GetPIN(KEY0, ACTIVO_BAJO) )
	if ( GetPIN(KEY0, ACTIVO_BAJO) )
		return SW12;


	return Codigo;
}

void TecladoSW (void)
{
	uint8_t CodigoActual;

	static uint8_t CodigoAnterior = NO_KEY;

	static uint8_t EstadosEstables;

	CodigoActual = TecladoHW ( );



	if ( EstadosEstables == 0 )
	{
		EstadosEstables = 1;

		CodigoAnterior = CodigoActual;

		return;
	}

	if ( CodigoActual != CodigoAnterior )
	{
		EstadosEstables = 0;

		CodigoAnterior = NO_KEY;

		return;
	}

	if ( EstadosEstables == REBOTES )
	{
		Buff_Key = CodigoActual;

		EstadosEstables = REBOTES + 1;

		return;
	}

	if ( EstadosEstables == REBOTES + 1 )
	{
		Buff_Key = CodigoActual;
		return;
	}
	EstadosEstables++;

	return;
}
