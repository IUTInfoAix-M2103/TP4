#ifndef _CHRONO
#define _CHRONO

namespace nsDigicode {

	class ObjetTempo;
	
	class Chrono 
	{
		int actif;
		static void* compter (void *);
	public:
		void demarrer (ObjetTempo*);
		void arreter (void);
		Chrono (void);
	};
	
} /* ns_Digicode */

#endif /* _CHRONO */
