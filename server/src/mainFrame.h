#pragma once

#include "mainFrameBase.h"

#include <wx/socket.h>
#include <wx/msgdlg.h>
#include <wx/regex.h>
#include <list>
#include <iostream>
#include <functional>

class mainFrame : public MyFrame1Base
{
public:
	mainFrame(wxWindow *parent);
	~mainFrame();


	void OnConnectionEvent(wxSocketEvent&);
	void OnSocketEvent(wxSocketEvent&);

	void setFrameLen(wxCommandEvent&);
	void setCRC(wxCommandEvent&);
	void setEncryption(wxCommandEvent&);

	void parsePacket(wxSocketBase*, char*);

private:
	wxSocketServer *m_server;

	wxIPV4address addr;

	unsigned long clients;

	bool encryption;
	bool crc;

	std::list<wxVector<wxString>> packets;

};



