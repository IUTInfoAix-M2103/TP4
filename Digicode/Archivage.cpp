#include <time.h>
#include <fstream>
#include <iostream>
using namespace std;
#include "Archivage.h"

#define NOM_FIC "../DigicodeIUT/Archive.txt"
#define MODE std::fstream::out | std::fstream::app

void nsDigicode::Archivage::archiver (int code)  
{  
	fstream leFichier (NOM_FIC,MODE);
	time_t dateActuelle;
	time (&dateActuelle);
	leFichier << "Code : " << code << "  Date : " << ctime (&dateActuelle) << endl;
	leFichier.close ();
} //archiver()
