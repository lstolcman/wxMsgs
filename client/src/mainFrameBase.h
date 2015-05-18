///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun  5 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __MAINFRAMEBASE_H__
#define __MAINFRAMEBASE_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/textctrl.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/stattext.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/checkbox.h>
#include <wx/spinctrl.h>
#include <wx/treectrl.h>
#include <wx/panel.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame1Base
///////////////////////////////////////////////////////////////////////////////
class MyFrame1Base : public wxFrame 
{
	private:
	
	protected:
		wxPanel* m_panel3;
		wxTextCtrl* m_cmdBox;
		wxStaticText* m_staticText1;
		wxTextCtrl* m_hostname;
		wxButton* m_btnConnect;
		wxTextCtrl* m_textCtrl3;
		wxButton* m_btnGenerate;
		wxCheckBox* m_checkBox2;
		wxCheckBox* m_checkBox3;
		wxStaticText* m_staticText2;
		wxSpinCtrl* m_encKey;
		wxTreeCtrl* m_treeCtrl2;
		wxTextCtrl* m_textCtrl4;
		wxTextCtrl* m_textCtrl7;
		wxTextCtrl* m_textCtrl6;
		wxTextCtrl* m_textCtrl5;
		wxTextCtrl* m_textCtrl51;
		wxTextCtrl* m_textCtrl511;
		wxTextCtrl* m_textCtrl512;
		wxButton* m_btnSend;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnConnect( wxCommandEvent& event ) { event.Skip(); }
		virtual void clkGenerate( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSend( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		MyFrame1Base( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Klient"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,500 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~MyFrame1Base();
	
};

#endif //__MAINFRAMEBASE_H__
