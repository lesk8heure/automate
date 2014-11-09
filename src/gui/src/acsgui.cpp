/*
*	C'est le main. Pour le moment, on y touche pas. Il reste comme il est là
*	On ne le modifiera que quand on linkera les différentes parties du projet
*/





#include "acsgui.h"

IMPLEMENT_APP(AcsGUI);

bool AcsGUI::OnInit()
{
	//_T("texte") permet de formater notre chaîne de caractère en wxString, les chaînes de caractère made in wxWidgets
    MainWin *frame = new MainWin(_T("ACS"), wxPoint(50,50), wxSize(600, 400));
    
    frame->Show(true);

    SetTopWindow(frame);

    return true;
}