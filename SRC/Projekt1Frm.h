///-----------------------------------------------------------------
///
/// @file      Projekt1Frm.h
/// @author    MaciekKubicki
/// Created:   2016-01-07 21:45:35
/// @section   DESCRIPTION
///            Projekt1Frm class declaration
///
///------------------------------------------------------------------

#ifndef __PROJEKT1FRM_H__
#define __PROJEKT1FRM_H__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/frame.h>
#else
	#include <wx/wxprec.h>
#endif

#include <vector>
#include <dirent.h>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
//Do not add custom headers between 
//Header Include Start and Header Include End.
//wxDev-C++ designer will remove them. Add custom headers after the block.
////Header Include Start
#include <wx/textctrl.h>
#include <wx/stattext.h>
#include <wx/button.h>
#include <wx/sizer.h>
////Header Include End

////Dialog Style Start
#undef Projekt1Frm_STYLE
#define Projekt1Frm_STYLE wxCAPTION | wxRESIZE_BORDER | wxSYSTEM_MENU | wxTHICK_FRAME | wxMINIMIZE_BOX | wxMAXIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End
#define wxTHICK_FRAME wxRESIZE_BORDER

class Projekt1Frm : public wxFrame
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		Projekt1Frm(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("Projekt1"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = Projekt1Frm_STYLE);
		virtual ~Projekt1Frm();
		void WxButton1Click(wxCommandEvent& event);
		void WxButton1Click0(wxCommandEvent& event);
		void WxButton1Click1(wxCommandEvent& event);
		void WxPanel2UpdateUI(wxUpdateUIEvent& event);
		void WxEdit1Updated(wxCommandEvent& event);
		void WxButton1Click2(wxCommandEvent& event);
		void WxButton2Click(wxCommandEvent& event);
		
	private:
		//Do not add custom control declarations between
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxButton *WxButton2;
		wxTextCtrl *WxEdit2;
		wxStaticText *WxStaticText4;
		wxTextCtrl *WxEdit1;
		wxStaticText *WxStaticText3;
		wxBoxSizer *WxBoxSizer5;
		wxBoxSizer *WxBoxSizer3;
		wxButton *WxButton1;
		wxBoxSizer *WxBoxSizer2;
		wxBoxSizer *WxBoxSizer1;
		////GUI Control Declaration End
		
		wxString path;//sciezka
        std::vector <std::string> names;//nazwy bitmap
        size_t quantity;//ilosc
        wxPoint points[20];//pozycje bitmap na bitmapie
		
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_WXBUTTON2 = 1015,
			ID_WXEDIT2 = 1014,
			ID_WXSTATICTEXT4 = 1018,
			ID_WXEDIT1 = 1011,
			ID_WXSTATICTEXT3 = 1017,
			ID_WXBUTTON1 = 1005,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
		
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
};

#endif
