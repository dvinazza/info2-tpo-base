/*
 * Trama.c
 *
 *  Created on: Dec 1, 2015
 *      Author: Catan
 */
#include "Aplicacion.h"

extern volatile uint8_t mensaje;

uint8_t leer_trama(void)
{
	int dato=-1;
	static uint8_t estado=ESPERA;
	static uint8_t aux=0;

	dato = PopRx();
	switch (estado)
	{
	case ESPERA:
		if(dato==10)
		{
			estado=CARGA;
		}
		break;
	case CARGA:
		if(dato!=-1)
		{
			aux=dato;
			estado=VALIDACION;
		}
		break;
	case VALIDACION:
		if(dato!=-1)
		{
			if(dato == 11)
			{
				estado=ESPERA;
				return aux;
			}
			else
				estado=ESPERA;
		}
		break;

	}
	return 0;

}


uint8_t leer_tramaQT(void)
{
	int dato=-1;
	static uint8_t aux=0;


	dato = PopRx0();
	if(dato!=-1)
	{
		aux = dato;
		return aux;
	}
		return 0;

}

void validar_entradapc(uint8_t * entrada)
{
	if(*entrada==E_STOP)
		return;
	if(*entrada==E_AD)
		return;
	if(*entrada==E_ATR)
		return;
	if(*entrada==E_IZQ)
		return;
	if(*entrada==E_DER)
		return;
	if(*entrada==E_RELEASE)
		return;
	else
		*entrada=E_RELEASE;
}

void Enviar_Trama(void)
{



	PushTx(mensaje);




}


