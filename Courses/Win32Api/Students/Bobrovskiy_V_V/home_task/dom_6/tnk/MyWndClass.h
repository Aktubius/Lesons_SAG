#ifndef _MY_WND_CLASS_
#define _MY_WND_CLASS_
//----------------------
#include "windows.h"
#include <string>
#include "BackBuffer.h" 
#include "Vec2.h" 
#include <list> 
//---
class MyWndClass{
private:
	HWND hMainWnd;
	MSG msg;
	UINT umsg;
	WNDCLASSEX wc;
	HINSTANCE hInstance;
	std::string szClassName;
	//---
	static LRESULT CALLBACK WndProcStub(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam);
	LRESULT WndProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam);
	//---
	void CreateWndClass();
	int CreateWnd();
	//---
	void create_Grid();
	void loadMap();
	void drawGrid(const HWND hWnd);
	//---
	int  Runn(); 	
	//---
public:
	MyWndClass();
	MyWndClass(HINSTANCE hInstance);		
	int Run();
};
typedef MyWndClass* pMyWndClass;

//----------------------
#endif