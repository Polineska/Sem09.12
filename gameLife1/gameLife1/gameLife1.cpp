﻿#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int ROWS = 10; // Количество строк в "вселенной"
const int COLS = 10; // Количество столбцов в "вселенной"
bool universeHistory[100][ROWS][COLS]; // Двумерный массив для хранения истории состояний "вселенной"

// Функция для инициализации "вселенной"
void initUniverse(bool universe[ROWS][COLS]) {
    srand(time(NULL)); // Инициализация генератора случайных чисел

    // Заполнение "вселенной" случайными состояниями клеток
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            universe[i][j] = rand() % 2; // 0 - мертвая клетка, 1 - живая клетка
        }
    }
}

// Функция для отображения "вселенной"
void printUniverse(const bool universe[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (universe[i][j]) {
                cout << "*"; // Вывод живой клетки
            }
            else {
                cout << " "; // Вывод мертвой клетки
            }
        }
        cout << endl;
    }
    cout << endl;
}

// Функция для подсчета количества живых соседей у клетки
int countAliveNeighbors(const bool universe[ROWS][COLS], int row, int col) {
    int count = 0;

    // Проверка всех 8 соседей клетки
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            // Игнорирование клетки самой клетки
            if (i == 0 && j == 0) {
                continue;
            }

            // Обработка граничных условий
            int newRow = (row + i + ROWS) % ROWS;
            int newCol = (col + j + COLS) % COLS;

            if (universe[newRow][newCol]) {
                count++;
            }
        }
    }

    return count;
}

// Функция для обновления "вселенной" до следующего поколения
void updateUniverse(bool universe[ROWS][COLS], int generations) {
    bool newUniverse[ROWS][COLS];

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int aliveNeighbors = countAliveNeighbors(universe, i, j);

            if (universe[i][j] && (aliveNeighbors == 2 || aliveNeighbors == 3)) {
                newUniverse[i][j] = true; // Живая клетка продолжает жить
            }
            else if (!universe[i][j] && aliveNeighbors == 3) {
                newUniverse[i][j] = true; // Зарождается жизнь в мертвой клетке
            }
            else {
                newUniverse[i][j] = false; // Клетка умирает
            }
        }
    }

    // Запись текущего состояния в историю
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            universeHistory[generations][i][j] = universe[i][j];
        }
    }

    // Копирование новой "вселенной" в основную "вселенную"
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            universe[i][j] = newUniverse[i][j];
        }
    }
}

// Функция для проверки окончания игры
bool checkEndGame(const bool universe[ROWS][COLS], const int generations) {
    // Проверка, остались ли на поле живые клетки
    bool allDead = true;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (universe[i][j]) {
                allDead = false;
                break;
            }
        }
        if (!allDead) {
            break;
        }
    }

    // Проверка, повторяется ли конфигурация
    for (int i = 0; i < generations; i++) {
        bool isSame = true;
        for (int row = 0; row < ROWS; row++) {
            for (int col = 0; col < COLS; col++) {
                if (universe[row][col] != universeHistory[i][row][col]) {
                    isSame = false;
                    break;
                }
            }
            if (!isSame) {
                break;
            }
        }

        if (isSame) {
            cout << "Game is over: configuration repeated." << endl;
            return true;
        }
    }

    // Проверка, не меняются ли клетки
    bool allStable = true;
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (universe[row][col] != universeHistory[generations - 1][row][col]) {
                allStable = false;
                break;
            }
        }
        if (!allStable) {
            break;
        }
    }

    if (allStable) {
        cout << "Game is over: configuration stabilised." << endl;
        return true;
    }

    return allDead;
}

int main() {
    bool universe[ROWS][COLS]; // Двумерный массив для хранения "вселенной"
    int generations = 0; // Счетчик поколений

    initUniverse(universe); // Инициализация "вселенной"
    std::cout << "Generation: " << generations << std::endl;
    printUniverse(universe); // Вывод первого поколения

    // Переход к следующим поколениям
    while (true) {
        updateUniverse(universe, generations);
        std::cout << "Generation: " << generations + 1<< std::endl;
        printUniverse(universe);

        generations++;

        if (checkEndGame(universe, generations)) {
            break;
        }

  
    }

    return 0;
}