#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;


int columnCharacteristic(int** matrix, int rows, int col) {
    // знаходить суму модулів від'ємних непарних елементів у заданому стовпці матриці.
    int sum = 0;
    for (int i = 0; i < rows; ++i) {
        if (matrix[i][col] < 0 && matrix[i][col] % 2 != 0) {
            sum += abs(matrix[i][col]);
            // модуль цього елементу до суми.
        }
    }
    return sum;
}

// Функція для обміну двох стовпців
void swapColumns(int** matrix, int rows, int col1, int col2) {
    for (int i = 0; i < rows; ++i) {
        swap(matrix[i][col1], matrix[i][col2]);
    }
}

int main() {
    int rows, cols;
    cout << "Введіть кількість рядків та стовпців матриці: ";
    cin >> rows >> cols;

    // Динамічне виділення пам'яті для матриці 
    int** matrix = new int*[rows];
    // створюємо вказівник на вказівник,який вказує на перший елемент масиву вказівників. 
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
        // Для кожного рядка виділяється пам'ять для стовпців 
    }

    cout << "Введіть елементи матриці:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            //За допомогою вкладених циклів отримуються від користувача елементи кожного рядка та кожного стовпця 
            cin >> matrix[i][j];
        }
    }

    // Сортування стовпців за характеристикою
    for (int i = 0; i < cols - 1; ++i) {
        for (int j = i + 1; j < cols; ++j) {
            // цикл, який починається з наступного стовпця після поточного, проходить до останнього стовпця.
            if (columnCharacteristic(matrix, rows, i) > columnCharacteristic(matrix, rows, j)) {
                swapColumns(matrix, rows, i, j);
            }
        }
    }

    cout << "Матриця після перестановки стовпців:\n";
    for (int i = 0; i < rows; ++i) {
        // рядки
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    // Видалення виділеної пам'яті
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
        // видалення динамічно виділеної пам'яті для кожного рядка матриці
    }
    delete[] matrix;
    // видалення динамічно виділеної пам'яті для самого масиву рядків матриці.

    return 0;
}
