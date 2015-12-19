/*
===============================================================================
 Name        : main.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#include <cr_section_macros.h>
#include <NXP/crp.h>

// Variable to store CRP value in. Will be placed automatically
// by the linker when "Enable Code Read Protect" selected.
// See crp.h header for more information
__CRP const unsigned int CRP_WORD = CRP_NO_CRP ;

#include "Aplicacion.h"

//variables globales
volatile uint8_t Buff_Key;				//Buffer de teclado
volatile uint8_t Buff_Display[DIGITOS];		//Buffer de display
volatile uint8_t Eventos;
volatile uint8_t TmrRun[TIMERS];

// globales UART1
volatile uint8_t bufferTx[TOPE];
volatile uint8_t bufferRx[TOPE];
volatile uint8_t inx_out=0;
volatile uint8_t inx_in=0;
volatile uint8_t outx_out=0;
volatile uint8_t outx_in=0;
volatile uint8_t enviando=0;

// globales UART0
volatile uint8_t bufferTx0[TOPE];
volatile uint8_t bufferRx0[TOPE];
volatile uint8_t inx0_out=0;
volatile uint8_t inx0_in=0;
volatile uint8_t outx0_out=0;
volatile uint8_t outx0_in=0;
volatile uint8_t enviando0=0;




//globales aplicacion
volatile uint8_t mensaje=MSJ_STOP;
volatile uint8_t estado_p;
volatile uint8_t estado_m;


volatile uint8_t t=0;
volatile uint8_t flagtiempo=0;

/////////////////////AUXILIAR/////////////////////////
void teclado_prueba(void);
uint8_t a=0;
//////////////////////////////////////////////////////
int main(void) {
	InicializarKit();

	 while(1)
	 {


		 maquina();
		 //teclado_prueba();
		 //a=leer_trama();

	 }
	 return 0 ;
}



void teclado_prueba(void)
{
	uint8_t tecla,aux;
	tecla=GetKey();
	aux =0;
	switch (tecla)
	{
	case SW1:
		Display(1,2);
		Enviar_Trama();
		tecla=NO_KEY;
		break;

	case SW2:

		if(a==1)
			Display(15,2);
		tecla=NO_KEY;
		break;
	case SW3:
		tecla=NO_KEY;
		aux=PopRx();
		Display(aux,2);
		break;
	case SW4:
		Display(7,2);
		break;
	case SW5:
		Display(2,2);
		break;
	case SW6:
		Display(4,2);
		break;
	case SW7:
		Display(6,2);
		break;
	case SW8:
		Display(8,2);
		break;

	}
}
