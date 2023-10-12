#include <iostream>
#include <cmath>

double calculateF(double a, double b, double c, double x) {
    if (x < 3 && b != 0) {
        return a * std::pow(x, 2) - b * x + c;
    } else if (x > 3) {
        return (x - a) / (x - c);
    } else {
        return x / c;
    }
}

bool additionalCondition(double a, double b, double c, double result) {
    // bool приймає істинну або не істинну
    return !((int(a) || int(b)) && !(int(a) % 2 == int(c) % 2)) && result != 0;
}

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
    // //рядок який має вивести у консоль,він містить заголовки для колонок таблиці,\t є символом відступу
    std::cout << "-----------------" << std::endl;
    // //Рядок з символами тире, які використовуються для утворення роздільної лінії.

    // Обчислення та вивід значень функції
    for (double x = Xstart; x <= Xend; x += H) {
        double result = calculateF(a, b, c, x);

        // Додаткова умова
        if (additionalCondition(a, b, c, result)) {
            std::cout << x << "\t|\t" << result << std::endl;
        }
    }

    return 0;
}