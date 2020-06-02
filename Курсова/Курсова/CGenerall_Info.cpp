#include "CGenerall_Info.h"

using namespace std;

char CGenerall_Info::Generall_Info(char UserMenuChoice, string name)
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
};
