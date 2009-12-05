#ifndef _MY_WND_CLASS_
#define _MY_WND_CLASS_
//----------------------
#include "windows.h"
#include <string>
#include <wingdi.h>
#include "math.h"
//----------------------
class MyWndClass{
private:
	HWND hMainWnd;
	MSG msg;
	UINT umsg;
	WNDCLASSEX wc;
	HINSTANCE hInstance;
	std::string szClassName;
	//here using the stub function mechanizm to avoid static variables and function in WndProc.
	static LRESULT CALLBACK WndProcStub(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam);
	LRESULT WndProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam);
	//---
	void CreateWndClass();
	int CreateWnd();
	//---
	void circleDiagram(HWND hWnd);
	void DrawPartOfPie(HWND hWnd,const COLORREF col,const int startAngle,const int endAngle,const char* str);
	//---
	
public:
	MyWndClass();
	MyWndClass(HINSTANCE hInstance);		
	int Run();
};
//---
typedef MyWndClass* pMyWndClass;
//----------------------
#endif