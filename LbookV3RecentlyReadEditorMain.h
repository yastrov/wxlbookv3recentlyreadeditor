/***************************************************************
 * Name:      LbookV3RecentlyReadEditorMain.h
 * Purpose:   Defines Application Frame
 * Author:    Yuriy Astrov (yuriastrov@gmail.com)
 * Created:   2016-05-01
 * Copyright: Yuriy Astrov (yuriastrov@gmail.com)
 * License:   GNU GPLv3
 **************************************************************/

#ifndef LBOOKV3RECENTLYREADEDITORMAIN_H
#define LBOOKV3RECENTLYREADEDITORMAIN_H

#include <wx/filedlg.h>

#include "LbookV3RecentlyReadEditorApp.h"
#include "BookDataViewModel.h"

#include "MainGUIFrame.h"

#if !defined(wxOVERRIDE)
	#define wxOVERRIDE override
#endif

class LbookV3RecentlyReadEditorFrame: public MainGUIFrame
{
    public:
        LbookV3RecentlyReadEditorFrame(wxFrame *frame);
        virtual ~LbookV3RecentlyReadEditorFrame();
    private:
        void OnClose(wxCloseEvent& event) wxOVERRIDE;
        void OnQuit(wxCommandEvent& event) wxOVERRIDE;
        void OnAbout(wxCommandEvent& event) wxOVERRIDE;
        void OnOpen( wxCommandEvent& event ) wxOVERRIDE;
        void OnSave( wxCommandEvent& event ) wxOVERRIDE;
        void OnSaveAs( wxCommandEvent& event ) wxOVERRIDE;
        void OnUp( wxCommandEvent& event ) wxOVERRIDE;
        void OnDown( wxCommandEvent& event ) wxOVERRIDE;
        void OnDataViewSelectionChanged( wxDataViewEvent& event ) wxOVERRIDE;

        wxString currentFilename;
        int selectedItem;
};

#endif // LBOOKV3RECENTLYREADEDITORMAIN_H
