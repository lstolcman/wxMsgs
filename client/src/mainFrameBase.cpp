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
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* sbSizer5;
	sbSizer5 = new wxStaticBoxSizer( new wxStaticBox( m_panel3, wxID_ANY, wxT("Command Box") ), wxVERTICAL );
	
	m_cmdBox = new wxTextCtrl( m_panel3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY );
	sbSizer5->Add( m_cmdBox, 1, wxEXPAND|wxRIGHT|wxLEFT, 5 );
	
	wxBoxSizer* bSizer61;
	bSizer61 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText1 = new wxStaticText( m_panel3, wxID_ANY, wxT("Adres:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer61->Add( m_staticText1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_hostname = new wxTextCtrl( m_panel3, wxID_ANY, wxT("localhost"), wxDefaultPosition, wxSize( 200,-1 ), 0 );
	bSizer61->Add( m_hostname, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_btnConnect = new wxButton( m_panel3, wxID_ANY, wxT("Connect"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer61->Add( m_btnConnect, 1, wxALIGN_RIGHT|wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer5->Add( bSizer61, 0, wxEXPAND, 5 );
	
	
	bSizer10->Add( sbSizer5, 1, wxEXPAND|wxALL, 5 );
	
	wxStaticBoxSizer* sbSizer6;
	sbSizer6 = new wxStaticBoxSizer( new wxStaticBox( m_panel3, wxID_ANY, wxT("Packets") ), wxVERTICAL );
	
	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxHORIZONTAL );
	
	m_textCtrl3 = new wxTextCtrl( m_panel3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer15->Add( m_textCtrl3, 1, wxALL|wxEXPAND, 5 );
	
	m_btnGenerate = new wxButton( m_panel3, wxID_ANY, wxT("Generuj"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer15->Add( m_btnGenerate, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer14->Add( bSizer15, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxVERTICAL );
	
	m_treeCtrl2 = new wxTreeCtrl( m_panel3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTR_DEFAULT_STYLE );
	bSizer17->Add( m_treeCtrl2, 1, wxEXPAND|wxRIGHT|wxLEFT, 5 );
	
	
	bSizer14->Add( bSizer17, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* sbSizer10;
	sbSizer10 = new wxStaticBoxSizer( new wxStaticBox( m_panel3, wxID_ANY, wxT("Typ") ), wxVERTICAL );
	
	m_textCtrl4 = new wxTextCtrl( m_panel3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 25,-1 ), 0 );
	sbSizer10->Add( m_textCtrl4, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	bSizer18->Add( sbSizer10, 0, wxTOP|wxBOTTOM, 5 );
	
	wxStaticBoxSizer* sbSizer9;
	sbSizer9 = new wxStaticBoxSizer( new wxStaticBox( m_panel3, wxID_ANY, wxT("Nr") ), wxVERTICAL );
	
	m_textCtrl7 = new wxTextCtrl( m_panel3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 25,-1 ), 0 );
	sbSizer9->Add( m_textCtrl7, 0, 0, 5 );
	
	
	bSizer18->Add( sbSizer9, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	wxStaticBoxSizer* sbSizer8;
	sbSizer8 = new wxStaticBoxSizer( new wxStaticBox( m_panel3, wxID_ANY, wxT("Ile") ), wxVERTICAL );
	
	m_textCtrl6 = new wxTextCtrl( m_panel3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 25,-1 ), 0 );
	sbSizer8->Add( m_textCtrl6, 0, 0, 5 );
	
	
	bSizer18->Add( sbSizer8, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	wxStaticBoxSizer* sbSizer7;
	sbSizer7 = new wxStaticBoxSizer( new wxStaticBox( m_panel3, wxID_ANY, wxT("Dl") ), wxVERTICAL );
	
	m_textCtrl5 = new wxTextCtrl( m_panel3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 25,-1 ), 0 );
	sbSizer7->Add( m_textCtrl5, 0, 0, 5 );
	
	
	bSizer18->Add( sbSizer7, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	wxStaticBoxSizer* sbSizer71;
	sbSizer71 = new wxStaticBoxSizer( new wxStaticBox( m_panel3, wxID_ANY, wxT("Enc") ), wxVERTICAL );
	
	m_textCtrl51 = new wxTextCtrl( m_panel3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 25,-1 ), 0 );
	sbSizer71->Add( m_textCtrl51, 0, 0, 5 );
	
	
	bSizer18->Add( sbSizer71, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	wxStaticBoxSizer* sbSizer711;
	sbSizer711 = new wxStaticBoxSizer( new wxStaticBox( m_panel3, wxID_ANY, wxT("CRC") ), wxVERTICAL );
	
	m_textCtrl511 = new wxTextCtrl( m_panel3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 25,-1 ), 0 );
	sbSizer711->Add( m_textCtrl511, 0, 0, 5 );
	
	
	bSizer18->Add( sbSizer711, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	wxStaticBoxSizer* sbSizer712;
	sbSizer712 = new wxStaticBoxSizer( new wxStaticBox( m_panel3, wxID_ANY, wxT("Dane") ), wxVERTICAL );
	
	m_textCtrl512 = new wxTextCtrl( m_panel3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), 0 );
	sbSizer712->Add( m_textCtrl512, 1, wxEXPAND, 5 );
	
	
	bSizer18->Add( sbSizer712, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer14->Add( bSizer18, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxHORIZONTAL );
	
	m_btnSend = new wxButton( m_panel3, wxID_ANY, wxT("Send"), wxDefaultPosition, wxDefaultSize, 0 );
	m_btnSend->Enable( false );
	
	bSizer16->Add( m_btnSend, 0, wxALIGN_RIGHT|wxALL, 5 );
	
	
	bSizer14->Add( bSizer16, 0, 0, 5 );
	
	
	sbSizer6->Add( bSizer14, 1, wxEXPAND, 5 );
	
	
	bSizer10->Add( sbSizer6, 1, wxEXPAND|wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	
	m_panel3->SetSizer( bSizer10 );
	m_panel3->Layout();
	bSizer10->Fit( m_panel3 );
	bSizer5->Add( m_panel3, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer5 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_btnConnect->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1Base::OnConnect ), NULL, this );
	m_btnGenerate->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1Base::clkGenerate ), NULL, this );
	m_btnSend->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1Base::OnSend ), NULL, this );
}

MyFrame1Base::~MyFrame1Base()
{
	// Disconnect Events
	m_btnConnect->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1Base::OnConnect ), NULL, this );
	m_btnGenerate->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1Base::clkGenerate ), NULL, this );
	m_btnSend->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1Base::OnSend ), NULL, this );
	
}
