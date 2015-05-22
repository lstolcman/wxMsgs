#pragma once

#include "mainFrameBase.h"

#include <wx/socket.h>
#include <wx/msgdlg.h>
#include <wx/time.h>
#include <wx/regex.h>
#include <wx/vector.h>

#include <functional>


class mainFrame : public MyFrame1Base
{
public:
	mainFrame(wxWindow *parent);
	~mainFrame();


	void OnConnect(wxCommandEvent &event);
	void OnSocketEvent(wxSocketEvent &event);

	void clkSend(wxCommandEvent &event);
	void clkSendAll(wxCommandEvent &event);
	void clkGenerate(wxCommandEvent &event);
	void clkListPackets(wxCommandEvent& event);
	void clkFieldChange(wxCommandEvent& event);

	void parsePacket(char* buf);

private:
	wxSocketClient* Socket;
	wxIPV4address addr;


	wxVector<wxVector<wxString>> packets;


};



