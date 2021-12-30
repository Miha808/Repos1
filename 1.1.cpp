#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

using namespace std;

/**
* \brief Математическая функция, рассчитывающая значение a
* \param const double x - константа, имеющая тип данных с плавающей точкой двойной точности
* \param const double y - константа, имеющая тип данных с плавающей точкой двойной точности
* \return Возвращает значение a
**/
double getA(const double x, const double y);

/**
* \brief Математическая функция, рассчитывающая значение b
* \param const double x - константа, имеющая тип данных с плавающей точкой двойной точности
* \param const double y - константа, имеющая тип данных с плавающей точкой двойной точности
* \param const double z - константа, имеющая тип данных с плавающей точкой двойной точности
* \return Возвращает значение b
**/
double getB(const double x, const double y, const double z);

/**
* \brief Точка входа в программу.
* \return Возвращает 0 в случае успешного выполнения.
*/
int main() {
const double x = 1.825;
const double y = 18.225;
const double z = -3.298;
const auto a = getA(x, y);
const auto b = getB(x, y, z);
cout << " x = " << x << "\n y = " << y << "\n z = " << z << "\n a = " << a << "\n b = " << b;
return 0;
}

double getA(const double x, const double y) {
return pow(x,y / x) - pow(sqrt(y / x),1 / 3);
}

double getB(const double x, const double y, const double z) {
return (y-x) + ((x-z) / (y-x)) / (3 + pow(z,2) / 5);
}
