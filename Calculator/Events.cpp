#include "stdafx.h"
#include "Events.h"


// Variable declaration


// Variable initialization
WNDPROC Events::ApplicationWindowProc = NULL;

bool Events::mouseButtonPressed = false;
bool Events::keyboardPressed = false;
bool Events::withinControl = false;
bool Events::keyboardInput = false;
bool Events::updateDisplayedContent = false;

int Events::displayedNumber = 0;
int Events::additionalNumber = 0;
int Events::currentResult = 0;


// -------- Miscellaneous handles --------
HWND Events::HANDLE_MAINWINDOW = NULL;
HWND Events::HANDLE_CURRENTCONTROL = NULL;


// -------- Edit handles --------


// -------- Button handles --------
HWND Events::CONTROL_STATIC_NUMBER_FIELD = NULL;

HWND Events::CONTROL_BUTTON_ACTION_DELETEDISPLAYED = NULL;
HWND Events::CONTROL_BUTTON_ACTION_DELETEEVERYTHING = NULL;
HWND Events::CONTROL_BUTTON_ACTION_DELETECHARACTER = NULL;
HWND Events::CONTROL_BUTTON_ACTION_DIVISION = NULL;

HWND Events::CONTROL_BUTTON_NUMBER_ONE = NULL;
HWND Events::CONTROL_BUTTON_NUMBER_TWO = NULL;
HWND Events::CONTROL_BUTTON_NUMBER_THREE = NULL;
HWND Events::CONTROL_BUTTON_ACTION_MULTIPLICATION = NULL;

HWND Events::CONTROL_BUTTON_NUMBER_FOUR = NULL;
HWND Events::CONTROL_BUTTON_NUMBER_FIVE = NULL;
HWND Events::CONTROL_BUTTON_NUMBER_SIX = NULL;
HWND Events::CONTROL_BUTTON_ACTION_SUBTRACTION = NULL;

HWND Events::CONTROL_BUTTON_NUMBER_SEVEN = NULL;
HWND Events::CONTROL_BUTTON_NUMBER_EIGHT = NULL;
HWND Events::CONTROL_BUTTON_NUMBER_NINE = NULL;
HWND Events::CONTROL_BUTTON_ACTION_ADDITION = NULL;

HWND Events::CONTROL_BUTTON_PLUSMINUS = NULL;
HWND Events::CONTROL_BUTTON_NUMBER_ZERO = NULL;
HWND Events::CONTROL_BUTTON_CHARACTER_COMMA = NULL;
HWND Events::CONTROL_BUTTON_ACTION_RESULT = NULL;


// -------- ComboBox handles --------


