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
	Socket->Destroy();
}

void mainFrame::clkFieldChange(wxCommandEvent &event)
{
	wxVector<wxString> tmp = packets[event.GetSelection()];

	m_textPacket->Clear();

	wxString textType = m_textType->GetLineText(0);
	wxString textNumber = m_textNumber->GetLineText(0);
	wxString textCount = m_textCount->GetLineText(0);
	wxString textLength = m_textLength->GetLineText(0);
	wxString textEnc = m_textEnc->GetLineText(0);
	wxString textCRC = m_textCRC->GetLineText(0);
	wxString textData = m_textData->GetLineText(0);
	m_textPacket->SetLabel(textType + textNumber + textCount + textLength + textEnc + textCRC + textData);

}


void mainFrame::clkGenerate(wxCommandEvent &event)
{
	packets.clear();
	m_packetList->Clear();

	unsigned packetCount = m_textMessage->GetLineLength(0) / wxAtoi(m_frameLen->GetLabel()) + (m_textMessage->GetLineLength(0) % wxAtoi(m_frameLen->GetLabel())>0 ? 1 : 0);
	for (unsigned i = 1; i <= packetCount; i++)
	{
		//create temp vars
		wxVector<wxString> tmp;
		wxString itNum, frameNum, frameLen, ifEnc, calcCRC, tmp2, txt;

		itNum << i;
		frameNum << packetCount;
		frameLen << m_frameLen->GetLabel();
		ifEnc = m_setEnc->GetValue() ? "T" : "N";
		if (i < packetCount)
		{
			txt << m_textMessage->GetLineText(0).Mid((i - 1)*wxAtoi(frameLen), wxAtoi(frameLen));
		}
		else
		{
			txt << m_textMessage->GetLineText(0).Mid((i - 1)*wxAtoi(frameLen), m_textMessage->GetLineLength(0));
		}
		if (m_setCRC->GetValue())
		{
			std::hash<std::string> h;
			calcCRC << wxString::Format("%04x", h(txt.ToStdString())).Truncate(4);
		}
		else
		{
			calcCRC = "0000";
		}

		//add temp vars to vector
		tmp.push_back("D"); //type
		tmp.push_back(wxString::Format("%02i", wxAtoi(itNum))); //frame number
		tmp.push_back(wxString::Format("%02i", wxAtoi(frameNum))); //number of frames
		tmp.push_back(wxString::Format("%02i", wxStrlen(txt))); //data length
		tmp.push_back(ifEnc); //encryption
		tmp.push_back(calcCRC); //crc

		//data
		tmp.push_back(txt);


		//add vector to global vector
		packets.push_back(tmp);

		tmp2 << "Pakiet " << i;
		m_packetList->Append(tmp2);
	}


}



void mainFrame::clkListPackets(wxCommandEvent& event)
{
	wxVector<wxString> tmp = packets[event.GetSelection()];
	m_textType->SetLabel(tmp[0]);
	m_textNumber->SetLabel(tmp[1]);
	m_textCount->SetLabel(tmp[2]);
	m_textLength->SetLabel(tmp[3]);
	m_textEnc->SetLabel(tmp[4]);
	m_textCRC->SetLabel(tmp[5]);
	m_textData->SetLabel(tmp[6]);
	m_textPacket->SetLabel(tmp[0] + tmp[1] + tmp[2] + tmp[3] + tmp[4] + tmp[5] + tmp[6]);

}

void mainFrame::clkSendAll(wxCommandEvent &event)
{
	if (Socket && Socket->IsConnected())
	{
		for (unsigned i = 0; i < packets.size(); i++)
		{
#pragma message("FIXME: not sending all packets, only first")
			wxString txt;
			txt << packets[i][0];
			txt << packets[i][1];
			txt << packets[i][2];
			txt << packets[i][3];
			txt << packets[i][4];
			txt << packets[i][5];
			txt << packets[i][6];

			Socket->Write(txt.mbc_str(), wxStrlen(txt) + 1);
		}
		//Socket->Close();
	}

}

void mainFrame::clkSend(wxCommandEvent &event)
{


	if (Socket && Socket->IsConnected())
	{
		if (m_packetList->GetSelection() >= 0)
		{
			Socket->Write(m_textPacket->GetLineText(0).mbc_str(), wxStrlen(m_textPacket->GetLineText(0)) + 1);
		}
		//Socket->Close();
	}
}

void mainFrame::OnConnect(wxCommandEvent &event)
{
	wxString s;
	addr.Hostname(m_hostname->GetValue());
	addr.Service(3000);

	if (Socket->IsDisconnected())
	{
		s = "P";
		Socket->Connect(addr, true);
		Socket->Write(s.mbc_str(), wxStrlen(s) + 1);
	}
	else
	{
		s = "R";
		Socket->Write(s.mbc_str(), wxStrlen(s) + 1);
		Socket->Close();
		m_btnSend->Disable();
		m_btnSendAll->Disable();
		m_btnGenerate->Disable();
		m_btnConnect->SetLabelText("Polacz");
	}

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
		m_btnSendAll->Enable();
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
		m_btnSendAll->Disable();
		m_btnGenerate->Disable();
		m_btnConnect->SetLabelText("Polacz");
		m_cmdBox->AppendText(wxDateTime::Now().Format("%X") + " wxSOCKET_LOST\n");
		break;
	}
	}
}




void mainFrame::parsePacket(char *buf)
{
	wxRegEx r;
	wxString sbuf = wxString::FromUTF8(buf);

	r.Compile("O([TN])([TN])([0-9]{2})");
	if (r.Matches(sbuf))
	{
		if (r.GetMatch(sbuf, 1) == "T")
		{
			m_setEnc->Set3StateValue(wxCHK_CHECKED);
		}
		else
		{
			m_setEnc->Set3StateValue(wxCHK_UNCHECKED);
		}

		if (r.GetMatch(sbuf, 2) == "T")
		{
			m_setCRC->Set3StateValue(wxCHK_CHECKED);
		}
		else
		{
			m_setCRC->Set3StateValue(wxCHK_UNCHECKED);
		}

		int len = wxAtoi(r.GetMatch(sbuf, 3));
		m_frameLen->SetLabel(wxString::Format("%i", len));

	}

}




