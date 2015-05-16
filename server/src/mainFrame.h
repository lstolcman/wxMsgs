#pragma once

#include "mainFrameBase.h"

#include <wx/socket.h>
#include <wx/msgdlg.h>

class mainFrame : public MyFrame1Base
{
public:
	mainFrame(wxWindow *parent);
	~mainFrame();


	void OnServerEvent(wxSocketEvent &event);
	void OnSocketEvent(wxSocketEvent &event);

	void StartClk(wxCommandEvent &event);


private:
	wxSocketServer *m_server;


};



