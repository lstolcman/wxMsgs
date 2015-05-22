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
	sbSizer5 = new wxStaticBoxSizer( new wxStaticBox( m_panel3, wxID_ANY, wxEmptyString ), wxVERTICAL );
	
	m_cmdBox = new wxTextCtrl( m_panel3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY );
	sbSizer5->Add( m_cmdBox, 1, wxEXPAND|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	wxBoxSizer* bSizer61;
	bSizer61 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText1 = new wxStaticText( m_panel3, wxID_ANY, wxT("Adres:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer61->Add( m_staticText1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_hostname = new wxTextCtrl( m_panel3, wxID_ANY, wxT("localhost"), wxDefaultPosition, wxSize( 200,-1 ), 0 );
	bSizer61->Add( m_hostname, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer61->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_btnConnect = new wxButton( m_panel3, wxID_ANY, wxT("Polacz"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer61->Add( m_btnConnect, 0, wxALIGN_RIGHT|wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer5->Add( bSizer61, 0, wxEXPAND, 5 );
	
	
	bSizer10->Add( sbSizer5, 1, wxEXPAND|wxALL, 5 );
	
	wxStaticBoxSizer* sbSizer6;
	sbSizer6 = new wxStaticBoxSizer( new wxStaticBox( m_panel3, wxID_ANY, wxEmptyString ), wxVERTICAL );
	
	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxHORIZONTAL );
	
	m_textMessage = new wxTextCtrl( m_panel3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer15->Add( m_textMessage, 1, wxALL|wxEXPAND, 5 );
	
	m_btnGenerate = new wxButton( m_panel3, wxID_ANY, wxT("Generuj"), wxDefaultPosition, wxDefaultSize, 0 );
	m_btnGenerate->Enable( false );
	
	bSizer15->Add( m_btnGenerate, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer14->Add( bSizer15, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer151;
	bSizer151 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer30;
	bSizer30 = new wxBoxSizer( wxVERTICAL );
	
	m_setEnc = new wxCheckBox( m_panel3, wxID_ANY, wxT("Szyfrowanie"), wxDefaultPosition, wxDefaultSize, 0 );
	m_setEnc->Enable( false );
	
	bSizer30->Add( m_setEnc, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_setCRC = new wxCheckBox( m_panel3, wxID_ANY, wxT("CRC"), wxDefaultPosition, wxDefaultSize, 0 );
	m_setCRC->Enable( false );
	
	bSizer30->Add( m_setCRC, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	
	bSizer151->Add( bSizer30, 0, 0, 5 );
	
	
	bSizer151->Add( 0, 0, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer32;
	bSizer32 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer31;
	bSizer31 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText2 = new wxStaticText( m_panel3, wxID_ANY, wxT("Klucz szyfrujacy:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer31->Add( m_staticText2, 0, wxALL, 5 );
	
	m_encKey = new wxSpinCtrl( m_panel3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 26, 0 );
	bSizer31->Add( m_encKey, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	
	bSizer32->Add( bSizer31, 0, 0, 5 );
	
	wxBoxSizer* bSizer33;
	bSizer33 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText5 = new wxStaticText( m_panel3, wxID_ANY, wxT("Max dlugosc pola danych w bajtach:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	bSizer33->Add( m_staticText5, 0, wxALL, 5 );
	
	m_frameLen = new wxStaticText( m_panel3, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_frameLen->Wrap( -1 );
	bSizer33->Add( m_frameLen, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	
	bSizer32->Add( bSizer33, 1, wxEXPAND, 5 );
	
	
	bSizer151->Add( bSizer32, 1, wxEXPAND, 5 );
	
	
	bSizer14->Add( bSizer151, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxVERTICAL );
	
	m_packetList = new wxListBox( m_panel3, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_HSCROLL ); 
	bSizer17->Add( m_packetList, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizer14->Add( bSizer17, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* sbSizer10;
	sbSizer10 = new wxStaticBoxSizer( new wxStaticBox( m_panel3, wxID_ANY, wxT("Typ") ), wxVERTICAL );
	
	m_textType = new wxTextCtrl( m_panel3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 25,-1 ), 0 );
	m_textType->SetMaxLength( 2 ); 
	sbSizer10->Add( m_textType, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	bSizer18->Add( sbSizer10, 0, wxTOP|wxBOTTOM, 5 );
	
	wxStaticBoxSizer* sbSizer9;
	sbSizer9 = new wxStaticBoxSizer( new wxStaticBox( m_panel3, wxID_ANY, wxT("Nr") ), wxVERTICAL );
	
	m_textNumber = new wxTextCtrl( m_panel3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 25,-1 ), 0 );
	m_textNumber->SetMaxLength( 2 ); 
	sbSizer9->Add( m_textNumber, 0, 0, 5 );
	
	
	bSizer18->Add( sbSizer9, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	wxStaticBoxSizer* sbSizer8;
	sbSizer8 = new wxStaticBoxSizer( new wxStaticBox( m_panel3, wxID_ANY, wxT("Ile") ), wxVERTICAL );
	
	m_textCount = new wxTextCtrl( m_panel3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 25,-1 ), 0 );
	m_textCount->SetMaxLength( 2 ); 
	sbSizer8->Add( m_textCount, 0, 0, 5 );
	
	
	bSizer18->Add( sbSizer8, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	wxStaticBoxSizer* sbSizer7;
	sbSizer7 = new wxStaticBoxSizer( new wxStaticBox( m_panel3, wxID_ANY, wxT("Dl") ), wxVERTICAL );
	
	m_textLength = new wxTextCtrl( m_panel3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 25,-1 ), 0 );
	m_textLength->SetMaxLength( 2 ); 
	sbSizer7->Add( m_textLength, 0, 0, 5 );
	
	
	bSizer18->Add( sbSizer7, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	wxStaticBoxSizer* sbSizer71;
	sbSizer71 = new wxStaticBoxSizer( new wxStaticBox( m_panel3, wxID_ANY, wxT("Enc") ), wxVERTICAL );
	
	m_textEnc = new wxTextCtrl( m_panel3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 25,-1 ), 0 );
	m_textEnc->SetMaxLength( 2 ); 
	sbSizer71->Add( m_textEnc, 0, 0, 5 );
	
	
	bSizer18->Add( sbSizer71, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	wxStaticBoxSizer* sbSizer711;
	sbSizer711 = new wxStaticBoxSizer( new wxStaticBox( m_panel3, wxID_ANY, wxT("CRC") ), wxVERTICAL );
	
	sbSizer711->SetMinSize( wxSize( 50,-1 ) ); 
	m_textCRC = new wxTextCtrl( m_panel3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), 0 );
	m_textCRC->SetMaxLength( 4 ); 
	sbSizer711->Add( m_textCRC, 0, 0, 5 );
	
	
	bSizer18->Add( sbSizer711, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	wxStaticBoxSizer* sbSizer712;
	sbSizer712 = new wxStaticBoxSizer( new wxStaticBox( m_panel3, wxID_ANY, wxT("Dane") ), wxVERTICAL );
	
	m_textData = new wxTextCtrl( m_panel3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), 0 );
	sbSizer712->Add( m_textData, 1, wxEXPAND, 5 );
	
	
	bSizer18->Add( sbSizer712, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer14->Add( bSizer18, 0, wxEXPAND, 5 );
	
	m_textPacket = new wxTextCtrl( m_panel3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14->Add( m_textPacket, 0, wxEXPAND|wxRIGHT|wxLEFT, 5 );
	
	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxHORIZONTAL );
	
	m_btnSend = new wxButton( m_panel3, wxID_ANY, wxT("Wyslij pojedynczo"), wxDefaultPosition, wxDefaultSize, 0 );
	m_btnSend->Enable( false );
	
	bSizer16->Add( m_btnSend, 0, wxALIGN_RIGHT|wxALL, 5 );
	
	m_btnSendAll = new wxButton( m_panel3, wxID_ANY, wxT("Wyslij wszystko"), wxDefaultPosition, wxDefaultSize, 0 );
	m_btnSendAll->Enable( false );
	
	bSizer16->Add( m_btnSendAll, 0, wxALL, 5 );
	
	
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
	m_packetList->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( MyFrame1Base::clkListPackets ), NULL, this );
	m_textType->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1Base::clkFieldChange ), NULL, this );
	m_textNumber->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1Base::clkFieldChange ), NULL, this );
	m_textCount->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1Base::clkFieldChange ), NULL, this );
	m_textLength->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1Base::clkFieldChange ), NULL, this );
	m_textEnc->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1Base::clkFieldChange ), NULL, this );
	m_textCRC->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1Base::clkFieldChange ), NULL, this );
	m_textData->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1Base::clkFieldChange ), NULL, this );
	m_btnSend->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1Base::clkSend ), NULL, this );
	m_btnSendAll->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1Base::clkSendAll ), NULL, this );
}

MyFrame1Base::~MyFrame1Base()
{
	// Disconnect Events
	m_btnConnect->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1Base::OnConnect ), NULL, this );
	m_btnGenerate->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1Base::clkGenerate ), NULL, this );
	m_packetList->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( MyFrame1Base::clkListPackets ), NULL, this );
	m_textType->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1Base::clkFieldChange ), NULL, this );
	m_textNumber->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1Base::clkFieldChange ), NULL, this );
	m_textCount->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1Base::clkFieldChange ), NULL, this );
	m_textLength->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1Base::clkFieldChange ), NULL, this );
	m_textEnc->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1Base::clkFieldChange ), NULL, this );
	m_textCRC->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1Base::clkFieldChange ), NULL, this );
	m_textData->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1Base::clkFieldChange ), NULL, this );
	m_btnSend->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1Base::clkSend ), NULL, this );
	m_btnSendAll->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1Base::clkSendAll ), NULL, this );
	
}
