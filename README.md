#include <iostream>
#include <cmath>

using namespace std;

/**
*\brief Математическая функция, вычисляющая силу тяжести
*\param const double mass - масса мешка
*\return возвращает значение F - сила тяжести
**/

double getGravity(const double mass);

/**
*\brief Математическая функция, вычисляющая вес мешка
*\param const double weight - вес мешка
*\return возвращает значение веса мешка
**/

double getWeight(const double wass);

/**
*\brief точка входа в программу
*\return возвращает 0 после успешного выполнения
*/

int main()
{
	cout<<"Введите число и нажмите Enter: /n";
	double mass;
	cin >> mass;
	const auto gravity = getGravity(mass);
	const auto wieght = getWeight(mass);
	cout <<"mass" = mass;
}

double getGravity(const double mass)
{
return 9,8 * mass;
}

double getMass(const double mass)
{
return mass * mass;
}
