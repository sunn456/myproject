#include <iostream>
// функція для виведення і введення даних у консоль
#include <cmath>
// умова для математичних обчислень
using namespace std;
// іменний простір

int main() {
    // початкова функція,яка є обов'язковою для виконання програми
    double a, b, c;
    // оголошення змінної числа з комою
    cout << "Введіть коефіцієнт a: ";
    cin >> a;
    cout << "Введіть коефіцієнт b: ";
    cin >> b;
    cout << "Введіть коефіцієнт c: ";
    cin >> c;

    double discriminant = b * b - 4 * a * c;
    //формула дискримінанта

    if (discriminant > 0) {
        double x1 = (-b + sqrt(discriminant)) / (2 * a);
        // sqrt корінь квадратний
        double x2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << "Два корені: " << x1 << " і " << x2 << endl;
    } else if (discriminant == 0) {
        double root = -b / (2 * a);
        cout << "Єдиний корінь: " << root << endl;
    } else if (discriminant < 0 ) {
        //умова
        cout << "Дійсних коренів немає" << endl;
    }

    return 0;
}