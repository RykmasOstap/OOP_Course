#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "CGenerall_Info.h"
#include "CFinances.h"
#include "CInventory.h"
#include "CWorkers.h"
#include "CShop.h"



using namespace std;

class CMain : public CGenerall_Info, public CFinances, public CInventory, public CWorkers, public CShop
{
private:
	char UserMenuChoice;
	string name;
	float money;
public:
	void GetChoiceMenu();
	void GetUserName();
	void GetUserMoney();
	void StartMenu();
	void AuthorizationMenu();
	void MainMenu();
	void info_Menu(string dirName, string name);
	int Main();
};