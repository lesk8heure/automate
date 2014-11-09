#include "mainWin.h"

MainWin::MainWin(const wxString& title, const wxPoint& pos, const wxSize& size)
		: wxFrame((wxFrame *)NULL, wxID_ANY, title, pos, size) {

    // wxMenu sont des onglets du menu du haut. On peut y ajouter des sous élements
	wxMenu *menuFile = new wxMenu;
        menuFile->Append(Id_loadRule, _T("&Charger une règle")); // lors du click sur cet élément, l'evenement d'id Id_loadRule est lancé
        menuFile->Append(Id_createRule, _T("Créer u&ne règle"));

        menuFile->AppendSeparator();

        menuFile->Append(Id_about, _T("&À propos..."));

        menuFile->AppendSeparator();

        menuFile->Append(Id_quit, _T("&Quitter"));

    wxMenu *menuEdit = new wxMenu;
        menuEdit->Append(Id_createRule, _T("&Modifier la règle"));


    wxMenuBar *menuBar = new wxMenuBar; // la barre de menu tout en haut
        menuBar->Append(menuFile, _T("&Fichiers")); // le nom de chaque onglet
        menuBar->Append(menuEdit, _T("&Edition"));

    SetMenuBar(menuBar); // on assigne notre barre de menu comme la barre de menu de la fenêtre

    CreateStatusBar(); // la barre tout en bas. Pas forcément utile.
    SetStatusText(_T("Bienvenue sur ACS !"));
}

void MainWin::onQuit(wxCommandEvent& WXUNUSED(event)) {
	Close(true); // font chier avec leurs méthodes qui commencent par des majuscules
}

void MainWin::onAbout(wxCommandEvent& WXUNUSED(event)) {
	wxMessageBox(_T("ACS est un logiciel permettant de faire fonctionner des automates cellulaires à signaux"), _T("À propos d'ACS"), wxOK | wxICON_INFORMATION);
}

void MainWin::onLoad(wxCommandEvent& WXUNUSED(event)) {
    wxMessageBox(_T("Bon... Là, tu es devant un gestionnaire de fichier. Sisi..."), _T("Charger une règle"), wxOK);
}

void MainWin::onCreate(wxCommandEvent& WXUNUSED(event)) {
    wxMessageBox(_T("Dat editeur de texte bro !!"), _T("Editeur de règle"), wxOK);
}

BEGIN_EVENT_TABLE(MainWin, wxFrame)
    EVT_MENU(Id_quit,  MainWin::onQuit)
    EVT_MENU(Id_about, MainWin::onAbout)
    EVT_MENU(Id_loadRule, MainWin::onLoad)
    EVT_MENU(Id_createRule, MainWin::onCreate)
END_EVENT_TABLE()