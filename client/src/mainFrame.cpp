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
}



mainFrame::~mainFrame()
{
	delete Socket;

}


void mainFrame::SendClk(wxCommandEvent &event)
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
		Socket->Write(buf, sizeof(buf));
	}

}

void mainFrame::OnConnectToServer(wxCommandEvent &event)
{
	addr.Hostname(m_hostname->GetValue());
	addr.Service(3000);

	if (Socket->IsDisconnected())
	{
		Socket->Connect(addr, true);
		m_btnSend->Enable(true);
	}


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
		break;
	}
	case wxSOCKET_INPUT:
	{
		break;
	}

	// The server hangs up after sending the data
	case wxSOCKET_LOST:
	{
		m_btnSend->Enable(false);
		break;
	}
	}
}


