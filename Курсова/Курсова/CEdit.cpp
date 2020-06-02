#include"CEdit.h"

using namespace std;


void CEdit::Show_Info(const char fileName[], string header1, string header2, string header3, string header4) //�������� ����������
{
	fstream fin(fileName); //³������ ���� ��� ����������
	while (!fin)
	{
		cout << "Cannot open file!\n";
		exit(0);
	}
	cout << setw(15) << left << header1 << setw(15) << header2 << setw(15) << header3 << setw(15) << header4 << '\n'; //���� ����� �������
	while (!fin.eof())
	{
		fin >> info_1 >> info_2 >> info_3 >> info_4; //���������� ����� � ����� ��� ������
		if (!fin.eof())
			cout << setw(15) << left << info_1 << setw(15) << info_2 << setw(15) << info_3 << setw(15) << info_4 << '\n'; //���� �����
	}
	if (!::shop_process) system("pause");
	fin.close(); //������� ���� ��� ����������
};
void CEdit::Write_Info(const char fileName[], string header1, string header2, string header3, string header4) //�������� ����������
{
	cout << header1;
	cin >> info_1;
	cout << header2;
	cin >> info_2;
	cout << header3;
	cin >> info_3;
	cout << header4;
	cin >> info_4;
	fstream fout(fileName, ios::app); //³������ ���� ��� ������
	if (!fout)
	{
		cout << "Cannot open file!\n";
		exit(0);
	}
	fout << setw(9) << left << info_1 << ' ' << setw(9) << info_2 << ' ' << setw(9) << info_3 << ' ' << setw(9) << info_4 << '\n'; //�����
	cout << "Data was successfully writen.\n";
	system("pause");
	fout.close();
};
void CEdit::Find_Info(const char fileName[]) //������ ����������
{
	cout << "information to find : "; //������ ���������� ��� ������
	cin >> findinfo_;
	fstream fin(fileName); //³������ ���� ��� ����������
	while (!fin)
	{
		cout << "Cannot open file!\n";
		exit(0);
	}
	while (!fin.eof())
	{
		fin >> info_;
		if (findinfo_ == info_)
		{
			cout << "information was successfully found.\n";
			isFound = true;
		}
	}
	if (!isFound)
		cout << "Not found!\n";
	system("pause");
	fin.close(); //������� ���� ��� ����������
};
void CEdit::Edit_Info(const char fileName[], const char fileName1[]) //���������� ����������
{
	cout << "information to edit : "; //������ �����, ��� ����� �������
	cin >> edinfo_;
	cout << "information to replace by : "; //������ �����, ���� �������
	cin >> repinfo_;
	fstream fin(fileName); //³������ ���� ��� ����������
	while (!fin)
	{
		cout << "Cannot open file!\n";
		exit(0);
	}
	fstream fout(fileName1, ios::out); //³������ ���� ����������
	if (!fout)
	{
		cout << "Cannot open file!\n";
		exit(0);
	}
	while (!fin.eof())
	{
		fin >> info_1 >> info_2 >> info_3 >> info_4; //���������� ����� � ����� ��� ������
		if (edinfo_ == info_1)
		{
			info_1 = repinfo_;
			isFound = true;
		}
		if (edinfo_ == info_2)
		{
			info_2 = repinfo_;
			isFound = true;
		}
		if (edinfo_ == info_3)
		{
			info_3 = repinfo_;
			isFound = true;
		}
		if (edinfo_ == info_4)
		{
			info_4 = repinfo_;
			isFound = true;
		}
		if (!fin.eof())
			fout << setw(9) << left << info_1 << ' ' << setw(9) << info_2 << ' ' << setw(9) << info_3 << ' ' << setw(9) << info_4 << '\n'; //���������
	}
	if (!isFound)
		cout << "Not found!\n";
	else
		cout << "Data was successfully edited.\n";
	system("pause");
	fin.close(); //������� ���� ��� �����������
	fout.close(); //������� ���� ��� ����������
	remove(fileName);
	rename(fileName1, fileName);
};
void CEdit::Delete_Info(const char fileName[]) //�������� ����������
{
	fstream fout(fileName, ios::out); //³������ ���� ��� ���������
	cout << "Data was successfully deleted.\n";
	system("pause");
	fout.close();
};