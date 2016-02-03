/*
 * UART.h
 *
 *  Created on: Nov 2, 2015
 *      Author: Catan
 */

#ifndef UART_H_
#define UART_H_


#define 	TOPE		15

// codigos a enviar
#define		MSJ_STOP  	0x02
#define		MSJ_AD		0x03
#define		MSJ_ATR		0x04
#define		MSJ_DER		0x06
#define		MSJ_IZQ 	0x05
#define 	MSJ_OBS		0x06
#define 	MSJ_NOBS	0x07

#define		E_STOP   	49
#define		E_AD		50
#define 	E_ATR		51
#define 	E_IZQ		52
#define		E_DER		53
#define		E_RELEASE	54


#define CARGA 1
#define VALIDACION 2


//UART 1
void PushTx(uint8_t dato);
int PopTx(void);
void PushRx(uint8_t);
int PopRx(void);
void InitUART1 (void);

//UART0

void PushTx0(uint8_t dato);
int PopTx0(void);
void PushRx0(uint8_t);
int PopRx0(void);
void InitUART0 (void);

// Funciones Aplicacion
uint8_t leer_trama(void);
uint8_t leer_tramaQT(void);
void Enviar_Trama(void);


#endif /* UART_H_ */
