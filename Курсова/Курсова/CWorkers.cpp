#include "CWorkers.h"
#include "CEdit.h"

char CWorkers::Workers(char UserMenuChoice, string name)
{
	if (UserMenuChoice == '1') //Прочитати інформацію з файлу
	{
		Show_Info("Workers.txt", "Name", "Profession", "Salary($)", "Age");
		return UserMenuChoice = 'w';
	}
	if ((UserMenuChoice == '2') && (name == "admin")) //Записати інформацію у файл, доступно тільки адміністратору
	{
		Write_Info("Workers.txt", "Name : ", "Profession : ", "Salary($) : ", "Age : ");
		return UserMenuChoice = 'w';
	}
	if (UserMenuChoice == '3') //Знайти інформацію
	{
		Find_Info("Workers.txt");
		return UserMenuChoice = 'w';
	}
	if ((UserMenuChoice == '4') && (name == "admin")) //Редагувати інформацію, доступно тільки адміністратору
	{
		Edit_Info("Workers.txt", "Workers1.txt");
		return UserMenuChoice = 'w';
	}
	if ((UserMenuChoice == '5') && (name == "admin")) //Видалити інформацію, доступно тільки адміністратору
	{
		Delete_Info("Workers.txt");
		return UserMenuChoice = 'w';
	}
	if ((UserMenuChoice == 'b') || (UserMenuChoice == 'B')) //Повернення до попереднього меню
	{
		return UserMenuChoice = 'm';
	}

	if ((UserMenuChoice == 'q') || (UserMenuChoice == 'Q')) //Вихід з програми
		exit(0);
	else
		return UserMenuChoice = 'w';
}
