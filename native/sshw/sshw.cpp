// sshw.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

static int create_ssh_process(_TCHAR* host, _TCHAR* cmd);
static int ask_password(_TCHAR* message);

<<<<<<< HEAD
=======
static WCHAR szEnvVariableName[] = L"SSHW_PID";

>>>>>>> development
int _tmain(int argc, _TCHAR* argv[])
{
	if (argc == 3) {
		return create_ssh_process(argv[1], argv[2]);
	} else if (argc == 2) {
		return ask_password(argv[1]);
	}
	return -1;
}

int create_ssh_process(_TCHAR* host, _TCHAR* cmd)
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	SECURITY_ATTRIBUTES sa;
	DWORD dwFlags = 0;
	HANDLE hStdInR = NULL, hStdInW = NULL;
	HANDLE hStdOutR = NULL, hStdOutW = NULL;
	HANDLE hStdErrR = NULL, hStdErrW = NULL;
<<<<<<< HEAD
	HANDLE hParentStdIn = GetStdHandle(STD_INPUT_HANDLE);
	HANDLE hParentStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hParentStdErr = GetStdHandle(STD_ERROR_HANDLE);
=======
	HANDLE hParentStdIn = ::GetStdHandle(STD_INPUT_HANDLE);
	HANDLE hParentStdOut = ::GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hParentStdErr = ::GetStdHandle(STD_ERROR_HANDLE);
>>>>>>> development
	TCHAR szPath[MAX_PATH];
	TCHAR szCmdline[1024];
	CHAR chBuf[1024];

