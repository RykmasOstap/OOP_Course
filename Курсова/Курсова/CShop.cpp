#include "CShop.h"

using namespace std;

void CShop::Buy()
{
	string name;
	int count = 0, price = 0, id_f = 0, count_o = 0, id = 0;
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
	cout << "# Enter id of product or '0' for exit:" << endl << "# ";
	cin >> (id);
	if (id == 0) ::shop_process = false;
	while (!fin.eof() && (id) != 0)
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
				fout << setw(9) << (price * count_o) << '\n'; //Запис
			}
			::buy_count_max++;
			break;
		}
	}

	fout.close();
	fin.close();
}

void CShop::Basket()
{
	string name;
	int price = 0, id = 0, count = 0, price_b = 0, g_price = 0, buy_count = ::buy_count_max;
	system("cls"); //Очистити екран
	cout << "#========================================#" << endl;
	cout << left << "# " << setw(38) << "Shop menu: Basket: " << " #" << "\n"; //Меню корзини

	fstream fin("Basket.txt"); //Відкрити файл для зчитування
	while (!fin)
	{
		cout << "Cannot open file!\n";
		exit(0);
	}
	fin.seekg(ios::beg, 0);
	cout << setw(20) << left << "Merchendise" << setw(15) << "Price per 1" << setw(15) << "ID" << setw(20) << "You order" << setw(20) << "Order price" << '\n'; //Вивід шапки таблиці
	while (!fin.eof() && buy_count > 0)
	{
		fin >> name >> price >> id >> count >> price_b; //Зчитування даних з файлу
		cout << '#' << setw(20) << left << name << setw(15) << price << setw(15) << id << setw(20) << count << setw(20) << price_b << '#' << '\n';
		g_price += price_b;
		buy_count--;
	}
	cout << right << setfill('=') << '#' << setw(69) << "= You must pay: " << setfill(' ') << left << setw(20) << g_price << '#' << endl;

	system("pause");

	fin.close(); //Закрити файл для зчитування

}

void CShop::ShopMenu()
{
	system("cls"); //Очистити екран
	int arr_count_max = 0, arr_count = 0, id = -1;
	char choice;
	cout << left;
	cout << "#========================================#" << endl;
	cout << "# " << setw(38) << "Do you want to continue shopping or order everything in the cart? (Y/N)" << " #" << "\n" << "# "; //Меню shop
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
