#include "stdafx.h"
#include "Events.h"


// Variable declaration


// Variable initialization
WNDPROC Events::ApplicationWindowProc = NULL;
bool Events::buttonPressed = false;
bool Events::withinControl = false;

// -------- Miscellaneous handles --------
HWND Events::HANDLE_MAINWINDOW = NULL;
HWND Events::HANDLE_CURRENTCONTROL = NULL;


// -------- Edit handles --------


// -------- Button handles --------
HWND Events::TestButton = NULL;

// -------- ComboBox handles --------


// -------- Static handles --------
HWND Events::CONTROL_STATIC_NUMBER_FIELD = NULL;
HWND Events::CONTROL_STATIC_NUMBER_ONE = NULL;
HWND Events::CONTROL_STATIC_NUMBER_TWO = NULL;
HWND Events::CONTROL_STATIC_NUMBER_THREE = NULL;
HWND Events::CONTROL_STATIC_NUMBER_FOUR = NULL;
HWND Events::CONTROL_STATIC_NUMBER_FIVE = NULL;
HWND Events::CONTROL_STATIC_NUMBER_SIX = NULL;
HWND Events::CONTROL_STATIC_NUMBER_SEVEN = NULL;
HWND Events::CONTROL_STATIC_NUMBER_EIGHT = NULL;
HWND Events::CONTROL_STATIC_NUMBER_NINE = NULL;

HWND Events::CONTROL_STATIC_NUMBER_ZERO = NULL;


// -------- CheckBox handles --------


// -------- UpDown handles --------


Events::Events()
{
}


Events::~Events()
{
}


