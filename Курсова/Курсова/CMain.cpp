#include "CMain.h"

void CMain::GetChoiceMenu()
{
	cout << "# ";
	cin >> UserMenuChoice;
}

void CMain::GetUserName()
{
	cout << "# Enter your name : "; //��� ��'� �����������
	cin >> name;
}

void CMain::GetUserMoney()
{
	cout << "# Enter your money ($) : "; //��� ������� �����
	cin >> money;
}

void CMain::StartMenu()
{
	system("cls"); //�������� ������

		//�������� ����:

	cout << left;
	cout << "#========================================#" << endl;
	cout << "# " << setw(38) << "Pharmaceutical company management : " << " #" << "\n";
	cout << "# " << setw(38) << "Main menu - press 'm'" << " #" << "\n"; //������� � ������� ����
	cout << "# " << setw(38) << "Shopping menu - press 's'" << " #" << "\n"; //������� � ���� �������
	cout << "# " << setw(38) << "Quit - press 'q'" << " #" << "\n"; //����� � �������� �������
	cout << "#========================================#" << endl << endl;
}

void CMain::AuthorizationMenu()
{
	system("cls"); //�������� �����
	cout << left;
	cout << "#========================================#" << endl;
	cout << "# " << setw(38) << "Authorization menu: " << " #" << "\n"; //���� �����������
}

void CMain::MainMenu()
{
	system("cls"); //�������� �����
	cout << left;
	cout << "#======================================================#" << endl;
	cout << "# " << setw(52) << "Pharmaceutical company management -> Main menu : " << " #" << "\n";
	cout << "#======================================================#" << endl;
	cout << "# " << setw(52) << "Generall_Info_information - press 'p'" << " #" << "\n"; //������� � ����� ������� ���������� 
	if (name == "admin") //�������� ����� ������������
		cout << "# " << setw(52) << "Finances - press 'f'" << " #" << "\n"; //������� � ����� ������� 
	cout << "# " << setw(52) << "Merchendise - press 'm'" << " #" << "\n"; //������� � ���� ������ 
	if (name == "admin") //�������� ����� ������������
		cout << "# " << setw(52) << "Inventory - press 'i'" << " #" << "\n"; //������� � ���� ��������� 
	if (name == "admin") //�������� ����� ������������
		cout << "# " << setw(52) << "Workers - press 'w'" << " #" << "\n"; //������� � ���� ���������� 
	cout << "# " << setw(52) << "Back - press 'b'" << " #" << "\n"; //���������� �� ������������ ���� 
	cout << "# " << setw(52) << "Quit - press 'q'" << " #" << "\n"; //����� � �������� 
	cout << "#======================================================#" << endl << endl;
}

void CMain::info_Menu(string dirName, string name)
{
	system("cls"); //�������� �����
	cout << left;
	cout << "#================================================================================#" << endl;
	cout << "# Pharmaceutical company management -> Main menu -> " << setw(26) << dirName << " : " << "#" << "\n";
	cout << "#================================================================================#" << endl;
	cout << "# " << setw(78) << "Show data - press '1'" << " #" << "\n"; //�������� ����������
	if (name == "admin") //�������� ����� ������������
		cout << "# " << setw(78) << "Write data - press '2'" << " #" << "\n"; //�������� ����������
	cout << "# " << setw(78) << "Find data - press '3'" << " #" << "\n"; //������ ����������
	if (name == "admin") //�������� ����� ������������
		cout << "# " << setw(78) << "Edit data - press '4'" << " #" << "\n"; //������ ����������
	if (name == "admin") //�������� ����� ������������
		cout << "# " << setw(78) << "Delete data - press '5'" << " #" << "\n"; //�������� ����������
	cout << "# " << setw(78) << "Back - press 'b'" << " #" << "\n"; //����������� �� ������������ ����
	cout << "# " << setw(78) << "Quit - press 'q'" << " #" << "\n"; //����� � �������� ������� 'q'
	cout << "#================================================================================#" << endl << endl;
}

int CMain::Main()
{
	fstream fout("Basket.txt", ios::out); //³������ ���� ��� ���������
	fout.close();
	::buy_count_max = 0;

	while (true)
	{
		StartMenu(); //�������� ����
		GetChoiceMenu();
		if ((UserMenuChoice == 's') || (UserMenuChoice == 'S')) //������� � ���� �������
		{
			CShop shop;
			shop.ShopMenu();
		}
		if ((UserMenuChoice == 'm') || (UserMenuChoice == 'M')) //������� � ���� �����������
		{
			AuthorizationMenu(); //���� �����������
			GetUserName();
			GetUserMoney();
		}
		back = false;
		while ((UserMenuChoice == 'm') || (UserMenuChoice == 'M')) //������� � ������� ����
		{
			MainMenu();
			GetChoiceMenu();
			while ((UserMenuChoice == 'p') || (UserMenuChoice == 'P')) //������� � ����� ������� ����������
			{
				info_Menu("Generall_Info_information", name);
				GetChoiceMenu();
				UserMenuChoice = Generall_Info(UserMenuChoice, name);
			}
			while (((UserMenuChoice == 'f') || (UserMenuChoice == 'F')) && (name == "admin")) //������� � ����� �������
			{
				info_Menu("Finances", name);
				GetChoiceMenu();
				UserMenuChoice = Finances(UserMenuChoice, name);
			}
			while (((UserMenuChoice == 'm') && (!this->back)) || ((UserMenuChoice == 'M') && (!this->back))) //������� � ���� ������
			{
				info_Menu("Merchendise", name);
				GetChoiceMenu();
				UserMenuChoice = Merchendise(UserMenuChoice, name);
			}
			while (((UserMenuChoice == 'i') || (UserMenuChoice == 'I')) && (name == "admin")) //������� � ���� ���������
			{
				info_Menu("Inventory", name);
				GetChoiceMenu();
				UserMenuChoice = Inventory(UserMenuChoice, name);
			}
			while (((UserMenuChoice == 'w') || (UserMenuChoice == 'W')) && (name == "admin")) //������� � ���� ����������
			{
				info_Menu("Workers", name);
				GetChoiceMenu();
				UserMenuChoice = Workers(UserMenuChoice, name);
			}
			if ((UserMenuChoice == 'b') || (UserMenuChoice == 'B')) //���������� �� ������������ ����
				break;
			if ((UserMenuChoice == 'q') || (UserMenuChoice == 'Q')) //����� � ��������
				exit(0);
			else
				UserMenuChoice = 'm';
		}
		if ((UserMenuChoice == 'q') || (UserMenuChoice == 'Q')) //����� � ��������
			exit(0);
	}
}
