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

int* memory_for_array1(int length) {
	int* array1 = new int[length];
	return array1;
}

void elements1(int* array, int length) {
	for (int i = 0; i < length; i++) {
		std::cin >> array[i];
	}
}

void show_array1(int* array, int length) {
	for (int i = 0; i < length; i++) {
		std::cout << array[i] << " ";
	}
}

void delete_array1(int* array, int length) {
	;   delete[]array;
	array = 0;
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
//




double* memory_for_array(int length){
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
        std::cout << array[i] << " ";
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
	arr = 0;
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

    /*Task2*/
	std::cout << "/*Task2.9.12*/" << std::endl;
    int length = 0;
    std::cin >> length;   
    double * array = memory_for_array( length);
    elements(array, length);
    show_array(array, length);
    delete_array(array, length);
	std::cout << " " << std::endl;

	/*Homework 9.12*/
	/*Task3*/
	std::cout << "/*Task3.9.12*/" << std::endl;
	int m = 12;
	int* array1 = memory_for_array1(m);
	elements1(array1, m);
	change_elements(array1, m);
	show_array1(array1, m);
	delete_array1(array1, m);
	std::cout << " " << std::endl;


    /*Task4*/
	std::cout << "/*Task4.9.12*/" << std::endl;
    int rows =0;
    int cols = 0;
    std::cout << " enter rows count " << std::endl;
    std::cin >> rows;
    std::cout << " enter cols count " << std::endl;
    std::cin >> cols;
    int** arr = create(rows, cols);
    input(arr, rows, cols);
    print(arr, rows, cols);
    //delete_arraydn(arr, rows, cols);
    delete_arraydn1(arr, rows, cols);

	/*Task5*/
	std::cout << "/*Task5.9.12*/" << std::endl;
	int num1 = 0;
	int num2 = 0;
	char operation;
	while (std::cin.get() != '\n'); //отчистили поток ввода
	operation = std::cin.get();
	if (operation == ' ') {
		std::cout << std::endl << "A space has been entered!" << std::endl;
		return 0;
	}
	int (*operationFunc)(int, int); // Указатель на функцию

	while ((operation == '+') || (operation == '-') || (operation == '*') || (operation == '/')) {
		if (operation == '+') {
			operationFunc = add;
			std::cout << std::endl << "Answer: " << operationFunc(num1, num2) << std::endl;
		}
		else if (operation == '-') {
			operationFunc = subtract;
			std::cout << std::endl << "Answer: " << operationFunc(num1, num2) << std::endl;
		}
		else if (operation == '*') {
			operationFunc = multiply;
			std::cout << std::endl << "Answer: " << operationFunc(num1, num2) << std::endl;
		}
		else if (operation == '/') {
			operationFunc = divide;
			std::cout << std::endl << "Answer: " << operationFunc(num1, num2) << std::endl;
		}
		std::cout << std::endl << "Enter operation: ";
		while (std::cin.get() != '\n'); //отчистили поток ввода
		operation = std::cin.get();
	}
	if (operation == ' ') {
		std::cout << std::endl << "Wrong operation!" << std::endl;
	}
	else {
		std::cout << std::endl << "A completely incorrect operation is being entered!" << std::endl;
	}

/*Homework 2.12*/
/*Task3*/
	std::cout << "/*Task3*/" << std::endl;
	int n = 0;
	std::cin >> n;
	int* array2 = memory_for_array1(n);
	elements1(array2, n);
	change_array(array2, n);
	show_array1(array2, n);
	delete_array1(array2, n);
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


    return 0;
}

