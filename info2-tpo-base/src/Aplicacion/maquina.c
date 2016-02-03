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

extern volatile uint8_t tecla;

extern volatile uint8_t t;
extern volatile uint8_t flagtiempo;

void maquina(void)
{
	//variables

	uint8_t obstaculo=0;
	static uint8_t entrada_pc=0;
	//desarrollo


	obstaculo = leer_trama(); // lee trama de la UART1
	//obstaculo=PopRx();


	entrada_pc = leer_tramaQT();// lee trama de la UART0

	tecla=GetKey();
	validar_tecla();// validacion de que se preciono una tecla correcta
	cargar_entradapc(&entrada_pc);


	if(tecla != NO_KEY)
		t=3;
	switch (estado_p)
	{

	case PROCESAR:

		SetPIN(RGBB,OFF);
		SetPIN(RGBG,OFF);
		SetPIN(RGBR,ON);

		if(tecla==T_STOP)
		{
			mensaje=MSJ_STOP;

		}
		if(tecla==T_AD)
		{
			estado_p=MOV_AD;
		}
		if(tecla==T_ATR)
		{
			estado_p=MOV_ATR;
		}
		if(tecla==T_IZQ)
		{
			estado_p=MOV_IZQ;
		}
		if(tecla==T_DER)
		{
			estado_p=MOV_DER;
		}
		break;
	case MOV_AD:
		mensaje=MSJ_AD;
		if(tecla==NO_KEY)
		{
			estado_p=MANTENER_MOV;
			t=3;
			flagtiempo=0;
		}
		else if(tecla!=T_AD )
		{
			estado_p=PROCESAR;
		}
		break;
	case MOV_ATR:
		mensaje=MSJ_ATR;
		if(tecla==NO_KEY)
		{
			estado_p=MANTENER_MOV;
			t=3;
			flagtiempo=0;
		}
		else if(tecla!=T_ATR )
		{
			estado_p=PROCESAR;
		}
		break;
	case MOV_IZQ:
		mensaje=MSJ_IZQ;
		if(tecla==NO_KEY)
		{
			estado_p=MANTENER_MOV;
			t=3;
			flagtiempo=0;
		}
		else if(tecla!=T_IZQ )
		{
			estado_p=PROCESAR;
		}
		break;
	case MOV_DER:
		mensaje=MSJ_DER;
		if(tecla==NO_KEY)
		{
			estado_p=MANTENER_MOV;
			t=3;
			flagtiempo=0;
			}
			else if(tecla!=T_DER )
			{
				estado_p=PROCESAR;
			}
			break;
		case MANTENER_MOV:

			SetPIN(RGBR,OFF);
			SetPIN(RGBG,OFF);
			SetPIN(RGBB,ON);
			if(tecla!=NO_KEY)
			{
				estado_p=PROCESAR;
				mensaje=MSJ_STOP;
			}
			if(flagtiempo==1)
			{
				mensaje=MSJ_STOP;

				estado_p=PROCESAR;
				flagtiempo=0;
			}
			break;

	}

}
