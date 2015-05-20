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


	/*
	wxRegEx r;
	wxString regula = "O([TN])([TN])([0-9]{2})";
	wxString s = "OTT09";

	r.Compile(regula);
	if (r.Matches(s))
	{
	m_cmdBox->AppendText(r.GetMatch(s, 0) + "\n");
	m_cmdBox->AppendText(r.GetMatch(s, 1) + "\n");
	m_cmdBox->AppendText(r.GetMatch(s, 2) + "\n");
	m_cmdBox->AppendText(r.GetMatch(s, 3) + "\n");
	}
	*/

	root = m_packetTree->AddRoot("");
	m_listBox2->Append("asdf");
	m_listBox2->Append("asdf");
	m_listBox2->Append("asdf");
}



mainFrame::~mainFrame()
{
	Socket->Destroy();
}

void mainFrame::aaa(wxCommandEvent& event)
{
	wxString a;
	a << event.GetSelection();
	wxMessageBox(a);

}
void mainFrame::clkGenerate(wxCommandEvent &event)
{

	/*
	wxString a;
	a << "dlugosc linii: ";
	a << m_textMessage->GetLineLength(0);
	a << "\n";
	a << "max dlugosc danych: ";
	a << wxAtoi(m_frameLen->GetLabel());
	a << "\n";
	a << "modulo: ";
	a << m_textMessage->GetLineLength(0) % wxAtoi(m_frameLen->GetLabel());
	a << "\n";
	a << "dzielenie +1: ";
	a << m_textMessage->GetLineLength(0) / wxAtoi(m_frameLen->GetLabel())+1;
	wxMessageBox(a);
	*/

	packets.clear();

	m_packetTree->DeleteChildren(root);
	unsigned packetCount = m_textMessage->GetLineLength(0) / wxAtoi(m_frameLen->GetLabel()) + 1;
	for (unsigned i = 1; i <= packetCount; i++)
	{
		wxVector<wxString> tmp;
		//create temp vars
		wxString itNum, frameNum, lastDataSize, dataSize, ifEnc, calcCRC;
		itNum << i;
		frameNum << packetCount;
		lastDataSize << m_textMessage->GetLineLength(0) % wxAtoi(m_frameLen->GetLabel());
		dataSize << packetCount - 1;
		ifEnc = m_setEnc->GetValue() ? "T" : "N";
		if (m_setCRC->GetValue())
		{
			calcCRC = hash(wxString::Format("iter=%i", i));
		}
		else
		{
			calcCRC = "0000";
		}

		//add temp vars to vector
		tmp.push_back("D"); //type
		tmp.push_back(itNum); //frame number
		tmp.push_back(frameNum); //number of frames
		if (i == packetCount)
			tmp.push_back(lastDataSize); //data length
		else
			tmp.push_back(dataSize); //data length
		tmp.push_back(ifEnc); //encryption
		tmp.push_back(calcCRC); //crc
		tmp.push_back(wxString::Format("iter=%i", i)); //data

		//add vector to global vector
		packets.push_back(tmp);

		m_packetTree->AppendItem(root, itNum);
	}







}

void mainFrame::tree(wxMouseEvent& event)
{
	int flags;

	//check mouse button click on text ctrl field
	//wxTreeItemId item = m_packetTree->HitTest(event.GetPoint(), flags);
	wxTreeItemId item = m_packetTree->HitTest(event.GetPosition(), flags);
	//check if mouse hit any item
	if (item.IsOk() && !(flags & wxTREE_HITTEST_ONITEMRIGHT))
	{
		//get item name and convert to int
		int packetId = wxAtoi(m_packetTree->GetItemText(item)) - 1;
		m_packetTree->SelectItem(item);
		m_packetTree->SetFocusedItem(item);

		wxVector<wxString> tmp = packets[packetId];
		m_textType->SetLabel(tmp[0]);
		m_textNumber->SetLabel(tmp[1]);
		m_textCount->SetLabel(tmp[2]);
		m_textLength->SetLabel(tmp[3]);
		m_textEnc->SetLabel(tmp[4]);
		m_textCRC->SetLabel(tmp[5]);
		m_textData->SetLabel(tmp[6]);
		m_textPacket->SetLabel(tmp[0] + tmp[1] + tmp[2] + tmp[3] + tmp[4] + tmp[5] + tmp[6]);
	}
}


void mainFrame::clkSend(wxCommandEvent &event)
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
		Socket->Write(s.mbc_str(), wxStrlen(s) + 1);
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
	char buf[200];

	switch (event.GetSocketEvent())
	{
	case wxSOCKET_CONNECTION:
	{
		m_cmdBox->AppendText(wxDateTime::Now().Format("%X") + " wxSOCKET_CONNECTION\n");
		m_btnSend->Enable();
		m_btnGenerate->Enable();
		m_btnConnect->SetLabelText("Rozlacz");
		break;
	}
	case wxSOCKET_INPUT:
	{
		sock->Read(buf, sizeof(buf));


		parsePacket(buf);

		m_cmdBox->AppendText(wxDateTime::Now().Format("%X") + " wxSOCKET_INPUT: " + wxString(buf) + "\n");
		break;
	}

	// The server hangs up after sending the data
	case wxSOCKET_LOST:
	{
		m_btnSend->Disable();
		m_btnGenerate->Disable();
		m_btnConnect->SetLabelText("Polacz");
		m_cmdBox->AppendText(wxDateTime::Now().Format("%X") + " wxSOCKET_LOST\n");
		break;
	}
	}
}




wxString mainFrame::parsePacket(char *buf)
{
	wxRegEx r;

	wxString sbuf = wxString::FromUTF8(buf);

	wxString regula = "O([TN])([TN])([0-9]{2})";

	r.Compile("O([TN])([TN])([0-9]{2})");
	if (r.Matches(sbuf))
	{
		if (r.GetMatch(sbuf, 1) == "T") m_setEnc->Set3StateValue(wxCHK_CHECKED);
		else m_setEnc->Set3StateValue(wxCHK_UNCHECKED);

		if (r.GetMatch(sbuf, 2) == "T") m_setCRC->Set3StateValue(wxCHK_CHECKED);
		else m_setCRC->Set3StateValue(wxCHK_UNCHECKED);

		int len = wxAtoi(r.GetMatch(sbuf, 3));
		m_frameLen->SetLabel(wxString::Format("%i", len));

	}


	wxString msg;
	msg.Alloc(200);

	msg = "U";


	return msg;
}


wxString mainFrame::hash(wxString data)
{
	wxString out;
	unsigned int hash, i;
	for (hash = i = 0; i < wxStrlen(data); ++i)
	{
		hash += data.mbc_str()[i];
		hash += (hash << 10);
		hash ^= (hash >> 6);
	}
	hash += (hash << 3);
	hash ^= (hash >> 11);
	hash += (hash << 15);

	return wxString::Format("%04x", hash).Truncate(4);
}


