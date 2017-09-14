///-----------------------------------------------------------------
///
/// @file      Projekt1Frm.cpp
/// @author    MaciekKubicki
/// Created:   2016-01-07 21:45:35
/// @section   DESCRIPTION
///            Projekt1Frm class implementation
///
///------------------------------------------------------------------

#include "Projekt1Frm.h"
#include <wx/graphics.h>
#include <wx/filename.h>


//Do not add custom headers between
//Header Include Start and Header Include End
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

//----------------------------------------------------------------------------
// Projekt1Frm
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(Projekt1Frm,wxFrame)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(Projekt1Frm::OnClose)
	EVT_BUTTON(ID_WXBUTTON2,Projekt1Frm::WxButton2Click)
	
	EVT_TEXT(ID_WXEDIT1,Projekt1Frm::WxEdit1Updated)
	EVT_BUTTON(ID_WXBUTTON1,Projekt1Frm::WxButton1Click2)
END_EVENT_TABLE()
////Event Table End

Projekt1Frm::Projekt1Frm(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

Projekt1Frm::~Projekt1Frm()
{
}

void Projekt1Frm::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	WxBoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	this->SetSizer(WxBoxSizer1);
	this->SetAutoLayout(true);

	WxBoxSizer2 = new wxBoxSizer(wxVERTICAL);
	WxBoxSizer1->Add(WxBoxSizer2, 0, wxALIGN_CENTER | wxALL, 5);

	WxButton1 = new wxButton(this, ID_WXBUTTON1, wxT("Wybierz folder"), wxPoint(5, 5), wxSize(125, 25), 0, wxDefaultValidator, wxT("WxButton1"));
	WxBoxSizer2->Add(WxButton1,0,wxALIGN_CENTER | wxALL,5);

	WxBoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer1->Add(WxBoxSizer3, 1, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer5 = new wxBoxSizer(wxVERTICAL);
	WxBoxSizer3->Add(WxBoxSizer5, 1, wxALIGN_CENTER | wxALL, 5);

	WxStaticText3 = new wxStaticText(this, ID_WXSTATICTEXT3, wxT("Sciezka do katalogu"), wxPoint(176, 5), wxDefaultSize, 0, wxT("WxStaticText3"));
	WxBoxSizer5->Add(WxStaticText3,0,wxALIGN_CENTER | wxALL,5);

	WxEdit1 = new wxTextCtrl(this, ID_WXEDIT1, wxT(""), wxPoint(5, 34), wxSize(450, 19), 0, wxDefaultValidator, wxT("WxEdit1"));
	WxEdit1->Enable(false);
	WxBoxSizer5->Add(WxEdit1,1,wxALIGN_CENTER | wxALL,5);

	WxStaticText4 = new wxStaticText(this, ID_WXSTATICTEXT4, wxT("Ilosc plikow .bmp"), wxPoint(181, 63), wxDefaultSize, 0, wxT("WxStaticText4"));
	WxBoxSizer5->Add(WxStaticText4,0,wxALIGN_CENTER | wxALL,5);

	WxEdit2 = new wxTextCtrl(this, ID_WXEDIT2, wxT(""), wxPoint(205, 92), wxSize(50, 19), 0, wxDefaultValidator, wxT("WxEdit2"));
	WxEdit2->Enable(false);
	WxBoxSizer5->Add(WxEdit2,0,wxALIGN_CENTER_HORIZONTAL | wxALL,5);

	WxButton2 = new wxButton(this, ID_WXBUTTON2, wxT("Zindeksuj"), wxPoint(192, 121), wxSize(75, 25), 0, wxDefaultValidator, wxT("WxButton2"));
	WxBoxSizer5->Add(WxButton2,0,wxALIGN_RIGHT | wxALL,5);

	SetTitle(wxT("Projekt1"));
	SetIcon(wxNullIcon);
	
	GetSizer()->Layout();
	GetSizer()->Fit(this);
	GetSizer()->SetSizeHints(this);
	Center();
	
	////GUI Items Creation End


    path = "";//sciezka
    quantity = 0;//ilosc
    wxInitAllImageHandlers();
    //wxPoint points[20];
    points[0]=wxPoint(25,20);
    points[1]=wxPoint(175,20);
    points[2]=wxPoint(325,20);
    points[3]=wxPoint(475,20);
    points[4]=wxPoint(625,20);
    points[5]=wxPoint(25,140);
    points[6]=wxPoint(175,140);
    points[7]=wxPoint(325,140);
    points[8]=wxPoint(475,140);
    points[9]=wxPoint(625,140);
    points[10]=wxPoint(25,260);
    points[11]=wxPoint(175,260);
    points[12]=wxPoint(325,260);
    points[13]=wxPoint(475,260);
    points[14]=wxPoint(625,260);
    points[15]=wxPoint(25,380);
    points[16]=wxPoint(175,380);
    points[17]=wxPoint(325,380);
    points[18]=wxPoint(475,380);
    points[19]=wxPoint(625,380);
    
}

void Projekt1Frm::OnClose(wxCloseEvent& event)
{
	Destroy();
}

/*
 * WxButton1Click
 */
void Projekt1Frm::WxButton1Click(wxCommandEvent& event)
{
	// insert your code here
		wxDirDialog dlg(NULL, "Choose input directory", "",
                wxDD_DEFAULT_STYLE | wxDD_DIR_MUST_EXIST);
    if (dlg.ShowModal() == wxID_CANCEL )
        return;
    path = dlg.GetPath();
    (*WxEdit1) << path;

}

std::vector <std::string> whatIsIn(const char* str)
{
        std::vector <std::string> files;
        DIR *dir;
        struct dirent *ent;
        if ((dir = opendir (str)) != NULL) 
        {
          
              while ((ent = readdir (dir)) != NULL) {
                    std::string s=ent->d_name;
                    if(s.find(".bmp")!= std::string::npos)
                    {
                        files.push_back(ent->d_name);
                        
                    }
              }
              closedir (dir);
              return files;
        } 
        else 
        {
          perror ("");
          return files;
        }
}





/*
 * WxPanel2UpdateUI
 */
void Projekt1Frm::WxPanel2UpdateUI(wxUpdateUIEvent& event)
{
	// insert your code here
}

/*
 * WxEdit1Updated
 */
void Projekt1Frm::WxEdit1Updated(wxCommandEvent& event)
{
	// insert your code here
}

/*
 * WxButton1Click2
 */
void Projekt1Frm::WxButton1Click2(wxCommandEvent& event)
{
	wxDirDialog dlg(NULL, "Choose input directory", "",
                wxDD_DEFAULT_STYLE | wxDD_DIR_MUST_EXIST);
    if(dlg.ShowModal() == wxID_CANCEL)
        return;
    WxEdit1->Clear();
    WxEdit2->Clear();
    path = dlg.GetPath();
    (*WxEdit1) << path;
    
    names = whatIsIn(path);
    quantity = names.size();
    
    std::ostringstream ss;
    ss << quantity;
    std::string str = ss.str();
    
    (*WxEdit2) << str;


        
    
}

wxString cutString(wxString name)
{
    if(name.length() > 10)
        return "~"+name.substr(0,9);
    else 
        return name;
}

/*
 * WxButton2Click
 */
void Projekt1Frm::WxButton2Click(wxCommandEvent& event)
{
	if (path == "")
	{
	   wxMessageDialog dlg(NULL,"Najpierw wybierz folder do zindeksowania","B³¹d",wxOK);
	   if(dlg.ShowModal() == wxID_CANCEL)
	       return;
    }
    else if (path != "" && quantity == 0)
    {
        wxMessageDialog dlg(NULL,"W folderze nie ma plików .bmp","B³¹d",wxOK);
	    if(dlg.ShowModal() == wxID_CANCEL)
	       return;
    }
    else
    {

       
        int bitmaps = (int)ceil((double)quantity / 20);

       /* wxMessageDialog dlg(NULL,"Indeksowanie","Index",wxOK);
       
	    if(dlg.ShowModal() == wxID_CANCEL)
	       return;*/
        
        for (int i = 0; i < bitmaps; i++)
        {
            wxBitmap *b=new wxBitmap(800,600);
            wxMemoryDC dc(*b);
            dc.Clear();
            for(int j =0; j<20; j++)
            {
              
                if((j+i*20+1)>(int)quantity)
                    break;
                
                    wxImage a;
                   
                    wxFileName fn(path,names[j+i*20]);
                    a.LoadFile(fn.GetFullPath());
                    a=a.Rescale(130,100);
                    wxBitmap aa(a);
                    
                 
                    
                    dc.DrawBitmap(aa,points[j].x,points[j].y);
                    dc.DrawText(cutString(fn.GetName()+"."+fn.GetExt()),points[j].x+35,points[j].y+105);
                   
                
            

                      
                

            } 
            std::ostringstream ss;
            ss << "Bitmapa nr " << i+1 << " z katalogu " << path;
            std::string str = ss.str();
            dc.DrawText(str,10,10);
            std::ostringstream s2;
            s2<<i+1;
            str = s2.str();
            wxTextEntryDialog dlg(NULL,"Dodaj komentarz do indeksu nr "+str,"Komentarz");
            
       
	        if(dlg.ShowModal() == wxID_CANCEL)
	           return;
	        wxString kom = dlg.GetValue();
	        dc.DrawText(kom,50,530);
	        
            
            
            std::ostringstream sss;
            sss << path << "\\bitmapa" << i+1 << ".bmp";
            str = sss.str();
            b->ConvertToImage().SaveFile(str,wxBITMAP_TYPE_BMP);
               


        } 
        std::ostringstream wynik;
        wynik << "Zakonczono indeksowanie, stworzono "<<bitmaps<<" bitmapy w katalogu: " <<path;
        wxMessageDialog dlg(NULL,wynik.str(),"Sukces",wxOK);
	    if(dlg.ShowModal() == wxID_CANCEL)
	       return;

    }
	   
}
