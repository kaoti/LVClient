#pragma once
#include "m_GlobalHeader.h"
#include "m_ProductManager.h"

class m_MainClientClass : public wxFrame {

public: 
	m_MainClientClass();


	m_ProductManager* m_Manager = new m_ProductManager();

	wxRichTextCtrl* m_LogConsole = nullptr;
	wxButton* m_StartButton = nullptr; 
	wxButton* m_StopButton = nullptr; 
	wxButton* m_ManageProductsButton = nullptr;
	wxCheckBox* m_SendDiscordCheck = nullptr;
	wxStaticText* m_DiscordWebHookLabel = nullptr;
	wxRichTextCtrl* m_DiscordWebHook = nullptr; 
	wxStaticText* m_TimeBetweenChecksLabel = nullptr;
	wxSpinCtrl* m_TimeBetweenChecks = nullptr;
	wxStaticText* m_TimeBetweenRequestsLabel = nullptr;
	wxSpinCtrl* m_TimeBetweenRequests = nullptr;
	wxRichTextCtrl* m_ClientConsole = nullptr;
	wxListBox* m_ProductsList = nullptr; 

	wxString m_LogConsoleLogBuffer;
	wxString m_DiscordWebHookBuffer;
	wxString m_ClientConsoleBuffer;
	  
	wxVector<m_Product> m_ProductsBuffer; 
	wxDECLARE_EVENT_TABLE();
	
	  //Basic functions
	void m_ExitButtonFunction(wxCommandEvent& m_Evn);
	void m_MinimizeButtonFunction(wxCommandEvent& m_Evn);
	void m_LoadProductsFunctionCaller(wxCommandEvent& m_Evn);
	void m_SaveProductsFunctionCaller(wxCommandEvent& m_Evn);
	void m_ProductLog(m_Product& m_Prod, m_MainClientClass* m_Cont);
	//ID Enumerator
	enum m_IDs{
		ID_MainWindow,
		ID_LogConsole,
		ID_StartButton,
		ID_StopButton,
		ID_ManageProductsButton,
		ID_SendDiscordCheck,
		ID_DiscordWebHookLabel,
		ID_DiscordWebHook,
		ID_TimeBetweenChecksLabel,
		ID_TimeBetweenChecks,
		ID_TimeBetweenRequestsLabel,
		ID_TimeBetweenRequests,
		ID_ClientConsole,
		ID_ProductsList
	};
};

