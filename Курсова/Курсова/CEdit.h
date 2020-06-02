#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

extern bool shop_process;
extern int buy_count_max;

class CEdit
{
protected:
	string info_1, info_2, info_3, info_4, findinfo_, info_, repinfo_, edinfo_;
	bool isFound = false;
public:
	void Show_Info(const char fileName[], string header1, string header2, string header3, string header4);
	void Write_Info(const char fileName[], string header1, string header2, string header3, string header4);
	void Find_Info(const char fileName[]);
	void Edit_Info(const char fileName[], const char fileName1[]);
	void Delete_Info(const char fileName[]);
};