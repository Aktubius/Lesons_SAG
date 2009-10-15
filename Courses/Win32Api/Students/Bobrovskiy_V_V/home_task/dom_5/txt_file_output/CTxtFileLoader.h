#ifndef _MY_PAGE_LOAD_CLASS_
#define _MY_PAGE_LOAD_CLASS_
//----
#include "windows.h"
#include <string>
#include <vector>
#include <fstream>
//----

class CTxtFileLoader{
private:
	std::vector<int> currentFilePos;
	std::string fileName;
	long fileSize;
	int pageCount;
	int pageNumber;
	enum {pageSize = 60};
	std::vector<std::string> page;
	int GetFileSize(const std::string txtFileName);
public:
	CTxtFileLoader();
	CTxtFileLoader(const std::string txtFileName); //load first page
	~CTxtFileLoader(); 
	//---
	void LoadNextPage();
	void LoadPrevPage();
	void FormatTextOutput(HWND hWnd);
	void DrawPageText(HWND hWnd);
	//---
	void init(const std::string txtFileName);
	void operator ()(const std::string txtFileName);
	//-------------------
	void Initialize(LPTEXTMETRIC tm);
	void ScrollSettings(HWND hwnd, int width, int height);
	void UpdateHscroll(HWND hwnd, int xInc);
	void UpdateVscroll(HWND hwnd, int yInc);
	void PutText(HWND hwnd, HDC hdc);
	const LOGFONT DefineFont(HWND hWnd);

	int cxChar;     // ������� ������ �������
	int yStep;      // ������ (���) ������
	int lineLenMax; // ������������ ����� ������

	SCROLLINFO vsi; // ������������ ���������
	int vertRange;  // �������� ������������ ������ ���������
	SCROLLINFO hsi; // �������������� ���������
	int horzRange;  // �������� �������������� ������ ���������
	//-------------------
};

//----
#endif