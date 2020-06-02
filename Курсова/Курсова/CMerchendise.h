#pragma once

#include <iomanip>
#include <string>

#include "CEdit.h"

class CMerchendise : public CEdit
{
protected:
	bool back;
public:
	char Merchendise(char UserMenuChoice, string name);
};