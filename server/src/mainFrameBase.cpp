///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun  5 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wx/wxprec.h"

#include "mainFrameBase.h"

///////////////////////////////////////////////////////////////////////////

MyFrame1Base::MyFrame1Base( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );
	
	m_panel3 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );
	
	m_cmdBox = new wxTextCtrl( m_panel3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY );
	bSizer6->Add( m_cmdBox, 1, wxEXPAND|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText1 = new wxStaticText( m_panel3, wxID_ANY, wxT("Podlaczono klientow:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer4->Add( m_staticText1, 0, wxALL, 5 );
	
	m_clConn = new wxStaticText( m_panel3, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_clConn->Wrap( -1 );
	bSizer4->Add( m_clConn, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	
	bSizer6->Add( bSizer4, 0, 0, 5 );
	
	
	m_panel3->SetSizer( bSizer6 );
	m_panel3->Layout();
	bSizer6->Fit( m_panel3 );
	bSizer5->Add( m_panel3, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer5 );
	this->Layout();
	
	this->Centre( wxBOTH );
}

MyFrame1Base::~MyFrame1Base()
{
}
