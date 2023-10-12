#include <iostream>
#include <cmath>

int main() {
    double a, b, c, Xstart, Xend, H;

    // Введення значень з клавіатури
    std::cout << "Enter a: ";
    std::cin >> a;
    
    std::cout << "Enter b: ";
    std::cin >> b;

    std::cout << "Enter c: ";
    std::cin >> c;

    std::cout << "Enter Xstart: ";
    std::cin >> Xstart;

    std::cout << "Enter Xend: ";
    std::cin >> Xend;

    std::cout << "Enter H: ";
    std::cin >> H;

    // Вивід заголовка таблиці
    std::cout << "X\t|\tF(x)" << std::endl;
    //рядок який має вивести у консоль,він містить заголовки для колонок таблиці,\t є символом відступу
    std::cout << "-----------------" << std::endl;
    //Рядок з символами тире, які використовуються для утворення роздільної лінії.

    // Обчислення та вивід значень функції
    for (double x = Xstart; x <= Xend; x += H) {
        // <= цикл буде виконуватись коли x менше або дорівнює
        // += означає що до поточного значення x буде додано значення H
        double result;
        if (x < 3 && b != 0) {
            result = a * std::pow(x, 2) - b * x + c;
            // std pow використання функції ,x підноситься до квадрату
        } else if (x > 3) {
            result = (x - a) / (x - c);
        } else {
            result = x / c;
        }

        // Додаткова умова
        if (!((int(a) || int(b)) && !(int(a) % 2 == int(c) % 2)) && result != 0) {
            std::cout << x << "\t|\t" << result << std::endl;
            // якщо a,b,с відровідвють критеріям і якщо result не дорівнює 0,то виводяться
            // x та result у вигляді таблиці
        }
    }

    return 0;
}