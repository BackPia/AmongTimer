#include "Tools.h"
#include "pch.h"
#include "framework.h"
#include "AmongTimer.h"
#include "AmongTimerDlg.h"
#include "afxdialogex.h"

//=====================  INI 관련  ========================

CString GetExePath(void)
{
	static TCHAR pBuf[256] = { 0, };
	memset(pBuf, NULL, sizeof(pBuf));
	GetModuleFileName(NULL, pBuf, sizeof(pBuf)); //현재 실행 경로를 가져오는 함수

	CString strFilePath;
	strFilePath.Format(_T("%s"), pBuf);
	strFilePath = strFilePath.Left(strFilePath.ReverseFind(_T('\\')));

	return strFilePath;
}

CString INIReadString(CString strAppName, CString strKeyName, CString strFilePath)
{
	char szReturnString[1024] = { 0, };
	memset(szReturnString, NULL, 1024);
	CString str_t;
	str_t.Format(_T("%s"), szReturnString);
	GetPrivateProfileString(strAppName, strKeyName, _T(""), str_t.GetBuffer(), 1024, strFilePath);
	CString str;
	str.Format(_T("%s"), szReturnString);

	return str;
}

void INIWriteString(CString strAppName, CString strKeyName, CString strValue, CString strFilePath)
{
	WritePrivateProfileString(strAppName, strKeyName, strValue, strFilePath);
}

//===================== 형변환 ==================

void CStringToChar(CString str, char** ptr)
{
	int n = str.GetLength();
	*ptr = new char[n + 1];
	WideCharToMultiByte(CP_ACP, 0, str, -1, *ptr, n + 1, NULL, NULL);
}