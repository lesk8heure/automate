#ifndef _WIN_ABOUT_H_
#define _WIN_ABOUT_H_

#include "utils.h"

/*
*	Définit la fenêtre principale de l'application. Celle qui contient la grille elle même.
*/

class WinAbout : public wxFrame {
	public:
		WinAbout(wxFrame *parent);
};

#endif // _WIN_ABOUT_H_