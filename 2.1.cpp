#define _USE_MATH_DEFINES 
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/**
 * \brief Расчет периметра прямоугольного треугольника
 * \param FirstKatet - Длина первого катета
 * \param SecondKatet - Длина второго катета
 * \return Периметр прямоугольного треугольника
 */
double getPerimeter(double FirstKatet, double SecondKatet);

/**
 * \brief Расчет площади прямоугольного треугольника
 * \param FirstKatet - Длина первого катета
 * \param SecondKatet - Длина второго катета
 * \return Площадь прямоугольного треугольника
 */
double getArea(double FirstKatet, double SecondKatet);

/**
 * \brief Пользовательский выбор расчета  периметра (1) или площади (0)
 */
enum class State { perimeter, area };

/**
* \brief Точка входа в программу
* \return Код ошибки (0) успех
*/
int main()
{
	
	double FirstKatet, SecondKatet;
	cout << "Длина первого катета - " << "Длина второго катета - ";
	cin >> FirstKatet >> SecondKatet;
	cout << "Выберите действие (для рачета площади выберите 0, для расчета перитметра выберите 1) ";
	int input;
	cin >> input;
	const auto choice = static_cast<State>(input);

	
	switch (choice)
	{
	case State::perimeter:
	{
		const double Perimeter = getPerimeter(FirstKatet, SecondKatet);
		
		cout << "Периметр треугольника = " << Perimeter;
		break;
	}
	case State::area:
	{
		const double Area = getArea(FirstKatet, SecondKatet);
		cout << "Площадь треуольника = " << Area;
		break;
	}
	}
	return 0;
}


double getPerimeter(double FirstKatet, double SecondKatet)
{
	return FirstKatet + SecondKatet + sqrt(FirstKatet * FirstKatet + SecondKatet * SecondKatet);
}


double getArea(double FirstKatet, double SecondKatet)
{
	return FirstKatet * SecondKatet / 2;
}