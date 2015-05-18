#include "wx/wxprec.h"

#include "mainFrame.h"


enum
{
	SOCKET_ID
};

mainFrame::mainFrame(wxWindow *parent) : MyFrame1Base(parent)
{
	//http://www.codeprogress.com/cpp/libraries/wxwidgets/showWxExample.php?index=57&key=wxSocketClientSMTP
	Connect(SOCKET_ID, wxEVT_SOCKET, (wxObjectEventFunction)&mainFrame::OnSocketEvent);

	// Create the socket
	Socket = new wxSocketClient();

	// Set up the event handler and subscribe to most events
	Socket->SetEventHandler(*this, SOCKET_ID);
	Socket->SetNotify(wxSOCKET_CONNECTION_FLAG | wxSOCKET_INPUT_FLAG | wxSOCKET_LOST_FLAG);
	Socket->Notify(true);


	wxRegEx r;
	r.Compile("Start");
	wxString s = "start";
	if (r.Matches(s))
	m_cmdBox->AppendText(r.GetMatch(s, 0));

	treeRoot = m_packetTree->AddRoot("");
	m_packetTree->AppendItem(treeRoot, "asd");
	m_packetTree->AppendItem(treeRoot, "asd");
	m_packetTree->AppendItem(treeRoot, "asd");
	m_packetTree->AppendItem(treeRoot, "asd");
	m_packetTree->AppendItem(treeRoot, "asd");

	m_setEnc->Set3StateValue(wxCHK_CHECKED);
	m_setCRC->Set3StateValue(wxCHK_CHECKED);

}



mainFrame::~mainFrame()
{
	Socket->Destroy();
}

void mainFrame::clkGenerate(wxCommandEvent &event)
{





}

void mainFrame::OnSend(wxCommandEvent &event)
{

	if (Socket && Socket->IsConnected())
	{
		char buf[10];
		// Fill the arry with the numbers 0 through 9 as characters
		char mychar = '0';
		for (int i = 0; i < 10; i++)
		{
			buf[i] = mychar++;
		}

		// Send the characters to the server

		strcpy(buf, "conn\n");
		//Socket->Write(buf, sizeof(buf));
		wxString s = "test str";
		Socket->Write(s.mbc_str(), wxStrlen(s)+1);
		//Socket->Close();
	}

}

void mainFrame::OnConnect(wxCommandEvent &event)
{
	addr.Hostname(m_hostname->GetValue());
	addr.Service(3000);

	if (Socket->IsDisconnected())
	{
		Socket->Connect(addr, true);
		wxString s = "P";
		Socket->Write(s.mbc_str(), wxStrlen(s) + 1);
	}
	else
	{
		wxString s = "R";
		Socket->Write(s.mbc_str(), wxStrlen(s) + 1);
		Socket->Close();
		m_btnSend->Disable();
		m_btnGenerate->Disable();
		m_btnConnect->SetLabelText("Polacz");
	}


	if (Socket->IsClosed()) m_cmdBox->AppendText("isClosed\n");
	if (Socket->IsConnected()) m_cmdBox->AppendText("isConnected\n");
	if (Socket->IsDisconnected()) m_cmdBox->AppendText("isDisconnected\n");
	if (Socket->IsInitialized()) m_cmdBox->AppendText("isInitialized\n");
	if (Socket->IsOk()) m_cmdBox->AppendText("isOk\n");


}


void mainFrame::OnSocketEvent(wxSocketEvent& event)
{
	// The socket that had the event
	wxSocketBase* sock = event.GetSocket();

	// Common buffer shared by the events
	char buf[10];

	switch (event.GetSocketEvent())
	{
	case wxSOCKET_CONNECTION:
	{
		m_cmdBox->AppendText(wxDateTime::Now().Format("%X")+" wxSOCKET_CONNECTION\n");
		m_btnSend->Enable();
		m_btnGenerate->Enable();
		m_btnConnect->SetLabelText("Rozlacz");
		break;
	}
	case wxSOCKET_INPUT:
	{
		sock->Read(buf, sizeof(buf));
		m_cmdBox->AppendText(wxDateTime::Now().Format("%X")+" wxSOCKET_INPUT: "+wxString(buf)+"\n");
		break;
	}

	// The server hangs up after sending the data
	case wxSOCKET_LOST:
	{
		m_btnSend->Disable();
		m_btnGenerate->Disable();
		m_btnConnect->SetLabelText("Polacz");
		m_cmdBox->AppendText(wxDateTime::Now().Format("%X")+" wxSOCKET_LOST\n");
		break;
	}
	}
}


