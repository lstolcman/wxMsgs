#include "wx/wxprec.h"

#include "mainFrame.h"


enum
{
	SERVER_ID,
	SOCKET_ID
};

mainFrame::mainFrame(wxWindow *parent) : MyFrame1Base(parent)
{

	Connect(SERVER_ID, wxEVT_SOCKET, (wxObjectEventFunction)&mainFrame::OnConnectionEvent);
	Connect(SOCKET_ID, wxEVT_SOCKET, (wxObjectEventFunction)&mainFrame::OnSocketEvent);

	// Create the address - defaults to localhost
	addr.Service(3000);
	m_server = new wxSocketServer(addr);

	// We use Ok() here to see if the server is really listening
	if (!m_server->Ok())
	{
		return;
	}

	m_cmdBox->AppendText(wxDateTime::Now().Format("%X") + " Socket server listening.\n");

	// Setup the event handler and subscribe to connection events
	m_server->SetEventHandler(*this, SERVER_ID);
	m_server->SetNotify(wxSOCKET_CONNECTION_FLAG);
	m_server->Notify(true);

	clients = 0;

	encryption = true;
	crc = true;


	m_setEncryption->SetValue(encryption);
	m_setCRC->SetValue(crc);
}


mainFrame::~mainFrame()
{
}

void mainFrame::setFrameLen(wxCommandEvent& event)
{
	m_frameLen->SetValue(m_frameLen->GetValue());
}


void mainFrame::setCRC(wxCommandEvent& event)
{
	crc = m_setCRC->GetValue();
}

void mainFrame::setEncryption(wxCommandEvent& event)
{
	encryption = m_setEncryption->GetValue();
}


void mainFrame::OnConnectionEvent(wxSocketEvent &event)
{
	m_cmdBox->AppendText(wxDateTime::Now().Format("%X") + " wxSOCKET_CONNECTION\n");


	// Accept the new connection and get the socket pointer
	wxSocketBase* sock = m_server->Accept(false);

	if (clients >= 1)
	{
		//m_server->Destroy();
		sock->Close();
		return;
	}

	// Tell the new socket how and where to process its events
	sock->SetEventHandler(*this, SOCKET_ID);
	sock->SetNotify(wxSOCKET_INPUT_FLAG | wxSOCKET_LOST_FLAG);
	sock->Notify(true);

	m_cmdBox->AppendText(wxDateTime::Now().Format("%X") + " Accepted incoming connection.\n");

	m_clConn->GetLabelText().ToULong(&clients);
	++clients;
	m_clConn->SetLabelText(wxString::Format("%i", clients));

	packets.clear();
}



void mainFrame::OnSocketEvent(wxSocketEvent& event)
{
	wxSocketBase *sock = event.GetSocket();

	// Process the event
	switch (event.GetSocketEvent())
	{
	case wxSOCKET_INPUT:
	{
		m_cmdBox->AppendText(wxDateTime::Now().Format("%X") + " wxSOCKET_INPUT\n");
		char buf[200];

		// Read the data
		sock->Read(buf, sizeof(buf));

		m_cmdBox->AppendText(wxDateTime::Now().Format("%X") + " Received: " + wxString(buf) + "\n");
		


		parsePacket(sock, buf);


		break;
	}
	case wxSOCKET_LOST:
	{
		m_cmdBox->AppendText(wxDateTime::Now().Format("%X") + " wxSOCKET_LOST\n");

		m_clConn->GetLabelText().ToULong(&clients);
		--clients;
		m_clConn->SetLabelText(wxString::Format("%i", clients));

		sock->Destroy();
		break;
	}
	}
}





void mainFrame::parsePacket(wxSocketBase *sock, char *buf)
{
	wxRegEx connect, data;
	wxString sbuf = wxString::FromUTF8(buf);
	wxString msg;

	msg.Alloc(20);
	connect.Compile("P.*");
	data.Compile("D([0-9]{2})([0-9]{2})([0-9]{2})([TN])([a-fA-F0-9]{4})(.*)");

	//connect packet incoming
	if (connect.Matches(sbuf))
	{
		if (clients > 1)
		{
			msg = "B";
		}
		else
		{
			msg = "O";
			msg += encryption ? "T" : "N";
			msg += crc ? "T" : "N";
			msg += wxString::Format("%02i", m_frameLen->GetValue());
		}

		sock->Write(msg.mbc_str(), wxStrlen(msg) + 1);
		//sock->Write(buf, sizeof(buf));

		m_cmdBox->AppendText(wxDateTime::Now().Format("%X") + " Sent: " + msg + "\n");
	}

	//data packet incoming
	if (data.Matches(sbuf))
	{
		m_cmdBox->AppendText(wxDateTime::Now().Format("%X") + " AAAAAAAAA" + "\n");
	}

}

