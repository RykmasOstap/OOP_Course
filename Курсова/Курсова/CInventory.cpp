#include "CInventory.h"

using namespace std;

char CInventory::Inventory(char UserMenuChoice, string name)
{
	if (UserMenuChoice == '1') //��������� ���������� � �����
	{
		Show_Info("Inventory.txt", "Object", "Count", "Price per 1", "ID");
		return UserMenuChoice = 'i';
	}
	if ((UserMenuChoice == '2') && (name == "admin")) //�������� ���������� � ����, �������� ����� ������������
	{
		Write_Info("Inventory.txt", "Object : ", "Count : ", "Price per 1 : ", "ID : ");
		return UserMenuChoice = 'i';
	}

	if (UserMenuChoice == '3') //������ ����������
	{
		Find_Info("Inventory.txt");
		return UserMenuChoice = 'i';
	}
	if ((UserMenuChoice == '4') && (name == "admin")) //���������� ����������, �������� ����� ������������
	{
		Edit_Info("Inventory.txt", "Inventory1.txt");
		return UserMenuChoice = 'i';
	}
	if ((UserMenuChoice == '5') && (name == "admin")) //�������� ����������, �������� ����� ������������
	{
		Delete_Info("Inventory.txt");
		return UserMenuChoice = 'i';
	}
	if ((UserMenuChoice == 'b') || (UserMenuChoice == 'B')) //���������� �� ������������ ����
	{
		return UserMenuChoice = 'm';
	}
	if ((UserMenuChoice == 'q') || (UserMenuChoice == 'Q')) //����� � ��������
		exit(0);
	else
		return UserMenuChoice = 'i';
}
