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
	static uint8_t aux=0,obstaculo;

	obstaculo=0;
	dato = PopRx();
	switch (estado)
	{
	case ESPERA:
		if(dato=='^')
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
	case VALIDACION:
		if(dato!=-1)
		{
			if(dato == '%')
			{
				if(aux==1)
				{
					obstaculo = 1;
					estado = ESPERA;
				}
			}
			else
				estado=ESPERA;
		}

	}
	//return obstaculo;
	return aux;
}

void Enviar_Trama(void)
{



	PushTx('^');
	PushTx(mensaje);
	PushTx('$');
	//PushTx(0x88);
	//PushTx(0x84);



}


