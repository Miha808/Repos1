
#include <iostream>
using namespace std;

/**
 * \brief Ввод элементов массива пользователем.
 * \param left - граница на массив.
 * \param right - граница массива.
 */

void input_manual(int* ar, unsigned int n, int left, int right);

/**
 * \brief Заполнение элементов массива случайными числами.
 * \param left - граница на массив.
 * \param right - граница массива.
 * \param n - размер массива.
 */

void input_random(int* ar, unsigned int n, int left, int right);

/**
 * \brief Вывод элементов массива в консоль.
 * \param left - граница на массив.
 * \param right - граница массива.
 * \param n - размер массива.
 */

void output_array(int* ar, unsigned  int n);

/**
 * \brief Замена элеменотов массива с нечетными номерами на квадраты их номеров.
 * \param left - граница на массив.
 * \param right - граница массива.
 * \param n - размер массива.
 */

int function1(int* ar, unsigned int  n);

/**
 * \brief Произведение элементов имеющих четное значение.
 * \param left - граница на массив.
 * \param right - граница массива.
 * \param n - размер массива.
 */

void function2(int* ar, unsigned int  n);

/**
 * \brief Определяет есть ли в данном массиве положительные элементы, делящиеся на заданное число с остатком 2.
 * \param left - граница на массив.
 * \param right - граница массива.
 * \param n - размер массива.
 * \param pk - заданное число
 */

int function3(int* ar, unsigned int  n, int* pk);




int main()
{
	setlocale(LC_ALL, "rus");
	const int left = -15;
	const int right = 15;
	unsigned int n;
	cout << "введите размерность массива " << endl;
	cin >> n;
	int* ar = new int[n];
	cout << "вы хотите ввести чила вручную(1) или заполнить случайно(0)?" << endl;
	int b;
	while (true)
	{
		cin >> b;
		switch (b)
		{
		case 1: input_manual(ar, n, left, right);
			break;
		case 0: input_random(ar, n, left, right);
			break;
		default:
			cout << "можно вводить только 1 или 0" << endl;
			continue;
		}
		break;
	}
	cout << "получили массив :" << endl;
	output_array(ar, n);
	int result = function1(ar, n);//произведение всех четных чисел от -15 до 15
	if (result == 1)
	{
		cout << "в вашем массиве нет четных чисел  " << endl;
	}
	else
	{
		cout << "произведение всех четных чисел от -15 до 15 равно " << result << endl;
	}
	function2(ar, n);//заменим все элементы массива с четными номерами на квадрат их номера
	cout << " массив после замены : " << endl;
	output_array(ar, n);//вывод массива
	int k;
	result = function3(ar, n, &k);//числа делимые на k с остатком 2
	if(result == 0)
	{
		cout << "в массиве нет чисел дающих остаток 2 от деления на " << k << endl;
	}
	else
	{
		cout << "в массиве " << result << " чисел делящихся на " << k << " с остатком 2" << endl;
	}
	delete[] ar;
}

void input_manual(int* ar, unsigned int n, int left, int right)
{
	cout << "введите " << n << " чисел от  " << left << " до " << right<< endl;
	for (unsigned int i = 0 ; i < n; ++i)
	{
		while (true)
		{
			cin >> ar[i];	
			if (ar[i] >= left && ar[i] <= right)
			{
				break;
			}
			else
			{
				cout << "повторите ввод" << endl;
			}
		}
	}
}

void input_random(int* ar, unsigned int n, int left, int right)
{
	for (unsigned int i = 0; i < n; ++i)
	{
		ar[i] = rand() % 31 - 15;
	}
}

void output_array( int* ar, unsigned int n)
{
	for (unsigned int i = 0; i < n; ++i)
	{
		cout << ar[i] << endl;
	}
}

int function1( int* ar, unsigned int  n)//произведение всех четных чисел от -15 до 15
{
	int c = 1;
	for (unsigned int i = 0; i < n; ++i)
	{
		if ( ar[i] % 2 == 0)
		{
			c *= ar[i];
		}

	}
	return c;
}

void function2( int* ar, unsigned int  n)//заменим все элементы массива с четными номерами на квадрат их номера
{
	for (unsigned int i = 0; i < n; i+=2)
	{
			ar[i] = i * i;
	}
}

int function3(int* ar, unsigned int  n, int* pk)//числа делимые на k с остатком 2
{
	cout << "введите целое число больше 2" << endl;
	int k;
	
	while (true)
	{
		cin >> k;
		if (k > 2)
		{
			break;
		}
		else
		{
			cout << "повторите ввод" << endl;
		}
	}
	*pk = k;
	int d = 0;
	for (int i = 0; i < n; ++i)
	{
		if (ar[i] % k == 2)
		{
			++d;
			cout << d << endl;
		}
	}
	return d;
}
