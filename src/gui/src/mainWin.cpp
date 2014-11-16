#include "mainWin.h"

MainWin::MainWin(const wxString& title, const wxPoint& pos, const wxSize& size)
		: wxFrame((wxFrame *)NULL, wxID_ANY, title, pos, size) {

    // wxMenu sont des onglets du menu du haut. On peut y ajouter des sous élements
	wxMenu *menuFile = new wxMenu;
        menuFile->Append(Id_loadRule, _T("&Charger une règle")); // lors du click sur cet élément, l'evenement d'id Id_loadRule est lancé
        menuFile->Append(Id_createRule, _T("&Créer une règle"));
        menuFile->Append(Id_editRule, _T("&Editer une règle"));
        menuFile->Append(Id_saveRule, _T("&Sauvegarder une règle")); 

        menuFile->AppendSeparator();

        menuFile->Append(Id_settings, _T("&Préférences"));
        menuFile->Append(Id_quit, _T("&Quitter"));

    wxMenu *menuEdit = new wxMenu;
        menuEdit->Append(Id_undo, _T("&Undo"));
        menuEdit->Append(Id_redo, _T("&Redo")); 

    wxMenu *menuControl = new wxMenu; 
        menuControl->Append(Id_start, _T("&Démarrer"));
        menuControl->Append(Id_break, _T("&Pause")); 
        menuControl->Append(Id_next, _T("&Prochaine etape"));
        menuControl->Append(Id_reload, _T("&Recharger"));
        menuControl->Append(Id_speed, _T("&Accélerer"));
        menuControl->Append(Id_slow, _T("&Slow"));

    wxMenu *menuDisplay = new wxMenu; 
        menuDisplay->Append(Id_sizeUp, _T("&Agrandir"));
        menuDisplay->Append(Id_sizeDown, _T("&Rétrécir"));
        menuDisplay->Append(Id_fit, _T("&Fit")); // Je vois pas comment traduire ça ..
        menuDisplay->AppendSeparator();
        menuDisplay->Append(Id_displayCell, _T("&Afficher grille")); 

    wxMenu *menuHelp = new wxMenu;
        menuHelp->Append(Id_helpACS, _T("&Aide ACS"));
        menuHelp->Append(Id_helpOnline, _T("&Aide en ligne")); // Comme s'il y en avait une
        menuHelp->AppendSeparator();
        menuHelp->Append(Id_about, _T("&A propos"));

    wxMenuBar *menuBar = new wxMenuBar; // la barre de menu tout en haut
        menuBar->Append(menuFile, _T("&Fichiers")); // le nom de chaque onglet
        menuBar->Append(menuEdit, _T("&Edition"));
        menuBar->Append(menuControl, _T("&Controles"));//le menu pour le controle
        menuBar->Append(menuDisplay, _T("&Affichage"));
        menuBar->Append(menuHelp, _T("&Aide"));

    SetMenuBar(menuBar); // on assigne notre barre de menu comme la barre de menu de la fenêtre

    CreateStatusBar(); // la barre tout en bas. Pas forcément utile.
    SetStatusText(_T("Bienvenue sur ACS !"));
}

void MainWin::onQuit(wxCommandEvent& WXUNUSED(event)) {
	Close(true); // font chier avec leurs méthodes qui commencent par des majuscules
}

void MainWin::onLoad(wxCommandEvent& WXUNUSED(event)) {
    wxMessageBox(_T("Bon... Là, tu es devant un gestionnaire de fichier. Sisi..."), _T("Charger une règle"), wxOK);
}

void MainWin::onCreate(wxCommandEvent& WXUNUSED(event)) {
    wxMessageBox(_T("Dat editeur de texte bro !!"), _T("Créateur de règle"), wxOK);
}

void MainWin::onEditrule(wxCommandEvent& WXUNUSED(event)) {
    wxMessageBox(_T("Edit Biatch"), _T("Editer la règle"), wxOK);
}

void MainWin::onSaverule(wxCommandEvent& WXUNUSED(event)) {
    wxMessageBox(_T("La règle à était sauvegarder"), _T("Sauvegarder la règle"), wxOK);
}

void MainWin::onSettings(wxCommandEvent& WXUNUSED(event)) {
    wxMessageBox(_T("Vous etes dans la section de paramètres"), _T("Préférences"), wxOK);
}