// -------- Static handles --------


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
	int buttonLocationColumnFour = buttonLocationColumnThree + buttonWidth + buttonSpace;

	int buttonLocationRowOne = 100;
	int buttonLocationRowTwo = buttonLocationRowOne + buttonHeight + buttonSpace;
	int buttonLocationRowThree = buttonLocationRowTwo + buttonHeight + buttonSpace;
	int buttonLocationRowFour = buttonLocationRowThree + buttonHeight + buttonSpace;
	int buttonLocationRowFive = buttonLocationRowFour + buttonHeight + buttonSpace;


	// -------- Edit handles --------


	// -------- Static handles --------
	CONTROL_STATIC_NUMBER_FIELD = CreateWindowW(L"Static", L"0",
		/*WS_TABSTOP |*/ WS_CHILD | WS_VISIBLE | SS_OWNERDRAW,
		buttonLocationColumnOne, buttonLocationRowOne - buttonSpace - buttonHeight, 255, buttonHeight,					// x, y, w, h
		Wea->hWnd, (HMENU)ID_STATIC_NUMBER_FIELD,
		(HINSTANCE)GetWindowLongPtr(Wea->hWnd, GWLP_HINSTANCE), NULL);


	// -------- Button handles --------
	CONTROL_BUTTON_ACTION_DELETEDISPLAYED = CreateWindowW(L"Button", L"CE",
		/*WS_TABSTOP |*/ WS_CHILD | WS_VISIBLE | BS_OWNERDRAW | BS_PUSHBUTTON,
		buttonLocationColumnOne, buttonLocationRowOne, buttonWidth, buttonHeight,					// x, y, w, h
		Wea->hWnd, (HMENU)ID_BUTTON_ACTION_DELETEDISPLAYED,
		(HINSTANCE)GetWindowLongPtr(Wea->hWnd, GWLP_HINSTANCE), NULL);

	CONTROL_BUTTON_ACTION_DELETEEVERYTHING = CreateWindowW(L"Button", L"C",
		/*WS_TABSTOP |*/ WS_CHILD | WS_VISIBLE | BS_OWNERDRAW | BS_PUSHBUTTON,
		buttonLocationColumnTwo, buttonLocationRowOne, buttonWidth, buttonHeight,					// x, y, w, h
		Wea->hWnd, (HMENU)ID_BUTTON_ACTION_DELETEEVERYTHING,
		(HINSTANCE)GetWindowLongPtr(Wea->hWnd, GWLP_HINSTANCE), NULL);

	CONTROL_BUTTON_ACTION_DELETECHARACTER = CreateWindowW(L"Button", L"<-",
		/*WS_TABSTOP |*/ WS_CHILD | WS_VISIBLE | BS_OWNERDRAW | BS_PUSHBUTTON,
		buttonLocationColumnThree, buttonLocationRowOne, buttonWidth, buttonHeight,					// x, y, w, h
		Wea->hWnd, (HMENU)ID_BUTTON_ACTION_DELETECHARACTER,
		(HINSTANCE)GetWindowLongPtr(Wea->hWnd, GWLP_HINSTANCE), NULL);

	CONTROL_BUTTON_ACTION_DIVISION = CreateWindowW(L"Button", L"/",
		/*WS_TABSTOP |*/ WS_CHILD | WS_VISIBLE | BS_OWNERDRAW | BS_PUSHBUTTON,
		buttonLocationColumnFour, buttonLocationRowOne, buttonWidth, buttonHeight,					// x, y, w, h
		Wea->hWnd, (HMENU)ID_BUTTON_ACTION_DIVISION,
		(HINSTANCE)GetWindowLongPtr(Wea->hWnd, GWLP_HINSTANCE), NULL);


	CONTROL_BUTTON_NUMBER_SEVEN = CreateWindowW(L"Button", L"7",
		/*WS_TABSTOP |*/ WS_CHILD | WS_VISIBLE | BS_OWNERDRAW | BS_PUSHBUTTON,
		buttonLocationColumnOne, buttonLocationRowTwo, buttonWidth, buttonHeight,					// x, y, w, h
		Wea->hWnd, (HMENU)ID_BUTTON_NUMBER_SEVEN,
		(HINSTANCE)GetWindowLongPtr(Wea->hWnd, GWLP_HINSTANCE), NULL);

	CONTROL_BUTTON_NUMBER_EIGHT = CreateWindowW(L"Button", L"8",
		/*WS_TABSTOP |*/ WS_CHILD | WS_VISIBLE | BS_OWNERDRAW | BS_PUSHBUTTON,
		buttonLocationColumnTwo, buttonLocationRowTwo, buttonWidth, buttonHeight,					// x, y, w, h
		Wea->hWnd, (HMENU)ID_BUTTON_NUMBER_EIGHT,
		(HINSTANCE)GetWindowLongPtr(Wea->hWnd, GWLP_HINSTANCE), NULL);

	CONTROL_BUTTON_NUMBER_NINE = CreateWindowW(L"Button", L"9",
		/*WS_TABSTOP |*/ WS_CHILD | WS_VISIBLE | BS_OWNERDRAW | BS_PUSHBUTTON,
		buttonLocationColumnThree, buttonLocationRowTwo, buttonWidth, buttonHeight,					// x, y, w, h
		Wea->hWnd, (HMENU)ID_BUTTON_NUMBER_NINE,
		(HINSTANCE)GetWindowLongPtr(Wea->hWnd, GWLP_HINSTANCE), NULL);

	CONTROL_BUTTON_ACTION_MULTIPLICATION = CreateWindowW(L"Button", L"*",
		/*WS_TABSTOP |*/ WS_CHILD | WS_VISIBLE | BS_OWNERDRAW | BS_PUSHBUTTON,
		buttonLocationColumnFour, buttonLocationRowTwo, buttonWidth, buttonHeight,					// x, y, w, h
		Wea->hWnd, (HMENU)ID_BUTTON_ACTION_MULTIPLICATION,
		(HINSTANCE)GetWindowLongPtr(Wea->hWnd, GWLP_HINSTANCE), NULL);


	CONTROL_BUTTON_NUMBER_FOUR = CreateWindowW(L"Button", L"4",
		/*WS_TABSTOP |*/ WS_CHILD | WS_VISIBLE | BS_OWNERDRAW | BS_PUSHBUTTON,
		buttonLocationColumnOne, buttonLocationRowThree, buttonWidth, buttonHeight,					// x, y, w, h
		Wea->hWnd, (HMENU)ID_BUTTON_NUMBER_FOUR,
		(HINSTANCE)GetWindowLongPtr(Wea->hWnd, GWLP_HINSTANCE), NULL);

	CONTROL_BUTTON_NUMBER_FIVE = CreateWindowW(L"Button", L"5",
		/*WS_TABSTOP |*/ WS_CHILD | WS_VISIBLE | BS_OWNERDRAW | BS_PUSHBUTTON,
		buttonLocationColumnTwo, buttonLocationRowThree, buttonWidth, buttonHeight,					// x, y, w, h
		Wea->hWnd, (HMENU)ID_BUTTON_NUMBER_FIVE,
		(HINSTANCE)GetWindowLongPtr(Wea->hWnd, GWLP_HINSTANCE), NULL);

	CONTROL_BUTTON_NUMBER_SIX = CreateWindowW(L"Button", L"6",
		/*WS_TABSTOP |*/ WS_CHILD | WS_VISIBLE | BS_OWNERDRAW | BS_PUSHBUTTON,
		buttonLocationColumnThree, buttonLocationRowThree, buttonWidth, buttonHeight,					// x, y, w, h
		Wea->hWnd, (HMENU)ID_BUTTON_NUMBER_SIX,
		(HINSTANCE)GetWindowLongPtr(Wea->hWnd, GWLP_HINSTANCE), NULL);

	CONTROL_BUTTON_ACTION_SUBTRACTION = CreateWindowW(L"Button", L"-",
		/*WS_TABSTOP |*/ WS_CHILD | WS_VISIBLE | BS_OWNERDRAW | BS_PUSHBUTTON,
		buttonLocationColumnFour, buttonLocationRowThree, buttonWidth, buttonHeight,					// x, y, w, h
		Wea->hWnd, (HMENU)ID_BUTTON_ACTION_SUBTRACTION,
		(HINSTANCE)GetWindowLongPtr(Wea->hWnd, GWLP_HINSTANCE), NULL);


	CONTROL_BUTTON_NUMBER_ONE = CreateWindowW(L"Button", L"1",
		/*WS_TABSTOP |*/ WS_CHILD | WS_VISIBLE | BS_OWNERDRAW | BS_PUSHBUTTON,
		buttonLocationColumnOne, buttonLocationRowFour, buttonWidth, buttonHeight,					// x, y, w, h
		Wea->hWnd, (HMENU)ID_BUTTON_NUMBER_ONE,
		(HINSTANCE)GetWindowLongPtr(Wea->hWnd, GWLP_HINSTANCE), NULL);

	CONTROL_BUTTON_NUMBER_TWO = CreateWindowW(L"Button", L"2",
		/*WS_TABSTOP |*/ WS_CHILD | WS_VISIBLE | BS_OWNERDRAW | BS_PUSHBUTTON,
		buttonLocationColumnTwo, buttonLocationRowFour, buttonWidth, buttonHeight,					// x, y, w, h
		Wea->hWnd, (HMENU)ID_BUTTON_NUMBER_TWO,
		(HINSTANCE)GetWindowLongPtr(Wea->hWnd, GWLP_HINSTANCE), NULL);

	CONTROL_BUTTON_NUMBER_THREE = CreateWindowW(L"Button", L"3",
		/*WS_TABSTOP |*/ WS_CHILD | WS_VISIBLE | BS_OWNERDRAW | BS_PUSHBUTTON,
		buttonLocationColumnThree, buttonLocationRowFour, buttonWidth, buttonHeight,				// x, y, w, h
		Wea->hWnd, (HMENU)ID_BUTTON_NUMBER_THREE,
		(HINSTANCE)GetWindowLongPtr(Wea->hWnd, GWLP_HINSTANCE), NULL);

	CONTROL_BUTTON_ACTION_ADDITION = CreateWindowW(L"Button", L"+",
		/*WS_TABSTOP |*/ WS_CHILD | WS_VISIBLE | BS_OWNERDRAW | BS_PUSHBUTTON,
		buttonLocationColumnFour, buttonLocationRowFour, buttonWidth, buttonHeight,				// x, y, w, h
		Wea->hWnd, (HMENU)ID_BUTTON_ACTION_ADDITION,
		(HINSTANCE)GetWindowLongPtr(Wea->hWnd, GWLP_HINSTANCE), NULL);


	CONTROL_BUTTON_PLUSMINUS = CreateWindowW(L"Button", L"+/-",
		/*WS_TABSTOP |*/ WS_CHILD | WS_VISIBLE | BS_OWNERDRAW | BS_PUSHBUTTON,
		buttonLocationColumnOne, buttonLocationRowFive, buttonWidth, buttonHeight,				// x, y, w, h
		Wea->hWnd, (HMENU)ID_BUTTON_CHARACTER_PLUSMINUS,
		(HINSTANCE)GetWindowLongPtr(Wea->hWnd, GWLP_HINSTANCE), NULL);

	CONTROL_BUTTON_NUMBER_ZERO = CreateWindowW(L"Button", L"0",
		/*WS_TABSTOP |*/ WS_CHILD | WS_VISIBLE | BS_OWNERDRAW | BS_PUSHBUTTON,
		buttonLocationColumnTwo, buttonLocationRowFive, buttonWidth, buttonHeight,				// x, y, w, h
		Wea->hWnd, (HMENU)ID_BUTTON_NUMBER_ZERO,
		(HINSTANCE)GetWindowLongPtr(Wea->hWnd, GWLP_HINSTANCE), NULL);

	CONTROL_BUTTON_CHARACTER_COMMA = CreateWindowW(L"Button", L",",
		/*WS_TABSTOP |*/ WS_CHILD | WS_VISIBLE | BS_OWNERDRAW | BS_PUSHBUTTON,
		buttonLocationColumnThree, buttonLocationRowFive, buttonWidth, buttonHeight,				// x, y, w, h
		Wea->hWnd, (HMENU)ID_BUTTON_CHARACTER_COMMA,
		(HINSTANCE)GetWindowLongPtr(Wea->hWnd, GWLP_HINSTANCE), NULL);

	CONTROL_BUTTON_ACTION_RESULT = CreateWindowW(L"Button", L"=",
		/*WS_TABSTOP |*/ WS_CHILD | WS_VISIBLE | BS_OWNERDRAW | BS_PUSHBUTTON,
		buttonLocationColumnFour, buttonLocationRowFive, buttonWidth, buttonHeight,				// x, y, w, h
		Wea->hWnd, (HMENU)ID_BUTTON_ACTION_RESULT,
		(HINSTANCE)GetWindowLongPtr(Wea->hWnd, GWLP_HINSTANCE), NULL);


	// -------- ComboBox handles --------


	// -------- CheckBox handles --------


	// -------- UpDown handles --------


	// Get the default window-procedure
	ApplicationWindowProc = (WNDPROC)GetWindowLongPtr(CONTROL_BUTTON_NUMBER_ONE, GWLP_WNDPROC);

	// Set the a sub window-procedure for the following controls
	SetWindowLongPtrW(CONTROL_BUTTON_ACTION_DELETEDISPLAYED, GWLP_WNDPROC, (LONG_PTR)CustomControlsWindowProc);
	SetWindowLongPtrW(CONTROL_BUTTON_ACTION_DELETEEVERYTHING, GWLP_WNDPROC, (LONG_PTR)CustomControlsWindowProc);
	SetWindowLongPtrW(CONTROL_BUTTON_ACTION_DELETECHARACTER, GWLP_WNDPROC, (LONG_PTR)CustomControlsWindowProc);
	SetWindowLongPtrW(CONTROL_BUTTON_ACTION_DIVISION, GWLP_WNDPROC, (LONG_PTR)CustomControlsWindowProc);

	SetWindowLongPtrW(CONTROL_BUTTON_NUMBER_SEVEN, GWLP_WNDPROC, (LONG_PTR)CustomControlsWindowProc);
	SetWindowLongPtrW(CONTROL_BUTTON_NUMBER_EIGHT, GWLP_WNDPROC, (LONG_PTR)CustomControlsWindowProc);
	SetWindowLongPtrW(CONTROL_BUTTON_NUMBER_NINE, GWLP_WNDPROC, (LONG_PTR)CustomControlsWindowProc);
	SetWindowLongPtrW(CONTROL_BUTTON_ACTION_MULTIPLICATION, GWLP_WNDPROC, (LONG_PTR)CustomControlsWindowProc);

	SetWindowLongPtrW(CONTROL_BUTTON_NUMBER_FOUR, GWLP_WNDPROC, (LONG_PTR)CustomControlsWindowProc);
	SetWindowLongPtrW(CONTROL_BUTTON_NUMBER_FIVE, GWLP_WNDPROC, (LONG_PTR)CustomControlsWindowProc);
	SetWindowLongPtrW(CONTROL_BUTTON_NUMBER_SIX, GWLP_WNDPROC, (LONG_PTR)CustomControlsWindowProc);
	SetWindowLongPtrW(CONTROL_BUTTON_ACTION_SUBTRACTION, GWLP_WNDPROC, (LONG_PTR)CustomControlsWindowProc);

	SetWindowLongPtrW(CONTROL_BUTTON_NUMBER_ONE, GWLP_WNDPROC, (LONG_PTR)CustomControlsWindowProc);
	SetWindowLongPtrW(CONTROL_BUTTON_NUMBER_TWO, GWLP_WNDPROC, (LONG_PTR)CustomControlsWindowProc);
	SetWindowLongPtrW(CONTROL_BUTTON_NUMBER_THREE, GWLP_WNDPROC, (LONG_PTR)CustomControlsWindowProc);
	SetWindowLongPtrW(CONTROL_BUTTON_ACTION_ADDITION, GWLP_WNDPROC, (LONG_PTR)CustomControlsWindowProc);

	SetWindowLongPtrW(CONTROL_BUTTON_PLUSMINUS, GWLP_WNDPROC, (LONG_PTR)CustomControlsWindowProc);
	SetWindowLongPtrW(CONTROL_BUTTON_NUMBER_ZERO, GWLP_WNDPROC, (LONG_PTR)CustomControlsWindowProc);
	SetWindowLongPtrW(CONTROL_BUTTON_CHARACTER_COMMA, GWLP_WNDPROC, (LONG_PTR)CustomControlsWindowProc);
	SetWindowLongPtrW(CONTROL_BUTTON_ACTION_RESULT, GWLP_WNDPROC, (LONG_PTR)CustomControlsWindowProc);

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
	std::wstring  szUeberschrift = L"Test";
	//DrawText(hDC, szUeberschrift.c_str(), lstrlenW(szUeberschrift.c_str()), &rc, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	TextOutW(hDC, 1, 1, szUeberschrift.c_str(), lstrlenW(szUeberschrift.c_str()));
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

	//cout << "CURRENT CONTROL ID: " << currentControlStruct->CtlID << endl;

	switch (currentControlStruct->CtlID)
	{
		case ID_STATIC_NUMBER_FIELD:
		{
			displayedNumber = 123123123;
			HandleItemDrawing(currentControlStruct, to_wstring(displayedNumber));
		}
		case ID_BUTTON_ACTION_DELETEDISPLAYED:
		{
			HandleItemDrawing(currentControlStruct, L"CE");
		}
		break;
		case ID_BUTTON_ACTION_DELETEEVERYTHING:
		{
			HandleItemDrawing(currentControlStruct, L"C");
		}
		break;
		case ID_BUTTON_ACTION_DELETECHARACTER:
		{
			HandleItemDrawing(currentControlStruct, L"<-");
		}
		break;
		case ID_BUTTON_ACTION_DIVISION:
		{
			HandleItemDrawing(currentControlStruct, L"/");
		}
		break;
		case ID_BUTTON_NUMBER_SEVEN:
		{
			HandleItemDrawing(currentControlStruct, L"7");
		}
		break;
		case ID_BUTTON_NUMBER_EIGHT:
		{
			HandleItemDrawing(currentControlStruct, L"8");
		}
		break;
		case ID_BUTTON_NUMBER_NINE:
		{
			HandleItemDrawing(currentControlStruct, L"9");
		}
		break;
		case ID_BUTTON_ACTION_MULTIPLICATION:
		{
			HandleItemDrawing(currentControlStruct, L"*");
		}
		break;
		case ID_BUTTON_NUMBER_FOUR:
		{
			HandleItemDrawing(currentControlStruct, L"4");
		}
		break;
		case ID_BUTTON_NUMBER_FIVE:
		{
			HandleItemDrawing(currentControlStruct, L"5");
		}
		break;
		case ID_BUTTON_NUMBER_SIX:
		{
			HandleItemDrawing(currentControlStruct, L"6");
		}
		break;
		case ID_BUTTON_ACTION_SUBTRACTION:
		{
			HandleItemDrawing(currentControlStruct, L"-");
		}
		break;
		case ID_BUTTON_NUMBER_ONE:
		{
			HandleItemDrawing(currentControlStruct, L"1");
		}
		break;
		case ID_BUTTON_NUMBER_TWO:
		{
			HandleItemDrawing(currentControlStruct, L"2");
		}
		break;
		case ID_BUTTON_NUMBER_THREE:
		{
			HandleItemDrawing(currentControlStruct, L"3");
		}
		break;
		case ID_BUTTON_ACTION_ADDITION:
		{
			HandleItemDrawing(currentControlStruct, L"+");
		}
		break;
		case ID_BUTTON_CHARACTER_PLUSMINUS:
		{
			HandleItemDrawing(currentControlStruct, L"+/-");
		}
		break;
		case ID_BUTTON_NUMBER_ZERO:
		{
			HandleItemDrawing(currentControlStruct, L"0");
		}
		break;
		case ID_BUTTON_CHARACTER_COMMA:
		{
			HandleItemDrawing(currentControlStruct, L",");
		}
		break;
		case ID_BUTTON_ACTION_RESULT:
		{
			HandleItemDrawing(currentControlStruct, L"=");
		}
		break;
		default:
		{
		}
		break;
	}

	return 0;
}


