#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <locale>;
#include "windows.h";
using namespace std;

bool shop_process = false;
int buy_count_max;

class CEdit
{
protected:
	string info_1, info_2, info_3, info_4, findinfo_, info_, repinfo_, edinfo_;
	bool isFound = false;
public:
	void Show_Info(const char fileName[], string header1, string header2, string header3, string header4) //Показати інформацію
	{
		fstream fin(fileName); //Відкрити файл для зчитування
		while (!fin)
		{
			cout << "Cannot open file!\n";
			exit(0);
		}
		cout << setw(15) << left << header1 << setw(15) << header2 << setw(15) << header3 << setw(15) << header4 << '\n'; //Вивід шапки таблиці
		while (!fin.eof())
		{
			fin >> info_1 >> info_2 >> info_3 >> info_4; //Зчитування даних з файлу для виводу
			if (!fin.eof())
				cout << setw(15) << left << info_1 << setw(15) << info_2 << setw(15) << info_3 << setw(15) << info_4 << '\n'; //Вивід даних
		}
		if(!::shop_process) system("pause");
		fin.close(); //Закрити файл для зчитування
	}
	void Write_Info(const char fileName[], string header1, string header2, string header3, string header4) //Записати інформацію
	{
		cout << header1;
		cin >> info_1;
		cout << header2;
		cin >> info_2;
		cout << header3;
		cin >> info_3;
		cout << header4;
		cin >> info_4;
		fstream fout(fileName, ios::app); //Відкрити файл для запису
		if (!fout)
		{
			cout << "Cannot open file!\n";
			exit(0);
		}
		fout << setw(9) << left << info_1 << ' ' << setw(9) << info_2 << ' ' << setw(9) << info_3 << ' ' << setw(9) << info_4 << '\n'; //Запис
		cout << "Data was successfully writen.\n";
		system("pause");
		fout.close();
	}
	void Find_Info(const char fileName[]) //Знайти інформацію
	{
		cout << "information to find : "; //Ввести інформацію для пошуку
		cin >> findinfo_;
		fstream fin(fileName); //Відкрити файл для зчитування
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
		fin.close(); //Закрити файл для зчитування
	}
	void Edit_Info(const char fileName[], const char fileName1[]) //Редагувати інформацію
	{
		cout << "information to edit : "; //Ввести слово, яке треба замінити
		cin >> edinfo_;
		cout << "information to replace by : "; //Ввести слово, яким замінити
		cin >> repinfo_;
		fstream fin(fileName); //Відкрити файл для зчитування
		while (!fin)
		{
			cout << "Cannot open file!\n";
			exit(0);
		}
		fstream fout(fileName1, ios::out); //Відкрити файл перезапису
		if (!fout)
		{
			cout << "Cannot open file!\n";
			exit(0);
		}
		while (!fin.eof())
		{
			fin >> info_1 >> info_2 >> info_3 >> info_4; //Зчитування даних з файлу для виводу
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
				fout << setw(9) << left << info_1 << ' ' << setw(9) << info_2 << ' ' << setw(9) << info_3 << ' ' << setw(9) << info_4 << '\n'; //Перезапис
		}
		if (!isFound)
			cout << "Not found!\n";
		else
			cout << "Data was successfully edited.\n";
		system("pause");
		fin.close(); //Закрити файл для рзчитування
		fout.close(); //Закрити файл для перезапису
		remove(fileName);
		rename(fileName1, fileName);
	}
	void Delete_Info(const char fileName[]) //Видалити інформацію
	{
		fstream fout(fileName, ios::out); //Відкрити файл для видалення
		cout << "Data was successfully deleted.\n";
		system("pause");
		fout.close();
	}
};

