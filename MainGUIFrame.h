///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __MAINGUIFRAME_H__
#define __MAINGUIFRAME_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/bmpbuttn.h>
#include <wx/button.h>
#include <wx/toolbar.h>
#include <wx/dataview.h>
#include <wx/sizer.h>
#include <wx/statusbr.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MainGUIFrame
///////////////////////////////////////////////////////////////////////////////
class MainGUIFrame : public wxFrame
{
	private:

	protected:
		wxMenuBar* mbar;
		wxMenu* fileMenu;
		wxMenu* helpMenu;
		wxToolBar* m_toolBar1;
		wxBitmapButton* m_bpButtonOpen;
		wxBitmapButton* m_bpButtonSave;
		wxBitmapButton* m_bpButtonUp;
		wxBitmapButton* m_bpButtonDown;
		wxDataViewListCtrl* m_dataViewListCtrl1;
		wxDataViewColumn* m_dataViewListColumnCheck;
		wxDataViewColumn* m_dataViewListColumnNumber;
		wxDataViewColumn* m_dataViewListColumnType;
		wxDataViewColumn* m_dataViewListColumnFilename;
		wxDataViewColumn* m_dataViewListColumnPath;
		wxStatusBar* statusBar;

		// Virtual event handlers, overide them in your derived class
		virtual void OnClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnQuit( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOpen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSaveAs( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAbout( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUp( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDown( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDataViewSelectionChanged( wxDataViewEvent& event ) { event.Skip(); }


	public:

		MainGUIFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("wxLbookV3RecentlyReadEditor"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 481,466 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		virtual ~MainGUIFrame();

};

#endif //__MAINGUIFRAME_H__
