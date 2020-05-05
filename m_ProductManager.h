#pragma once
#define RAPIDJSON_NO_SIZETYPEDEFINE

#include <cstdio>
#include <string>
class m_ProductManager {
public:
	void m_LoadFromFile(wxVector<m_Product>& m_List, wxString& m_LogBuffer, wxRichTextCtrl* m_Main) {
		
		std::ifstream m_InData("ProductData.KObj");
		
	}
	void m_SaveToFileList(wxVector<m_Product>& m_List, wxString& m_LogBuffer, wxRichTextCtrl* m_Main) {
	}
	//}
};

