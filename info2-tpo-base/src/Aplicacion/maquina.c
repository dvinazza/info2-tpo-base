/*
 * maquina.c
 *
 *  Created on: Nov 25, 2015
 *      Author: Catan
 */
#include "Aplicacion.h"
extern volatile uint8_t estado_p;
extern volatile uint8_t estado_m;
extern volatile uint8_t mensaje;

extern volatile uint8_t t;
extern volatile uint8_t flagtiempo;

void maquina(void)
{
	//variables
	static uint8_t tecla=NO_KEY;
	static uint8_t obstaculo=0;
	//desarrollo

	tecla=GetKey();
	validar_tecla(&tecla);
	obstaculo=leer_trama();
	switch (estado_p)
	{
	case ESPERA:
		Display(obstaculo,2);
		if(tecla != NO_KEY)
		{
			estado_p= MOVER;
		}
		break;
	case MOVER:
			mover(tecla);
		break;
	}
}


void mover (uint8_t tecla)
{
	//variables
	static uint8_t obstaculo=0;
	//desarrollo

	obstaculo = leer_trama();
	if(obstaculo==MSJ_OBS)
	{
		estado_p=ESPERA;
		estado_m=PROCESAR;
	}

	switch(estado_m)
	{
	case PROCESAR:

		if(tecla==T_STOP)
		{
			mensaje=MSJ_STOP;
			estado_p=ESPERA;

		}
		if(tecla==T_AD)
		{
			estado_m=MOV_AD;
		}
		if(tecla==T_ATR)
		{
			estado_m=MOV_ATR;
		}
		if(tecla==T_IZQ)
		{
			estado_m=MOV_IZQ;
		}
		if(tecla==T_DER)
		{
			estado_m=MOV_DER;

		}
		break;
	case MOV_AD:
		mensaje=MSJ_AD;
		if(tecla==NO_KEY)
		{
			estado_m=MANTENER_MOV;
			t=3;
			//TmrStart(1,3);
		}
		else if(tecla!=T_AD)
		{
			estado_m=PROCESAR;
		}
		break;
	case MOV_ATR:
		mensaje=MSJ_ATR;
		if(tecla==NO_KEY)
		{
			estado_m=MANTENER_MOV;
			t=3;
			//TmrStart(1,3);
		}
		else if(tecla!=T_ATR)
		{
			estado_m=PROCESAR;
		}
		break;
	case MOV_IZQ:
		mensaje=MSJ_IZQ;
		if(tecla==NO_KEY)
		{
			estado_m=MANTENER_MOV;
			t=3;
			//TmrStart(1,3);
		}
		else if(tecla!=T_IZQ)
		{
			estado_m=PROCESAR;
		}
		break;
	case MOV_DER:

		mensaje=MSJ_DER;
		if(tecla==NO_KEY)
		{
			estado_m=MANTENER_MOV;
			t=3;
			//TmrStart(1,3);
		}
		else if(tecla!=T_DER)
		{
			estado_m=PROCESAR;
		}
		break;
	case MANTENER_MOV:
		Display(obstaculo,2);

		if(tecla != NO_KEY)
		{
			estado_m=PROCESAR;
		}
		if(flagtiempo==1)
		{
			mensaje=MSJ_STOP;
			estado_m=PROCESAR;
			estado_p=ESPERA;
			flagtiempo=0;
		}
		break;



	}
}
