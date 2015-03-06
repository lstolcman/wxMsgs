
#include "mainFrame.h"



/*mainFrame::mainFrame(wxWindow *parent) : MyFrame1Base(parent)
{

}


mainFrame::~mainFrame()
{

}
*/


void mainFrame::ButtonClk(wxCommandEvent& event)
{
	m_button4->SetLabel("A");

	wxTreeItemId rootId = m_treeCtrl1->AddRoot("root");

	wxTreeItemId itemId1 = m_treeCtrl1->AppendItem(rootId, wxT("File item 1"), 1, 1);

	wxTreeItemId itemId2 = m_treeCtrl1->AppendItem(itemId1, wxT("File item 2"), 1, 1);
	wxTreeItemId itemId21 = m_treeCtrl1->AppendItem(rootId, wxT("File item 21"), 1, 1);

	wxTreeItemId itemId22 = m_treeCtrl1->AppendItem(itemId21, wxT("File item 22"), 1, 1);



}


