//---------------------------------------------------------------------------
//
// Name:        Projekt1App.cpp
// Author:      MaciekKubicki
// Created:     2016-01-07 21:45:34
// Description: 
//
//---------------------------------------------------------------------------

#include "Projekt1App.h"
#include "Projekt1Frm.h"
#define wxTHICK_FRAME wxRESIZE_BORDER

IMPLEMENT_APP(Projekt1FrmApp)

bool Projekt1FrmApp::OnInit()
{
    Projekt1Frm* frame = new Projekt1Frm(NULL);
    SetTopWindow(frame);
    frame->Show();
    return true;
}
 
int Projekt1FrmApp::OnExit()
{
	return 0;
}
