// Hello1.cpp
#include <windows.h>
#include <string>

using namespace std;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

///////////////////////////////////////////////////////////////////////////////////////////////
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	HWND hMainWnd;  
	char szClassName[] = "MyClass";
	MSG msg;
	WNDCLASSEX wc;
	
	// ��������� ��������� ������ ����
	wc.cbSize        = sizeof(wc);		
	wc.style         = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc   = WndProc;
	wc.cbClsExtra	 = 0;
	wc.cbWndExtra    = 0;
	wc.hInstance     = hInstance;
	wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName  = NULL;
	wc.lpszClassName = szClassName;
	wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

	// ������������ ����� ����
	if (!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Cannot register class", "Error", MB_OK);
		return 0;
	}
	
	// ������� �������� ���� ����������
	hMainWnd = CreateWindow( 
		szClassName, "A Hello1 Application", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0,
		(HWND)NULL, (HMENU)NULL,
		(HINSTANCE)hInstance, NULL
	);
	
	if (!hMainWnd) {
		MessageBox(NULL, "Cannot create main window", "Error", MB_OK);
		return 0;
	}

	// ���������� ���� ����
	ShowWindow(hMainWnd, nCmdShow); 
//	UpdateWindow(hMainWnd);

	// ��������� ���� ��������� ��������� �� �������� ����������
	while (GetMessage(&msg, NULL, 0, 0))  {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}
///////////////////////////////////////////////////////////////////////////////////////////////
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	static HDC hDC;
	static int x, y;

	PAINTSTRUCT ps;
	RECT rect;

	switch (msg)
	{
	case WM_CREATE:
		hDC = GetDC(hWnd);
		return 0;
	//case WM_PAINT:
	//	{
	//		
	//		GetClientRect(hWnd, &rect);

	//		DrawText(hDC, "Hello from Win32 API", -1, &rect,
	//			DT_SINGLELINE | DT_CENTER | DT_VCENTER );			

	//		return 0;
	//	}
	case WM_MOUSEMOVE:
		{
			x = LOWORD(lParam);
			y = HIWORD(lParam);

			char xStr[6] = "";
			char yStr[6] = "";
			
			string str;
			str.append(itoa(x, xStr, 10));
			str.append(", ");
			str.append(itoa(y, yStr, 10));

			GetClientRect(hWnd, &rect);
			DrawText(hDC, str.c_str(), -1, &rect,
					DT_SINGLELINE | DT_CENTER | DT_VCENTER );			
					
			return 0;
		}
	case WM_CLOSE:
		DestroyWindow(hWnd);
		return 0;

    case WM_DESTROY:
		ReleaseDC(hWnd, hDC);
		PostQuitMessage(0);
		return 0;

	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}

	return 0;
}