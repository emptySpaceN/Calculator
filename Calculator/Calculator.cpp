//----------------------------------------------------------------
#include "stdafx.h"
#include "Calculator.h"
//----------------------------------------------------------------

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
#pragma region Local variables and initialization:
	Calculator CalculatorClass;

	// Initialization
	CalculatorClass.SetApplicationInstance(hInstance);					// Store instance handle in the global variable
#pragma endregion

	// Initialize the console and set a global keyboard & mouse hook
	HRESULT result = CalculatorClass.Initialize(CalculatorClass.GetApplicationInstance(), nCmdShow);

	if (SUCCEEDED(result))
	{
		MSG message;

		while (GetMessage(&message, NULL, 0, 0) > 0)
		{
			TranslateMessage(&message);
			DispatchMessage(&message);
		}
	}

	//CalculatorClass.UnhookGlobalHook();

	return 0;
}

Calculator::Calculator()
{
	// Initialize the events class
	//Events EventsClass;

	this->globalMouseHook = NULL;
	this->globalKeyboardHook = NULL;
}

Calculator::~Calculator()
{
}

HRESULT Calculator::Initialize(HINSTANCE hInstance, int nCmdShow)
{
	Calculator::AttachEventHandlers();
	Calculator::Console(true);
	//Calculator::InitializeGlobalHooks(globalKeyboardHook, globalMouseHook);

	if (!Calculator::RegisterWindowsClass(programInstance))
	{
		MessageBox(NULL, L"Window Registration Failed!", L"Error!", MB_ICONEXCLAMATION | MB_OK);
		return FALSE;
	}

	// Perform application initialization:
	if (!Calculator::InitInstance(programInstance, nCmdShow))
	{
		return FALSE;
	}

	// Function succeeded and is returning a Boolean true. S_OK is defined as 0.
	// Function succeeded and is returning a Boolean false. S_FALSE is defined as 1.
	return 0;
}

HINSTANCE Calculator::GetApplicationInstance()
{
	return programInstance;
}

void Calculator::SetApplicationInstance(HINSTANCE hInstance)
{
	programInstance = hInstance;
}

static std::vector<Events::EVENTHANDLER> EventHandler[1];

void Calculator::AttachEventHandlers()
{
	EventHandler->push_back(Events::EVENTHANDLER());
	EventHandler->at(EventHandler->size() - 1).Code = WM_CREATE;
	EventHandler->at(EventHandler->size() - 1).fnPtr = Events::MainWindowProc_OnCreate;

	EventHandler->push_back(Events::EVENTHANDLER());
	EventHandler->at(EventHandler->size() - 1).Code = WM_PAINT;
	EventHandler->at(EventHandler->size() - 1).fnPtr = Events::MainWindowProc_OnPaint;

	EventHandler->push_back(Events::EVENTHANDLER());
	EventHandler->at(EventHandler->size() - 1).Code = WM_CLOSE;
	EventHandler->at(EventHandler->size() - 1).fnPtr = Events::MainWindowProc_OnClose;

	EventHandler->push_back(Events::EVENTHANDLER());
	EventHandler->at(EventHandler->size() - 1).Code = WM_GETWINDOWHANDLE;
	EventHandler->at(EventHandler->size() - 1).fnPtr = Events::MainWindowProc_GetWindowHandle;
	
	EventHandler->push_back(Events::EVENTHANDLER());
	EventHandler->at(EventHandler->size() - 1).Code = WM_DRAWITEM;
	EventHandler->at(EventHandler->size() - 1).fnPtr = Events::MainWindowProc_OnDawControl;

	EventHandler->push_back(Events::EVENTHANDLER());
	EventHandler->at(EventHandler->size() - 1).Code = WM_MOUSEMOVE;
	EventHandler->at(EventHandler->size() - 1).fnPtr = Events::MainWindowProc_OnMouseMove;

	EventHandler->push_back(Events::EVENTHANDLER());
	EventHandler->at(EventHandler->size() - 1).Code = WM_KEYDOWN;
	EventHandler->at(EventHandler->size() - 1).fnPtr = Events::MainWindowProc_OnKeyDown;

	EventHandler->push_back(Events::EVENTHANDLER());
	EventHandler->at(EventHandler->size() - 1).Code = WM_KEYUP;
	EventHandler->at(EventHandler->size() - 1).fnPtr = Events::MainWindowProc_OnKeyUp;


	//// Asign the event code
	//EventHandler[0].Code = WM_CREATE;
	//EventHandler[1].Code = WM_PAINT;
	//EventHandler[2].Code = WM_CLOSE;
	//EventHandler[3].Code = WM_GETMINMAXINFO;
	//EventHandler[4].Code = WM_COMMAND;
	//EventHandler[5].Code = WM_GETWINDOWHANDLE;

	//// Asign the event void
	//EventHandler[0].fnPtr = &Events::MainWindowProc_OnCreate;
	//EventHandler[1].fnPtr = &Events::MainWindowProc_OnPaint;
	//EventHandler[2].fnPtr = &Events::MainWindowProc_OnClose;
	//EventHandler[3].fnPtr = &Events::MainWindowProc_OnGetMaxMinInfo;
	//EventHandler[4].fnPtr = &Events::MainWindowProc_OnCommand;
	//EventHandler[5].fnPtr = &Events::MainWindowProc_GetWindowHandle;
	//
	//// Counts the elements of the EventHandler array
	//eventCounter = sizeof(EventHandler) / sizeof(EventHandler[0]);
}

