/*
 * Aplicacion.h
 *
 *  Created on: 14/06/2013
 *      Author: Marcelo
 */

#ifndef APLICACION_H_
#define APLICACION_H_

	#include "Display7seg.h"
	#include "FW_GPIO.h"
	#include "KitInfo2_BaseBoard.h"
	#include "Oscilador.h"
	#include "RegsLPC1769.h"
	#include "Teclado.h"
	#include "UART.h"
	#include "TIMERS.h"


	#define T0 1 // Prendo led ROJO Llevo el timpo de barrido al valor normal de 2,5 mseg
	#define T1 2 // Prendo led AZUL apago ROJO
	#define T2 3 // Prendo led VERDE apago AZUL
	#define T3 4 // Apago todos
	#define T4 5 // Prendo todos Aumento barrido a 10 mseg para mostrar el efecto en el display

	#define	RGB_RED_ON		SetPIN(RGBR,ON)
	#define	RGB_RED_OFF		SetPIN(RGBR,OFF)
	#define	RGB_BLUE_ON		SetPIN(RGBB,ON)
	#define	RGB_BLUE_OFF	SetPIN(RGBB,OFF)
	#define	RGB_GREEN_ON	SetPIN(RGBG,ON)
	#define	RGB_GREEN_OFF	SetPIN(RGBG,OFF)

	/****Estados****/
	#define 	ESPERA 			0
	#define 	MOVER			1
	#define 	PROCESAR 		0
	#define		MOV_AD			1
	#define 	MOV_ATR			2
	#define 	MOV_IZQ			3
	#define 	MOV_DER			4
	#define 	MANTENER_MOV 	5

	void InicializarKit ( void );
	void Check_tecla(void);
	void maquina(void);
	void mover (uint8_t tecla);
#endif /* APLICACION_H_ */
