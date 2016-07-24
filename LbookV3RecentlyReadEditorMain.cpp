/***************************************************************
 * Name:      LbookV3RecentlyReadEditorMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Yuriy Astrov (yuriastrov@gmail.com)
 * Created:   2016-05-01
 * Copyright: Yuriy Astrov (yuriastrov@gmail.com)
 * License:   GNU GPLv3
 **************************************************************/
#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#   include "wx/wx.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "LbookV3RecentlyReadEditorMain.h"
#include <wx/aboutdlg.h>
//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__WXMAC__)
        wxbuild << _T("-Mac");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }
    return wxbuild;
}


LbookV3RecentlyReadEditorFrame::LbookV3RecentlyReadEditorFrame(wxFrame *frame)
    : MainGUIFrame(frame), currentFilename(wxEmptyString), selectedItem(-1)
{
#if wxUSE_STATUSBAR
    statusBar->SetStatusText(_("Hello user!"), 0);
    statusBar->SetStatusText(wxbuildinfo(short_f), 1);
#endif
}

LbookV3RecentlyReadEditorFrame::~LbookV3RecentlyReadEditorFrame()
{
}

void LbookV3RecentlyReadEditorFrame::OnClose(wxCloseEvent &event)
{
    Destroy();
    // Or also you can event.Skip(true);
}

void LbookV3RecentlyReadEditorFrame::OnQuit(wxCommandEvent &event)
{
    Destroy();
    // Or also you can event.Skip(true);
}

void LbookV3RecentlyReadEditorFrame::OnAbout(wxCommandEvent &event)
{
    //wxString msg = wxbuildinfo(long_f);
    wxAboutDialogInfo info;
    info.SetName(_("wxLbookV3RecentlyReadEditor"));
    info.SetVersion(_("1.0.0 Beta"));
    info.SetDescription(_("This program does something great."));
    info.SetCopyright(wxT("(C) 2016 Yuriy Astrov <yuriastrov@gmail.com>"));
    info.SetLicence("GNU GPLv3");
    info.SetWebSite("https://github.com/yastrov/wxLbookV3RecentlyReadEditor");
    info.AddDeveloper("Yuriy Astrov");
    wxAboutBox(info);
}

void LbookV3RecentlyReadEditorFrame::OnOpen( wxCommandEvent& event ) {
    wxLogDebug("Entering LbookV3RecentlyReadEditorFrame::OnOpen");
    wxFileDialog openFileDialog(this, _("Open SYS file"),
                                wxEmptyString, wxEmptyString,
                                "SYS files (*.sys)|*.sys",
                                wxFD_OPEN|wxFD_FILE_MUST_EXIST
                                |wxFD_CHANGE_DIR);
    if (openFileDialog.ShowModal() == wxID_CANCEL) {
        wxLogDebug("Leave LbookV3RecentlyReadEditorFrame::OnOpen by Cancel");
        return;     // the user changed idea...
    }
    wxLogDebug(wxString::Format("Open %s", openFileDialog.GetPath()));
    wxObjectDataPtr<BookDataViewModel> model;  //From official example !
    model = new BookDataViewModel(); //From official example !
    wxLogDebug("Load data to model");
    currentFilename = openFileDialog.GetPath();
    const int result = model->LoadFromFile( openFileDialog.GetPath());
    if(result == 0) {
        wxLogDebug("AssociateModel with dataViewListCtrl1");
        m_dataViewListCtrl1->AssociateModel(model.get());
    } else {
        wxLogDebug("model->DecRef()");
        model->DecRef();
    }
    wxLogDebug("Leave LbookV3RecentlyReadEditorFrame::OnOpen");
}

void LbookV3RecentlyReadEditorFrame::OnSave( wxCommandEvent& event )
{
    //event.Skip();
    const int answer = wxMessageBox(wxT("Do you want to overwrite file?"),
                                    wxT("Confirm"),
                                    wxYES_NO | wxCANCEL, this);
    if (answer == wxYES && !currentFilename.empty()) {
        BookDataViewModel *model = reinterpret_cast<BookDataViewModel *>(m_dataViewListCtrl1->GetModel());
        model->SaveToFile(currentFilename);
    }
}

void LbookV3RecentlyReadEditorFrame::OnSaveAs( wxCommandEvent& event )
{
    wxFileDialog saveFileDialog(this, _("Save SYS file"),
                                wxEmptyString, wxEmptyString,
                                "SYS files (*.sys)|*.sys",
                                wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
    if (saveFileDialog.ShowModal() == wxID_CANCEL) {
        wxLogDebug("Leave LbookV3RecentlyReadEditorFrame::SaveAs by Cancel");
        return;     // the user changed idea...
    }
    if (saveFileDialog.GetPath().empty()) {
        wxLogDebug("Leave LbookV3RecentlyReadEditorFrame::SaveAs by Cancel");
        return;
    }
    BookDataViewModel *model = reinterpret_cast<BookDataViewModel *>(m_dataViewListCtrl1->GetModel());
    model->SaveToFile(saveFileDialog.GetPath());
    currentFilename = saveFileDialog.GetPath();
}

void LbookV3RecentlyReadEditorFrame::OnUp( wxCommandEvent& event )
{
    BookDataViewModel *model = reinterpret_cast<BookDataViewModel *>(m_dataViewListCtrl1->GetModel());
    if (selectedItem > 0) {
        model->UpRow(selectedItem);
        --selectedItem;
    }
}

void LbookV3RecentlyReadEditorFrame::OnDown( wxCommandEvent& event )
{
    BookDataViewModel *model = reinterpret_cast<BookDataViewModel *>(m_dataViewListCtrl1->GetModel());
    if (selectedItem < static_cast<int>(model->GetLastElementIndex())) {
        model->DownRow(selectedItem);
        ++selectedItem;
    }
}

void LbookV3RecentlyReadEditorFrame::OnDataViewSelectionChanged( wxDataViewEvent& event )
{
    /* It's one is best way to get current selectionn in wxDataViewListCtrl1. */
    if(m_dataViewListCtrl1->GetSelectedItemsCount() <= 0) {
        selectedItem = -1;
        event.Skip(false);
        return;
    }
    BookDataViewModel *model = reinterpret_cast<BookDataViewModel *>(m_dataViewListCtrl1->GetModel());
    selectedItem = model->GetRow(event.GetItem());
}


