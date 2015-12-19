/*
 * Teclado.h
 *
 *  Created on: 1/8/2015
 *      Author: emmaotm
 */

#ifndef INC_TECLADO_H_
#define INC_TECLADO_H_



#define		SW1			2
#define		SW2			6
#define		SW3			4
#define		SW4			0
#define		SW5			1
#define		SW6			5
#define		SW7			7
#define		SW8			3


#define		SW9			9
#define		SW10		10
#define		SW11		11
#define		SW12		12

#define 	T_AD		SW6
#define 	T_STOP		SW2
#define 	T_ATR		SW7
#define 	T_IZQ		SW1
#define 	T_DER		SW5
#define		NO_KEY		255

#define		REBOTES		7


void InicializarExp3 (void);
void InicTecladoExp3 ( void );
void InicTeclado4x1 (void);

uint8_t TecladoHW ( void );
void TecladoSW ( void );
uint8_t GetKey ( void );
void validar_tecla(uint8_t * tecla);


#endif /* INC_TECLADO_H_ */
