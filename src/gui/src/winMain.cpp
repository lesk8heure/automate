#include "winMain.h"

WinMain::WinMain(wxString const& title)
				: wxFrame((wxFrame*)NULL, wxID_ANY, title, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE) {
	wxInitAllImageHandlers();
	// on charge les menus
	loadMenuBar();
	// la barre d'outils
	loadToolBar();
	onDisplayGrid(); 
	CreateStatusBar();
	SetStatusText(_T("Bienvenue sur ACS !")); // pas forcément utile pour le moment, mais le deviendra

	Center();
	Maximize();
}

void WinMain::updateGrid() {
	/* à faire */
}

void WinMain::quit() {
	/* gérer les cas où il faut sauvegarder du contenu non sauvegardé */
	Close();
}

bool WinMain::loadRule() {
	//wxString plop = selectFile(); 
	//if(plop = _T("")) return false; 
	editFile(selectFile());	
	return true;
}

void WinMain::saveCurrentConfig() {
	/* va demander un nom de fichier à l'utilisateur puis sauvegarder la configuration actuelle de la grille */
}

void WinMain::openPreferences() {
	//Creer une nouvelle fenetres avec des options.
    wxFrame *paramW = new wxFrame(this, 1 , _T("Paramètres"), wxPoint(50,70), wxSize(600,400)); //Créer une nouvelle fenetre
    wxToolBar* toolbarParam = paramW->CreateToolBar(wxTB_VERTICAL | wxNO_BORDER);//

    wxBitmap imgGeneral(_T("img/general.png"), wxBITMAP_TYPE_PNG); 
    wxBitmapButton *b_general = new wxBitmapButton(toolbarParam, -1, imgGeneral); 

    //toolbarParam->SetMargins(3,3); 
    toolbarParam->AddControl(b_general); 

    paramW->Show(true); 
}

void WinMain::editFile(wxString const& filepath) {
	/* affiche l'editeur de fichier */
	wxFrame* editFrame = new wxFrame(this, wxID_ANY, _T("Edition"), wxPoint(50,70), wxSize(800,600)); 
	wxPanel* editPanelDos = new wxPanel(editFrame, wxID_ANY, wxPoint(0,0), wxSize(100,600), wxMAXIMIZE_BOX);
	//wxPanel* editPanelText = new wxPanel(editFrame, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxMAXIMIZE_BOX); 
	wxTextCtrl* editText = new wxTextCtrl(editFrame, wxID_ANY, _T("Coucou"), wxPoint(20,0), wxSize(700,600), wxTE_MULTILINE | 
		wxHSCROLL | wxTE_LEFT);
	//editSBS->Add(label,0,wxLEFT|wxRIGHT|wxTOP,5); 
	/*wxBoxSizer* mainsizer = new wxBoxSizer(wxHORIZONTAL); 
	wxStaticBoxSizer* leftvsizer = new wxStaticBoxSizer(wxVERTICAL, this, _T("Choix du fichier")); 
	wxStaticText* label = new wxStaticText(editation, wxID_ANY, _T("Fichiers des règles"));
	leftvsizer->Add(label, 0, wxLEFT | wxRIGHT | wxTOP , 5); 
	wxTextCtrl* editRuleText = new wxTextCtrl(editation, wxID_ANY, _T(""));
	leftvsizer->Add(editRuleText,0,wxLEFT|wxRIGHT|wxBOTTOM,5); */
	editFrame->Show(true); 
}

