#include "m_ThreadsWorker.h"

void* m_ThreadsWorker::m_ResourcesValueUpdater::Entry() {
	//Cpu stuff
	m_KUtils::CpuUsage* m_Cpu = new m_KUtils::CpuUsage();

	//Memory stuff
	MEMORYSTATUSEX memInfo;
	PROCESS_MEMORY_COUNTERS_EX pmc;

	while (true) {
		//Memory ram stuff
		memInfo.dwLength = sizeof(MEMORYSTATUSEX);
		GlobalMemoryStatusEx(&memInfo);
		GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));

		DWORDLONG m_TotalMem = memInfo.ullTotalPhys;
		SIZE_T m_RamUsed = pmc.WorkingSetSize;

		//Update labels
		m_CPUContainer.SetValue("CPU: " + std::to_string(m_Cpu->GetUsage()) + "%");
		m_RAMContainer.SetValue("RAM USED: " + std::to_string(((long double)m_RamUsed * 100) / m_TotalMem) + "%");
		m_PKGCount.SetValue("PKGs ANALYZED: " + std::to_string(m_PackageCounter));
		Sleep(1000);
	}
}