ATOM Calculator::RegisterWindowsClass(HINSTANCE hInstance)
{
	WNDCLASSEX windowClass;
	
	windowClass.cbSize = sizeof(WNDCLASSEX);
	windowClass.style = 0;
	windowClass.lpfnWndProc = Calculator::MainWindowProc;
	windowClass.cbClsExtra = 0;
	windowClass.cbWndExtra = 0;
	windowClass.hInstance = programInstance;
	windowClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	windowClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	windowClass.lpszMenuName = NULL;
	windowClass.lpszClassName = aplicationClassName;
	windowClass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	return RegisterClassEx(&windowClass);
}

BOOL Calculator::InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND mainWindowHandle = CreateWindowExW(WS_EX_CLIENTEDGE,
		aplicationClassName,
		L"Calculator",
		WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX /*| WS_MAXIMIZEBOX*/,
		CW_USEDEFAULT, CW_USEDEFAULT,
		350, 500,
		HWND_DESKTOP,
		NULL,
		hInstance,
		NULL);

	if (!mainWindowHandle)
	{
		MessageBox(NULL, L"Handle Creation Failed!", L"Error!", MB_ICONEXCLAMATION | MB_OK);
		return FALSE;
	}

	ShowWindow(mainWindowHandle, nCmdShow);
	UpdateWindow(mainWindowHandle);

	return TRUE;
}

LRESULT CALLBACK Calculator::MainWindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	using namespace std;

	//cout << message << endl;

	Events::WndEventArgs Wea;								//This procedure loops through the EVENTHANDER array
															//of structs to try to make a match with the msg parameter
	for (int i = 0; i < EventHandler->size(); i++)			//of the WndProc.  If a match is made the event handling
	{														//procedure is called through a function pointer -
		if (EventHandler->at(i).Code == message)			//(EventHandler[i].fnPtr).  If no match is found the
		{													//msg is passed onto DefWindowProc().
			Wea.hWnd = hwnd, Wea.lParam = lParam, Wea.wParam = wParam;
			return (*EventHandler->at(i).fnPtr)(&Wea);
		}
	}

	return DefWindowProc(hwnd, message, wParam, lParam);
}

void Calculator::Console(bool _activateConsole)
{
	if (_activateConsole)
	{
		AllocConsole();
		AttachConsole(GetCurrentProcessId());
		FILE* pCout;
		freopen_s(&pCout, "CON", "w", stdout); //returns 0

		std::cout << "Console initialised" << std::endl;
	}
	else
	{
		FreeConsole();
	}
}

void Calculator::SetGlobalHooks(HHOOK _keyboardHook, HHOOK _mouseHook)
{
	_keyboardHook = SetWindowsHookExW(WH_KEYBOARD_LL, (HOOKPROC)Events::GlobalKeyboardHook, NULL, NULL);
	_mouseHook = SetWindowsHookExW(WH_MOUSE_LL, (HOOKPROC)Events::GlobalMouseHook, NULL, NULL);
}

void Calculator::UnhookGlobalHook()
{
	UnhookWindowsHookEx(globalKeyboardHook);
	UnhookWindowsHookEx(globalMouseHook);
}