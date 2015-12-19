#include "Aplicacion.h"


extern volatile uint8_t Eventos;
extern volatile uint8_t TmrRun[TIMERS];


void AnalizarTimer()
{
	uint8_t i;

	for(i=0; i<TIMERS; i++)
	{
		if(TmrRun[i])
		{
			TmrRun[i]--;
			if(!TmrRun[i])
			Eventos|=((uint8_t)1<<i);
		}
	}
}

void TmrStart(uint8_t Ev,uint8_t t)
{
	if(t)
	{
		TICKINT=0;
		TmrRun[Ev]=t;
		Eventos= Eventos &(~((uint8_t)1<<Ev));
		TICKINT = 1;
	}
	else
	{
		TmrRun[Ev]=0;
		Eventos=Eventos | ((uint8_t)1<<Ev);
	}
}


void TmrClose(void)
{
	uint8_t i;
	TICKINT = 0;
	for(i=0; i<TIMERS;i++)
	{
		TmrRun[i]=0;

	}
	Eventos=0;
	TICKINT =1;
}


void TmrStop(uint8_t Ev)
{
	TICKINT = 0;
	TmrRun[Ev]=0;
	Eventos = Eventos &(~((uint8_t)1<<Ev));
	TICKINT = ON;
}
