#pragma once
#include <windows.h>
#include <wx/setup.h>
#include <wx/wx.h>
class m_KUtils {
public:
	static void m_UpdateConsole(wxRichTextCtrl& m_RegularLog, wxString m_Log, wxString& m_ConsoleLogBuffer, wxColor m_Color, bool m_Bold) {
		if (m_Bold) {
			m_ConsoleLogBuffer.append(m_Log + "\n");
			m_RegularLog.BeginTextColour(m_Color);
			m_RegularLog.BeginBold();
			m_RegularLog.WriteText(m_Log + "\n");
			m_RegularLog.EndTextColour();
			m_RegularLog.EndBold();
		}
		else {
			m_ConsoleLogBuffer.append(m_Log);
			m_RegularLog.BeginTextColour(m_Color);
			m_RegularLog.WriteText(m_Log + "\n");
			m_RegularLog.EndTextColour();
		}
	}
public:
	class CpuUsage {

	public:
		inline bool IsFirstRun() const { return (m_dwLastRun == 0); }

		//system total times
		FILETIME m_ftPrevSysKernel;
		FILETIME m_ftPrevSysUser;

		//process times
		FILETIME m_ftPrevProcKernel;
		FILETIME m_ftPrevProcUser;

		short m_nCpuUsage;
		ULONGLONG m_dwLastRun;

		volatile LONG m_lRunCount;

		CpuUsage() : m_nCpuUsage(-1), m_dwLastRun(0), m_lRunCount(0) {
			ZeroMemory(&m_ftPrevSysKernel, sizeof(FILETIME));
			ZeroMemory(&m_ftPrevSysUser, sizeof(FILETIME));

			ZeroMemory(&m_ftPrevProcKernel, sizeof(FILETIME));
			ZeroMemory(&m_ftPrevProcUser, sizeof(FILETIME));

		}
		short GetUsage() {
			short nCpuCopy = m_nCpuUsage;
			if (::InterlockedIncrement(&m_lRunCount) == 1) {
				if (!EnoughTimePassed()) {
					::InterlockedDecrement(&m_lRunCount);
					return nCpuCopy;
				}

				FILETIME ftSysIdle, ftSysKernel, ftSysUser;
				FILETIME ftProcCreation, ftProcExit, ftProcKernel, ftProcUser;

				if (!GetSystemTimes(&ftSysIdle, &ftSysKernel, &ftSysUser) ||
					!GetProcessTimes(GetCurrentProcess(), &ftProcCreation, &ftProcExit, &ftProcKernel, &ftProcUser)) {
					::InterlockedDecrement(&m_lRunCount);
					return nCpuCopy;
				}

				if (!IsFirstRun()) {
					ULONGLONG ftSysKernelDiff = SubtractTimes(ftSysKernel, m_ftPrevSysKernel);
					ULONGLONG ftSysUserDiff = SubtractTimes(ftSysUser, m_ftPrevSysUser);

					ULONGLONG ftProcKernelDiff = SubtractTimes(ftProcKernel, m_ftPrevProcKernel);
					ULONGLONG ftProcUserDiff = SubtractTimes(ftProcUser, m_ftPrevProcUser);

					ULONGLONG nTotalSys = ftSysKernelDiff + ftSysUserDiff;
					ULONGLONG nTotalProc = ftProcKernelDiff + ftProcUserDiff;

					if (nTotalSys > 0) {
						m_nCpuUsage = (short)((100.0 * nTotalProc) / nTotalSys);
					}
				}

				m_ftPrevSysKernel = ftSysKernel;
				m_ftPrevSysUser = ftSysUser;
				m_ftPrevProcKernel = ftProcKernel;
				m_ftPrevProcUser = ftProcUser;

				m_dwLastRun = GetTickCount64();

				nCpuCopy = m_nCpuUsage;
			}

			::InterlockedDecrement(&m_lRunCount);

			return nCpuCopy;
		}

		ULONGLONG SubtractTimes(const FILETIME& ftA, const FILETIME& ftB) {
			LARGE_INTEGER a, b;
			a.LowPart = ftA.dwLowDateTime;
			a.HighPart = ftA.dwHighDateTime;

			b.LowPart = ftB.dwLowDateTime;
			b.HighPart = ftB.dwHighDateTime;

			return a.QuadPart - b.QuadPart;
		}

		bool EnoughTimePassed() {
			const int minElapsedMS = 250;

			ULONGLONG dwCurrentTickCount = GetTickCount64();

			return (dwCurrentTickCount - m_dwLastRun) > minElapsedMS;
		}
	public:

	};
};