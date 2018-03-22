#include <iostream>
#include <iomanip>
#include "InterfaceDeSaisie.h"                  
#include "Chrono.h"
using namespace std;

void nsDigicode::InterfaceDeSaisie::statut (string s)
{
    cout << endl     << "VERT"  << setw (4) // << leVoyantVert.getStatut ()
         << setw (7) << "ROUGE" << setw (4) // << leVoyantRouge.getStatut ()
	     << setw (24) << s << flush;
} //statut
