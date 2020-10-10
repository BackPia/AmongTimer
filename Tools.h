#pragma once
#include "resource.h"
#ifndef __TOOLS__
#define __TOOLS__
#endif // !__TOOLS__


CString GetExePath(void);
CString INIReadString(CString strAppName, CString strKeyName, CString strFilePath);
void INIWriteString(CString strAppName, CString strKeyName, CString strValue, CString strFilePath);

void CStringToChar(CString str, char** ptr);