wxString WinMain::saveAs(wxString const& format, wxString const& root, wxString const& filename) {
	wxFileDialog saveDialog(this, _T("Sauvegarder"), root, filename, format, wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
	saveDialog.ShowModal();	
	return saveDialog.GetFilename();
}

void WinMain::selectFiles(wxArrayString & str, wxString const& format, wxString const& root) {
	wxFileDialog dialog(this, _T("Choix de fichiers"), root, _T(""), format, wxFD_OPEN | wxFD_FILE_MUST_EXIST | wxFD_MULTIPLE);
	dialog.ShowModal();
	dialog.GetFilenames(str);
}

wxString WinMain::selectFile(wxString const& format, wxString const& root) {
	wxFileDialog dialog(this, _T("Choix d'un fichier"), root, _T(""), format, wxFD_OPEN | wxFD_FILE_MUST_EXIST);
	dialog.ShowModal();
	return dialog.GetFilename();
}

wxColor WinMain::pickColor() {
	wxColourDialog color(this); // **tain de notation à l'anglaise
	color.SetTitle(_T("Choix d'une couleur"));
	color.ShowModal();
	return color.GetColourData().GetColour();
}

void WinMain::togglePlay() {
	/* déactive les menus et bouton de play lorsque pause et inversement */
	/* à faire */
	play_ = !play_;
}
void WinMain::nextStep() {
	/* à faire */
}

void WinMain::onDisplayGrid() { 
	wxColour boum(255,0,0);
	wxBrush* redBrush = new wxBrush(boum); 
}

/**************************************************************************/
/************************ EVENTS *****************************************/
/************************************************************************/

void WinMain::onQuit(wxCommandEvent &  WXUNUSED(event)) {
	quit();
}

void WinMain::onCreateRule(wxCommandEvent & WXUNUSED(event)) {
	wxMessageBox(_T("Nouvelle règle crée"), _T("Règle Crée Biatch"));
}

void WinMain::onLoadRule(wxCommandEvent & WXUNUSED(event)) {
	if(loadRule()) {
		wxMessageBox(_T("Le chargement s'est déroulé sans encombre"), _T("Chargement réussi"));
	}
	else {		
		wxMessageBox(_T("Le chargement n'a pas pu se faire."), _T("Chargement non réussi"));
	}
}

void WinMain::onEditRule(wxCommandEvent & WXUNUSED(event)) {
	//wxMessageBox(_T("Edition d'une règle"), _T("Edition"));
	loadRule(); 
}

void WinMain::onSaveRule(wxCommandEvent & WXUNUSED(event)) {
	wxMessageBox(_T("Contenu sauvegardé"), _T("Sauvegarde"));
}

void WinMain::onSettings(wxCommandEvent & WXUNUSED(event)) {
	openPreferences();
}

void WinMain::onPlay(wxCommandEvent & WXUNUSED(event)) {
	togglePlay(); // on part du principe que le toggle bloque bien les différentes options
}

void WinMain::onPause(wxCommandEvent & WXUNUSED(event)) {
	togglePlay();
}

void WinMain::onStep(wxCommandEvent & WXUNUSED(event)) {
	nextStep();
}

void WinMain::onReload(wxCommandEvent & WXUNUSED(event)) {
	/* à faire */
}

void WinMain::onMoreSpeed(wxCommandEvent & WXUNUSED(event)) {
	/* à faire */
}

void WinMain::onLessSpeed(wxCommandEvent & WXUNUSED(event)) {
	/* à faire */
}

void WinMain::onZoomIn(wxCommandEvent & WXUNUSED(event)) {
	/* à faire */
}

void WinMain::onZoomOut(wxCommandEvent & WXUNUSED(event)) {
	/* à faire */
}

void WinMain::onZoomFit(wxCommandEvent & WXUNUSED(event)) {
	/* à faire */
}

void WinMain::onToggleGridDisplay(wxCommandEvent & WXUNUSED(event)) {
	/* à faire */
}

void WinMain::onUndo(wxCommandEvent & WXUNUSED(event)) {
	/* à faire */
}

void WinMain::onRedo(wxCommandEvent & WXUNUSED(event)) {
	/* à faire */
}

void WinMain::onAbout(wxCommandEvent & WXUNUSED(event)) {
	wxFrame *about = new WinAbout(this);
	about->Show(true);
}

void WinMain::onHelpOnline(wxCommandEvent & WXUNUSED(event)) {
	wxFrame *helpOnline = new WinHelpOnline(this);
	helpOnline->Show(true);
}

void WinMain::onHelp(wxCommandEvent & WXUNUSED(event)) {
	wxFrame *help = new WinHelp(this);
	help->Show(true);
}

/**************************************************************************/
/************************ PROTECTED **************************************/
/************************************************************************/


void WinMain::loadMenuBar() {
	// création des menus
	wxMenu* menuFile = new wxMenu;
		menuFile->Append(evt_loadRule, _T("&Charger une règle\tCTRL+O"));
		menuFile->Append(evt_createRule, _T("&Nouvelle règle\tCTRL+N"));
		menuFile->Append(evt_editRule, _T("&Editer une règle\tCTRL+E"));

		menuFile->AppendSeparator();
		menuFile->Append(evt_settings, _T("&Préférences"));

		menuFile->AppendSeparator();
		menuFile->Append(evt_quit, _T("&Quitter\tCTRL+Q"));

	wxMenu* menuEdit = new wxMenu;
		menuEdit->Append(evt_undo, _T("&Annuler action\tCTRL+Z"));
		menuEdit->Append(evt_redo, _T("&Refaire action\tCTRL+Y"));

	wxMenu* menuCtrl = new wxMenu;
		menuCtrl->Append(evt_togglePlay, _T("&Démarrer\tEnter"));
		menuCtrl->Append(evt_togglePlay, _T("Mettre en &pause\tEnter"));
		menuCtrl->Append(evt_step, _T("Prochaine &itération\tSpace"));

		menuCtrl->AppendSeparator();
		menuCtrl->Append(evt_reload, _T("&Recharger"));

		menuCtrl->AppendSeparator();
		menuCtrl->Append(evt_moreSpeed, _T("&Accélérer\tRight"));
		menuCtrl->Append(evt_lessSpeed, _T("Ralentir\tLeft"));

	wxMenu* menuDisplay = new wxMenu;
		menuDisplay->Append(evt_zoomIn, _T("Zoomer\tUp"));
		menuDisplay->Append(evt_zoomOut, _T("Dézoomer\tDown"));
		menuDisplay->Append(evt_zoomFit, _T("Adapter\t")); // traduction pour fit ?

		menuDisplay->AppendSeparator();
		menuDisplay->AppendCheckItem(evt_toggleGridDisplay, _T("Afficher la grille"));

	wxMenu* menuHelp = new wxMenu;
		menuHelp->Append(evt_help, _T("Aide\tF1"));
		menuHelp->Append(evt_helpOnline, _T("Aide en ligne"));

		menuHelp->AppendSeparator();
		menuHelp->Append(evt_about, _T("À propos d'ACS"));

	wxMenuBar* menuBar = new wxMenuBar;
		menuBar->Append(menuFile, _T("&Fichiers"));
		menuBar->Append(menuEdit, _T("&Edition"));
		menuBar->Append(menuCtrl, _T("&Contrôles"));
		menuBar->Append(menuDisplay, _T("&Affichage"));
		menuBar->Append(menuHelp, _T("A&ide"));

	SetMenuBar(menuBar);
}

void WinMain::loadToolBar() {
	// déclaration et chargement des images :
	wxBitmap bmNew(_T("img/new.png"), wxBITMAP_TYPE_PNG);
	wxBitmap bmEdit(_T("img/edit.png"), wxBITMAP_TYPE_PNG);
	wxBitmap bmSave(_T("img/save.png"), wxBITMAP_TYPE_PNG); 

	wxBitmap bmPlay(_T("img/play.png"), wxBITMAP_TYPE_PNG);
	wxBitmap bmPause(_T("img/pause.png"), wxBITMAP_TYPE_PNG);
	wxBitmap bmStep(_T("img/step.png"), wxBITMAP_TYPE_PNG);

	wxBitmap bmZoomIn(_T("img/zoomIn.png"), wxBITMAP_TYPE_PNG);
	wxBitmap bmZoomOut(_T("img/zoomOut.png"), wxBITMAP_TYPE_PNG);
	wxBitmap bmFit(_T("img/fit.png"), wxBITMAP_TYPE_PNG);


	wxToolBar* toolbar = CreateToolBar();
		// on crée les images
		wxBitmapButton* bbNew = new wxBitmapButton(toolbar, evt_createRule, bmNew);
		wxBitmapButton* bbEdit = new wxBitmapButton(toolbar, evt_editRule, bmEdit);
		wxBitmapButton* bbSave = new wxBitmapButton(toolbar, evt_saveRule, bmSave); 
		wxBitmapButton* bbPlay = new wxBitmapButton(toolbar, evt_togglePlay, bmPlay);
		wxBitmapButton* bbPause = new wxBitmapButton(toolbar, evt_togglePlay, bmPause);
		wxBitmapButton* bbStep = new wxBitmapButton(toolbar, evt_step, bmStep);
		wxBitmapButton* bbZoomIn = new wxBitmapButton(toolbar, evt_zoomIn, bmZoomIn);
		wxBitmapButton* bbZoomOut = new wxBitmapButton(toolbar, evt_zoomOut, bmZoomOut);
		wxBitmapButton* bbFit = new wxBitmapButton(toolbar, evt_zoomFit, bmFit);

		// on les ajoute à la toolbar
		toolbar->AddControl(bbNew);
		toolbar->AddControl(bbEdit);
		toolbar->AddControl(bbSave); 

		toolbar->AddSeparator();
		toolbar->AddControl(bbPlay);
		toolbar->AddControl(bbPause);
		toolbar->AddControl(bbStep);

		toolbar->AddSeparator();
		toolbar->AddControl(bbZoomIn);
		toolbar->AddControl(bbZoomOut);
		toolbar->AddControl(bbFit);
}

/**************************************************************************/
/************************ EVENT TABLE ************************************/
/************************************************************************/


BEGIN_EVENT_TABLE(WinMain, wxFrame)
    /*Les événements du menu*/
    EVT_MENU		(evt_quit, WinMain::onQuit) // lors de la demande de fermeture via le menu
    EVT_MENU		(evt_createRule, WinMain::onCreateRule)
    EVT_MENU		(evt_loadRule, WinMain::onLoadRule) // chargement via le menu
    EVT_MENU		(evt_settings, WinMain::onSettings) //Ouverture des paramètres via le menu
    EVT_MENU		(evt_editRule, WinMain::onEditRule) //Ouverture de l'éditeur de règles via le menu
    EVT_MENU		(evt_saveRule, WinMain::onSaveRule) //Sauvegarde via le menu
    EVT_MENU		(evt_togglePlay, WinMain::onPlay) //Lance la règle via le menu
    EVT_MENU		(evt_togglePlay, WinMain::onPause) //Met en pause via le menu
	EVT_MENU		(evt_step, WinMain::onStep) //Affiche un par un les changements de la grille via le menu
	EVT_MENU		(evt_zoomIn, WinMain::onZoomIn) //Zoom +
	EVT_MENU		(evt_zoomOut, WinMain::onZoomOut) //Zoom -
	EVT_MENU		(evt_zoomFit, WinMain::onZoomFit) //Zoom Adapter à la grille
	EVT_MENU		(evt_toggleGridDisplay, WinMain::onToggleGridDisplay) //Affiche la grille
    EVT_MENU		(evt_about, WinMain::onAbout) // lorsque qu'on veut des infos supplémentaires
    EVT_MENU		(evt_helpOnline, WinMain::onHelpOnline) //Affiche l'aide en ligne
    EVT_MENU		(evt_help, WinMain::onHelp) //Affiche l'aide en ligne

    /*Les événements pour les boutons*/
    EVT_BUTTON		(evt_createRule, WinMain::onCreateRule) //Crée une nouvelle règle via la toolbar
    EVT_BUTTON		(evt_editRule, WinMain::onEditRule) //Ouvre l'editeur via la toolbar
    EVT_BUTTON 		(evt_saveRule, WinMain::onSaveRule) //Sauvegarde la règle via la toolbar
    EVT_BUTTON		(evt_togglePlay, WinMain::onPlay) //Lance la règle via la toolbar 
    EVT_BUTTON		(evt_togglePlay, WinMain::onPause) //Met en pause via la toolbar
    EVT_BUTTON		(evt_step, WinMain::onStep) //Affiche un par un les changements via la toolbar
    EVT_BUTTON 		(evt_zoomIn, WinMain::onZoomIn) //Zoom + 
    EVT_BUTTON		(evt_zoomOut, WinMain::onZoomOut) // Zoom-
    EVT_BUTTON		(evt_zoomFit, WinMain::onZoomFit) //Zoom adapter à la grille
END_EVENT_TABLE()