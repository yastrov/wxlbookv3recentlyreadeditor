/***************************************************************
 * Name:      LbookV3RecentlyReadEditorApp.h
 * Purpose:   Defines Application Class
 * Author:    Yuriy Astrov (yuriastrov@gmail.com)
 * Created:   2016-05-01
 * Copyright: Yuriy Astrov (yuriastrov@gmail.com)
 * License:   GNU GPLv3
 **************************************************************/

#ifndef LBOOKV3RECENTLYREADEDITORAPP_H
#define LBOOKV3RECENTLYREADEDITORAPP_H
#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#   include "wx/wx.h"
#endif

class LbookV3RecentlyReadEditorApp : public wxApp
{
    public:
        virtual bool OnInit() override;
};

#endif // LBOOKV3RECENTLYREADEDITORAPP_H
