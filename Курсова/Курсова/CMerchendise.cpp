#include "CMerchendise.h"

using namespace std;

char CMerchendise::Merchendise(char UserMenuChoice, string name)
{
	if (UserMenuChoice == '1') //��������� ���������� � �����
	{
		Show_Info("Merchendise.txt", "Merchendise", "Count", "Price per 1", "ID");
		return UserMenuChoice = 'm';
	}
	if ((UserMenuChoice == '2') && (name == "admin")) //�������� ���������� � ����, �������� ����� ������������
	{
		Write_Info("Merchendise.txt", "Merchendise : ", "Count : ", "Price per 1 : ", "ID : ");
		return UserMenuChoice = 'm';
	}
	if (UserMenuChoice == '3') //������ ����������
	{
		Find_Info("Merchendise.txt");
		return UserMenuChoice = 'm';
	}
	if ((UserMenuChoice == '4') && (name == "admin")) //���������� ����������, �������� ����� ������������
	{
		Edit_Info("Merchendise.txt", "Merchendise1.txt");
		return UserMenuChoice = 'm';
	}

	if ((UserMenuChoice == '5') && (name == "admin")) //�������� ����������, �������� ����� ������������
	{
		Delete_Info("Merchendise.txt");
		return UserMenuChoice = 'm';
	}
	if ((UserMenuChoice == 'b') || (UserMenuChoice == 'B')) //���������� �� ������������ ����
	{
		back = true;
		return UserMenuChoice = 'm';
	}
	if ((UserMenuChoice == 'q') || (UserMenuChoice == 'Q')) //����� � ��������
		exit(0);
	else
		return UserMenuChoice = 'm';
}