class CGenerall_Info : public CEdit
{
public:
	char Generall_Info(char UserMenuChoice, string name)
	{
		if (UserMenuChoice == '1') //Прочитати інформацію з файлу
		{
			Show_Info("Generall_Info_information.txt", "Subsidiaries name", "Subsidiaries's_Director", "Price($)", "Income($)");
			return UserMenuChoice = 'p';
		}
		if ((UserMenuChoice == '2') && (name == "admin")) //Записати інформацію, доступно тільки адміністратору
		{
			Write_Info("Generall_Info_information.txt", "Subsidiaries name : ", "Subsidiaries's_Director : ", "Price($) : ", "Income($) : ");
			return UserMenuChoice = 'p';
		}
		if (UserMenuChoice == '3') //Знайти інформацію
		{
			Find_Info("Generall_Info_information.txt");
			return UserMenuChoice = 'p';
		}

		if ((UserMenuChoice == '4') && (name == "admin")) //Редагувати інформацію, доступно тільки адміністратору
		{
			Edit_Info("Generall_Info_information.txt", "Generall_Info_information1.txt");
			return UserMenuChoice = 'p';
		}
		if ((UserMenuChoice == '5') && (name == "admin")) //Видалити інформацію, доступно тільки адміністратору
		{
			Delete_Info("Generall_Info_information.txt");
			return UserMenuChoice = 'p';
		}
		if ((UserMenuChoice == 'b') || (UserMenuChoice == 'B')) //Повернення до попереднього меню
		{
			return UserMenuChoice = 'm';
		}
		if ((UserMenuChoice == 'q') || (UserMenuChoice == 'Q')) //Вихід з програми
			exit(0);
		else
			return UserMenuChoice = 'p';
	}
};////

class CFinances : public CEdit
{
public:
	char Finances(char UserMenuChoice, string name)
	{
		if (UserMenuChoice == '1') //Прочитати інформацію з файлу
		{
			Show_Info("Finances.txt", "Date", "Income($)", "Expense($)", "Total($)");
			return UserMenuChoice = 'f';
		}

		if ((UserMenuChoice == '2') && (name == "admin")) //Записати інформацію у файл, доступно тільки адміністратору
		{
			Write_Info("Finances.txt", "Date : ", "Income($) : ", "Expense($) : ", "Total($) : ");
			return UserMenuChoice = 'f';
		}
		if (UserMenuChoice == '3') //Знайти інформацію
		{
			Find_Info("Finances.txt");
			return UserMenuChoice = 'f';
		}
		if ((UserMenuChoice == '4') && (name == "admin")) //Редагувати інформацію, доступно тільки адміністратору
		{
			Edit_Info("Finances.txt", "Finances1.txt");
			return UserMenuChoice = 'f';
		}
		if ((UserMenuChoice == '5') && (name == "admin")) //Видалити інформацію, доступно тільки адміністратору
		{
			Delete_Info("Finances.txt");
			return UserMenuChoice = 'f';
		}
		if ((UserMenuChoice == 'b') || (UserMenuChoice == 'B')) //Повернення до попереднього меню
		{
			return UserMenuChoice = 'm';
		}
		if ((UserMenuChoice == 'q') || (UserMenuChoice == 'Q')) //Вихід з програми
			exit(0);
		else
			return UserMenuChoice = 'f';
	}
};

class CMerchendise : public CEdit
{
protected:
	bool back;
public:
	char Merchendise(char UserMenuChoice, string name)
	{
		if (UserMenuChoice == '1') //Прочитати інформацію з файлу
		{
			Show_Info("Merchendise.txt", "Merchendise", "Count", "Price per 1", "ID");
			return UserMenuChoice = 'm';
		}
		if ((UserMenuChoice == '2') && (name == "admin")) //Записати інформацію у файл, доступно тільки адміністратору
		{
			Write_Info("Merchendise.txt", "Merchendise : ", "Count : ", "Price per 1 : ", "ID : ");
			return UserMenuChoice = 'm';
		}
		if (UserMenuChoice == '3') //Знайти інформацію
		{
			Find_Info("Merchendise.txt");
			return UserMenuChoice = 'm';
		}
		if ((UserMenuChoice == '4') && (name == "admin")) //Редагувати інформацію, доступно тільки адміністратору
		{
			Edit_Info("Merchendise.txt", "Merchendise1.txt");
			return UserMenuChoice = 'm';
		}

		if ((UserMenuChoice == '5') && (name == "admin")) //Видалити інформацію, доступно тільки адміністратору
		{
			Delete_Info("Merchendise.txt");
			return UserMenuChoice = 'm';
		}
		if ((UserMenuChoice == 'b') || (UserMenuChoice == 'B')) //Повернення до попереднього меню
		{
			back = true;
			return UserMenuChoice = 'm';
		}
		if ((UserMenuChoice == 'q') || (UserMenuChoice == 'Q')) //Вихід з програми
			exit(0);
		else
			return UserMenuChoice = 'm';
	}
};

