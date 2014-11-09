#ifndef _ACSGUI_H_
#define _ACSGUI_H_


#include "mainWin.h"

// AcsGUI hérite de wxApp qui est la classe utilisée par wxWidgets pour représenter l'application en elle même

class AcsGUI : public wxApp {
    public:
        virtual bool OnInit(); // OnInit est appelé à l'ouverture de l'application. C'est dedans qu'on va tout charger
};


DECLARE_APP(AcsGUI); // signifie juste que c'est AcsGUI qui est l'application à lancer (spour ça qu'il n'y a pas de main nul part. C'est wxWidget qui s'occupe de ça)


#endif // _ACSGUI_H_