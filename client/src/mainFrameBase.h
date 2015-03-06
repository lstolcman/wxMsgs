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
#include <wx/treectrl.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/button.h>
#include <wx/sizer.h>
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
		wxTreeCtrl* m_treeCtrl1;
		wxButton* m_button4;
		
		// Virtual event handlers, overide them in your derived class
		virtual void ButtonClk( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		MyFrame1Base( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("zzz"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~MyFrame1Base();
	
};

#endif //__MAINFRAMEBASE_H__
