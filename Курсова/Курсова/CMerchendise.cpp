#include "CMerchendise.h"

using namespace std;

char CMerchendise::Merchendise(char UserMenuChoice, string name)
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