LRESULT Events::MainWindowProc_OnCreate(lpWndEventArgs Wea)
{
	int buttonWidth = 60;
	int buttonHeight = 60;

	int buttonSpace = 5;

	int buttonLocationColumnOne = 50;
	int buttonLocationColumnTwo = buttonLocationColumnOne + buttonWidth + buttonSpace;
	int buttonLocationColumnThree = buttonLocationColumnTwo + buttonWidth + buttonSpace;

	int buttonLocationRowOne = 150;
	int buttonLocationRowTwo = buttonLocationRowOne + buttonHeight + buttonSpace;
	int buttonLocationRowThree = buttonLocationRowTwo + buttonHeight + buttonSpace;
	int buttonLocationRowFour = buttonLocationRowThree + buttonHeight + buttonSpace;

	// -------- Edit handles --------


	// -------- Button handles --------
	//TestButton = CreateWindowW(L"Button", L"",
	//	WS_CHILD | WS_VISIBLE | BS_OWNERDRAW | BS_PUSHBUTTON,
	//	10, 10, 50, 50,					// x, y, w, h
	//	Wea->hWnd, (HMENU)ID_STATIC_NUMBER_ONE,
	//	(HINSTANCE)GetWindowLong(Wea->hWnd, GWLP_HINSTANCE), NULL);


	// -------- ComboBox handles --------


	// -------- Label handles --------
	CONTROL_STATIC_NUMBER_FIELD = CreateWindowW(L"Static", L"0",
		/*WS_TABSTOP |*/ WS_CHILD | WS_VISIBLE | SS_RIGHT | SS_CENTERIMAGE,
		buttonLocationColumnOne, buttonLocationRowOne - buttonSpace - buttonHeight, 190, buttonHeight,					// x, y, w, h
		Wea->hWnd, (HMENU)ID_STATIC_NUMBER_FIELD,
		(HINSTANCE)GetWindowLongPtr(Wea->hWnd, GWLP_HINSTANCE), NULL);
	
	CONTROL_STATIC_NUMBER_ONE = CreateWindowW(L"Button", L"1",
		/*WS_TABSTOP |*/ WS_CHILD | WS_VISIBLE | BS_OWNERDRAW | BS_PUSHBUTTON,
		buttonLocationColumnOne, buttonLocationRowOne, buttonWidth, buttonHeight,					// x, y, w, h
		Wea->hWnd, (HMENU)ID_STATIC_NUMBER_ONE,
		(HINSTANCE)GetWindowLongPtr(Wea->hWnd, GWLP_HINSTANCE), NULL);

	CONTROL_STATIC_NUMBER_TWO = CreateWindowW(L"Button", L"2",
		/*WS_TABSTOP |*/ WS_CHILD | WS_VISIBLE | BS_OWNERDRAW | BS_PUSHBUTTON,
		buttonLocationColumnTwo, buttonLocationRowOne, buttonWidth, buttonHeight,					// x, y, w, h
		Wea->hWnd, (HMENU)ID_STATIC_NUMBER_TWO,
		(HINSTANCE)GetWindowLongPtr(Wea->hWnd, GWLP_HINSTANCE), NULL);

	CONTROL_STATIC_NUMBER_THREE = CreateWindowW(L"Button", L"3",
		/*WS_TABSTOP |*/ WS_CHILD | WS_VISIBLE | BS_OWNERDRAW | BS_PUSHBUTTON,
		buttonLocationColumnThree, buttonLocationRowOne, buttonWidth, buttonHeight,					// x, y, w, h
		Wea->hWnd, (HMENU)ID_STATIC_NUMBER_THREE,
		(HINSTANCE)GetWindowLongPtr(Wea->hWnd, GWLP_HINSTANCE), NULL);

	CONTROL_STATIC_NUMBER_FOUR = CreateWindowW(L"Button", L"4",
		/*WS_TABSTOP |*/ WS_CHILD | WS_VISIBLE | BS_OWNERDRAW | BS_PUSHBUTTON,
		buttonLocationColumnOne, buttonLocationRowTwo, buttonWidth, buttonHeight,					// x, y, w, h
		Wea->hWnd, (HMENU)ID_STATIC_NUMBER_FOUR,
		(HINSTANCE)GetWindowLongPtr(Wea->hWnd, GWLP_HINSTANCE), NULL);

	CONTROL_STATIC_NUMBER_FIVE = CreateWindowW(L"Button", L"5",
		/*WS_TABSTOP |*/ WS_CHILD | WS_VISIBLE | BS_OWNERDRAW | BS_PUSHBUTTON,
		buttonLocationColumnTwo, buttonLocationRowTwo, buttonWidth, buttonHeight,					// x, y, w, h
		Wea->hWnd, (HMENU)ID_STATIC_NUMBER_FIVE,
		(HINSTANCE)GetWindowLongPtr(Wea->hWnd, GWLP_HINSTANCE), NULL);

	CONTROL_STATIC_NUMBER_SIX = CreateWindowW(L"Button", L"6",
		/*WS_TABSTOP |*/ WS_CHILD | WS_VISIBLE | BS_OWNERDRAW | BS_PUSHBUTTON,
		buttonLocationColumnThree, buttonLocationRowTwo, buttonWidth, buttonHeight,					// x, y, w, h
		Wea->hWnd, (HMENU)ID_STATIC_NUMBER_SIX,
		(HINSTANCE)GetWindowLongPtr(Wea->hWnd, GWLP_HINSTANCE), NULL);

	CONTROL_STATIC_NUMBER_SEVEN = CreateWindowW(L"Button", L"7",
		/*WS_TABSTOP |*/ WS_CHILD | WS_VISIBLE | BS_OWNERDRAW | BS_PUSHBUTTON,
		buttonLocationColumnOne, buttonLocationRowThree, buttonWidth, buttonHeight,					// x, y, w, h
		Wea->hWnd, (HMENU)ID_STATIC_NUMBER_SEVEN,
		(HINSTANCE)GetWindowLongPtr(Wea->hWnd, GWLP_HINSTANCE), NULL);

	CONTROL_STATIC_NUMBER_EIGHT = CreateWindowW(L"Button", L"8",
		/*WS_TABSTOP |*/ WS_CHILD | WS_VISIBLE | BS_OWNERDRAW | BS_PUSHBUTTON,
		buttonLocationColumnTwo, buttonLocationRowThree, buttonWidth, buttonHeight,					// x, y, w, h
		Wea->hWnd, (HMENU)ID_STATIC_NUMBER_EIGHT,
		(HINSTANCE)GetWindowLongPtr(Wea->hWnd, GWLP_HINSTANCE), NULL);

	CONTROL_STATIC_NUMBER_NINE = CreateWindowW(L"Button", L"9",
		/*WS_TABSTOP |*/ WS_CHILD | WS_VISIBLE | BS_OWNERDRAW | BS_PUSHBUTTON,
		buttonLocationColumnThree, buttonLocationRowThree, buttonWidth, buttonHeight,				// x, y, w, h
		Wea->hWnd, (HMENU)ID_STATIC_NUMBER_NINE,
		(HINSTANCE)GetWindowLongPtr(Wea->hWnd, GWLP_HINSTANCE), NULL);









	CONTROL_STATIC_NUMBER_ZERO = CreateWindowW(L"Button", L"0",
		/*WS_TABSTOP |*/ WS_CHILD | WS_VISIBLE | BS_OWNERDRAW | BS_PUSHBUTTON,
		buttonLocationColumnTwo, buttonLocationRowFour, buttonWidth, buttonHeight,				// x, y, w, h
		Wea->hWnd, (HMENU)ID_STATIC_NUMBER_ZERO,
		(HINSTANCE)GetWindowLongPtr(Wea->hWnd, GWLP_HINSTANCE), NULL);


	// -------- CheckBox handles --------


	// -------- UpDown handles --------


	// Get the default window-procedure
	ApplicationWindowProc = (WNDPROC)GetWindowLongPtr(CONTROL_STATIC_NUMBER_ONE, GWLP_WNDPROC);

	// Set the a sub window-procedure for the following controls
	SetWindowLongPtrW(CONTROL_STATIC_NUMBER_ONE, GWLP_WNDPROC, (LONG_PTR)CustomControlsWindowProc);
	SetWindowLongPtrW(CONTROL_STATIC_NUMBER_TWO, GWLP_WNDPROC, (LONG_PTR)CustomControlsWindowProc);
	SetWindowLongPtrW(CONTROL_STATIC_NUMBER_THREE, GWLP_WNDPROC, (LONG_PTR)CustomControlsWindowProc);
	SetWindowLongPtrW(CONTROL_STATIC_NUMBER_FOUR, GWLP_WNDPROC, (LONG_PTR)CustomControlsWindowProc);
	SetWindowLongPtrW(CONTROL_STATIC_NUMBER_FIVE, GWLP_WNDPROC, (LONG_PTR)CustomControlsWindowProc);
	SetWindowLongPtrW(CONTROL_STATIC_NUMBER_SIX, GWLP_WNDPROC, (LONG_PTR)CustomControlsWindowProc);
	SetWindowLongPtrW(CONTROL_STATIC_NUMBER_SEVEN, GWLP_WNDPROC, (LONG_PTR)CustomControlsWindowProc);
	SetWindowLongPtrW(CONTROL_STATIC_NUMBER_EIGHT, GWLP_WNDPROC, (LONG_PTR)CustomControlsWindowProc);
	SetWindowLongPtrW(CONTROL_STATIC_NUMBER_NINE, GWLP_WNDPROC, (LONG_PTR)CustomControlsWindowProc);
	SetWindowLongPtrW(CONTROL_STATIC_NUMBER_ZERO, GWLP_WNDPROC, (LONG_PTR)CustomControlsWindowProc);

	// Asign the application handle to the variable 
	SendMessage(Wea->hWnd, WM_GETWINDOWHANDLE, 0, 0);

	return 0;
}


