/*
 * KitInic.c
 */

#include "Aplicacion.h"

//-----------------------------------------------------------------------------
// Configuración del SysTick para 10ms
//-----------------------------------------------------------------------------
void InicSysTick(void){ //si divido x 4, interrumpe cada 2,5ms
		STRELOAD  = ( STCALIB / 4 ) - 1 ;   //N=1 para 10ms
		STCURR = 0;


		TICKINT = 1;
		CLKSOURCE = 1;
		ENABLE = 1;
		return;
}

//-----------------------------------------------------------------------------
// Inicialización general del Kit de acuerdo al uso que se le dará.
//-----------------------------------------------------------------------------
void InicializarKit ( void )
{
	InicPLL();
	Inicializar_Relay();
	Inicializar_RGB();

// ESCRIBIR CODIGO DE OTRAS INICIALIZACIONES A PARTIR DE AQUI   <<<-----------------------
	InicSysTick();
	InicializarLEDS ( );
	InicTeclado4x1 ( );
	InicLedStick ( );
	InicEntradaCaptura ( );
	InitUART1 ();
	InicializarExp3 ();
}


void InicializarLEDS (void)		// Están Ordenados por Puerto y Pin ( Ascendente ).
{								// No se Podía utilizar las Funciones SetPINSEL, SetDIR, etc.
	// LED 6 ====> P0.19
	PINSEL1 = PINSEL1 & (~(3<<6));
	FIO0DIR = FIO0DIR | (1<<19);

	// LED 5 ====> P1.20
	PINSEL3 = PINSEL3 & (~(3<<28));
	FIO1DIR = FIO1DIR | (1<<20);

	// LED 4 ====> P1.23
	PINSEL3 = PINSEL3 & (~(3<<14));
	FIO1DIR = FIO1DIR | (1<<23);

	// LED 8 ====> P1.25
	PINSEL3 = PINSEL3 & (~(3<<18));
	FIO1DIR = FIO1DIR | (1<<25);

	// LED 2 ====> P1.29
	PINSEL3 = PINSEL3 & (~(3<<26));
	FIO1DIR = FIO1DIR | (1<<29);

	// LED 1 ====> P2.7
	PINSEL4 = PINSEL4 & (~(3<<14));
	FIO2DIR = FIO2DIR | (1<<7);

	// LED 7 ====> P3.26
	PINSEL7 = PINSEL7 & (~(3<<20));
	FIO3DIR = FIO3DIR | (1<<26);

	// LED 3 ====> P4.28
	PINSEL9 = PINSEL9 & (~(3<<26));
	FIO4DIR = FIO4DIR | (1<<28);
}

//******* Manera Correcta de Hacerlo. *******
//void InicializarLEDS (void)
//{
//	SetPINSEL(LED1, PINSEL_GPIO);
//	SetDIR (LED1, SALIDA);
//
//	SetPINSEL (LED2, PINSEL_GPIO);
//	SetDIR (LED2, SALIDA);
//
//	SetPINSEL (LED3, PINSEL_GPIO);
//	SetDIR (LED3, SALIDA);
//
//	SetPINSEL (LED4, PINSEL_GPIO);
//	SetDIR (LED4, SALIDA);
//
//	SetPINSEL (LED5, PINSEL_GPIO);
//	SetDIR (LED5, SALIDA);
//
//	SetPINSEL (LED6, PINSEL_GPIO);
//	SetDIR (LED6, SALIDA);
//
//	SetPINSEL (LED7, PINSEL_GPIO);
//	SetDIR (LED7, SALIDA);
//
//	SetPINSEL (LED8, PINSEL_GPIO);
//	SetDIR (LED8, SALIDA);
//}


//****************************************************************
//******* Inicialización del Teclado 4x1 de la Placa Base. *******
//****************************************************************
void InicTeclado4x1 (void)
{
	SetPINSEL (KEY0, PINSEL_GPIO);
	SetPINSEL (KEY1, PINSEL_GPIO);
	SetPINSEL (KEY2, PINSEL_GPIO);
	SetPINSEL (KEY3, PINSEL_GPIO);

	SetDIR (KEY0, ENTRADA);
	SetDIR (KEY1, ENTRADA);
	SetDIR (KEY2, ENTRADA);
	SetDIR (KEY3, ENTRADA);

	SetPINMODE (KEY0, PINMODE_PULLUP);
	SetPINMODE (KEY1, PINMODE_PULLUP);
	SetPINMODE (KEY2, PINMODE_PULLUP);
	SetPINMODE (KEY3, PINMODE_PULLUP);
}

// Inicializo el Pulsador como Evento de Captura.
void InicEntradaCaptura (void)
{
	SetPINSEL (KEYCAPTURE, PINSEL_FUNC3);
}

void InicLedStick (void)
{
	SetPINSEL (LEDSTICK, PINSEL_GPIO);
	SetDIR (LEDSTICK, SALIDA);
}

/*void Inicializar( void )
{
	InitPLL ( );

	InicializarSysTick ( );
	InicializarTimer0 ( );
	InicializarExp3 ( );

}*/