LRESULT Events::MainWindowProc_OnMouseMove(lpWndEventArgs Wea)
{
	using namespace std;

	if (mouseButtonPressed)
	{
		POINT point;

		GetCursorPos(&point);

		HWND HANDLE_BUFFER = WindowFromPoint(point);

		switch (GetDlgCtrlID((HWND)HANDLE_BUFFER))
		{
			default:
			{
				//wcout << "Out of control" << endl;
				if (withinControl)
				{
					withinControl = false;
					RedrawWindow(HANDLE_CURRENTCONTROL, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
				}
			}
			break;
		}
	}

	return 0;
}


LRESULT Events::MainWindowProc_OnKeyDown(lpWndEventArgs Wea)
{
	using namespace std;

	//cout << Wea->wParam << endl;

	switch (Wea->wParam)
	{
		case VK_DELETE:
		{
			DisplayCharacter(EnteredCharacter::Action_DeleteDisplayed);

			if (!keyboardPressed)
			{
				//system("cls");
				//cout << "key down<----------------------------------------------: " << endl;
				//HandleButtonAction(InputAction::Keyboard, CONTROL_BUTTON_ACTION_DELETEDISPLAYED);
			}
		}
		break;
		case VK_BACK:
		{
			DisplayCharacter(EnteredCharacter::Action_DeleteCharacter);

			if (!keyboardPressed)
			{
				HandleButtonAction(InputAction::Keyboard, CONTROL_BUTTON_ACTION_DELETECHARACTER);
			}
		}
		break;
		case VK_KEY_0:
		case VK_NUMPAD0:
		{
			DisplayCharacter(EnteredCharacter::Number_Zero);

			if (!keyboardPressed)
			{
				HandleButtonAction(InputAction::Keyboard, CONTROL_BUTTON_NUMBER_ZERO);
			}
		}
		break;
		case VK_KEY_1:
		case VK_NUMPAD1:
		{
			DisplayCharacter(EnteredCharacter::Number_One);

			if (!keyboardPressed)
			{
				HandleButtonAction(InputAction::Keyboard, CONTROL_BUTTON_NUMBER_ONE);
			}
		}
		break;
		case VK_KEY_2:
		case VK_NUMPAD2:
		{
			DisplayCharacter(EnteredCharacter::Number_Two);

			if (!keyboardPressed)
			{
				HandleButtonAction(InputAction::Keyboard, CONTROL_BUTTON_NUMBER_TWO);
			}
		}
		break;
		case VK_KEY_3:
		case VK_NUMPAD3:
		{
			DisplayCharacter(EnteredCharacter::Number_Three);

			if (!keyboardPressed)
			{
				HandleButtonAction(InputAction::Keyboard, CONTROL_BUTTON_NUMBER_THREE);
			}
		}
		break;
		case VK_KEY_4:
		case VK_NUMPAD4:
		{
			DisplayCharacter(EnteredCharacter::Number_Four);

			if (!keyboardPressed)
			{
				HandleButtonAction(InputAction::Keyboard, CONTROL_BUTTON_NUMBER_FOUR);
			}
		}
		break;
		case VK_KEY_5:
		case VK_NUMPAD5:
		{
			DisplayCharacter(EnteredCharacter::Number_Five);

			if (!keyboardPressed)
			{
				HandleButtonAction(InputAction::Keyboard, CONTROL_BUTTON_NUMBER_FIVE);
			}
		}
		break;
		case VK_KEY_6:
		case VK_NUMPAD6:
		{
			DisplayCharacter(EnteredCharacter::Number_Six);

			if (!keyboardPressed)
			{
				HandleButtonAction(InputAction::Keyboard, CONTROL_BUTTON_NUMBER_SIX);
			}
		}
		break;
		case VK_KEY_7:
		case VK_NUMPAD7:
		{
			DisplayCharacter(EnteredCharacter::Number_Seven);

			if (!keyboardPressed)
			{
				cout << "test 7" << endl;
				HandleButtonAction(InputAction::Keyboard, CONTROL_BUTTON_NUMBER_SEVEN);
			}
		}
		break;
		case VK_KEY_8:
		case VK_NUMPAD8:
		{
			DisplayCharacter(EnteredCharacter::Number_Eight);

			if (!keyboardPressed)
			{
				HandleButtonAction(InputAction::Keyboard, CONTROL_BUTTON_NUMBER_EIGHT);
			}
		}
		break;
		case VK_KEY_9:
		case VK_NUMPAD9:
		{
			DisplayCharacter(EnteredCharacter::Number_Nine);

			if (!keyboardPressed)
			{
				HandleButtonAction(InputAction::Keyboard, CONTROL_BUTTON_NUMBER_NINE);
			}
		}
		break;
		case VK_OEM_COMMA:
		case VK_DECIMAL:
		{
			DisplayCharacter(EnteredCharacter::Character_Comma);

			if (!keyboardPressed)
			{
				HandleButtonAction(InputAction::Keyboard, CONTROL_BUTTON_CHARACTER_COMMA);
			}
		}
		break;
		case VK_OEM_MINUS:
		{
			//TODO: Add numpad and kkeyboard minus
			DisplayCharacter(EnteredCharacter::Character_PlusMinus);

			if (!keyboardPressed)
			{
				HandleButtonAction(InputAction::Keyboard, CONTROL_BUTTON_PLUSMINUS);
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


LRESULT Events::MainWindowProc_OnKeyUp(lpWndEventArgs Wea)
{
	using namespace std;

	keyboardPressed = false;
	//cout << "key up<----------------------------------------------: " << endl;

	return 0;
}


LRESULT CALLBACK Events::GlobalKeyboardHook(int nCode, WPARAM wParam, LPARAM lParam)
{
	return 0;
}


LRESULT CALLBACK Events::GlobalMouseHook(int nCode, WPARAM wParam, LPARAM lParam)
{
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

	//wcout << "Pressed handle text: " << GetWindowTextToWstring(HANDLE_CURRENTCONTROL) << " - Current handle text: " << GetWindowTextToWstring(HANDLE_BUFFER) << endl;

	//cout << "mouseButtonPressed! - " << mouseButtonPressed << endl;
	//cout << "withinControl! - " << withinControl << endl;
	//cout << "keyboardPressed! - " << keyboardPressed << endl;
	//cout << "keyboardInput! - " << keyboardInput << endl;
	//cout << endl;

	hDC = _passedControlStruct->hDC;
	GetClientRect(_passedControlStruct->hwndItem, &rc);

	if (((mouseButtonPressed && withinControl && (HANDLE_CURRENTCONTROL == HANDLE_BUFFER)) && !updateDisplayedContent) || (keyboardInput && !updateDisplayedContent))
	{

		hBrush = CreateSolidBrush(RGB(5, 221, 221));

		if (keyboardPressed) { keyboardInput = false; }
		//cout << "keyboardInput!" << keyboardInput << endl;
	}
	else
	{
		hBrush = CreateSolidBrush(RGB(255, 255, 255));

		if (keyboardPressed) { keyboardInput = true; }

		//cout << "keyboardInput!" << keyboardInput << endl;
	}

	FillRect(hDC, &rc, hBrush);
	DeleteObject(hBrush);
	SetTextColor(hDC, RGB(0, 0, 0));
	hFont = CreateFontW(25, 0, 0, 0, FW_BOLD, 0, 0, 0, 0, 0, 0, 2, 0, L"SYSTEM_FIXED_FONT");
	hTmp = (HFONT)SelectObject(hDC, hFont);
	SetBkMode(hDC, TRANSPARENT);

	cout << "in the custom draw event - ID: " << _passedControlStruct->CtlID << endl;
	
	if (!updateDisplayedContent && _passedControlStruct->CtlID != ID_STATIC_NUMBER_FIELD)
	{
		// Draw the current cntrols text
		DrawText(hDC, _controlText.c_str(), -1, &rc, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	}
	else
	{
		// If true, update the displayed content
		SIZE textSize;
		int textPositionX = 0;
		int textPositionY = 0;
		wstring newDisplayedContent = to_wstring(displayedNumber);

		GetTextExtentPoint32W(hDC, newDisplayedContent.c_str(), lstrlenW(newDisplayedContent.c_str()), &textSize);

		textPositionX = rc.right - textSize.cx - 20;
		textPositionY = ((rc.bottom - rc.top) / 2) - (textSize.cy / 2);

		TextOutW(hDC, textPositionX, textPositionY, newDisplayedContent.c_str(), lstrlenW(newDisplayedContent.c_str()));

		//wcout << "x: " << textSize.cx << " - y: " << textSize.cy << " - Height: " << rc.bottom - rc.top << " string: " << _controlText << endl;

		updateDisplayedContent = false;
	}

	//Rectangle(hDC, rc.left, rc.top, rc.right, rc.bottom);
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

int Events::ConcatenateInteger(int _passedNumberOne, int _passedNumberTwo)
{
	using namespace std;

	int concatenatedNumber;
	ostringstream oss;
	

	oss << _passedNumberOne << _passedNumberTwo;

	istringstream iss(oss.str());
	
	iss >> concatenatedNumber;

	cout << "Number one: " << concatenatedNumber << " Number two: " << _passedNumberTwo << endl;
	
	return concatenatedNumber;
}


void Events::DisplayCharacter(EnteredCharacter _passedCharacter)
{
	using namespace std;

	switch (_passedCharacter)
	{
		case EnteredCharacter::Action_DeleteDisplayed:
		{
			if (displayedNumber != 0)
			{
				updateDisplayedContent = true;
				displayedNumber = 0;

				RedrawWindow(CONTROL_STATIC_NUMBER_FIELD, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
				cout << "Delete displayed - bool: " << updateDisplayedContent << endl;
				//SendMessage(CONTROL_STATIC_NUMBER_FIELD, WM_SETTEXT, 0, (LPARAM)L"0");
			}
		}
		break;
		case EnteredCharacter::Action_DeleteEverything:
		{
			// TODO: Delete all number and calculating variables
			if (displayedNumber != 0)
			{
				updateDisplayedContent = true;
				displayedNumber = 0;
				RedrawWindow(CONTROL_STATIC_NUMBER_FIELD, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
				cout << "Delete everything - bool: " << updateDisplayedContent << endl;
				//SendMessage(CONTROL_STATIC_NUMBER_FIELD, WM_SETTEXT, 0, (LPARAM)L"0");
			}
		}
		break;
		case EnteredCharacter::Action_DeleteCharacter:
		{
			if (displayedNumber >= 9)
			{
				std::wstring currentNumber = to_wstring(displayedNumber);
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
		case EnteredCharacter::Action_Disision:
		{


		}
		break;
		case EnteredCharacter::Number_Zero:
		{
			if (GetWindowTextToWstring(CONTROL_STATIC_NUMBER_FIELD) != L"0")
			{
				std::wstring currentNumber = GetWindowTextToWstring(CONTROL_STATIC_NUMBER_FIELD) + L"0";
				SendMessage(CONTROL_STATIC_NUMBER_FIELD, WM_SETTEXT, 0, (LPARAM)currentNumber.c_str());
			}
		}
		break;
		case EnteredCharacter::Number_One:
		{
			if (displayedNumber != 0)
			{
				updateDisplayedContent = true;
				displayedNumber = ConcatenateInteger(displayedNumber, 1);

				RedrawWindow(CONTROL_STATIC_NUMBER_FIELD, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
				//SendMessage(CONTROL_STATIC_NUMBER_FIELD, WM_SETTEXT, 0, (LPARAM)currentNumber.c_str());
				cout << "one uneven Displayed: " << displayedNumber << " - bool: " << updateDisplayedContent << endl;
			}
			else
			{
				
				displayedNumber = 1;
				RedrawWindow(CONTROL_STATIC_NUMBER_FIELD, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
				
			//SendMessage(CONTROL_STATIC_NUMBER_FIELD, WM_SETTEXT, 0, (LPARAM)L"1");
				cout << "one even " << displayedNumber << endl;
			}
		}
		break;
		case EnteredCharacter::Number_Two:
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
		case EnteredCharacter::Number_Three:
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
		case EnteredCharacter::Number_Four:
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
		case EnteredCharacter::Number_Five:
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
		case EnteredCharacter::Number_Six:
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
		case EnteredCharacter::Number_Seven:
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
		case EnteredCharacter::Number_Eight:
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
		case EnteredCharacter::Number_Nine:
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
		case EnteredCharacter::Character_PlusMinus:
		{
		}
		break;
		case EnteredCharacter::Character_Comma:
		{
			if (GetWindowTextToWstring(CONTROL_STATIC_NUMBER_FIELD) != L"0")
			{
				std::wstring currentNumber = GetWindowTextToWstring(CONTROL_STATIC_NUMBER_FIELD) + L",";
				SendMessage(CONTROL_STATIC_NUMBER_FIELD, WM_SETTEXT, 0, (LPARAM)currentNumber.c_str());
			}
			else
			{
				SendMessage(CONTROL_STATIC_NUMBER_FIELD, WM_SETTEXT, 0, (LPARAM)L"0,");
			}
		}
		break;
		case EnteredCharacter::Action_Addition:
		{
		}
		break;
		case EnteredCharacter::Action_Subtraction:
		{
		}
		break;
		case EnteredCharacter::Action_Multiplication:
		{
		}
		break;
		default:
		{
		}
		break;
	}
}


void Events::HandleButtonAction(InputAction _passedAction, HWND _passedNewCurrentControl = NULL)
{
	switch (_passedAction)
	{
		case Events::Mouse:
		{

			RedrawWindow(HANDLE_CURRENTCONTROL, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
		}
		break;
		case Events::Keyboard:
		{
			HANDLE_CURRENTCONTROL = _passedNewCurrentControl;
			keyboardPressed = true;

			RedrawWindow(HANDLE_CURRENTCONTROL, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);

			DWORD threadID;
			HANDLE newThread = CreateThread(0, 0, ResetButtonState, 0, 0, &threadID);
		}
		break;
		default:
		{
		}
		break;
	}
}


void Events::CalculateResult(int _passedCurrentResult, int _passedAdditionNumber, CalculationOperator _passedOperator)
{
	switch (_passedOperator)
	{
		case Events::Divison:
		{
			currentResult = _passedCurrentResult / _passedAdditionNumber;

			displayedNumber = currentResult;

			DisplayCharacter(EnteredCharacter::Action_Result);
		}
		break;
		case Events::Multiplication:
		{

		}
		break;
		case Events::Subtraction:
		{

		}
		break;
		case Events::Addition:
		{

		}
		break;
		default:
		{
		}
		break;
	}
}


DWORD WINAPI Events::ResetButtonState(__in LPVOID lpParameter)
{
	using namespace std;

	//cout << "----------------------->loop started: " << endl;

	chrono::time_point<chrono::system_clock> start, end;
	start = chrono::system_clock::now();

	long long elapsed_seconds = 0;
	
	while (keyboardPressed)
	{
		end = chrono::system_clock::now();
		/*std::cout << "keyboardinput: " << keyboardPressed << std::endl;*/
		elapsed_seconds = chrono::duration_cast<chrono::milliseconds>(end - start).count();

		if (elapsed_seconds >= 50)
		{
			start = chrono::system_clock::now();
			RedrawWindow(HANDLE_CURRENTCONTROL, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
		}
	}

	if (!keyboardInput)
	{
		RedrawWindow(HANDLE_CURRENTCONTROL, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
	}
	else
	{
		keyboardInput = false;
	}

	//cout << "mouseButtonPressed! - " << mouseButtonPressed << endl;
	//cout << "withinControl! - " << withinControl << endl;
	//cout << "keyboardPressed! - " << keyboardPressed << endl;
	//cout << "keyboardInput! - " << keyboardInput << endl;
	//cout << endl;

	//cout << "----------------------->loop ended: " << endl;

	return 0;
}


LRESULT CALLBACK Events::CustomControlsWindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	using namespace std;

	switch (msg)
	{
		case WM_LBUTTONDOWN:
		case WM_LBUTTONDBLCLK:
		{
			HANDLE_CURRENTCONTROL = hwnd;
			mouseButtonPressed = true;
			withinControl = true;

			std::wstring currentNumber = GetWindowTextToWstring(CONTROL_STATIC_NUMBER_FIELD);
			std::wstring buttonNumber = currentNumber + GetWindowTextToWstring(HANDLE_CURRENTCONTROL);

			switch (GetDlgCtrlID((HWND)HANDLE_CURRENTCONTROL))
			{
				case ID_BUTTON_ACTION_DELETEDISPLAYED:
				{
					DisplayCharacter(EnteredCharacter::Action_DeleteDisplayed);
					HandleButtonAction(InputAction::Mouse);
				}
				break;
				case ID_BUTTON_ACTION_DELETEEVERYTHING:
				{
					DisplayCharacter(EnteredCharacter::Action_DeleteEverything);
					HandleButtonAction(InputAction::Mouse);
				}
				break;
				case ID_BUTTON_ACTION_DELETECHARACTER:
				{
					DisplayCharacter(EnteredCharacter::Action_DeleteCharacter);
					HandleButtonAction(InputAction::Mouse);
				}
				break;
				case ID_BUTTON_ACTION_DIVISION:
				{
					DisplayCharacter(EnteredCharacter::Action_Disision);
					HandleButtonAction(InputAction::Mouse);
				}
				break;
				case ID_BUTTON_NUMBER_SEVEN:
				{
					DisplayCharacter(EnteredCharacter::Number_Seven);
					HandleButtonAction(InputAction::Mouse);
				}
				break;
				case ID_BUTTON_NUMBER_EIGHT:
				{
					DisplayCharacter(EnteredCharacter::Number_Eight);
					HandleButtonAction(InputAction::Mouse);
				}
				break;
				case ID_BUTTON_NUMBER_NINE:
				{
					DisplayCharacter(EnteredCharacter::Number_Nine);
					HandleButtonAction(InputAction::Mouse);
				}
				break;
				case ID_BUTTON_ACTION_MULTIPLICATION:
				{
					DisplayCharacter(EnteredCharacter::Action_Multiplication);
					HandleButtonAction(InputAction::Mouse);
				}
				break;
				case ID_BUTTON_NUMBER_FOUR:
				{
					DisplayCharacter(EnteredCharacter::Number_Four);
					HandleButtonAction(InputAction::Mouse);
				}
				break;
				case ID_BUTTON_NUMBER_FIVE:
				{
					DisplayCharacter(EnteredCharacter::Number_Five);
					HandleButtonAction(InputAction::Mouse);
				}
				break;
				case ID_BUTTON_NUMBER_SIX:
				{
					DisplayCharacter(EnteredCharacter::Number_Six);
					HandleButtonAction(InputAction::Mouse);
				}
				break;
				case ID_BUTTON_ACTION_SUBTRACTION:
				{
					DisplayCharacter(EnteredCharacter::Action_Subtraction);
					HandleButtonAction(InputAction::Mouse);
				}
				break;
				case ID_BUTTON_NUMBER_ONE:
				{
					DisplayCharacter(EnteredCharacter::Number_One);
					HandleButtonAction(InputAction::Mouse);
				}
				break;
				case ID_BUTTON_NUMBER_TWO:
				{
					DisplayCharacter(EnteredCharacter::Number_Two);
					HandleButtonAction(InputAction::Mouse);
				}
				break;
				case ID_BUTTON_NUMBER_THREE:
				{
					DisplayCharacter(EnteredCharacter::Number_Three);
					HandleButtonAction(InputAction::Mouse);
				}
				break;
				case ID_BUTTON_ACTION_ADDITION:
				{
					DisplayCharacter(EnteredCharacter::Action_Addition);
					HandleButtonAction(InputAction::Mouse);
				}
				break;
				case ID_BUTTON_CHARACTER_PLUSMINUS:
				{
					DisplayCharacter(EnteredCharacter::Character_PlusMinus);
					HandleButtonAction(InputAction::Mouse);
				}
				break;
				case ID_BUTTON_NUMBER_ZERO:
				{
					DisplayCharacter(EnteredCharacter::Number_Zero);
					HandleButtonAction(InputAction::Mouse);
				}
				break;
				case ID_BUTTON_CHARACTER_COMMA:
				{
					DisplayCharacter(EnteredCharacter::Character_Comma);
					HandleButtonAction(InputAction::Mouse);
				}
				break;
				case ID_BUTTON_ACTION_RESULT:
				{
					DisplayCharacter(EnteredCharacter::Action_Result);
					HandleButtonAction(InputAction::Mouse);
				}
				break;
				default:
				{
					mouseButtonPressed = false;
					withinControl = false;
				}
				break;
			}
			return (INT_PTR)TRUE;
		}
		break;
		case WM_LBUTTONUP:
		{
			if (mouseButtonPressed)
			{
				mouseButtonPressed = false;
				withinControl = false;
				RedrawWindow(HANDLE_CURRENTCONTROL, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
				//wcout << "Mouse button up - this is the current control text: " << GetWindowTextToWstring(HANDLE_CURRENTCONTROL) << endl;
			}
			return (INT_PTR)TRUE;
		}
		break;
		case WM_MOUSEMOVE:
		{
			if (mouseButtonPressed)
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
					case ID_BUTTON_ACTION_DELETEDISPLAYED:
					case ID_BUTTON_ACTION_DELETEEVERYTHING:
					case ID_BUTTON_ACTION_DELETECHARACTER:
					case ID_BUTTON_ACTION_DIVISION:
					case ID_BUTTON_NUMBER_SEVEN:
					case ID_BUTTON_NUMBER_EIGHT:
					case ID_BUTTON_NUMBER_NINE:
					case ID_BUTTON_ACTION_MULTIPLICATION:
					case ID_BUTTON_NUMBER_FOUR:
					case ID_BUTTON_NUMBER_FIVE:
					case ID_BUTTON_NUMBER_SIX:
					case ID_BUTTON_ACTION_SUBTRACTION:
					case ID_BUTTON_NUMBER_ONE:
					case ID_BUTTON_NUMBER_TWO:
					case ID_BUTTON_NUMBER_THREE:
					case ID_BUTTON_ACTION_ADDITION:
					case ID_BUTTON_CHARACTER_PLUSMINUS:
					case ID_BUTTON_NUMBER_ZERO:
					case ID_BUTTON_CHARACTER_COMMA:
					case ID_BUTTON_ACTION_RESULT:
					{
						if (HANDLE_CURRENTCONTROL == HANDLE_BUFFER)
						{
							//wcout << "Within control" << endl;
							if (!withinControl)
							{
								withinControl = true;
								RedrawWindow(HANDLE_CURRENTCONTROL, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
							}
						}
					}
					break;
					default:
					{
					}
					break;
				}
			}
			return (INT_PTR)TRUE;
		}
		break;
		default:
		{
		}
		break;
	}

	return CallWindowProcW(ApplicationWindowProc, hwnd, msg, wParam, lParam);
}