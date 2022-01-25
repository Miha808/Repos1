#include <iostream>
#include <string>

using namespace std;

/**
 * \brief Перечисляемый тип вычеслений, для которых считаем площадь и объем.
 */
enum class Cube
{
	/**
	 * \brief Неправильно сформированный выбор.
	 */
	none,

	/**
	 * \brief Выбранный расчет --  периметр.
	 */
	 perimetr,

	 /**
	  * \brief Выбранный расчет -- площади .
	  */
	  area,

};

/**
 * \brief Функция расчета площади грани куба.
 * \param a сторона куба.
 * \return Площадь гарни куба.
 */
double GetCubeSquare(const double a);

/**
 * \brief Расчет периметра прямоугольного треугольника
 * \param FirstKatet - Длина первого катета
 * \param SecondKatet - Длина второго катета
 * \return Периметр прямоугольного треугольника
 */
double getPerimeter(const double FirstKatet,const double SecondKatet);

/**
 * \brief Расчет площади прямоугольного треугольника
 * \param FirstKatet - Длина первого катета
 * \param SecondKatet - Длина второго катета
 * \return Площадь прямоугольного треугольника
 */
double getArea(const double FirstKatet,const double SecondKatet);

/**
 * \brief Ввод стороны куба.
 * \param message Разъясняющая надпись.
 * \param out Произвольный поток вывода.
 * \param in Произвольный поток ввода.
 * \return Сторону куба.
 */
double ReadSide(const string& message = "", ostream& out = cout, istream& in = cin);


/**
 * \brief
 * \param message Сообщение для пользователя.
 * \param out Произвольный поток вывода.
 * \param in Произвольный поток ввода.
 * \return Выбор пользователя.
 */
Cube ReadUserChoice(const string& message = "", ostream& out = cout, istream& in = cin);

/**
 * \brief Точка вход в программу
 * \return Код ошибки, если 0 - успешное выполнение
 */
int main()
{
	setlocale(LC_ALL, "Russian");

	const auto message = "Выберите, что посчитать: "
		+ to_string(static_cast<int>(Cube::perimetr)) + " - периметр,"
		+ to_string(static_cast<int>(Cube::area)) + " - площадь ,";

	const auto cube = ReadUserChoice(message);

	switch (cube)
	{
	case Cube::perimetr:
	{
		const auto side = ReadSide("Введите сторону куба = ");

		const auto perimetrCube = getPerimeter(side);
		cout << "\nПериметр " << perimetrCube << endl;
		break;
	}
	case Cube::area:
	{
		const auto side = ReadSide("Введите сторону куба = ");

		const auto areaCube = getArea(side);
		cout << "\nПлощадь  " << areaCube << endl;
		break;
	}
	
	default:
		cout << "ошибка!";
	}

	system("pause");
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


double ReadSide(const string& message, ostream& out, istream& in) {
	out << message;
	double side;
	in >> side;
	return side;
}

Cube ReadUserChoice(const string& message, ostream& out, istream& in)
{
	out << message;
	int userInput;
	in >> userInput;
	return static_cast<Cube>(userInput);