class CShop : public CMerchendise
{
public:
	void Buy()
	{
		string name;
		int count=0, price=0, id_f=0, count_o=0, id=0;
		fstream fin("Merchendise.txt");//Відкриття файла для зчитування
		fstream fout("Basket.txt", ios::app); //Відкрити файл для запису
		while (!fin)
		{
			cout << "Cannot open file!\n";
			exit(0);
		}
		if (!fout)
		{
			cout << "Cannot open file!\n";
			exit(0);
		}
		cout << "#========================================#" << endl;
		cout << "# " << setw(38) << "Shop menu: " << " #" << "\n"; //Меню shop
		::CMerchendise::Merchendise('1', "name");
		cout << "# Enter id of product or '0' for exit:" << endl<<"# ";
		cin >> (id);
		if (id == 0) ::shop_process = false;
		while (!fin.eof()&&(id)!=0)
		{
			fin >> name >> count >> price >> id_f;
			if ((id) == id_f)
			{
				cout << endl << "# Enter count: ";
				cin >> count_o;

				fout << setw(9) << left << name << ' ' << setw(9) << price << ' ' << setw(9) << id_f << ' ' << setw(9) << count_o;//Запис
				if (count_o > count)
				{
					fout << setw(9) << 0 << '\n'; //Запис
				}
				else
				{
					fout<< setw(9) << (price*count_o) << '\n'; //Запис
				}
				::buy_count_max++;
				break;
			}
		}

		fout.close();		
		fin.close();
	}

	void Basket()
	{
		string name;
		int price=0, id=0, count=0, price_b=0, g_price=0, buy_count=::buy_count_max;
		system("cls"); //Очистити екран
		cout << "#========================================#" << endl;
		cout <<left<< "# " << setw(38) << "Shop menu: Basket: " << " #" << "\n"; //Меню корзини
		
		fstream fin("Basket.txt"); //Відкрити файл для зчитування
		while (!fin)
		{
			cout << "Cannot open file!\n";
			exit(0);
		}
		fin.seekg(ios::beg, 0);
		cout << setw(20) << left << "Merchendise" << setw(15) << "Price per 1" << setw(15) << "ID" << setw(20) << "You order" << setw(20) << "Order price"<< '\n'; //Вивід шапки таблиці
		while (!fin.eof()&&buy_count>0)
		{
			fin >> name >> price >> id>>count>>price_b; //Зчитування даних з файлу
			cout <<'#'<< setw(20) << left << name << setw(15) << price << setw(15) << id << setw(20) << count << setw(20) << price_b << '#' << '\n';
			g_price += price_b;
			buy_count--;
		}
		cout<< right<<setfill('=')<<'#'<<setw(69)<<"= You must pay: " << setfill(' ') <<left<< setw(20)<<g_price << '#' <<endl;

		system("pause");

		fin.close(); //Закрити файл для зчитування

	}

	void ShopMenu()
	{
		system("cls"); //Очистити екран
		int arr_count_max = 0,arr_count=0, id=-1;
		char choice;
		cout << left;
		cout << "#========================================#" << endl;
		cout << "# " << setw(38) << "Do you want to continue shopping or order everything in the cart? (Y/N)" << " #" << "\n"<< "# "; //Меню shop
		cin >> choice;
		system("cls"); //Очистити екран
		if ((choice == 'y') || (choice == 'Y'))
		{
			::shop_process = true;
			while (::shop_process)
			{
				Buy();
				system("cls"); //Очистити екран
			}
		}

		Basket();


	}
};////

