#include "CMain.h"

void CMain::GetChoiceMenu()
{
	cout << "# ";
	cin >> UserMenuChoice;
}

void CMain::GetUserName()
{
	cout << "# Enter your name : "; //Ввід ім'я користувача
	cin >> name;
}

void CMain::GetUserMoney()
{
	cout << "# Enter your money ($) : "; //Ввід балансу юзера
	cin >> money;
}

void CMain::StartMenu()
{
	system("cls"); //Очищення екрану

		//Стартову меню:

	cout << left;
	cout << "#========================================#" << endl;
	cout << "# " << setw(38) << "Pharmaceutical company management : " << " #" << "\n";
	cout << "# " << setw(38) << "Main menu - press 'm'" << " #" << "\n"; //Перехід в головне меню
	cout << "# " << setw(38) << "Shopping menu - press 's'" << " #" << "\n"; //Перехід в меню покупок
	cout << "# " << setw(38) << "Quit - press 'q'" << " #" << "\n"; //Вихід з програми кнопкою
	cout << "#========================================#" << endl << endl;
}

void CMain::AuthorizationMenu()
{
	system("cls"); //Очистити екран
	cout << left;
	cout << "#========================================#" << endl;
	cout << "# " << setw(38) << "Authorization menu: " << " #" << "\n"; //Меню авторизації
}

void CMain::MainMenu()
{
	system("cls"); //Очистити екран
	cout << left;
	cout << "#======================================================#" << endl;
	cout << "# " << setw(52) << "Pharmaceutical company management -> Main menu : " << " #" << "\n";
	cout << "#======================================================#" << endl;
	cout << "# " << setw(52) << "Generall_Info_information - press 'p'" << " #" << "\n"; //Перехід в розділ основної інформації 
	if (name == "admin") //Доступно тільки адміністратору
		cout << "# " << setw(52) << "Finances - press 'f'" << " #" << "\n"; //Перехід в розділ фінансів 
	cout << "# " << setw(52) << "Merchendise - press 'm'" << " #" << "\n"; //Перехід в меню товарів 
	if (name == "admin") //Доступно тільки адміністратору
		cout << "# " << setw(52) << "Inventory - press 'i'" << " #" << "\n"; //Перехід в меню інвентарю 
	if (name == "admin") //Доступно тільки адміністратору
		cout << "# " << setw(52) << "Workers - press 'w'" << " #" << "\n"; //Перехід в меню працівників 
	cout << "# " << setw(52) << "Back - press 'b'" << " #" << "\n"; //Повернення до попереднього меню 
	cout << "# " << setw(52) << "Quit - press 'q'" << " #" << "\n"; //Вихід з програми 
	cout << "#======================================================#" << endl << endl;
}

void CMain::info_Menu(string dirName, string name)
{
	system("cls"); //Очистити екран
	cout << left;
	cout << "#================================================================================#" << endl;
	cout << "# Pharmaceutical company management -> Main menu -> " << setw(26) << dirName << " : " << "#" << "\n";
	cout << "#================================================================================#" << endl;
	cout << "# " << setw(78) << "Show data - press '1'" << " #" << "\n"; //Показати інформацію
	if (name == "admin") //Доступно тільки адміністратору
		cout << "# " << setw(78) << "Write data - press '2'" << " #" << "\n"; //Записати інформацію
	cout << "# " << setw(78) << "Find data - press '3'" << " #" << "\n"; //Знайти інформацію
	if (name == "admin") //Доступно тільки адміністратору
		cout << "# " << setw(78) << "Edit data - press '4'" << " #" << "\n"; //Знайти інформацію
	if (name == "admin") //Доступно тільки адміністратору
		cout << "# " << setw(78) << "Delete data - press '5'" << " #" << "\n"; //Видалити інформацію
	cout << "# " << setw(78) << "Back - press 'b'" << " #" << "\n"; //Повернутися до попереднього меню
	cout << "# " << setw(78) << "Quit - press 'q'" << " #" << "\n"; //Вихід з програми кнопкою 'q'
	cout << "#================================================================================#" << endl << endl;
}

int CMain::Main()
{
	fstream fout("Basket.txt", ios::out); //Відкрити файл для видалення
	fout.close();
	::buy_count_max = 0;

	while (true)
	{
		StartMenu(); //Стартове меню
		GetChoiceMenu();
		if ((UserMenuChoice == 's') || (UserMenuChoice == 'S')) //Перехід в меню покупок
		{
			CShop shop;
			shop.ShopMenu();
		}
		if ((UserMenuChoice == 'm') || (UserMenuChoice == 'M')) //Перехід в меню авторизації
		{
			AuthorizationMenu(); //Меню авторизації
			GetUserName();
			GetUserMoney();
		}
		back = false;
		while ((UserMenuChoice == 'm') || (UserMenuChoice == 'M')) //Перехід в головне меню
		{
			MainMenu();
			GetChoiceMenu();
			while ((UserMenuChoice == 'p') || (UserMenuChoice == 'P')) //Перехід в розділ основної інформації
			{
				info_Menu("Generall_Info_information", name);
				GetChoiceMenu();
				UserMenuChoice = Generall_Info(UserMenuChoice, name);
			}
			while (((UserMenuChoice == 'f') || (UserMenuChoice == 'F')) && (name == "admin")) //Перехід в розділ фінансів
			{
				info_Menu("Finances", name);
				GetChoiceMenu();
				UserMenuChoice = Finances(UserMenuChoice, name);
			}
			while (((UserMenuChoice == 'm') && (!this->back)) || ((UserMenuChoice == 'M') && (!this->back))) //Перехід в меню товарів
			{
				info_Menu("Merchendise", name);
				GetChoiceMenu();
				UserMenuChoice = Merchendise(UserMenuChoice, name);
			}
			while (((UserMenuChoice == 'i') || (UserMenuChoice == 'I')) && (name == "admin")) //Перехід в меню інвентарю
			{
				info_Menu("Inventory", name);
				GetChoiceMenu();
				UserMenuChoice = Inventory(UserMenuChoice, name);
			}
			while (((UserMenuChoice == 'w') || (UserMenuChoice == 'W')) && (name == "admin")) //Перехід в меню працівників
			{
				info_Menu("Workers", name);
				GetChoiceMenu();
				UserMenuChoice = Workers(UserMenuChoice, name);
			}
			if ((UserMenuChoice == 'b') || (UserMenuChoice == 'B')) //Повернення до попереднього меню
				break;
			if ((UserMenuChoice == 'q') || (UserMenuChoice == 'Q')) //Вихід з програми
				exit(0);
			else
				UserMenuChoice = 'm';
		}
		if ((UserMenuChoice == 'q') || (UserMenuChoice == 'Q')) //Вихід з програми
			exit(0);
	}
}
