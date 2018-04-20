#pragma once
#include "Calculator.h"
#include <CommCtrl.h>
#include <vector>


// Virtual KeyCodes
#define VK_KEY_0								0x30
#define VK_KEY_1								0x31
#define VK_KEY_2								0x32
#define VK_KEY_3								0x33
#define VK_KEY_4								0x34
#define VK_KEY_5								0x35
#define VK_KEY_6								0x36
#define VK_KEY_7								0x37
#define VK_KEY_8								0x38
#define VK_KEY_9								0x39

// -------- Edit IDs --------
#define ID_EDIT_TEXTHOLDER						1100
#define ID_EDIT_WINDOWTEXT						1101
#define ID_EDIT_CLASSTEXT						1102


// -------- Button IDs --------


// -------- ComboBox IDs --------
#define ID_COMBOBOX_							1300


// -------- Static IDs --------
#define ID_STATIC_NUMBER_FIELD					1400
#define ID_STATIC_NUMBER_ONE					1401
#define ID_STATIC_NUMBER_TWO					1402
#define ID_STATIC_NUMBER_THREE					1403
#define ID_STATIC_NUMBER_FOUR					1404
#define ID_STATIC_NUMBER_FIVE					1405
#define ID_STATIC_NUMBER_SIX					1406
#define ID_STATIC_NUMBER_SEVEN					1407
#define ID_STATIC_NUMBER_EIGHT					1408
#define ID_STATIC_NUMBER_NINE					1409
#define ID_STATIC_NUMBER_ZERO					1410


// -------- CheckBox IDs --------
#define ID_CHECKBOX_DYNAMIC_CAPTURECHECK_ONE	1500


// -------- UpDown handles --------
#define ID_UPDOWN_EDIT_SETPOS_X					1600


// Custom messages
#define WM_GETWINDOWHANDLE (WM_USER + 1) //RegisterWindowMessageW(L"WindowMessage_GetMainWindowHandle")


class Events
{
public:
	// -------- Contructoor and destructor --------
	Events();
	~Events();
	// --------------------------------------------

	typedef struct WindowsEventArguments
	{
		HWND             hWnd;
		WPARAM           wParam;
		LPARAM           lParam;
		HINSTANCE        hIns;
	}WndEventArgs, *lpWndEventArgs;



	struct EVENTHANDLER
	{
		unsigned int     Code;
		LRESULT(*fnPtr)(lpWndEventArgs);
	};

	// Event functions declaration
	static LRESULT					MainWindowProc_OnCreate(lpWndEventArgs Wea);
	static LRESULT					MainWindowProc_OnPaint(lpWndEventArgs Wea);
	static LRESULT					MainWindowProc_OnClose(lpWndEventArgs Wea);
	static LRESULT					MainWindowProc_GetWindowHandle(lpWndEventArgs Wea);
	static LRESULT					MainWindowProc_OnDawControl(lpWndEventArgs Wea);
	static LRESULT					MainWindowProc_OnMouseMove(lpWndEventArgs Wea);
	static LRESULT					MainWindowProc_OnKeyDown(lpWndEventArgs Wea);

	// -------- Normal functions and global hooks --------
	static LRESULT CALLBACK			GlobalKeyboardHook(int nCode, WPARAM wParam, LPARAM lParam);
	static LRESULT CALLBACK			GlobalMouseHook(int nCode, WPARAM wParam, LPARAM lParam);

	static void						GetWindowPos(HWND hWnd, int *x, int *y);
	static INT_PTR					PaintButtonBackground(LPARAM _passedlParam, WPARAM _passedwParam);
	static void						HandleItemDrawing(LPDRAWITEMSTRUCT _passedControlStruct, std::wstring _controlText);

	
private:
#pragma region Variables:
	// Function declarations
	static std::wstring				GetWindowTextToWstring(HWND _passedHandle);
	static std::wstring				GetClassNameToWstring(HWND _passedHandle);
	static LRESULT CALLBACK			CustomControlsWindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

	static WNDPROC ApplicationWindowProc;
	static bool buttonPressed;
	static bool withinControl;

	// -------- Miscellaneous handles --------
	static HWND HANDLE_MAINWINDOW;
	static HWND HANDLE_CURRENTCONTROL;


	// -------- Edit handles --------


	// -------- Button handles --------
	static HWND TestButton;

	// -------- ComboBox handles --------


	// -------- Static handles --------
	static HWND CONTROL_STATIC_NUMBER_FIELD;
	static HWND CONTROL_STATIC_NUMBER_ONE;
	static HWND CONTROL_STATIC_NUMBER_TWO;
	static HWND CONTROL_STATIC_NUMBER_THREE;
	static HWND CONTROL_STATIC_NUMBER_FOUR;
	static HWND CONTROL_STATIC_NUMBER_FIVE;
	static HWND CONTROL_STATIC_NUMBER_SIX;
	static HWND CONTROL_STATIC_NUMBER_SEVEN;
	static HWND CONTROL_STATIC_NUMBER_EIGHT;
	static HWND CONTROL_STATIC_NUMBER_NINE;

	static HWND CONTROL_STATIC_NUMBER_ZERO;


	// -------- CheckBox handles --------


	// -------- UpDown handles --------


#pragma endregion
};
