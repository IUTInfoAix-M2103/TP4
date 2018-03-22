#include <iostream>
#include <time.h>
#include <pthread.h>
#include "ObjetTempo.h"
#include "Chrono.h"         

void nsDigicode::Chrono::arreter (void) { actif = 0; } 

nsDigicode::Chrono::Chrono (void) { actif = 0; }

void* nsDigicode::Chrono::compter (void * p)
{ 
	double duree   = (clock_t) ( (ObjetTempo *) p)->getDelai ();
	Chrono *lec    = ( (ObjetTempo *) p)->getChrono ();
	clock_t debut  = clock ();
	double tempsEcoule = (clock () - debut) / CLOCKS_PER_SEC;
	lec->actif = 1;
	while (lec->actif && tempsEcoule<duree)
	{
		tempsEcoule = (clock () - debut) / CLOCKS_PER_SEC;
	}
	if (tempsEcoule >= duree )
	{
		 ( (ObjetTempo *) p)->finTempo ();
		lec->actif = 0;
	}
	pthread_exit (NULL);
} //compter()

void nsDigicode::Chrono::demarrer (ObjetTempo * a) 
{  
	pthread_t thread;
	while (actif) std::cout.flush ();
//	double duree = a->getDelai ();
	std::cout.flush ();
	pthread_create (&thread, NULL, compter, (void *) a);
} //demarrer()
