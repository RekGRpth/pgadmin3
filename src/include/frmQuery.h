//////////////////////////////////////////////////////////////////////////
//
// pgAdmin III - PostgreSQL Tools
// Copyright (C) 2002 - 2003, The pgAdmin Development Team
// This software is released under the Artistic Licence
//
// frmQuery.h - The SQL Query form
//
//////////////////////////////////////////////////////////////////////////

#ifndef __FRM_QUERY_H
#define __FRM_QUERY_H



// wxWindows headers
#include <wx/wx.h>

#include "ctlSQLResult.h"


class frmQuery : public wxFrame
{
public:
    frmQuery(frmMain *form, const wxString& _title, pgConn *conn, const wxPoint& pos, const wxSize& size, const wxString& qry);
    ~frmQuery();
    void Go();

private:
    frmMain *mainForm;
    wxSplitterWindow* horizontal;
    ctlSQLBox *sqlQuery;
    wxNotebook *output;
    ctlSQLResult *sqlResult;
    wxTextCtrl *msgResult;
    wxStatusBar *statusBar;
    wxToolBar *toolBar;
    pgConn *conn;
    wxLongLong elapsedQuery, elapsedRetrieve;

    void OnClose(wxCloseEvent& event);
    void OnHelp(wxCommandEvent& event);
    void OnCancel(wxCommandEvent& event);
    void OnExecute(wxCommandEvent& event);
    void OnExplain(wxCommandEvent& event);
    void OnOpen(wxCommandEvent& event);
    void OnSave(wxCommandEvent& event);
    void OnSaveAs(wxCommandEvent& event);
    void OnExport(wxCommandEvent& event);
    void OnChange(wxNotifyEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnRecent(wxCommandEvent& event);
    void OnCut(wxCommandEvent& event);
    void OnCopy(wxCommandEvent& event);
    void OnPaste(wxCommandEvent& event);
    void OnClear(wxCommandEvent& event);
    void OnFind(wxCommandEvent& event);
    void OnUndo(wxCommandEvent& event);
    void OnRedo(wxCommandEvent& event);
    void OnKeyDown(wxKeyEvent& event);

    void updateRecentFiles();
    void openLastFile();
    void updateMenu();
    void execQuery(const wxString &query, int resultToRetrieve=0, bool singleResult=false, const int queryOffset=0);
    void setTools(const bool running);
    void showMessage(const wxString& msg, const wxString &msgShort=wxT(""));
    void setExtendedTitle();
    wxMenuBar *menuBar;
    wxMenu *fileMenu, *recentFileMenu, *editMenu, *queryMenu;
    wxString title;
    wxString lastFilename, lastDir, lastPath;

    bool changed, aborted;

    DECLARE_EVENT_TABLE()
};



// Position of status line fields
enum
{
    STATUSPOS_MSGS = 1,
    STATUSPOS_ROWS,
    STATUSPOS_SECS
};


enum
{
    CTL_SQLQUERY=331,
    CTL_SQLRESULT,
    CTL_MSGRESULT
};


#endif // __FRM_QUERY_H