LRESULT Events::MainWindowProc_OnPaint(lpWndEventArgs Wea)
{



	// Font-test
	HFONT hFont, hTmp;
	PAINTSTRUCT ps;
	HBRUSH hBrush;
	RECT rc;
	HDC hDC;

	hDC = BeginPaint(Wea->hWnd, &ps);
	GetClientRect(Wea->hWnd, &rc);
	hBrush = CreateSolidBrush(RGB(182, 182, 182));
	FillRect(hDC, &rc, hBrush);
	DeleteObject(hBrush);
	SetTextColor(hDC, RGB(0, 255, 255));
	hFont = CreateFontW(80, 0, 0, 0, FW_BOLD, 0, 0, 0, 0, 0, 0, 2, 0, L"SYSTEM_FIXED_FONT");
	hTmp = (HFONT)SelectObject(hDC, hFont);
	SetBkMode(hDC, TRANSPARENT);
	DrawText(hDC, L"Hello, World!", -1, &rc, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	DeleteObject(SelectObject(hDC, hTmp));

	EndPaint(Wea->hWnd, &ps);

	return 0;
}


LRESULT Events::MainWindowProc_OnClose(lpWndEventArgs Wea)
{
	DestroyWindow(Wea->hWnd);
	PostQuitMessage(0);

	return 0;
}





LRESULT Events::MainWindowProc_GetWindowHandle(lpWndEventArgs Wea)
{
	HANDLE_MAINWINDOW = Wea->hWnd;
	return 0;
}


LRESULT Events::MainWindowProc_OnDawControl(lpWndEventArgs Wea)
{
	using namespace std;

	LPDRAWITEMSTRUCT currentControlStruct = (LPDRAWITEMSTRUCT)Wea->lParam;

	cout << "CURRENT CONTROL ID: " << currentControlStruct->CtlID << endl;
	//if (HANDLE_CURRENTSELECTED == currentControlStruct->hwndItem)
	//{
		switch (currentControlStruct->CtlID)
		{
			case ID_STATIC_NUMBER_ONE:
			{
				HandleItemDrawing(currentControlStruct, L"1");
			}
			break;
			case ID_STATIC_NUMBER_TWO:
			{
				HandleItemDrawing(currentControlStruct, L"2");
			}
			break;
			case ID_STATIC_NUMBER_THREE:
			{
				HandleItemDrawing(currentControlStruct, L"3");
			}
			break;
			case ID_STATIC_NUMBER_FOUR:
			{
				HandleItemDrawing(currentControlStruct, L"4");
			}
			break;
			case ID_STATIC_NUMBER_FIVE:
			{
				HandleItemDrawing(currentControlStruct, L"5");
			}
			break;
			case ID_STATIC_NUMBER_SIX:
			{
				HandleItemDrawing(currentControlStruct, L"6");
			}
			break;
			case ID_STATIC_NUMBER_SEVEN:
			{
				HandleItemDrawing(currentControlStruct, L"7");
			}
			break;
			case ID_STATIC_NUMBER_EIGHT:
			{
				HandleItemDrawing(currentControlStruct, L"8");
			}
			break;
			case ID_STATIC_NUMBER_NINE:
			{
				HandleItemDrawing(currentControlStruct, L"9");
			}
			break;
			case ID_STATIC_NUMBER_ZERO:
			{
				HandleItemDrawing(currentControlStruct, L"0");
			}
			break;
			default:
			{
			}
			break;
		}
	//}




	


	return (INT_PTR)TRUE;
}


LRESULT Events::MainWindowProc_OnStaticBackgroundColor(lpWndEventArgs Wea)
{
	//if (buttonPressed && withinControl)
	//{
	//	switch (GetDlgCtrlID((HWND)Wea->lParam))
	//	{
	//		case ID_STATIC_NUMBER_FIELD:
	//		{
	//		}
	//		break;
	//		case ID_STATIC_NUMBER_ONE:
	//		case ID_STATIC_NUMBER_TWO:
	//		case ID_STATIC_NUMBER_THREE:
	//		case ID_STATIC_NUMBER_FOUR:
	//		case ID_STATIC_NUMBER_FIVE:
	//		case ID_STATIC_NUMBER_SIX:
	//		case ID_STATIC_NUMBER_SEVEN:
	//		case ID_STATIC_NUMBER_EIGHT:
	//		case ID_STATIC_NUMBER_NINE:
	//		{
	//			return (INT_PTR)PaintButtonBackground(Wea->lParam, Wea->wParam);
	//		}
	//		break;
	//		default:
	//		{

	//		}
	//		break;
	//	}
	//}

	return 0;
}


LRESULT CALLBACK Events::GlobalKeyboardHook(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (GetForegroundWindow() == HANDLE_MAINWINDOW)
	{
		if (wParam == WM_KEYDOWN)
		{
			using namespace std;
			PKBDLLHOOKSTRUCT p = (PKBDLLHOOKSTRUCT)lParam;
			//cout << wParam << " - " << lParam << " - " << nCode << p->vkCode << endl;

			switch (p->vkCode)
			{
				case VK_DELETE:
				{
					if (GetWindowTextToWstring(CONTROL_STATIC_NUMBER_FIELD) != L"0")
					{
						SendMessage(CONTROL_STATIC_NUMBER_FIELD, WM_SETTEXT, 0, (LPARAM)L"0");
					}
				}
				break;
				case VK_BACK:
				{
					if (GetWindowTextToWstring(CONTROL_STATIC_NUMBER_FIELD).length() > 1)
					{
						std::wstring currentNumber = GetWindowTextToWstring(CONTROL_STATIC_NUMBER_FIELD);
						size_t stringLength = currentNumber.length();

						currentNumber = currentNumber.substr(0, stringLength - 1);

						SendMessage(CONTROL_STATIC_NUMBER_FIELD, WM_SETTEXT, 0, (LPARAM)currentNumber.c_str());
					}
					else
					{
						SendMessage(CONTROL_STATIC_NUMBER_FIELD, WM_SETTEXT, 0, (LPARAM)L"0");
					}
				}
				break;
				case VK_KEY_0:
				case VK_NUMPAD0:
				{
					if (GetWindowTextToWstring(CONTROL_STATIC_NUMBER_FIELD) != L"0")
					{
						std::wstring currentNumber = GetWindowTextToWstring(CONTROL_STATIC_NUMBER_FIELD) + L"0";
						SendMessage(CONTROL_STATIC_NUMBER_FIELD, WM_SETTEXT, 0, (LPARAM)currentNumber.c_str());
					}
				}
				break;
				case VK_KEY_1:
				case VK_NUMPAD1:
				{
					if (GetWindowTextToWstring(CONTROL_STATIC_NUMBER_FIELD) != L"0")
					{
						std::wstring currentNumber = GetWindowTextToWstring(CONTROL_STATIC_NUMBER_FIELD) + L"1";
						SendMessage(CONTROL_STATIC_NUMBER_FIELD, WM_SETTEXT, 0, (LPARAM)currentNumber.c_str());
					}
					else
					{
						SendMessage(CONTROL_STATIC_NUMBER_FIELD, WM_SETTEXT, 0, (LPARAM)L"1");
					}
				}
				break;
				case VK_KEY_2:
				case VK_NUMPAD2:
				{
					if (GetWindowTextToWstring(CONTROL_STATIC_NUMBER_FIELD) != L"0")
					{
						std::wstring currentNumber = GetWindowTextToWstring(CONTROL_STATIC_NUMBER_FIELD) + L"2";
						SendMessage(CONTROL_STATIC_NUMBER_FIELD, WM_SETTEXT, 0, (LPARAM)currentNumber.c_str());
					}
					else
					{
						SendMessage(CONTROL_STATIC_NUMBER_FIELD, WM_SETTEXT, 0, (LPARAM)L"2");
					}
				}
				break;
				case VK_KEY_3:
				case VK_NUMPAD3:
				{
					if (GetWindowTextToWstring(CONTROL_STATIC_NUMBER_FIELD) != L"0")
					{
						std::wstring currentNumber = GetWindowTextToWstring(CONTROL_STATIC_NUMBER_FIELD) + L"3";
						SendMessage(CONTROL_STATIC_NUMBER_FIELD, WM_SETTEXT, 0, (LPARAM)currentNumber.c_str());
					}
					else
					{
						SendMessage(CONTROL_STATIC_NUMBER_FIELD, WM_SETTEXT, 0, (LPARAM)L"3");
					}
				}
				break;
				case VK_KEY_4:
				case VK_NUMPAD4:
				{
					if (GetWindowTextToWstring(CONTROL_STATIC_NUMBER_FIELD) != L"0")
					{
						std::wstring currentNumber = GetWindowTextToWstring(CONTROL_STATIC_NUMBER_FIELD) + L"4";
						SendMessage(CONTROL_STATIC_NUMBER_FIELD, WM_SETTEXT, 0, (LPARAM)currentNumber.c_str());
					}
					else
					{
						SendMessage(CONTROL_STATIC_NUMBER_FIELD, WM_SETTEXT, 0, (LPARAM)L"4");
					}
				}
				break;
				case VK_KEY_5:
				case VK_NUMPAD5:
				{
					if (GetWindowTextToWstring(CONTROL_STATIC_NUMBER_FIELD) != L"0")
					{
						std::wstring currentNumber = GetWindowTextToWstring(CONTROL_STATIC_NUMBER_FIELD) + L"5";
						SendMessage(CONTROL_STATIC_NUMBER_FIELD, WM_SETTEXT, 0, (LPARAM)currentNumber.c_str());
					}
					else
					{
						SendMessage(CONTROL_STATIC_NUMBER_FIELD, WM_SETTEXT, 0, (LPARAM)L"5");
					}
				}
				break;
				case VK_KEY_6:
				case VK_NUMPAD6:
				{
					if (GetWindowTextToWstring(CONTROL_STATIC_NUMBER_FIELD) != L"0")
					{
						std::wstring currentNumber = GetWindowTextToWstring(CONTROL_STATIC_NUMBER_FIELD) + L"6";
						SendMessage(CONTROL_STATIC_NUMBER_FIELD, WM_SETTEXT, 0, (LPARAM)currentNumber.c_str());
					}
					else
					{
						SendMessage(CONTROL_STATIC_NUMBER_FIELD, WM_SETTEXT, 0, (LPARAM)L"6");
					}
				}
				break;
				case VK_KEY_7:
				case VK_NUMPAD7:
				{
					if (GetWindowTextToWstring(CONTROL_STATIC_NUMBER_FIELD) != L"0")
					{
						std::wstring currentNumber = GetWindowTextToWstring(CONTROL_STATIC_NUMBER_FIELD) + L"7";
						SendMessage(CONTROL_STATIC_NUMBER_FIELD, WM_SETTEXT, 0, (LPARAM)currentNumber.c_str());
					}
					else
					{
						SendMessage(CONTROL_STATIC_NUMBER_FIELD, WM_SETTEXT, 0, (LPARAM)L"7");
					}
				}
				break;
				case VK_KEY_8:
				case VK_NUMPAD8:
				{
					if (GetWindowTextToWstring(CONTROL_STATIC_NUMBER_FIELD) != L"0")
					{
						std::wstring currentNumber = GetWindowTextToWstring(CONTROL_STATIC_NUMBER_FIELD) + L"8";
						SendMessage(CONTROL_STATIC_NUMBER_FIELD, WM_SETTEXT, 0, (LPARAM)currentNumber.c_str());
					}
					else
					{
						SendMessage(CONTROL_STATIC_NUMBER_FIELD, WM_SETTEXT, 0, (LPARAM)L"8");
					}
				}
				break;
				case VK_KEY_9:
				case VK_NUMPAD9:
				{
					if (GetWindowTextToWstring(CONTROL_STATIC_NUMBER_FIELD) != L"0")
					{
						std::wstring currentNumber = GetWindowTextToWstring(CONTROL_STATIC_NUMBER_FIELD) + L"9";
						SendMessage(CONTROL_STATIC_NUMBER_FIELD, WM_SETTEXT, 0, (LPARAM)currentNumber.c_str());
					}
					else
					{
						SendMessage(CONTROL_STATIC_NUMBER_FIELD, WM_SETTEXT, 0, (LPARAM)L"9");
					}
				}
				break;
				default:
				{
				}
				break;
			}
		}
	}

	return 0;
}


LRESULT CALLBACK Events::GlobalMouseHook(int nCode, WPARAM wParam, LPARAM lParam)
{
	using namespace std;

	switch (wParam)
	{
		case WM_LBUTTONDOWN:
		{
			POINT point;

			GetCursorPos(&point);

			HANDLE_CURRENTCONTROL = WindowFromPoint(point);

			switch (GetDlgCtrlID((HWND)HANDLE_CURRENTCONTROL))
			{
				case ID_STATIC_NUMBER_FIELD:
				{
				}
				break;
				case ID_STATIC_NUMBER_ONE:
				case ID_STATIC_NUMBER_TWO:
				case ID_STATIC_NUMBER_THREE:
				case ID_STATIC_NUMBER_FOUR:
				case ID_STATIC_NUMBER_FIVE:
				case ID_STATIC_NUMBER_SIX:
				case ID_STATIC_NUMBER_SEVEN:
				case ID_STATIC_NUMBER_EIGHT:
				case ID_STATIC_NUMBER_NINE:
				case ID_STATIC_NUMBER_ZERO:
				{
					buttonPressed = true;
					withinControl = true;

					std::wstring currentNumber = GetWindowTextToWstring(CONTROL_STATIC_NUMBER_FIELD);
					std::wstring buttonNumber = currentNumber + GetWindowTextToWstring(HANDLE_CURRENTCONTROL);

					SendMessage(CONTROL_STATIC_NUMBER_FIELD, WM_SETTEXT, 0, (LPARAM)buttonNumber.c_str());

					//RedrawWindow(HANDLE_CURRENTSELECTED, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
				}
				break;
				default:
				{

				}
				break;
			}
		}
		break;
		case WM_LBUTTONUP:
		{
			if (buttonPressed)
			{
				buttonPressed = false;
				withinControl = false;
				//RedrawWindow(HANDLE_CURRENTSELECTED, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
				//wcout << "Mouse button up - this is the current control text: " << GetWindowTextToWstring(HANDLE_CURRENTSELECTED) << endl;
			}
		}
		break;
		case WM_MOUSEMOVE:
		{
			if (buttonPressed)
			{
				POINT point;

				GetCursorPos(&point);

				HWND HANDLE_BUFFER = WindowFromPoint(point);

				switch (GetDlgCtrlID((HWND)HANDLE_BUFFER))
				{
					case ID_STATIC_NUMBER_FIELD:
					{
					}
					break;
					case ID_STATIC_NUMBER_ONE:
					case ID_STATIC_NUMBER_TWO:
					case ID_STATIC_NUMBER_THREE:
					case ID_STATIC_NUMBER_FOUR:
					case ID_STATIC_NUMBER_FIVE:
					case ID_STATIC_NUMBER_SIX:
					case ID_STATIC_NUMBER_SEVEN:
					case ID_STATIC_NUMBER_EIGHT:
					case ID_STATIC_NUMBER_NINE:
					case ID_STATIC_NUMBER_ZERO:
					{
						if (HANDLE_CURRENTCONTROL == HANDLE_BUFFER)
						{
							if (!withinControl)
							{
								withinControl = true;
								//RedrawWindow(HANDLE_CURRENTSELECTED, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
							}
						}
					}
					break;
					default:
					{
						if (withinControl)
						{
							withinControl = false;
							//RedrawWindow(HANDLE_CURRENTSELECTED, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
						}
					}
					break;
				}
			}
		}
		break;
		default:
		{
		}
		break;
	}

	return 0;
}


void Events::GetWindowPos(HWND hWnd, int *x, int *y)
{
	HWND hWndParent = GetParent(hWnd);
	POINT p = { 0 };

	MapWindowPoints(hWnd, hWndParent, &p, 1);

	(*x) = p.x;
	(*y) = p.y;
}


INT_PTR Events::PaintButtonBackground(LPARAM _passedlParam, WPARAM _passedwParam)
{
	//std::cout << "painting..." << std::endl;
	COLORREF backgroundColor = RGB(221, 221, 221);
	HBRUSH brush = CreateSolidBrush(backgroundColor);
	HDC hdcStatic = (HDC)_passedwParam;

	//SetTextColor(hdcStatic, RGB(255, 0, 0));
	SetBkColor(hdcStatic, backgroundColor);

	return (INT_PTR)brush;
}


void Events::HandleItemDrawing(LPDRAWITEMSTRUCT _passedControlStruct, std::wstring _controlText)
{
	using namespace std;





	HFONT hFont, hTmp;
	HBRUSH hBrush;
	RECT rc;
	HDC hDC;

	POINT point;
	HWND HANDLE_BUFFER;

	GetCursorPos(&point);

	HANDLE_BUFFER = WindowFromPoint(point);

	//wcout << "Pressed handle text: " << GetWindowTextToWstring(HANDLE_CURRENTSELECTED) << " - Current handle text: " << GetWindowTextToWstring(HANDLE_BUFFER) << endl;

	hDC = _passedControlStruct->hDC;
	GetClientRect(_passedControlStruct->hwndItem, &rc);

	if (buttonPressed && withinControl && (HANDLE_CURRENTCONTROL == HANDLE_BUFFER))
	{
		hBrush = CreateSolidBrush(RGB(221, 221, 221));
		//cout << "Button pressed!" << endl;
	}
	else
	{
		hBrush = CreateSolidBrush(RGB(255, 255, 255));
		//cout << "Button not pressed!" << endl;
	}

	FillRect(hDC, &rc, hBrush);
	DeleteObject(hBrush);
	SetTextColor(hDC, RGB(0, 0, 0));
	hFont = CreateFontW(25, 0, 0, 0, FW_BOLD, 0, 0, 0, 0, 0, 0, 2, 0, L"SYSTEM_FIXED_FONT");
	hTmp = (HFONT)SelectObject(hDC, hFont);
	SetBkMode(hDC, TRANSPARENT);

	DrawText(hDC, _controlText.c_str(), -1, &rc, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	DeleteObject(SelectObject(hDC, hTmp));
}


std::wstring Events::GetWindowTextToWstring(HWND _passedHandle)
{
	int lngth = GetWindowTextLengthW(_passedHandle) + 1;
	std::vector<wchar_t> buf(lngth);
	GetWindowTextW(_passedHandle, &buf[0], lngth);
	std::wstring stxt = &buf[0];
	return stxt;
}


std::wstring Events::GetClassNameToWstring(HWND _passedHandle)
{
	// Take a big enough buffer size
	int lngth = 999;
	std::vector<wchar_t> buf(lngth);

	lngth = GetClassNameW(_passedHandle, &buf[0], lngth) + 1;

	std::vector<wchar_t> buf2(lngth);

	GetClassNameW(_passedHandle, &buf2[0], lngth);

	std::wstring stxt = &buf2[0];
	return stxt;
}














LRESULT CALLBACK Events::CustomControlsWindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	using namespace std;

	switch (msg)
	{
		case WM_MOUSEMOVE:
		{
			cout << "WM_MOUSEMOVE" << endl;
			return (INT_PTR)TRUE;
		}
		break;
		case WM_LBUTTONDOWN:
		{
			HANDLE_CURRENTCONTROL = hwnd;
			wcout << "WM_LBUTTONDOWN: " << GetWindowTextToWstring(hwnd) << endl;
			//RedrawWindow(hwnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
			return (INT_PTR)TRUE;
		}
		break;
		case WM_LBUTTONUP:
		{
			cout << "WM_LBUTTONUP" << endl;
			return (INT_PTR)TRUE;
		}
		break;
		default:
		{
			//cout << "SubClass: " << msg << endl;
		}
		break;
	}
	return CallWindowProcW(ApplicationWindowProc, hwnd, msg, wParam, lParam);
}