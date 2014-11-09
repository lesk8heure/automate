#ifndef _MAINWIN_H_
#define _MAINWIN_H_

#include <wx/wx.h>

// redéfinition de wxFrame pour faire la fenêtre principale

typedef enum Events {
	Id_quit = 1,
	Id_loadRule = 2,
	Id_createRule = 3,
	Id_about
} Events;

class MainWin : public wxFrame {

	public:
		MainWin(const wxString& title, const wxPoint& pos, const wxSize& size);
		// pas de destructeur. wxWidgets s'en occupe.

		// les evenements
		void onQuit(wxCommandEvent& event);
		void onAbout(wxCommandEvent& event);
		void onLoad(wxCommandEvent& event);
		void onCreate(wxCommandEvent& event);

	private:
		DECLARE_EVENT_TABLE()


};

#endif // _MAINWIN_H_