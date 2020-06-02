#pragma once

#include <iomanip>
#include <string>

#include "CEdit.h"

using namespace std;

class CWorkers : public CEdit
{
public:
	char Workers(char UserMenuChoice, string name);
};