#include "CWorkers.h"
#include "CEdit.h"

char CWorkers::Workers(char UserMenuChoice, string name)
{
	if (UserMenuChoice == '1') //��������� ���������� � �����
	{
		Show_Info("Workers.txt", "Name", "Profession", "Salary($)", "Age");
		return UserMenuChoice = 'w';
	}
	if ((UserMenuChoice == '2') && (name == "admin")) //�������� ���������� � ����, �������� ����� ������������
	{
		Write_Info("Workers.txt", "Name : ", "Profession : ", "Salary($) : ", "Age : ");
		return UserMenuChoice = 'w';
	}
	if (UserMenuChoice == '3') //������ ����������
	{
		Find_Info("Workers.txt");
		return UserMenuChoice = 'w';
	}
	if ((UserMenuChoice == '4') && (name == "admin")) //���������� ����������, �������� ����� ������������
	{
		Edit_Info("Workers.txt", "Workers1.txt");
		return UserMenuChoice = 'w';
	}
	if ((UserMenuChoice == '5') && (name == "admin")) //�������� ����������, �������� ����� ������������
	{
		Delete_Info("Workers.txt");
		return UserMenuChoice = 'w';
	}
	if ((UserMenuChoice == 'b') || (UserMenuChoice == 'B')) //���������� �� ������������ ����
	{
		return UserMenuChoice = 'm';
	}

	if ((UserMenuChoice == 'q') || (UserMenuChoice == 'Q')) //����� � ��������
		exit(0);
	else
		return UserMenuChoice = 'w';
}
