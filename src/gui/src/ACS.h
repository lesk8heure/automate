#ifndef _ACS_H_
#define _ACS_H_

#include "events.h"

/*
*	Classe principale contenant l'application.
*	Ne fait quasiment rien à part ouvrir la fenêtre principale
*/

class ACS : public wxApp {
	public:
		virtual bool OnInit();
};

DECLARE_APP(ACS);

#endif // _ACS_H_