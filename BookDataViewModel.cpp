/***************************************************************
 * Name:      BookDataViewModel.cpp
 * Purpose:   Code for Application Class
 * Author:    Yuriy Astrov (yuriastrov@gmail.com)
 * Created:   2016-05-01
 * Copyright: Yuriy Astrov (yuriastrov@gmail.com)
 * License:   GNU GPLv3
 **************************************************************/
#include "BookDataViewModel.h"
#include <algorithm>
#define INITIAL_NUMBER_OF_ITEMS 0

BookDataViewModel::BookDataViewModel():
        wxDataViewVirtualListModel(INITIAL_NUMBER_OF_ITEMS)
{
    //ctor
}

BookDataViewModel::~BookDataViewModel()
{
    //dtor
}

int BookDataViewModel::LoadFromFile(const wxString &fileName)
{
    wxLogDebug("Entering BookDataViewModel::LoadFromFile");
    int result = 0;
    wxFileInputStream input(fileName);
    if(input.IsOk()) {
        wxLogDebug("Read from input stream");
        wxDataInputStream data( input );
        data >> countOfBooks;
        wxLogDebug("Number of books: %d", countOfBooks);
        items.resize(countOfBooks);
        for(wxUint32 i=0; i < countOfBooks; ++i) {
            wxLogDebug("Read info about %d book", i);
            items[i].checked = true;
            data >> items[i].number;
            data >> items[i].type;
            data >> items[i].path;
            data >> items[i].filename;
        }
    } else {
        result = 1;
    }
    wxLogDebug("Leave BookDataViewModel::LoadFromFile");
    return result;
}

int BookDataViewModel::SaveToFile(const wxString &fileName)
{
    int result = 0;
    wxUint32 local_countOfBooks = 0;
    wxUint32 number = 0;
    wxFileOutputStream output(fileName);
    if(output.IsOk()) {
        wxDataOutputStream data(output);

        for(auto i=items.cbegin(); i != items.cend(); ++i) {
           if( (*i).checked ) {
               ++local_countOfBooks;
           }
        }

        data << local_countOfBooks;
        for(auto i=items.cbegin(); i != items.cend(); ++i) {
            if( !(*i).checked )
                continue;
            data << number;
            data << (*i).type;
            data << (*i).path;
            data << (*i).filename;
            ++number;
        }
        //Write EOF !
        data.Write32(305419896);
    } else {
        result = 1;
    }
    return result;
}
// helper methods to change the model

void BookDataViewModel::Prepend(const FileInfo &item)
{
    items.insert(items.begin(), item);
    RowPrepended();
}

void BookDataViewModel::UpRow(int row)
{
    if(row <= 0 || row > static_cast<int>(GetLastElementIndex()) )
        return;
    const int rI = row-1;
    items[row].number = items[row].number -1;
    items[rI].number = items[rI].number +1;
    std::swap(items[row], items[rI]);
    RowChanged(row);
    RowChanged(rI);
}

void BookDataViewModel::DownRow(int row)
{
    //wxMessageBox(wxString::Format(wxT("%d"), row));
    if(row >= static_cast<int>(GetLastElementIndex()) || row < 0)
        return;
    auto iter = std::next(items.begin(), row);
    if(iter == items.end()) return;
    const int rI = row+1;
    items[row].number = items[row].number +1;
    items[rI].number = items[rI].number -1;
    std::swap(items[row], items[rI]);
    RowChanged(row);
    RowChanged(rI);
}

void BookDataViewModel::DeleteItem( const wxDataViewItem &item )
{
    if(!item.IsOk()) return;
    const unsigned int row = GetRow(item);

    if (row >= GetLastElementIndex())
        return;
    auto iter = std::next(items.begin(), row);
    items.erase(iter);
    //items.RemoveAt(row);
    //items.erase(*items[row]);
    RowDeleted(row);
}

//

wxString BookDataViewModel::GetColumnType(unsigned int col) const
{
    wxLogDebug("Enter BookDataViewModel::GetColumnType");
    switch(col)
    {
        case FileColumns::CHKBOX:
            //wxDataViewToggleRenderer
            return wxT("bool");
            break;
        case FileColumns::NUMBER:
            return wxT("string");
            break;
        case FileColumns::TYPE:
            return wxT("string");
            //return wxT("int");
            break;
        case FileColumns::FILENAME:
            return wxT("string");
            break;
        case FileColumns::PATH:
            return wxT("string");
            break;
        default:
            return wxT("string");
    }
}

void BookDataViewModel::GetValueByRow(wxVariant &variant,
                                      unsigned int row,
                                      unsigned int col) const
{
    wxLogDebug("Enter BookDataViewModel::GetValueByRow");
    switch(col)
    {
        case FileColumns::CHKBOX:
            variant = items[row].checked;
            break;
        case FileColumns::NUMBER:
            variant = wxString::Format(wxT("%d"), items[row].number);
            break;
        case FileColumns::TYPE:
            variant = wxString::Format(wxT("%d"), items[row].type);
            break;
        case FileColumns::FILENAME:
            variant = items[row].filename;
            break;
        case FileColumns::PATH:
            variant = items[row].path;
            break;
        default:
            variant = wxT("string");
    }
    wxLogDebug("Leave BookDataViewModel::GetValueByRow");
}

bool BookDataViewModel::GetAttrByRow(unsigned int row,
                                     unsigned int col,
                                     wxDataViewItemAttr &attr) const
{
    switch (row % 2)
    {
        case 0:
            attr.SetColour(*wxBLACK);
            attr.SetBackgroundColour(*wxWHITE);
            break;
        case 1:
            attr.SetColour(*wxBLACK);
            attr.SetBackgroundColour(*wxGREEN);
            break;
        default:
            return false;
    }
    wxLogDebug("Leave BookDataViewModel::GetColumnType");
    return true;
}

bool BookDataViewModel::SetValueByRow(const wxVariant &variant,
                                      unsigned int row,
                                      unsigned int col)
{
    switch(col)
    {
        case FileColumns::CHKBOX:
            bool data;
            if(variant.Convert(&data)) {
                items[row].checked = data;
            }
            break;
        default:
            return false;
    }
    return false;
}
//
// For sort
int BookDataViewModel::Compare(const wxDataViewItem & item1,
                               const wxDataViewItem & item2,
                               unsigned int column,
                               bool ascending
                               ) const
{
    if(!item1.IsOk() || !item2.IsOk())
        return 0;
    const unsigned int row1 = GetRow( item1 );
    const unsigned int row2 = GetRow( item2 );
    int result = 0;
    switch(column)
    {
        case FileColumns::CHKBOX:
            //result = items[row].checked;
            break;
        case FileColumns::NUMBER:
            result = items[row1].number - items[row2].number;
            break;
        case FileColumns::TYPE:
            result = items[row1].type - items[row2].type;
            break;
        case FileColumns::FILENAME:
            result = items[row1].filename.Cmp(items[row2].filename);
            break;
        case FileColumns::PATH:
            result = items[row1].path.Cmp(items[row2].path);
            break;
        default:
            result = 0;
    }
    if(!ascending) {
        result = result * (-1);
    }
    return result;
}
