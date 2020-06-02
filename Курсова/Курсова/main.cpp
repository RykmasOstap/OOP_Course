#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <locale>;
#include "windows.h";

#include "CMain.h"

using namespace std;

bool shop_process = false;
int buy_count_max;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	CMain main;
	main.Main();
	return 0;
}
