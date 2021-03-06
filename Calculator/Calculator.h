#pragma once

#include <iostream>
//#include "resource.h"


class Calculator
{
public:
	Calculator();
	~Calculator();

	HRESULT						Initialize(HINSTANCE hInstance, int nCmdShow);
	HINSTANCE					GetApplicationInstance();
	void						SetApplicationInstance(HINSTANCE hInstance);
	void						UnhookGlobalHook();

private:
	void						AttachEventHandlers();
	ATOM						RegisterWindowsClass(HINSTANCE hInstance);
	BOOL						InitInstance(HINSTANCE hInstance, int ShowCode);
	static LRESULT CALLBACK		MainWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	void						Console(bool _activateConsole);
	void						SetGlobalHooks(HHOOK _keyboardHook, HHOOK _mouseHook);


#pragma region Global Variables:
	HHOOK globalKeyboardHook;
	HHOOK globalMouseHook;

	LPCWSTR aplicationClassName = L"CalculatorHWND";			// Class name of the application

	HINSTANCE programInstance;									// current instance
#pragma endregion
};