#include "CListOfFiles.h"
#include <fstream>
//-------------------------
CListOfFiles::CListOfFiles() {
///-----

};
//---
CListOfFiles::~CListOfFiles(){
///------

};
//---
void CListOfFiles::removeFile(std::string fileName){
///------
	remove(fileName.c_str());
};
//---
void CListOfFiles::createListOfFiles(std::string dirName){
///------
	std::string path = 	dirName;
	// �������� ����� ������ 
	std::string mask("*.txt");
	// �������� ��� ������, �� ������� ���������
	// �.�. ��� ����� ����� ������������ � ���
	std::string fullpath;
	 fullpath.assign(path);
	  fullpath.append(mask);
	//strcat(path, mask);
		
	// ���������� ��������� fileinfo �� ��������� _finddata_t
	// � �������� ������������� ������� ��������� _finddata_t
    _finddata_t *fileinfo=new _finddata_t;	

	// �������� �����
	long done = _findfirst(fullpath.c_str(),fileinfo);

	// ���� done ����� ��������� -1, 
	// �� ����� ����� �����������
	int MayWeWork = done;	

	// �������, �������� ���������� � ���������� �������� ������.	
	int count = 0;   
	while (MayWeWork!=-1) {	
		count++;
		this->listOfFiles.push_back(fileinfo->name);
		//cout << fileinfo->name << "\n\n"; 
		// �������� ����� ��������� ���� �� ������
		MayWeWork = _findnext(done, fileinfo);        
	}
	// ������� ������
	_findclose(done);
	delete fileinfo;

};
//---
std::vector<std::string>& CListOfFiles::getListOfFiles(){
///------
	return this->listOfFiles;
};
//---
void CListOfFiles::writedatatofile( inStrucData& datastruct) {
///--------
	std::string filename;
	//--- form file name --
	filename.append("..\\formlist\\");
	filename.append(datastruct.Name);
	filename.append("_");
	filename.append(datastruct.Surname);
	filename.append("_");
	filename.append(datastruct.ThirdName);
	filename.append(".txt");
	//-----
	ofstream write(filename.c_str());
	//------
	write << datastruct.Name <<"\r\n";
	 write << datastruct.Surname <<"\r\n";
	 write << datastruct.ThirdName <<"\r\n";
	 write << datastruct.Gender <<"\r\n";
	 write << datastruct.Phone <<"\r\n";
	 write << datastruct.Nationality <<"\r\n";
	 write << datastruct.FamilyState <<"\r\n";
	 write << datastruct.Adress <<"\r\n";
	 //------
	write.close();

};
const inStrucData& CListOfFiles::readdatafromfile(std::string fileName) {
///--------
	inStrucData data;
	TCHAR str[40];
	std::string fullname;
	fullname.append("..\\formlist\\");
	fullname.append(fileName.c_str());
	ifstream read(fullname.c_str());
	//---------
	read>>data.Name;
	read>>data.Surname;
	read>>data.ThirdName;
	read>>data.Gender;
	read>>data.Phone;
	read>>data.Nationality;
	read>>data.FamilyState;
	read>>data.Adress;
	//----------
	read.close();
	return data;
};