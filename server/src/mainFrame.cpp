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

	//Packet data format:
	//(Type)(Num)(Count)(Len)(Enc)(CRC)(Data)
	//   1    2     3     4    5    6    7
	data.Compile("([D])([0-9]{2})([0-9]{2})([0-9]{2})([TN])([a-fA-F0-9]{4})(.*)");

	//connect packet incoming
	if (connect.Matches(sbuf))
	{
		if (clients > 1)
		{
			msg = "B";
		}
		else
		{
			msg << "O";
			msg += encryption ? "T" : "N";
			msg += crc ? "T" : "N";
			msg << wxString::Format("%02i", m_frameLen->GetValue());
		}

		sock->Write(msg.mbc_str(), wxStrlen(msg) + 1);
		//sock->Write(buf, sizeof(buf));

		m_cmdBox->AppendText(wxDateTime::Now().Format("%X") + " Sent: " + msg + "\n");
	}

	//data packet incoming
	else if (data.Matches(sbuf))
	{
		wxVector<wxString> tmp;
		std::hash<std::string> hash;
		wxString calcCRC;

		bool allPackets = true;
		bool correctCRC = true;
		bool correctEnc = true;

		//pNum - abbreviation of "packet number"
		unsigned pNum = wxAtoi(data.GetMatch(sbuf, 2));
		unsigned pCount = wxAtoi(data.GetMatch(sbuf, 3));
		unsigned pLen = wxAtoi(data.GetMatch(sbuf, 4));
		bool pEnc = data.GetMatch(sbuf, 5) == "T" ? true : false;
		wxString pCRC = data.GetMatch(sbuf, 6);
		wxString pData = data.GetMatch(sbuf, 7);

		m_cmdBox->AppendText(wxDateTime::Now().Format("%X") + " Got matched packet" + "\n");

		//add temp vars to vector
		tmp.push_back("D"); //type
		tmp.push_back(wxString::Format("%02i", pNum)); //frame number
		tmp.push_back(wxString::Format("%02i", pCount)); //number of frames
		tmp.push_back(wxString::Format("%02i", pLen)); //data length
		tmp.push_back(pEnc ? "T" : "N"); //encryption
		tmp.push_back(pCRC); //crc
		tmp.push_back(pData); //data

		calcCRC << wxString::Format("%04x", hash(pData.ToStdString())).Truncate(4);

		if (pCRC.compare(calcCRC) != 0)
		{
			correctCRC = false;
		}

		if (packets.empty() || packets.size() != pCount)
		{
			packets.clear();
			packets.resize(pCount);
		}


		//insert new packet in place of old
		std::list<wxVector<wxString>>::iterator iter = packets.begin();
		std::advance(iter, pNum - 1);
		packets.insert(iter, tmp);
		packets.erase(iter);

		m_cmdBox->AppendText(wxDateTime::Now().Format("%X") + " size: " + wxString::Format("%i", packets.size()) + "\n");


		//check if we have all packets with correct crc and encoding
		for (auto i : packets)
		{
			if (i.size() == 0)
			{
				allPackets = false;
				break;
			}
		}

		//then, decode message
		if (allPackets && correctCRC && correctEnc)
		{
#pragma message("TODO: CRC, encoding check")
			m_cmdBox->AppendText(wxDateTime::Now().Format("%X") + " Zdekodowany pakiet: ");
			for (auto i : packets)
			{
				m_cmdBox->AppendText(i[6]);
			}
			m_cmdBox->AppendText("\n");
		}

	}
	else
	{

	}

}

