#ifndef _MAINWIN_H_
#define _MAINWIN_H_

#include <wx/wx.h>

// redéfinition de wxFrame pour faire la fenêtre principale

typedef enum Events {
	Id_quit = 1,
	Id_loadRule = 2,
	Id_createRule = 3,
	Id_about,
	Id_editRule,
	Id_saveRule,
	Id_settings,
	Id_start,
	Id_break, 
	Id_next,
	Id_reload,
	Id_speed,
	Id_slow,
	Id_sizeUp,
	Id_sizeDown,
	Id_fit,
	Id_displayCell, Id_helpACS, Id_helpOnline, Id_undo, Id_redo
} Events;

class MainWin : public wxFrame {

	public:
		MainWin(const wxString& title, const wxPoint& pos, const wxSize& size);
		// pas de destructeur. wxWidgets s'en occupe.

		// les evenements
		void onQuit(wxCommandEvent& event);
		void onLoad(wxCommandEvent& event);
		void onUndo(wxCommandEvent& event); 
		void onRedo(wxCommandEvent& event); 
		void onCreate(wxCommandEvent& event);
		void onEditrule(wxCommandEvent& event); 
		void onSaverule(wxCommandEvent& event);
		void onSettings(wxCommandEvent& event);
		void onStart(wxCommandEvent& event);
		void onBreak(wxCommandEvent& event); 
		void onNext(wxCommandEvent& event);
		void onReload(wxCommandEvent& event);
		void onSpeed(wxCommandEvent& event);
		void onSlow(wxCommandEvent& event);
		void onSizeup(wxCommandEvent& event);
		void onSizedown(wxCommandEvent& event);
		void onFit(wxCommandEvent& event);
		void onDisplaycell(wxCommandEvent& event);
		void onHelpACS(wxCommandEvent& event);
		void onHelponline(wxCommandEvent& event);
		void onAbout(wxCommandEvent& event); 

	private:
		DECLARE_EVENT_TABLE()


};

#endif // _MAINWIN_H_