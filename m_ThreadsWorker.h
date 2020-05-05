#pragma once
#include "m_GlobalHeader.h"

class m_ThreadsWorker{
	class m_ResourcesValueUpdater : public wxThread {
	public:
		wxTextCtrl& m_CPUContainer;
		wxTextCtrl& m_RAMContainer;
		wxTextCtrl& m_PKGCount;
		int m_PackageCounter;

		m_ResourcesValueUpdater(wxTextCtrl& m_CPU, wxTextCtrl& m_RAM, int& m_PKG, wxTextCtrl& m_PackageCounterLabelref)
			: m_CPUContainer(m_CPU), m_RAMContainer(m_RAM), m_PackageCounter(m_PKG), m_PKGCount(m_PackageCounterLabelref) {}

		void* Entry();
	};

};

