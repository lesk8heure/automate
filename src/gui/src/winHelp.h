#ifndef _WIN_HELP_H_
#define _WIN_HELP_H_

#include "utils.h"

/*
*	Définit la fenêtre principale de l'application. Celle qui contient la grille elle même.
*/

class WinHelp : public wxFrame {
	public:
		WinHelp(wxFrame *parent);
};

#endif // _WIN_HELP_H_