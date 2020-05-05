#include "m_MainClientClass.h"

wxBEGIN_EVENT_TABLE(m_MainClientClass, wxFrame)
EVT_BUTTON(ID_ManageProductsButton, m_MainClientClass::m_SaveProductsFunctionCaller)
EVT_BUTTON(ID_StopButton, m_MainClientClass::m_LoadProductsFunctionCaller)
wxEND_EVENT_TABLE()

m_MainClientClass::m_MainClientClass() : wxFrame(nullptr, ID_MainWindow, "Chat UI", wxPoint(100, 200), wxSize(1000, 600)) {
	SetBackgroundColour(m_Black);

	wxFont* m_GlobalFont = new wxFont(8, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_SEMIBOLD);
	this->SetFont(*m_GlobalFont);

	m_LogConsole = new wxRichTextCtrl(this, ID_LogConsole, m_LogConsoleLogBuffer, wxPoint(20, 20), wxSize((this->GetSize().x / 3) - 20, this->GetSize().y - 80), wxRE_READONLY | wxRE_MULTILINE);
	m_LogConsole->SetBackgroundColour(m_Black);
	m_LogConsole->SetForegroundColour(m_ConsoleLightBlue);

	m_StartButton = new wxButton(this, ID_StartButton, "START", wxPoint(m_LogConsole->GetSize().x + 30, 20), wxSize((this->GetSize().x / 3), 35));
	m_StartButton->SetBackgroundColour(m_Black);
	m_StartButton->SetForegroundColour(m_ConsoleLightBlue);

	m_StopButton = new wxButton(this, ID_StopButton, "STOP", wxPoint(m_LogConsole->GetSize().x + 30, m_StartButton->GetSize().y + 30), wxSize((this->GetSize().x / 3), 35));
	m_StopButton->SetBackgroundColour(m_Black);
	m_StopButton->SetForegroundColour(m_ConsoleLightBlue);

	m_ManageProductsButton = new wxButton(this, ID_ManageProductsButton, "MANAGE PRODUCTS", wxPoint(m_LogConsole->GetSize().x + 30, m_StartButton->GetSize().y + 76), wxSize((this->GetSize().x / 3), 35));
	m_ManageProductsButton->SetBackgroundColour(m_Black);
	m_ManageProductsButton->SetForegroundColour(m_ConsoleLightBlue);

	m_SendDiscordCheck = new wxCheckBox(this, ID_SendDiscordCheck, "LOG DISCORD", wxPoint(m_LogConsole->GetSize().x + 30, m_StartButton->GetSize().y + 120), wxSize((this->GetSize().x / 3), 10));
	m_SendDiscordCheck->SetForegroundColour(m_ConsoleLightBlue);

	m_DiscordWebHookLabel = new wxStaticText(this, ID_DiscordWebHookLabel, "DISCORD WEB HOOK CODE:", wxPoint(m_LogConsole->GetSize().x + 30, m_StopButton->GetSize().y + 140), wxSize((this->GetSize().x / 3), 20));
	m_DiscordWebHookLabel->SetForegroundColour(m_ConsoleLightBlue);

	m_DiscordWebHook = new wxRichTextCtrl(this, ID_DiscordWebHook, m_DiscordWebHookBuffer, wxPoint(m_LogConsole->GetSize().x + 30, m_DiscordWebHookLabel->GetPosition().y + 20), wxSize((this->GetSize().x / 3), 50), wxRE_MULTILINE);
	m_DiscordWebHook->SetBackgroundColour(m_Black);
	m_DiscordWebHook->BeginTextColour(m_ConsoleLightBlue);
	m_DiscordWebHook->WriteText("DELETE THIS AND ENTER HERE YOUR DISCORD SERVER ROOM ID");
	m_DiscordWebHook->EndTextColour();
	
	m_TimeBetweenChecksLabel = new wxStaticText(this, ID_TimeBetweenChecksLabel, "TIME BETWEEN CHECKS (S):", wxPoint(m_LogConsole->GetSize().x + 30, m_DiscordWebHook->GetPosition().y + 70), wxSize(this->GetSize().x/3, 20));
	m_TimeBetweenChecksLabel->SetBackgroundColour(m_Black);
	m_TimeBetweenChecksLabel->SetForegroundColour(m_ConsoleLightBlue);

	m_TimeBetweenChecks = new wxSpinCtrl(this, ID_TimeBetweenChecks, "", wxPoint(m_LogConsole->GetSize().x + 32.5f, m_DiscordWebHook->GetPosition().y + 90), wxSize((this->GetSize().x / 3), 20), wxSP_ARROW_KEYS | wxTE_PROCESS_ENTER, 0, 5000, 2);
	m_TimeBetweenChecks->SetBackgroundColour(m_Black);
	m_TimeBetweenChecks->SetForegroundColour(m_ConsoleLightBlue);

	m_TimeBetweenRequestsLabel = new wxStaticText(this, ID_TimeBetweenRequestsLabel, "TIME BETWEEN REQUEST (MS):", wxPoint(m_LogConsole->GetSize().x + 30, m_TimeBetweenChecks->GetPosition().y + 30), wxSize(this->GetSize().x / 3, 20));
	m_TimeBetweenRequestsLabel->SetBackgroundColour(m_Black);
	m_TimeBetweenRequestsLabel->SetForegroundColour(m_ConsoleLightBlue);

	m_TimeBetweenRequests = new wxSpinCtrl(this, ID_TimeBetweenRequests, "", wxPoint(m_LogConsole->GetSize().x + 32.5f, m_TimeBetweenRequestsLabel->GetPosition().y + 20), wxSize((this->GetSize().x / 3), 20), wxSP_ARROW_KEYS | wxTE_PROCESS_ENTER, 0, 5000000, 100);
	m_TimeBetweenRequests->SetBackgroundColour(m_Black);
	m_TimeBetweenRequests->SetForegroundColour(m_ConsoleLightBlue);
	m_ProductsBuffer.push_back(m_Product("x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x"));

	this->Refresh();
}
 
void m_MainClientClass::m_ExitButtonFunction(wxCommandEvent& m_Evn){

}

void m_MainClientClass::m_MinimizeButtonFunction(wxCommandEvent& m_Evn){

}
void m_MainClientClass::m_LoadProductsFunctionCaller(wxCommandEvent& m_Evn) {
	m_Manager->m_LoadFromFile(m_ProductsBuffer, m_LogConsoleLogBuffer, m_LogConsole);
}
void m_MainClientClass::m_SaveProductsFunctionCaller(wxCommandEvent& m_Evn){
	m_Manager->m_SaveToFileList(m_ProductsBuffer, m_LogConsoleLogBuffer, m_LogConsole);
}

void m_MainClientClass::m_ProductLog(m_Product& m_Prod, m_MainClientClass* m_Cont) {
	m_Cont->m_ProductsBuffer.push_back(m_Prod);
}