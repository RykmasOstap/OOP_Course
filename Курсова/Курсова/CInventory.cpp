#include "CInventory.h"

using namespace std;

char CInventory::Inventory(char UserMenuChoice, string name)
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
