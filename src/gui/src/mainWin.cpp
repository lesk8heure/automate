#include "mainWin.h"


MainWin::MainWin(const wxString& title, const wxPoint& pos, const wxSize& size)
		: wxFrame((wxFrame *)NULL, wxID_ANY, title, pos, size) {

    wxInitAllImageHandlers(); 
    
        // wxMenu sont des onglets du menu du haut. On peut y ajouter des sous élements
    wxMenu *menuFile = new wxMenu;
        menuFile->Append(Id_loadRule, _T("&Charger une règle\tCtrl+C")); // lors du click sur cet élément, l'evenement d'id Id_loadRule est lance


        wxMenu *newRule = new wxMenu;
        newRule->Append(Id_createRule, _T("Créer une règle\tCTRL+N"));
        newRule->Append(Id_createColorRule, _T("Créer une règle de couleur"));
        newRule->Append(Id_createGridRule, _T("Créer une règle de grille"));
        newRule->Append(Id_createLinkRule, _T("Lier des règles"));

        menuFile->AppendSubMenu(newRule, _T("&Nouvelle règle"));
        menuFile->Append(Id_editRule, _T("&Editer une règle\tCtrl+E"));
        menuFile->Append(Id_saveRule, _T("&Sauvegarder une règle\tCtrl+S")); 

        menuFile->AppendSeparator();

        menuFile->Append(Id_settings, _T("&Préférences"));
        menuFile->Append(Id_quit, _T("&Quitter\tCtrl+Q"));

    wxMenu *menuEdit = new wxMenu;
        menuEdit->Append(Id_undo, _T("&Undo\tCtrl+X"));
        menuEdit->Append(Id_redo, _T("&Redo\tCtrl+Y")); 

    wxMenu *menuControl = new wxMenu; 
        menuControl->Append(Id_start, _T("&Démarrer\tEnter"));
        menuControl->Append(Id_break, _T("&Pause")); 
        menuControl->Append(Id_next, _T("Prochaine etape\tSpace"));
        menuControl->Append(Id_reload, _T("Recharger"));
        menuControl->Append(Id_speed, _T("&Accélerer\tUp"));
        menuControl->Append(Id_slow, _T("&Ralentir\tDown"));

    wxMenu *menuDisplay = new wxMenu; 
        menuDisplay->Append(Id_sizeUp, _T("&Agrandir\tCTRL+P"));
        menuDisplay->Append(Id_sizeDown, _T("&Rétrécir\tCTRL+M"));
        menuDisplay->Append(Id_fit, _T("&Fit")); // Je vois pas comment traduire ça ..
        menuDisplay->AppendSeparator();
        menuDisplay->AppendCheckItem(Id_displayGrid, _T("Afficher grille")); 

    wxMenu *menuHelp = new wxMenu;
        menuHelp->Append(Id_helpACS, _T("Aide ACS\tF1"));
        menuHelp->Append(Id_helpOnline, _T("Aide en ligne")); // Comme s'il y en avait une
        menuHelp->AppendSeparator();
        menuHelp->Append(Id_about, _T("A propos"));

    wxMenuBar *menuBar = new wxMenuBar; // la barre de menu tout en haut
        menuBar->Append(menuFile, _T("&Fichiers")); // le nom de chaque onglet
        menuBar->Append(menuEdit, _T("&Edition"));
        menuBar->Append(menuControl, _T("&Controles"));//le menu pour le controle
        menuBar->Append(menuDisplay, _T("&Affichage"));
        menuBar->Append(menuHelp, _T("A&ide"));

    SetMenuBar(menuBar); // on assigne notre barre de menu comme la barre de menu de la fenêtre

    MainWin::loadToolBar();
    CreateStatusBar(); // la barre tout en bas. Pas forcément utile.
    SetStatusText(_T("Bienvenue sur ACS !"));
    
}

void MainWin::onQuit(wxCommandEvent& WXUNUSED(event)) {
	Close(true); // font chier avec leurs méthodes qui commencent par des majuscules
}

void MainWin::onLoad(wxCommandEvent& WXUNUSED(event)) {
    //wxString maregle = wxFileSelector(_T("Choisis ta règle"), );
     wxFileDialog *loadW = new wxFileDialog(this, _T("Choose a file"), wxEmptyString, wxEmptyString,  _T("(*.acr)|*.acr|(*.acc)|*.acc"), wxFD_OPEN | wxFD_MULTIPLE | wxFD_FILE_MUST_EXIST);
     loadW->ShowModal(); 
}   

void MainWin::onCreate(wxCommandEvent& WXUNUSED(event)) {
    wxMessageBox(_T("Dat editeur de texte bro !!"), _T("Créateur de règle"), wxOK);
}

