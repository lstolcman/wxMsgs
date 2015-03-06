#pragma once

#include "mainFrameBase.h"


class mainFrame : public MyFrame1Base
{
public:
	mainFrame(wxWindow *parent) : MyFrame1Base(parent) {};
	//virtual ~mainFrame() {};
	virtual void ButtonClk(wxCommandEvent& event);

};



