#define CURL_STATICLIB
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <curl/curl.h>
#include <iostream>
#include <wx/wx.h>
#include <wx/richtext/richtextctrl.h>
#include "m_MainClientClass.h"
#include <wx/spinctrl.h>
#include "m_KUtils.h"
#include <psapi.h>
#include <fstream>
#include <utility>
#include "m_ProductHeader.h"

#pragma region R_Defines
#define Any wxID_ANY
#define Size wxWindow::GetSize()
#define m_ConsoleGreen wxColor(0, 255, 34)
#define m_ConsoleLightBlue wxColor(0, 162,255)
#define m_Black wxColor(0,0,0)
#pragma endregion

