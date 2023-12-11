// Sem09.12.cpp : Задачи на указатели и массивы.
//

#include <iostream>
#include <array>
#include <cstdlib> 
#include <ctime>
#include "math.h"
#include <fstream>

/*Homework 2.12*/
/*Task 3*/

int change_array(int* array, int n) {
	int* pa = array;
	int* pla = array + (n - 1);
	int t = *pa;
	*pa = *pla;
	*pla = t;
	return *array;
}


/*Homework 9.12*/
/*Task3*/
int change_elements(int* array1, int m)
{
	int element = 0;
	for (int i = 0; i < m; i++)
	{
		if (i % 2 == 0)
		{
			element = array1[i];
			array1[i] = array1[i + 1];
			array1[i + 1] = element;
		}
	}
	return *array1;

}

/*Task5*/
int add(int a, int b) {
	return a + b;
}

int subtract(int a, int b) {
	return a - b;
}

int multiply(int a, int b) {
	return a * b;
}

int divide(int a, int b) {
	return a / b;
}

int end(int a, int b) {
	return 0;
}



double* memory_for_array(int length){
    std::cin >> length;
    double* array = new double[length];
    return array;
}

void elements(double *array, int length) {
    for (int i = 0; i < length; i++) {
        std::cin >> array[i];
    }
}

void show_array(double* array, int length) {
    for (int i = 0; i < length; i++) {
        std::cout << array[i] << "";
    }
}

void delete_array(double *array, int length) {
;   delete[]array;
    array = 0;
}
void delete_arraydn(int** array, int a, int b) {
    delete[]array;
    array = 0;
}
void delete_arraydn1(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) //очистка памяти
    {
        delete[] arr[i];
    }
}

int** create(int rows, int cols)
{
    int** arr = new int* [rows];

    for (int i = 0; i < rows; i++) //создание массива
    {
        arr[i] = new int[cols];
    }
    return arr;
}

void input(int** arr, int rows, int cols)
{
    srand(time(0));
    for (int i = 0; i < rows; i++) //заполнение массива
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = 10 + rand() % 41; //генерируем случайные числа в каждый элемент массива
        }
    }
}

void print(int** arr, int rows, int cols)
{
    for (int i = 0; i < rows; i++) //вывод массива в консоль
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << arr[i][j]<<"\t";
        }
        std::cout << std::endl;
    }
}



int main()
{
    /*Task1*/
    const float a = 0.0;
    const float* const ptr = &a;

    typedef long int* ptr;
    long int b = 9;
    long int* ptr = &b; //инициализируем ptr адресом значения переменной 
    
    double c = 0;
    double* ptr = &c;

    const short int d = 0;
    const short int* ptr = &d;

    typedef float* ptr;
    const float e = 0.0;
    const float* const ptr = &e;

    typedef char* ptr;
    const char f = 0;
    const char* ptr = &f;

    double k = 0;
    double * const  ptr = &k;

    typedef unsigned int* ptr;
    unsigned int r = 0;
    unsigned int* const  ptr = &r;


    /*Task2*/
    int length = 0;
    std::cin >> length;   
    double * array = memory_for_array( length);
    elements(array, length);
    show_array(array, length);
    delete_array(array, length);

    

    /*Task4*/
    int rows =0;
    int cols = 0;
    std::cout << " enter rows count " << std::endl;
    std::cin >> rows;
    std::cout << " enter cols count " << std::endl;
    std::cin >> cols;
    int** arr = create(rows, cols);
    input(arr, rows, cols);
    print(arr, rows, cols);
    delete_arraydn(arr, rows, cols);
    delete_arraydn1(arr, rows, cols);

	/*Homework 2.12*/
/*Task3*/
	std::cout << "/*Task3*/" << std::endl;
	int n = 0;
	std::cin >> n;
	int* array = memory_for_array(n);
	elements(array, n);
	change_array(array, n);
	show_array(array, n);
	delete_array(array, n);
	std::cout << "" << std::endl;

	/*Task4*/
	std::cout << "/*Task4*/" << std::endl;
	double** p = 0;
	p = new double*;
	*p = new double;
	**p = 2;
	std::cout << **p << std::endl;
	std::cout << "";
	delete* p;
	delete p;
	std::cout << "" << std::endl;

	/*Homework 9.12*/
	/*Task3*/
	std::cout << "/*Task4.9.12*/" << std::endl;
	int m = 12;
	int* array1 = memory_for_array(m);
	elements(array1, m);
	change_elements(array1, m);
	show_array(array1, m);
	delete_array(array1, m);
	std::cout << "" << std::endl;

	/*Task5*/
	int num1, num2;
	char operation;

	int (*operationFunc)(int, int); // Указатель на функцию

	while (true) {
		std::cout << "Enter two digits and symbol of operation: ";
		std::cin >> num1 >> num2 >> operation;

		if (operation == ' ') {
			break;
		}
		// Установка указателя на соответствующую функцию в зависимости от символа операции
		switch (operation) {
		case '+':
			operationFunc = add;
			break;
		case '-':
			operationFunc = subtract;
			break;
		case '*':
			operationFunc = multiply;
			break;
		case '/':
			operationFunc = divide;
			break;

			// Вызов функции, указанной указателем, и вывод результата
			int result = operationFunc(num1, num2);
			std::cout << "Result: " << result << std::endl;
		}

		return 0;
	}



    return 0;
}

