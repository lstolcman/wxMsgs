#pragma once

#include "mainFrameBase.h"

#include <wx/socket.h>
#include <wx/msgdlg.h>
#include <wx/time.h>


class mainFrame : public MyFrame1Base
{
public:
	mainFrame(wxWindow *parent);
	~mainFrame();


	void OnConnectToServer(wxCommandEvent &event);
	void OnSocketEvent(wxSocketEvent &event);

	void SendClk(wxCommandEvent &event);


private:
	wxSocketClient* Socket;
	wxIPV4address addr;

};



