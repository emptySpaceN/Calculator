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


// -------- Static IDs --------
#define ID_STATIC_NUMBER_FIELD					1201


// -------- Button IDs --------
#define ID_BUTTON_ACTION_DELETEDISPLAYED		1301
#define ID_BUTTON_ACTION_DELETEEVERYTHING		1302
#define ID_BUTTON_ACTION_DELETECHARACTER		1303
#define ID_BUTTON_ACTION_DIVISION				1304

#define ID_BUTTON_NUMBER_SEVEN					1305
#define ID_BUTTON_NUMBER_EIGHT					1306
#define ID_BUTTON_NUMBER_NINE					1307
#define ID_BUTTON_ACTION_MULTIPLICATION			1308

#define ID_BUTTON_NUMBER_FOUR					1309
#define ID_BUTTON_NUMBER_FIVE					1310
#define ID_BUTTON_NUMBER_SIX					1311
#define ID_BUTTON_ACTION_SUBTRACTION			1312

#define ID_BUTTON_NUMBER_ONE					1313
#define ID_BUTTON_NUMBER_TWO					1314
#define ID_BUTTON_NUMBER_THREE					1315
#define ID_BUTTON_ACTION_ADDITION				1316

#define ID_BUTTON_CHARACTER_PLUSMINUS			1317
#define ID_BUTTON_NUMBER_ZERO					1318
#define ID_BUTTON_CHARACTER_COMMA				1319
#define ID_BUTTON_ACTION_RESULT					1320


// -------- ComboBox IDs --------


// -------- CheckBox IDs --------


// -------- UpDown handles --------


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

	enum EnteredCharacter
	{
		Number_Zero,
		Number_One,
		Number_Two,
		Number_Three,
		Number_Four,
		Number_Five,
		Number_Six,
		Number_Seven,
		Number_Eight,
		Number_Nine,
		Character_PlusMinus,
		Character_Comma,
		Action_DeleteDisplayed,
		Action_DeleteEverything,
		Action_DeleteCharacter,
		Action_Addition,
		Action_Subtraction,
		Action_Disision,
		Action_Multiplication,
		Action_Result
	};

	enum InputAction
	{
		Mouse,
		Keyboard
	};

	enum CalculationOperator
	{
		Divison,
		Multiplication,
		Subtraction,
		Addition
	};

	// Event functions declaration
	static LRESULT					MainWindowProc_OnCreate(lpWndEventArgs Wea);
	static LRESULT					MainWindowProc_OnPaint(lpWndEventArgs Wea);
	static LRESULT					MainWindowProc_OnClose(lpWndEventArgs Wea);
	static LRESULT					MainWindowProc_GetWindowHandle(lpWndEventArgs Wea);
	static LRESULT					MainWindowProc_OnDawControl(lpWndEventArgs Wea);
	static LRESULT					MainWindowProc_OnMouseMove(lpWndEventArgs Wea);
	static LRESULT					MainWindowProc_OnKeyDown(lpWndEventArgs Wea);
	static LRESULT					MainWindowProc_OnKeyUp(lpWndEventArgs Wea);

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
	static double					ConcatenateInteger(double _passedNumberOne, double _passedNumberTwo);
	static double					RemoveDigitFromInteger(double _passedNumber);

	static void						DisplayCharacter(EnteredCharacter _passedCharacter);
	static void						HandleButtonAction(InputAction _passedAction, HWND _passedNewCurrentControl);
	static void						CalculateResult(double _passedCurrentResult, double _passedAdditionNumber, CalculationOperator _passedOperator);

	static DWORD WINAPI				ResetButtonState(__in LPVOID lpParameter);
	static LRESULT CALLBACK			CustomControlsWindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

		
	// Vaiables
	static WNDPROC ApplicationWindowProc;

	static bool mouseButtonPressed;
	static bool keyboardPressed;
	static bool withinControl;
	static bool keyboardInput;
	static bool updateDisplayedContent;

	static double displayedNumber;
	static double additionalNumber;
	static double currentResult;


	// -------- Miscellaneous handles --------
	static HWND HANDLE_MAINWINDOW;
	static HWND HANDLE_CURRENTCONTROL;


	// -------- Edit handles --------


	// -------- Static handles --------
	static HWND CONTROL_STATIC_NUMBER_FIELD;


	// -------- Button handles --------
	static HWND CONTROL_BUTTON_ACTION_DELETEDISPLAYED;
	static HWND CONTROL_BUTTON_ACTION_DELETEEVERYTHING;
	static HWND CONTROL_BUTTON_ACTION_DELETECHARACTER;
	static HWND CONTROL_BUTTON_ACTION_DIVISION;
	
	static HWND CONTROL_BUTTON_NUMBER_ONE;
	static HWND CONTROL_BUTTON_NUMBER_TWO;
	static HWND CONTROL_BUTTON_NUMBER_THREE;
	static HWND CONTROL_BUTTON_ACTION_MULTIPLICATION;
	
	static HWND CONTROL_BUTTON_NUMBER_FOUR;
	static HWND CONTROL_BUTTON_NUMBER_FIVE;
	static HWND CONTROL_BUTTON_NUMBER_SIX;
	static HWND CONTROL_BUTTON_ACTION_SUBTRACTION;

	static HWND CONTROL_BUTTON_NUMBER_SEVEN;
	static HWND CONTROL_BUTTON_NUMBER_EIGHT;
	static HWND CONTROL_BUTTON_NUMBER_NINE;
	static HWND CONTROL_BUTTON_ACTION_ADDITION;

	static HWND CONTROL_BUTTON_PLUSMINUS;
	static HWND CONTROL_BUTTON_NUMBER_ZERO;
	static HWND CONTROL_BUTTON_CHARACTER_COMMA;
	static HWND CONTROL_BUTTON_ACTION_RESULT;


	// -------- ComboBox handles --------
	

	// -------- CheckBox handles --------


	// -------- UpDown handles --------


#pragma endregion
};
