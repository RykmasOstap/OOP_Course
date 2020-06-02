#pragma once

#include <iomanip>
#include <string>

#include "CEdit.h"

class CInventory : public CEdit
{
public:
	char Inventory(char UserMenuChoice, string name);
};