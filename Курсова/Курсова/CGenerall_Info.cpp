#include "CGenerall_Info.h"

using namespace std;

char CGenerall_Info::Generall_Info(char UserMenuChoice, string name)
{
	if (UserMenuChoice == '1') //��������� ���������� � �����
	{
		Show_Info("Generall_Info_information.txt", "Subsidiaries name", "Subsidiaries's_Director", "Price($)", "Income($)");
		return UserMenuChoice = 'p';
	}
	if ((UserMenuChoice == '2') && (name == "admin")) //�������� ����������, �������� ����� ������������
	{
		Write_Info("Generall_Info_information.txt", "Subsidiaries name : ", "Subsidiaries's_Director : ", "Price($) : ", "Income($) : ");
		return UserMenuChoice = 'p';
	}
	if (UserMenuChoice == '3') //������ ����������
	{
		Find_Info("Generall_Info_information.txt");
		return UserMenuChoice = 'p';
	}

	if ((UserMenuChoice == '4') && (name == "admin")) //���������� ����������, �������� ����� ������������
	{
		Edit_Info("Generall_Info_information.txt", "Generall_Info_information1.txt");
		return UserMenuChoice = 'p';
	}
	if ((UserMenuChoice == '5') && (name == "admin")) //�������� ����������, �������� ����� ������������
	{
		Delete_Info("Generall_Info_information.txt");
		return UserMenuChoice = 'p';
	}
	if ((UserMenuChoice == 'b') || (UserMenuChoice == 'B')) //���������� �� ������������ ����
	{
		return UserMenuChoice = 'm';
	}
	if ((UserMenuChoice == 'q') || (UserMenuChoice == 'Q')) //����� � ��������
		exit(0);
	else
		return UserMenuChoice = 'p';
};