void MainWin::onStart(wxCommandEvent& WXUNUSED(event)) {
    wxMessageBox(_T("C'est parti !"), _T("Démarrer"), wxOK); 
}

void MainWin::onBreak(wxCommandEvent& WXUNUSED(event)) {
    wxMessageBox(_T("GrosseBiatch !"), _T("Pause"), wxOK); 
}

void MainWin::onNext(wxCommandEvent& WXUNUSED(event)) {
    wxMessageBox(_T("C'est qui qui le suivant"), _T("Suivant"), wxOK);
}

void MainWin::onReload(wxCommandEvent& WXUNUSED(event)) {
    wxMessageBox(_T("Nous avons fait un jolie reset"), _T("Recharger"), wxOK);
}

void MainWin::onSpeed(wxCommandEvent& WXUNUSED(event)) {
    wxMessageBox(_T("PLus vite !!!"), _T("Accélerer"), wxOK); 
}

void MainWin::onSlow(wxCommandEvent& WXUNUSED(event)) {
    wxMessageBox(_T("PLus lentement !!!"), _T("Ralentir"), wxOK); 
}

void MainWin::onSizeup(wxCommandEvent& WXUNUSED(event)) {
    wxMessageBox(_T("Tu vois mieux là ?"), _T("Agrandir"), wxOK);
}

void MainWin::onSizedown(wxCommandEvent& WXUNUSED(event)) {
    wxMessageBox(_T("Spèce de lunetté"), _T("Rétrécir"), wxOK); 
}

void MainWin::onFit(wxCommandEvent& WXUNUSED(event)) {
    wxMessageBox(_T("Fit ?"), _T("Fit"), wxOK); 
}

void MainWin::onDisplaycell(wxCommandEvent& WXUNUSED(event)) {
    wxMessageBox(_T("Disparu ou pas ?"), _T("Monter la grille"), wxOK); 
}

void MainWin::onHelpACS(wxCommandEvent& WXUNUSED(event)) {
    wxMessageBox(_T("Toi aussi tu y comprends rien ? "), _T("Aide d'ACS"), wxOK); 
}

void MainWin::onHelponline(wxCommandEvent& WXUNUSED(event)) {
    wxMessageBox(_T("Google est ton ami :)"), _T("Aide en ligne"), wxOK); 
}

void MainWin::onAbout(wxCommandEvent& WXUNUSED(event)) {
    wxMessageBox(_T("Ceci est une version beta, Enjoy !"), _T("A propos"), wxOK); 
}

void MainWin::onUndo(wxCommandEvent& WXUNUSED(event)) {
    wxMessageBox(_T("Uno !!"), _T("Undo"),wxOK); 
}

void MainWin::onRedo(wxCommandEvent& WXUNUSED(event)) {
    wxMessageBox(_T("La Si Do"), _T("Redo"), wxOK); 
}

BEGIN_EVENT_TABLE(MainWin, wxFrame)
    EVT_MENU(Id_quit, MainWin::onQuit)
    EVT_MENU(Id_loadRule, MainWin::onLoad)
    EVT_MENU(Id_undo, MainWin::onUndo)
    EVT_MENU(Id_redo, MainWin::onRedo)
    EVT_MENU(Id_createRule, MainWin::onCreate)
    EVT_MENU(Id_editRule, MainWin::onEditrule)
    EVT_MENU(Id_saveRule, MainWin::onSaverule)
    EVT_MENU(Id_settings, MainWin::onSettings)
    EVT_MENU(Id_start, MainWin::onStart)
    EVT_MENU(Id_break, MainWin::onBreak)
    EVT_MENU(Id_next, MainWin::onNext)
    EVT_MENU(Id_reload, MainWin::onReload)
    EVT_MENU(Id_speed, MainWin::onSpeed)
    EVT_MENU(Id_slow, MainWin::onSlow)
    EVT_MENU(Id_sizeUp, MainWin::onSizeup)
    EVT_MENU(Id_sizeDown, MainWin::onSizedown)
    EVT_MENU(Id_fit, MainWin::onFit)
    EVT_MENU(Id_displayCell, MainWin::onDisplaycell)
    EVT_MENU(Id_helpACS, MainWin::onHelpACS)
    EVT_MENU(Id_helpOnline, MainWin::onHelponline)
    EVT_MENU(Id_about, MainWin::onAbout)
END_EVENT_TABLE()