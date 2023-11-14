#include <iostream>
using namespace std;

void rotateMatrix(int mat[][4], int R, int C, int n, char direction) {
    if (direction == 'R') {
        //Перевірка, чи обрано напрямок зсуву вправо
        while (n--) {
            int temp = mat[0][C - 1];
            // присвоює їй значення останнього елемента в першому рядку матриці. 
            for (int i = 0; i < R; i++) {
                swap(mat[i][C - 1], temp);
                // Зсув елементів останньої колонки вниз.
                //Функція swap обмінює значення елементів, так що кожен елемент стовпця з індексом C - 1 переміщується на одну позицію вниз.
            }
            for (int i = C - 2; i >= 0; i--) {
                swap(mat[0][i], temp);
                // Зсув елементів першого рядка вправо.
            }
            for (int i = 1; i < R; i++) {
                swap(mat[i][0], temp);
                // Зсув елементів першої колонки вверх.
            }
        }
    } else if (direction == 'D') {
        while (n--) {
            int temp = mat[R - 1][0];
            // Збереження останнього елемента останнього рядка в змінній temp.
            for (int i = 0; i < C; i++) {
                swap(mat[R - 1][i], temp);
                // Зсув елементів останнього рядка вправо.
            }
            for (int i = R - 2; i >= 0; i--) {
                swap(mat[i][C - 1], temp);
                // Зсув елементів останньої колонки вверх.
            }
            for (int i = 1; i < C; i++) {
                swap(mat[0][i], temp);
                // Зсув елементів першого рядка вліво.
            }
        }
    }
}

int main() {
    int R = 4, C = 4;
    int mat[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    int n;
    char direction;
    // Оголошення змінних для кількості обертів та напрямку зсуву.
    cout << "Enter the number of rotations: ";
    cin >> n;
    // Введення кількості обертів від користувача.
    cout << "Enter the direction (R for right, D for down): ";
    cin >> direction;

    rotateMatrix(mat, R, C, n, direction);
    // Виклик функції rotateMatrix для зсуву матриці.

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << mat[i][j] << " ";
            // Виведення оновленої матриці.
        }
        cout << endl;
    }

    return 0;
}
