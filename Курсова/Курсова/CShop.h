#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "CMerchendise.h"

extern bool shop_process;
extern int buy_count_max;

class CShop : public CMerchendise
{
public:
	void Buy();

	void Basket();

	void ShopMenu();
};////