void MainWin::onEditrule(wxCommandEvent& WXUNUSED(event)) {
    wxMessageBox(_T("Edit Biatch"), _T("Editer la règle"), wxOK);
    //Deux choix possible, soit on edit la regle en cours
    //Soi on va chercher une règle à éditer

}

void MainWin::onSaverule(wxCommandEvent& WXUNUSED(event)) {
    wxMessageBox(_T("La règle à était sauvegarder"), _T("Sauvegarder la règle"), wxOK);
    //On recupere la source des fichiers (regle etc..) et on les sauvegarde

}

void MainWin::onSettings(wxCommandEvent& WXUNUSED(event)) {
    //wxMessageBox(_T("Vous etes dans la section de paramètres"), _T("Préférences"), wxOK);
    //Creer une nouvelle fenetres avec des options.
    wxFrame *paramW = new wxFrame(this, 1 , _T("Paramètres"), wxPoint(50,70), wxSize(600,400), wxDEFAULT_FRAME_STYLE , _T("Para")); 
    paramW->Show(true); 
}

void MainWin::onStart(wxCommandEvent& WXUNUSED(event)) {
    wxMessageBox(_T("C'est parti !"), _T("Démarrer"), wxOK); 
    //Lance la commande dans le core pour lancer le programme
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

void MainWin::onToggleGridView(wxCommandEvent& WXUNUSED(event)) {
    // a traiter
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

void MainWin::loadToolBar(){

    //La barre d'outils
    wxToolBar* toolbar = CreateToolBar(wxNO_BORDER | wxTB_HORIZONTAL, -1, _T("toolBar")); 
    //Les images
    wxBitmap imgOpen(_T("../../img/open.png"), wxBITMAP_TYPE_PNG);
    wxBitmap imgNewRule(_T("../../img/new.png"), wxBITMAP_TYPE_PNG); 
    wxBitmap imgEdit(_T("../../img/edit.png"), wxBITMAP_TYPE_PNG); 
    wxBitmap imgStart(_T("../../img/start.png"), wxBITMAP_TYPE_PNG);
    wxBitmap imgPause(_T("../../img/pause.png"), wxBITMAP_TYPE_PNG);
    wxBitmap imgHelp(_T("../../img/help.png"), wxBITMAP_TYPE_PNG); 
    wxBitmap imgAvanc(_T("../../img/avancer.png"), wxBITMAP_TYPE_PNG); 
    wxBitmap imgRet(_T("../../img/retour.png"), wxBITMAP_TYPE_PNG); 
    wxBitmap imgPref(_T("../../img/pref.png"), wxBITMAP_TYPE_PNG); 
    //Les boutons
    wxBitmapButton *b_open = new wxBitmapButton(toolbar, -1, imgOpen);
    wxBitmapButton *b_newRule = new wxBitmapButton(toolbar, -1, imgNewRule); 
    wxBitmapButton *b_edit = new wxBitmapButton(toolbar, -1, imgEdit); 
    wxBitmapButton *b_start = new wxBitmapButton(toolbar, -1, imgStart);
    wxBitmapButton *b_pause = new wxBitmapButton(toolbar, -1 , imgPause);
    wxBitmapButton *b_help = new wxBitmapButton(toolbar, -1, imgHelp); 
    wxBitmapButton *b_avanc = new wxBitmapButton(toolbar, -1, imgAvanc); 
    wxBitmapButton *b_ret = new wxBitmapButton(toolbar, -1, imgRet); 
    wxBitmapButton *b_pref = new wxBitmapButton(toolbar, -1, imgPref); 
    
    toolbar->SetMargins(3,3); 
    toolbar->AddControl(b_newRule); 
    toolbar->AddControl(b_open);
    toolbar->AddControl(b_edit);

    toolbar->AddSeparator(); 

    toolbar->AddControl(b_start);
    toolbar->AddControl(b_pause); 

    toolbar->AddSeparator(); 

    toolbar->AddControl(b_ret); 
    toolbar->AddControl(b_avanc); 

    toolbar->AddSeparator(); 

    toolbar->AddControl(b_pref); 
    toolbar->AddControl(b_help); 

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
    EVT_MENU(Id_displayGrid, MainWin::onToggleGridView)
    EVT_MENU(Id_helpACS, MainWin::onHelpACS)
    EVT_MENU(Id_helpOnline, MainWin::onHelponline)
    EVT_MENU(Id_about, MainWin::onAbout)
    EVT_TOOL(Id_helpOnline, MainWin::onHelponline)
END_EVENT_TABLE()