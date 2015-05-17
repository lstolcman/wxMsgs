#pragma once

#include "mainFrameBase.h"

#include <wx/socket.h>
#include <wx/msgdlg.h>

class mainFrame : public MyFrame1Base
{
public:
	mainFrame(wxWindow *parent);
	~mainFrame();


	void OnConnectionEvent(wxSocketEvent &event);
	void OnSocketEvent(wxSocketEvent &event);



private:
	wxSocketServer *m_server;

	wxIPV4address addr;


};



