///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif //WX_PRECOMP

#include "MainGUIFrame.h"

///////////////////////////////////////////////////////////////////////////

MainGUIFrame::MainGUIFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetFont( wxFont( 14, 74, 90, 90, false, wxT("Arial") ) );
	
	mbar = new wxMenuBar( 0 );
	mbar->SetFont( wxFont( 14, 74, 90, 90, false, wxT("Arial") ) );
	
	fileMenu = new wxMenu();
	wxMenuItem* menuFileQuit;
	menuFileQuit = new wxMenuItem( fileMenu, wxID_EXIT, wxString( wxT("&Quit") ) + wxT('\t') + wxT("Alt+F4"), wxT("Quit the application"), wxITEM_NORMAL );
	fileMenu->Append( menuFileQuit );
	
	wxMenuItem* menuFileOpen;
	menuFileOpen = new wxMenuItem( fileMenu, wxID_OPEN, wxString( wxT("&Open") ) , wxEmptyString, wxITEM_NORMAL );
	fileMenu->Append( menuFileOpen );
	
	wxMenuItem* menuFileSave;
	menuFileSave = new wxMenuItem( fileMenu, wxID_SAVE, wxString( wxT("&Save") ) , wxEmptyString, wxITEM_NORMAL );
	fileMenu->Append( menuFileSave );
	
	wxMenuItem* menuFileSaveAs;
	menuFileSaveAs = new wxMenuItem( fileMenu, wxID_SAVEAS, wxString( wxT("Save &As...") ) , wxEmptyString, wxITEM_NORMAL );
	fileMenu->Append( menuFileSaveAs );
	
	mbar->Append( fileMenu, wxT("&File") ); 
	
	helpMenu = new wxMenu();
	wxMenuItem* menuHelpAbout;
	menuHelpAbout = new wxMenuItem( helpMenu, wxID_ABOUT, wxString( wxT("&About") ) + wxT('\t') + wxT("F1"), wxT("Show info about this application"), wxITEM_NORMAL );
	helpMenu->Append( menuHelpAbout );
	
	mbar->Append( helpMenu, wxT("&Help") ); 
	
	this->SetMenuBar( mbar );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	m_toolBar1 = new wxToolBar( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL ); 
	m_bpButtonOpen = new wxBitmapButton( m_toolBar1, wxID_OPEN, wxArtProvider::GetBitmap( wxART_FILE_OPEN, wxART_TOOLBAR ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpButtonOpen->SetFont( wxFont( 14, 74, 90, 90, false, wxT("Arial") ) );
	m_bpButtonOpen->SetToolTip( wxT("Open") );
	
	m_toolBar1->AddControl( m_bpButtonOpen );
	m_bpButtonSave = new wxBitmapButton( m_toolBar1, wxID_SAVE, wxArtProvider::GetBitmap( wxART_FILE_SAVE, wxART_TOOLBAR ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpButtonSave->SetToolTip( wxT("Save") );
	
	m_toolBar1->AddControl( m_bpButtonSave );
	m_bpButtonUp = new wxBitmapButton( m_toolBar1, wxID_UP, wxArtProvider::GetBitmap( wxART_GO_UP, wxART_TOOLBAR ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpButtonUp->SetToolTip( wxT("Up Item") );
	
	m_toolBar1->AddControl( m_bpButtonUp );
	m_bpButtonDown = new wxBitmapButton( m_toolBar1, wxID_DOWN, wxArtProvider::GetBitmap( wxART_GO_DOWN, wxART_TOOLBAR ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpButtonDown->SetToolTip( wxT("Down Item") );
	
	m_toolBar1->AddControl( m_bpButtonDown );
	m_toolBar1->Realize(); 
	
	bSizer1->Add( m_toolBar1, 0, wxEXPAND, 5 );
	
	m_dataViewListCtrl1 = new wxDataViewListCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxDV_HORIZ_RULES|wxDV_ROW_LINES|wxDV_VERT_RULES );
	m_dataViewListCtrl1->SetFont( wxFont( 14, 74, 90, 90, false, wxT("Arial") ) );
	m_dataViewListCtrl1->SetMinSize( wxSize( 400,400 ) );
	
	m_dataViewListColumnCheck = m_dataViewListCtrl1->AppendToggleColumn( wxT("?") );
	m_dataViewListColumnNumber = m_dataViewListCtrl1->AppendTextColumn( wxT("Number") );
	m_dataViewListColumnType = m_dataViewListCtrl1->AppendTextColumn( wxT("Type") );
	m_dataViewListColumnFilename = m_dataViewListCtrl1->AppendTextColumn( wxT("Name") );
	m_dataViewListColumnPath = m_dataViewListCtrl1->AppendTextColumn( wxT("Path") );
	bSizer1->Add( m_dataViewListCtrl1, 0, wxALL|wxEXPAND, 0 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	statusBar = this->CreateStatusBar( 2, wxST_SIZEGRIP, wxID_ANY );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MainGUIFrame::OnClose ) );
	this->Connect( menuFileQuit->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainGUIFrame::OnQuit ) );
	this->Connect( menuFileOpen->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainGUIFrame::OnOpen ) );
	this->Connect( menuFileSave->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainGUIFrame::OnSave ) );
	this->Connect( menuFileSaveAs->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainGUIFrame::OnSaveAs ) );
	this->Connect( menuHelpAbout->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainGUIFrame::OnAbout ) );
	m_bpButtonOpen->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainGUIFrame::OnOpen ), NULL, this );
	m_bpButtonSave->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainGUIFrame::OnSave ), NULL, this );
	m_bpButtonUp->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainGUIFrame::OnUp ), NULL, this );
	m_bpButtonDown->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainGUIFrame::OnDown ), NULL, this );
	this->Connect( wxID_ANY, wxEVT_COMMAND_DATAVIEW_SELECTION_CHANGED, wxDataViewEventHandler( MainGUIFrame::OnDataViewSelectionChanged ) );
}

MainGUIFrame::~MainGUIFrame()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MainGUIFrame::OnClose ) );
	this->Disconnect( wxID_EXIT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainGUIFrame::OnQuit ) );
	this->Disconnect( wxID_OPEN, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainGUIFrame::OnOpen ) );
	this->Disconnect( wxID_SAVE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainGUIFrame::OnSave ) );
	this->Disconnect( wxID_SAVEAS, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainGUIFrame::OnSaveAs ) );
	this->Disconnect( wxID_ABOUT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainGUIFrame::OnAbout ) );
	m_bpButtonOpen->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainGUIFrame::OnOpen ), NULL, this );
	m_bpButtonSave->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainGUIFrame::OnSave ), NULL, this );
	m_bpButtonUp->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainGUIFrame::OnUp ), NULL, this );
	m_bpButtonDown->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainGUIFrame::OnDown ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_DATAVIEW_SELECTION_CHANGED, wxDataViewEventHandler( MainGUIFrame::OnDataViewSelectionChanged ) );
	
}
