// Sem09.12.cpp : Задачи на указатели и массивы.
//

#include <iostream>
#include <array>
#include <cstdlib> 
#include <ctime>
#include "math.h"
#include <fstream>

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

void Calculate(int (*Operator)(int*, int*), int A, int B, char C) {
    int res;
    switch (C) {
    case '+':
        res = Operator(&A, &B);
        std::cout << res << std::endl;
        break;
    case '-':
        res = Operator(&A, &B);
        std::cout << res << std::endl;
        break;
    case '*':
        res = Operator(&A, &B);
        std::cout << res << std::endl;
        break;
    case '/':
        res = Operator(&A, &B);
        cout << res << endl;
        break;
    }
}


int main()
{
    /*Task1*/
    /*const float a = 0.0;
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
    unsigned int* const  ptr = &r;*/


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




    /*Task5*/
    int n1, n2; 
    std::cin >> n1 >> n2;
    char c; 
    std::cin >> c;

    switch (c) {
    case '+':
        Calculate(Plus, a, b, c);
        break;
    case '-':
        Calculate(Minus, a, b, c);
        break;
    case '*':
        Calculate(Mul, a, b, c);
        break;
    case '/':
        Calculate(Div, a, b, c);
        break;
    return 0;
}
