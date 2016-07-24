/***************************************************************
 * Name:      BookDataViewModel.h
 * Purpose:   Code for Application Class
 * Author:    Yuriy Astrov (yuriastrov@gmail.com)
 * Created:   2016-05-01
 * Copyright: Yuriy Astrov (yuriastrov@gmail.com)
 * License:   GNU GPLv3
 **************************************************************/
#ifndef BOOKDATAVIEWMODEL_H
#define BOOKDATAVIEWMODEL_H

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#   include "wx/wx.h"
#endif
#include <wx/dataview.h>
#include <wx/wfstream.h>
#include <wx/datstrm.h>
#include <wx/variant.h>
#if !defined(wxOVERRIDE)
    #define wxOVERRIDE override
#endif
#include <vector>

struct FileInfo
{
    bool checked;
    wxUint32 number;
    wxUint32 type;
   // wxUint32 sizeP; // It for compability with printelement function.
    wxString path;
   // wxUint32 sizeF; // It for compability with printelement function.
    wxString filename;
};
typedef struct FileInfo FileInfoStrct;

#define NUMBER_OF_COLUMNS 5

class BookDataViewModel : public wxDataViewVirtualListModel
{
private:
    wxUint32 countOfBooks;
    std::vector<FileInfoStrct> items;
    enum FileColumns {
        CHKBOX,
        NUMBER,
        TYPE,
        FILENAME,
        PATH
    };

public:
    BookDataViewModel();
    virtual ~BookDataViewModel();

    int LoadFromFile(const wxString &fileName);
    int SaveToFile(const wxString &fileName);

    // helper methods to change the model

    void Prepend(const FileInfo &item);
    void UpRow(int row);
    void DownRow(int row);
    void DeleteItem(const wxDataViewItem &item);

    // implementation of base class virtuals to define model

    virtual unsigned int GetColumnCount() const wxOVERRIDE {
        return NUMBER_OF_COLUMNS;
    }

    unsigned int GetCount() const {
        return countOfBooks;
    }
    unsigned int GetLastElementIndex() const {
        return items.size()-1;
    }

    virtual wxString GetColumnType(unsigned int col) const wxOVERRIDE;

    virtual void GetValueByRow(wxVariant &variant,
                               unsigned int row, unsigned int col) const wxOVERRIDE;
    virtual bool GetAttrByRow(unsigned int row, unsigned int col,
                              wxDataViewItemAttr &attr) const wxOVERRIDE;
    virtual bool SetValueByRow(const wxVariant &variant,
                               unsigned int row, unsigned int col) wxOVERRIDE;
    // For sort
    int Compare(const wxDataViewItem & item1,
                const wxDataViewItem & item2,
                unsigned int column,
                bool ascending
                ) const;
protected:
};

#endif // BOOKDATAVIEWMODEL_H
