#include "Aplicacion.h"
extern volatile uint8_t t;
extern volatile uint8_t flagtiempo;

extern volatile uint8_t estado_p;
extern volatile uint8_t mensaje;
void SysTick_Handler (void)
{

	static uint16_t decimas=400,medioseg=100;
	TecladoSW();
	BarridoDisplay7Seg();

	if(decimas)
		{
			decimas--;
			if(!decimas)
			{
				decimas = 400;

				if(estado_p == MANTENER_MOV)
				{
					t--;
					if(!t) flagtiempo=1;//mensaje=MSJ_STOP;
				}
				//AnalizarTimer();
			}
		}
	if(medioseg)
	{
		medioseg--;
		if(!medioseg)
		{
			medioseg=100;
			Enviar_Trama();

		}
	}
}
