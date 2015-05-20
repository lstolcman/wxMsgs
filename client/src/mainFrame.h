#pragma once

#include "mainFrameBase.h"

#include <wx/socket.h>
#include <wx/msgdlg.h>
#include <wx/time.h>
#include <wx/regex.h>

#include <wx/vector.h>
#include <wx/hash.h>


class mainFrame : public MyFrame1Base
{
public:
	mainFrame(wxWindow *parent);
	~mainFrame();


	void OnConnect(wxCommandEvent &event);
	void OnSocketEvent(wxSocketEvent &event);

	void clkSend(wxCommandEvent &event);
	void clkGenerate(wxCommandEvent &event);
	void tree(wxMouseEvent& event);
	void aaa(wxCommandEvent& event);

	wxString parsePacket(char* buf);
	wxString hash(wxString data);

private:
	wxSocketClient* Socket;
	wxIPV4address addr;

	wxTreeItemId root;

	wxVector<wxVector<wxString>> packets;


};



