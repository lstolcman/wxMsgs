#include "wx/wxprec.h"

#include "mainFrame.h"


enum
{
	SERVER_ID,
	SOCKET_ID
};

mainFrame::mainFrame(wxWindow *parent) : MyFrame1Base(parent)
{

	Connect(SERVER_ID, wxEVT_SOCKET, (wxObjectEventFunction)&mainFrame::OnServerEvent);
	Connect(SOCKET_ID, wxEVT_SOCKET, (wxObjectEventFunction)&mainFrame::OnSocketEvent);

}


mainFrame::~mainFrame()
{
	delete m_server;
}



void mainFrame::StartClk(wxCommandEvent &event)
{
	// Create the address - defaults to localhost
	wxIPV4address addr;
	addr.Service(3000);

	// Create the socket, we maintain a class pointer so we can shut it down
	m_server = new wxSocketServer(addr);

	// We use Ok() here to see if the server is really listening
	if (!m_server->Ok())
	{
		return;
	}

	m_cmdBox->AppendText(_("\nSocket server listening.\n"));

	// Setup the event handler and subscribe to connection events
	m_server->SetEventHandler(*this, SERVER_ID);
	m_server->SetNotify(wxSOCKET_CONNECTION_FLAG);
	m_server->Notify(true);
}





void mainFrame::OnServerEvent(wxSocketEvent &event)
{
	// Accept the new connection and get the socket pointer
	wxSocketBase* sock = m_server->Accept(false);

	// Tell the new socket how and where to process its events
	sock->SetEventHandler(*this, SOCKET_ID);
	sock->SetNotify(wxSOCKET_INPUT_FLAG | wxSOCKET_LOST_FLAG);
	sock->Notify(true);

	m_cmdBox->AppendText(_("\nAccepted incoming connection.\n"));
}



void mainFrame::OnSocketEvent(wxSocketEvent& event)
{
	wxSocketBase *sock = event.GetSocket();

	// Process the event
	switch (event.GetSocketEvent())
	{
	case wxSOCKET_INPUT:
	{
		char buf[10];

		// Read the data
		sock->Read(buf, sizeof(buf));

		m_cmdBox->AppendText(wxString(_("Received from client: ")) + wxString(buf, wxConvUTF8, 10) + _("\n"));

		// Write it back
		sock->Write(buf, sizeof(buf));

		m_cmdBox->AppendText(_("Wrote string back to client.\n"));

		// We are done with the socket, destroy it
		sock->Destroy();

		break;
	}
	case wxSOCKET_LOST:
	{
		sock->Destroy();
		break;
	}
	}
}


