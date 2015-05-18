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
	wxBoxSizer* bSizer51;
	bSizer51 = new wxBoxSizer( wxVERTICAL );
	
	m_cmdBox = new wxTextCtrl( m_panel3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY );
	bSizer51->Add( m_cmdBox, 1, wxEXPAND|wxALL, 5 );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );
	
	m_setCRC = new wxCheckBox( m_panel3, wxID_ANY, wxT("CRC"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_setCRC, 1, wxALL, 5 );
	
	m_staticText1 = new wxStaticText( m_panel3, wxID_ANY, wxT("Max dlugosc calej ramki w bajtach:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer3->Add( m_staticText1, 0, wxALL, 5 );
	
	m_setFrameLen = new wxSpinCtrl( m_panel3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 5, 20, 10 );
	bSizer3->Add( m_setFrameLen, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	
	bSizer51->Add( bSizer3, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxHORIZONTAL );
	
	m_setEncryption = new wxCheckBox( m_panel3, wxID_ANY, wxT("Szyfrowanie"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer16->Add( m_setEncryption, 1, wxALL, 5 );
	
	m_staticText7 = new wxStaticText( m_panel3, wxID_ANY, wxT("Klucz deszyfrujacy:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	bSizer16->Add( m_staticText7, 0, wxALL, 5 );
	
	m_decKey = new wxSpinCtrl( m_panel3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 26, 0 );
	bSizer16->Add( m_decKey, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	
	bSizer51->Add( bSizer16, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer31;
	bSizer31 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText10 = new wxStaticText( m_panel3, wxID_ANY, wxT("Polaczono klientow:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10->Wrap( -1 );
	bSizer31->Add( m_staticText10, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_clConn = new wxStaticText( m_panel3, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_clConn->Wrap( -1 );
	bSizer31->Add( m_clConn, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxRIGHT, 5 );
	
	
	bSizer51->Add( bSizer31, 0, wxEXPAND, 5 );
	
	
	m_panel3->SetSizer( bSizer51 );
	m_panel3->Layout();
	bSizer51->Fit( m_panel3 );
	bSizer5->Add( m_panel3, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer5 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_setCRC->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrame1Base::setCRC ), NULL, this );
	m_setFrameLen->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1Base::setFrameLen ), NULL, this );
	m_setEncryption->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrame1Base::setEncryption ), NULL, this );
}

MyFrame1Base::~MyFrame1Base()
{
	// Disconnect Events
	m_setCRC->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrame1Base::setCRC ), NULL, this );
	m_setFrameLen->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1Base::setFrameLen ), NULL, this );
	m_setEncryption->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrame1Base::setEncryption ), NULL, this );
	
}
