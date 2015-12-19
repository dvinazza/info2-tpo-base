/*
 * Display7Seg.h
 *
 *  Created on: 1/8/2015
 *      Author: emmaotm
 */

#ifndef INC_DISPLAY7SEG_H_
#define INC_DISPLAY7SEG_H_

#include "RegsLPC1769.h"
#define 		DIGITOS			6

#define			DSP0			0
#define			DSP1			1
#define			DSP2			2


void InicDisplayExp3 ( void );
void BarridoDisplay7Seg ( void );
void ApagarDisplay ( void );
void Display (uint16_t val, uint8_t pos);


#endif /* INC_DISPLAY7SEG_H_ */