<<<<<<< HEAD
	if (!GetModuleFileName(NULL, szPath, MAX_PATH) ) {
		printf("Cannot get program path (%d)\n", GetLastError());
		return -1;
	}
	if( !GetEnvironmentVariable(_T("SSH_CMD"), szCmdline, sizeof(szCmdline)/sizeof(*szCmdline)) ) {
=======
	if (!::GetModuleFileName(NULL, szPath, MAX_PATH) ) {
		printf("Cannot get program path (%d)\n", GetLastError());
		return -1;
	}
	if( !::GetEnvironmentVariable(_T("SSH_CMD"), szCmdline, sizeof(szCmdline)/sizeof(*szCmdline)) ) {
>>>>>>> development
		_tcscpy_s(szCmdline, sizeof(szCmdline)/sizeof(*szCmdline), _T("ssh"));
	}
	_tcscat_s(szCmdline, sizeof(szCmdline)/sizeof(*szCmdline), _T(" \""));
	_tcscat_s(szCmdline, sizeof(szCmdline)/sizeof(*szCmdline), host);
	_tcscat_s(szCmdline, sizeof(szCmdline)/sizeof(*szCmdline), _T("\" \""));
	_tcscat_s(szCmdline, sizeof(szCmdline)/sizeof(*szCmdline), cmd);
	_tcscat_s(szCmdline, sizeof(szCmdline)/sizeof(*szCmdline), _T("\""));
	
	sa.nLength = sizeof(SECURITY_ATTRIBUTES); 
	sa.bInheritHandle = TRUE; 
	sa.lpSecurityDescriptor = NULL;

	// STDOUT
<<<<<<< HEAD
	if ( !CreatePipe(&hStdOutR, &hStdOutW, &sa, 0) ) {
		printf("Cannot create pipe (%d)\n", GetLastError());
		return -1;
	}
	if ( !SetHandleInformation(hStdOutR, HANDLE_FLAG_INHERIT, 0) ) {
=======
	if ( !::CreatePipe(&hStdOutR, &hStdOutW, &sa, 0) ) {
		printf("Cannot create pipe (%d)\n", GetLastError());
		return -1;
	}
	if ( !::SetHandleInformation(hStdOutR, HANDLE_FLAG_INHERIT, 0) ) {
>>>>>>> development
		printf("Set inheritable for pipe failed (%d)\n", GetLastError());
		return -1;
	}
	// STDERR
<<<<<<< HEAD
	if ( !CreatePipe(&hStdErrR, &hStdErrW, &sa, 0) ) {
		printf("Cannot create pipe (%d)\n", GetLastError());
		return -1;
	}
	if ( !SetHandleInformation(hStdErrR, HANDLE_FLAG_INHERIT, 0) ) {
=======
	if ( !::CreatePipe(&hStdErrR, &hStdErrW, &sa, 0) ) {
		printf("Cannot create pipe (%d)\n", GetLastError());
		return -1;
	}
	if ( !::SetHandleInformation(hStdErrR, HANDLE_FLAG_INHERIT, 0) ) {
>>>>>>> development
		printf("Set inheritable for pipe failed (%d)\n", GetLastError());
		return -1;
	}
	// STDIN
<<<<<<< HEAD
	if ( !CreatePipe(&hStdInR, &hStdInW, &sa, 0) ) {
		printf("Cannot create pipe (%d)\n", GetLastError());
		return -1;
	}
	if ( !SetHandleInformation(hStdInW, HANDLE_FLAG_INHERIT, 0) ) {
=======
	if ( !::CreatePipe(&hStdInR, &hStdInW, &sa, 0) ) {
		printf("Cannot create pipe (%d)\n", GetLastError());
		return -1;
	}
	if ( !::SetHandleInformation(hStdInW, HANDLE_FLAG_INHERIT, 0) ) {
>>>>>>> development
		printf("Set inheritable for pipe failed (%d)\n", GetLastError());
		return -1;
	}

<<<<<<< HEAD
	ZeroMemory(&si, sizeof(si));
=======
	::ZeroMemory(&si, sizeof(si));
>>>>>>> development
	si.cb = sizeof(si);
	si.hStdError = hStdErrW;
	si.hStdOutput = hStdOutW;
	si.hStdInput = hStdInR;
	si.dwFlags |= STARTF_USESTDHANDLES;
<<<<<<< HEAD
    ZeroMemory(&pi, sizeof(pi));
=======
	::ZeroMemory(&pi, sizeof(pi));
>>>>>>> development

#ifdef UNICODE
    dwFlags = CREATE_UNICODE_ENVIRONMENT;
#endif

<<<<<<< HEAD
	SetEnvironmentVariable(_T("SSH_ASKPASS"), szPath);
	SetEnvironmentVariable(_T("DISPLAY"), _T(":9999"));

	if( !CreateProcess(
=======
	::SetEnvironmentVariable(_T("SSH_ASKPASS"), szPath);
	::SetEnvironmentVariable(_T("DISPLAY"), _T(":9999"));

	WCHAR szValue[64];
	__time64_t ltime;
	_ui64tow_s(::GetCurrentProcessId(), szValue, sizeof(szValue)/sizeof(szValue[0]), 16);
	wcscat(szValue, L"/");
	_time64(&ltime);
	wcscat(szValue, _wctime64( &ltime ));
	::SetEnvironmentVariableW(szEnvVariableName, szValue);

	if( !::CreateProcess(
>>>>>>> development
		NULL,		// No module name (use command line)
        szCmdline,	// Command line
        NULL,		// Process handle not inheritable
        NULL,		// Thread handle not inheritable
        TRUE,		// Set handle inheritance
        dwFlags | DETACHED_PROCESS,	// creation flags
        NULL,           // Use parent's environment block
        NULL,           // Use parent's starting directory 
        &si,            // Pointer to STARTUPINFO structure
        &pi )           // Pointer to PROCESS_INFORMATION structure
		) {
        printf( "CreateProcess failed (%d).\n", GetLastError() );
        return -1;
	}
<<<<<<< HEAD
	CloseHandle(hStdOutW);
	CloseHandle(hStdErrW);
	CloseHandle(hStdInR);
=======
	::CloseHandle(hStdOutW);
	::CloseHandle(hStdErrW);
	::CloseHandle(hStdInR);
>>>>>>> development

	while( true ) {
		DWORD dwRead = 0, dwWritten = 0;
		DWORD dwExitCode = WaitForSingleObject(pi.hProcess, 100);
<<<<<<< HEAD
		FlushFileBuffers(hParentStdIn);
		while ( PeekNamedPipe(hParentStdIn, NULL, 0L, NULL, &dwRead, NULL) && (dwRead != 0) ) {
			if( !ReadFile(hParentStdIn, chBuf, sizeof(chBuf), &dwRead, NULL) ) {
				break;
			}
			if( !WriteFile(hStdInW, chBuf, dwRead, &dwWritten, NULL) ) {
=======
		::FlushFileBuffers(hParentStdIn);
		while ( ::PeekNamedPipe(hParentStdIn, NULL, 0L, NULL, &dwRead, NULL) && (dwRead != 0) ) {
			if( !::ReadFile(hParentStdIn, chBuf, sizeof(chBuf), &dwRead, NULL) ) {
				break;
			}
			if( !::WriteFile(hStdInW, chBuf, dwRead, &dwWritten, NULL) ) {
>>>>>>> development
				break;
			}
		}
		if ( dwWritten != 0 ) {
			continue;
		}
<<<<<<< HEAD
		FlushFileBuffers(hStdOutR);
		while ( PeekNamedPipe(hStdOutR, NULL, 0L, NULL, &dwRead, NULL) && (dwRead != 0) ) {
			if( !ReadFile(hStdOutR, chBuf, sizeof(chBuf), &dwRead, NULL) ) {
				break;
			}
			if( !WriteFile(hParentStdOut, chBuf, dwRead, &dwWritten, NULL) ) {
=======
		::FlushFileBuffers(hStdOutR);
		while ( ::PeekNamedPipe(hStdOutR, NULL, 0L, NULL, &dwRead, NULL) && (dwRead != 0) ) {
			if( !::ReadFile(hStdOutR, chBuf, sizeof(chBuf), &dwRead, NULL) ) {
				break;
			}
			if( !::WriteFile(hParentStdOut, chBuf, dwRead, &dwWritten, NULL) ) {
>>>>>>> development
				break;
			}
		}
		if ( dwWritten != 0 ) {
			continue;
		}
<<<<<<< HEAD
		FlushFileBuffers(hStdErrR);
		while ( PeekNamedPipe(hStdErrR, NULL, 0L, NULL, &dwRead, NULL) && (dwRead != 0) ) {
			if( !ReadFile(hStdErrR, chBuf, sizeof(chBuf), &dwRead, NULL) ) {
				break;
			}
			if( !WriteFile(hParentStdErr, chBuf, dwRead, &dwWritten, NULL) ) {
=======
		::FlushFileBuffers(hStdErrR);
		while ( ::PeekNamedPipe(hStdErrR, NULL, 0L, NULL, &dwRead, NULL) && (dwRead != 0) ) {
			if( !::ReadFile(hStdErrR, chBuf, sizeof(chBuf), &dwRead, NULL) ) {
				break;
			}
			if( !::WriteFile(hParentStdErr, chBuf, dwRead, &dwWritten, NULL) ) {
>>>>>>> development
				break;
			}
		}
		if ( dwWritten != 0 ) {
			continue;
		}
		if( dwExitCode != WAIT_TIMEOUT ) {
			break;
		}
	}
<<<<<<< HEAD
	CloseHandle(hStdOutR);
	CloseHandle(hStdErrR);

	WaitForSingleObject(pi.hProcess, INFINITE);

    // Close process and thread handles. 
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
=======
	::CloseHandle(hStdOutR);
	::CloseHandle(hStdErrR);

	::WaitForSingleObject(pi.hProcess, INFINITE);

    // Close process and thread handles. 
	::CloseHandle(pi.hProcess);
	::CloseHandle(pi.hThread);
>>>>>>> development
	return 0;
}

static BOOL CALLBACK DialogProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
<<<<<<< HEAD
_TCHAR szPassword[80];
=======
static void SavePassword(LPCTSTR szKeyName);
static BOOL LoadPassword(LPCTSTR szKeyName);

static _TCHAR szRegistrySubKey[] = _T("Software\\SSHW");
static _TCHAR szPassword[80];
static _TCHAR szKeyName[MAX_PATH+1];
static BOOL bRememberPassword = FALSE;
>>>>>>> development

int ask_password(_TCHAR* message)
{
	if( _tcsstr(message, _T("(yes/no)"))) {
		if( MessageBox(NULL,
			message,
			_T("SSH"),
			MB_ICONEXCLAMATION | MB_YESNO) == IDYES ) {
			_tprintf(_T("yes"));
			return 0;
		}
	} else {
<<<<<<< HEAD
		if( DialogBoxParam(GetModuleHandle(NULL),
=======
		::ZeroMemory(szKeyName, sizeof(szKeyName));
		_TCHAR *lpszBegin = _tcschr(message, _T('\''));
		if( lpszBegin != NULL ) {
			++lpszBegin;
			_TCHAR *lpszEnd = _tcschr(lpszBegin, _T('\''));
			if( lpszEnd != NULL ) {
				_tcsncpy_s(szKeyName, sizeof(szKeyName)/sizeof(szKeyName[0]), lpszBegin, lpszEnd - lpszBegin);
			}
		}
		::ZeroMemory(szPassword, sizeof(szPassword));
		if( (_tcslen(szKeyName) != 0) && LoadPassword(szKeyName) )
		{
			_tprintf(szPassword);
			SavePassword(szKeyName);
			::SecureZeroMemory(szPassword, sizeof(szPassword));
			return 0;
		}
		if( ::DialogBoxParam(GetModuleHandle(NULL),
>>>>>>> development
			MAKEINTRESOURCE(IDD_DIALOG),
			NULL,
			DialogProc,
			(LPARAM)message) ) {
				_tprintf(szPassword);
<<<<<<< HEAD
=======
				if( bRememberPassword && (_tcslen(szKeyName) != 0) ) {
					SavePassword(szKeyName);
				}
				::SecureZeroMemory(szPassword, sizeof(szPassword));
>>>>>>> development
				return 0;
		}
	}
	return -1;
}

BOOL CALLBACK DialogProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch(message) {
		case WM_INITDIALOG:
<<<<<<< HEAD
			SetDlgItemText(hDlg, IDC_MESSAGE, (LPCTSTR)lParam);
=======
			::SetDlgItemText(hDlg, IDC_MESSAGE, (LPCTSTR)lParam);
>>>>>>> development
			break;
		case WM_COMMAND:
			switch(LOWORD(wParam)) {
				case IDOK: {
<<<<<<< HEAD
						if( !GetDlgItemText(hDlg, IDC_PASSWORD, szPassword, sizeof(szPassword)) ) {
							*szPassword = 0;
						}
						EndDialog(hDlg, IDOK);
					}
					return TRUE;
				case IDCANCEL:
					EndDialog(hDlg, IDCANCEL);
=======
						bRememberPassword = ::IsDlgButtonChecked(hDlg, IDC_REMEMBER) == BST_CHECKED;
						if( !::GetDlgItemText(hDlg, IDC_PASSWORD, szPassword, sizeof(szPassword)) ) {
							*szPassword = 0;
						}
						::EndDialog(hDlg, IDOK);
					}
					return TRUE;
				case IDCANCEL:
					::EndDialog(hDlg, IDCANCEL);
>>>>>>> development
					return TRUE;
			}
			break;
	}
	return FALSE;
}

<<<<<<< HEAD
=======
void SavePassword(LPCTSTR szKeyName)
{
	DATA_BLOB dbDataIn;
	DATA_BLOB dbDataOut;
	dbDataIn.pbData = (LPBYTE)szPassword;
	dbDataIn.cbData = (DWORD)(_tcslen(szPassword)+1)*sizeof(_TCHAR);
	WCHAR szDescription[64];
	::ZeroMemory(szDescription, sizeof(szDescription));
	::GetEnvironmentVariableW(szEnvVariableName, szDescription, sizeof(szDescription)/sizeof(szDescription[0]));
	if ( !::CryptProtectData(&dbDataIn, szDescription, NULL, NULL, NULL, CRYPTPROTECT_UI_FORBIDDEN, &dbDataOut) ) {
		return;
	}
	HKEY hKey;
	if( ::RegCreateKeyEx(HKEY_CURRENT_USER, szRegistrySubKey, 0, NULL, REG_OPTION_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey, NULL) == ERROR_SUCCESS )
	{
		::RegSetValueEx(hKey, szKeyName, 0, REG_BINARY, dbDataOut.pbData, dbDataOut.cbData);
		::RegCloseKey(hKey);
	}
	::LocalFree(dbDataOut.pbData);
}

BOOL LoadPassword(LPCTSTR szKeyName)
{
	HKEY hKey;
	if( ::RegOpenKeyEx(HKEY_CURRENT_USER, szRegistrySubKey, 0, KEY_READ, &hKey) != ERROR_SUCCESS ) {
		return FALSE;
	}
	BOOL bResult = FALSE;
	DWORD dwType;
	DWORD dwSize = 2048;
	LPBYTE lpData = (LPBYTE)::LocalAlloc(LPTR, dwSize);
	if( ::RegQueryValueEx(hKey, szKeyName, NULL, &dwType, lpData, &dwSize) == ERROR_SUCCESS )
	{
		DATA_BLOB dbDataIn;
		DATA_BLOB dbDataOut;
		dbDataIn.pbData = lpData;
		dbDataIn.cbData = dwSize;
		LPWSTR lpwstrDescription = NULL;
		if ( ::CryptUnprotectData(&dbDataIn, &lpwstrDescription, NULL, NULL, NULL, CRYPTPROTECT_UI_FORBIDDEN, &dbDataOut) ) {
			WCHAR szDescription[64];
			::ZeroMemory(szDescription, sizeof(szDescription));
			::GetEnvironmentVariableW(szEnvVariableName, szDescription, sizeof(szDescription)/sizeof(szDescription[0]));
			if( wcscmp(szDescription, lpwstrDescription) != 0 )
			{
				::CopyMemory(szPassword, dbDataOut.pbData, dbDataOut.cbData);
				::SecureZeroMemory(dbDataOut.pbData, dbDataOut.cbData);
				::LocalFree(dbDataOut.pbData);
				bResult = TRUE;
			}
		}
		::LocalFree(lpwstrDescription);
	}
	::RegCloseKey(hKey);
	::LocalFree(lpData);
	return bResult;
}

>>>>>>> development
