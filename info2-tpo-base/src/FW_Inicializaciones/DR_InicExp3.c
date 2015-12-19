/*
 * DR_InicExp3.c
 *
 *  Created on: 1/8/2015
 *      Author: emmaotm
 */

#include "Aplicacion.h"


//***************************************************************************************************
// ACÁ VAN LAS INICIALIZACIONES ASOCIADAS A LOS DISPLAYS Y TECLADO DE LA EXPANSIÓN 3.
//***************************************************************************************************

void InicDisplayExp3 (void)
{
	SetPINSEL (BCD_A, PINSEL_GPIO);
	SetPINSEL (BCD_B, PINSEL_GPIO);
	SetPINSEL (BCD_C, PINSEL_GPIO);
	SetPINSEL (BCD_D, PINSEL_GPIO);
	SetPINSEL (seg_dp, PINSEL_GPIO);

	SetPINSEL (CLK, PINSEL_GPIO);
	SetPINSEL (RST, PINSEL_GPIO);

	SetDIR (BCD_A, SALIDA);
	SetDIR (BCD_B, SALIDA);
	SetDIR (BCD_C, SALIDA);
	SetDIR (BCD_D, SALIDA);
	SetDIR (seg_dp, SALIDA);

	SetDIR (CLK, SALIDA);
	SetDIR (RST, SALIDA);
}

void InicTecladoExp3 (void)
{
	SetPINSEL (FILA0, PINSEL_GPIO);
	SetPINSEL (FILA1, PINSEL_GPIO);
	SetPINSEL (FILA2, PINSEL_GPIO);
	SetPINSEL (FILA3, PINSEL_GPIO);

	SetPINSEL (COLUMNA0, PINSEL_GPIO);
	SetPINSEL (COLUMNA1, PINSEL_GPIO);

	SetDIR (FILA0, SALIDA);
	SetDIR (FILA1, SALIDA);
	SetDIR (FILA2, SALIDA);
	SetDIR (FILA3, SALIDA);

	SetDIR (COLUMNA0, ENTRADA);
	SetDIR (COLUMNA1, ENTRADA);

	SetPINMODE (COLUMNA0, PINMODE_PULLDOWN);
	SetPINMODE (COLUMNA1, PINMODE_PULLDOWN);
}

void InicializarExp3 (void)
{
	InicDisplayExp3 ( );
	InicTecladoExp3 ( );
}
