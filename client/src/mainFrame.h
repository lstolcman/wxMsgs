#pragma once

#include "mainFrameBase.h"

#include <wx/socket.h>
#include <wx/msgdlg.h>
#include <wx/time.h>
#include <wx/regex.h>


class mainFrame : public MyFrame1Base
{
public:
	mainFrame(wxWindow *parent);
	~mainFrame();


	void OnConnect(wxCommandEvent &event);
	void OnSocketEvent(wxSocketEvent &event);

	void OnSend(wxCommandEvent &event);

	void clkGenerate(wxCommandEvent &event);


private:
	wxSocketClient* Socket;
	wxIPV4address addr;

};



