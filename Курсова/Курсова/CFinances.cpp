#include "CFinances.h"

using namespace std;

char CFinances::Finances(char UserMenuChoice, string name)
{
	if (UserMenuChoice == '1') //��������� ���������� � �����
	{
		Show_Info("Finances.txt", "Date", "Income($)", "Expense($)", "Total($)");
		return UserMenuChoice = 'f';
	}

	if ((UserMenuChoice == '2') && (name == "admin")) //�������� ���������� � ����, �������� ����� ������������
	{
		Write_Info("Finances.txt", "Date : ", "Income($) : ", "Expense($) : ", "Total($) : ");
		return UserMenuChoice = 'f';
	}
	if (UserMenuChoice == '3') //������ ����������
	{
		Find_Info("Finances.txt");
		return UserMenuChoice = 'f';
	}
	if ((UserMenuChoice == '4') && (name == "admin")) //���������� ����������, �������� ����� ������������
	{
		Edit_Info("Finances.txt", "Finances1.txt");
		return UserMenuChoice = 'f';
	}
	if ((UserMenuChoice == '5') && (name == "admin")) //�������� ����������, �������� ����� ������������
	{
		Delete_Info("Finances.txt");
		return UserMenuChoice = 'f';
	}
	if ((UserMenuChoice == 'b') || (UserMenuChoice == 'B')) //���������� �� ������������ ����
	{
		return UserMenuChoice = 'm';
	}
	if ((UserMenuChoice == 'q') || (UserMenuChoice == 'Q')) //����� � ��������
		exit(0);
	else
		return UserMenuChoice = 'f';
}
