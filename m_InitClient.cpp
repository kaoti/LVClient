#include "m_InitClient.h"

wxIMPLEMENT_APP(m_InitClient);

bool m_InitClient::OnInit(){
	m_MainClientClass* m_Main = new m_MainClientClass();
	m_Main->Show();
	return true;
}