class CInventory : public CEdit
{
public:
	char Inventory(char UserMenuChoice, string name)
	{
		if (UserMenuChoice == '1') //Прочитати інформацію з файлу
		{
			Show_Info("Inventory.txt", "Object", "Count", "Price per 1", "ID");
			return UserMenuChoice = 'i';
		}
		if ((UserMenuChoice == '2') && (name == "admin")) //Записати інформацію у файл, доступно тільки адміністратору
		{
			Write_Info("Inventory.txt", "Object : ", "Count : ", "Price per 1 : ", "ID : ");
			return UserMenuChoice = 'i';
		}

		if (UserMenuChoice == '3') //Знайти інформацію
		{
			Find_Info("Inventory.txt");
			return UserMenuChoice = 'i';
		}
		if ((UserMenuChoice == '4') && (name == "admin")) //Редагувати інформацію, доступно тільки адміністратору
		{
			Edit_Info("Inventory.txt", "Inventory1.txt");
			return UserMenuChoice = 'i';
		}
		if ((UserMenuChoice == '5') && (name == "admin")) //Видалити інформацію, доступно тільки адміністратору
		{
			Delete_Info("Inventory.txt");
			return UserMenuChoice = 'i';
		}
		if ((UserMenuChoice == 'b') || (UserMenuChoice == 'B')) //Повернення до попереднього меню
		{
			return UserMenuChoice = 'm';
		}
		if ((UserMenuChoice == 'q') || (UserMenuChoice == 'Q')) //Вихід з програми
			exit(0);
		else
			return UserMenuChoice = 'i';
	}
};

class CWorkers : public CEdit
{
public:
	char Workers(char UserMenuChoice, string name)
	{
		if (UserMenuChoice == '1') //Прочитати інформацію з файлу
		{
			Show_Info("Workers.txt", "Name", "Profession", "Salary($)", "Age");
			return UserMenuChoice = 'w';
		}
		if ((UserMenuChoice == '2') && (name == "admin")) //Записати інформацію у файл, доступно тільки адміністратору
		{
			Write_Info("Workers.txt", "Name : ", "Profession : ", "Salary($) : ", "Age : ");
			return UserMenuChoice = 'w';
		}
		if (UserMenuChoice == '3') //Знайти інформацію
		{
			Find_Info("Workers.txt");
			return UserMenuChoice = 'w';
		}
		if ((UserMenuChoice == '4') && (name == "admin")) //Редагувати інформацію, доступно тільки адміністратору
		{
			Edit_Info("Workers.txt", "Workers1.txt");
			return UserMenuChoice = 'w';
		}
		if ((UserMenuChoice == '5') && (name == "admin")) //Видалити інформацію, доступно тільки адміністратору
		{
			Delete_Info("Workers.txt");
			return UserMenuChoice = 'w';
		}
		if ((UserMenuChoice == 'b') || (UserMenuChoice == 'B')) //Повернення до попереднього меню
		{
			return UserMenuChoice = 'm';
		}

		if ((UserMenuChoice == 'q') || (UserMenuChoice == 'Q')) //Вихід з програми
			exit(0);
		else
			return UserMenuChoice = 'w';
	}
};

class CMain : public CGenerall_Info, public CFinances, public CInventory, public CWorkers, public CShop
{
private:
	char UserMenuChoice;
	string name;
	float money;
public:
	void GetChoiceMenu()////
	{
		cout << "# ";
		cin >> UserMenuChoice;
	}
	void GetUserName()////
	{
		cout << "# Enter your name : "; //Ввід ім'я користувача
		cin >> name;
		
	}
	void GetUserMoney()////
	{
		cout << "# Enter your money ($) : "; //Ввід балансу юзера
		cin >> money;
	}
	void StartMenu() ////
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
	void AuthorizationMenu()////
	{
		system("cls"); //Очистити екран
		cout << left;
		cout << "#========================================#" << endl;
		cout << "# " << setw(38) << "Authorization menu: " << " #" << "\n"; //Меню авторизації
	}
	void MainMenu()
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
		cout << "#======================================================#" << endl<<endl;
	}////
	void info_Menu(string dirName, string name)
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
	}////
	int Main()
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
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	CMain main;
	main.Main();
	return 0;
}
