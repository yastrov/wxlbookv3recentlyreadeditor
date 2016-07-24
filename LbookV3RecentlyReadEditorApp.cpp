/***************************************************************
 * Name:      LbookV3RecentlyReadEditorApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Yuriy Astrov (yuriastrov@gmail.com)
 * Created:   2016-05-01
 * Copyright: Yuriy Astrov (yuriastrov@gmail.com)
 * License:   GNU GPLv3
 **************************************************************/
//#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#   include "wx/wx.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "LbookV3RecentlyReadEditorApp.h"
#include "LbookV3RecentlyReadEditorMain.h"

IMPLEMENT_APP(LbookV3RecentlyReadEditorApp);

bool LbookV3RecentlyReadEditorApp::OnInit()
{
    wxLogDebug("Entering LbookV3RecentlyReadEditorApp::OnInit");
    LbookV3RecentlyReadEditorFrame* frame = new LbookV3RecentlyReadEditorFrame(0L);
    frame->Show();
    wxLogDebug("Leave LbookV3RecentlyReadEditorApp::OnInit");
    return true;
}
