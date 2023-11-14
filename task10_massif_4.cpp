#include <iostream>
#include <string>
// рядками
#include <sstream>
// потоки
#include <cctype>
// перевірка символів
using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y');
}

int countConsonants(const string &word) {
    int count = 0;
    // для використання підрахунку кількості приголосних у слові
    for (char c : word) {
        if (isalpha(c) && !isVowel(c)) {
            // перевіряє чи він є літерою алфавіту 
            count++;
        }
    }
    return count;
}

void processString(const string &text) {
    // оголошує функцію processString, яка не повертає жодного значення (void) і приймає один параметр, посилання на константний рядок 
    stringstream ss(text);
   // для подальшого читання слів з рядка.
    string word;
    int vowelStartingWords = 0;
    // Вона буде використовуватися для підрахунку кількості слів, які починаються з голосної букви.

    while (ss >> word) {
        if (isVowel(word[0])) {
            vowelStartingWords++;
            // Якщо перша літера слова (word[0]) є голосною (як визначено у функції isVowel), лічильник vowelStartingWords збільшується на один.
        }
        if (countConsonants(word) % 2 == 1) {
            cout << word << " ";
            //  викликається для підрахунку кількості приголосних у слові 
        }
    }
    cout << "\nTotal words starting with a vowel: " << vowelStartingWords << endl;
    
}

string removeNumbers(const string &text) {
    string result;
    for (char c : text) {
        if (!isdigit(c)) {
            // Умова всередині циклу перевіряє, чи символ c НЕ є цифрою. 
            result += c;
            // Якщо символ c не є цифрою, він додається до рядка result. Оператор += використовується для конкатенації символа до рядка.
        }
    }
    return result;
}

int main() {
    string text;
    // використовуватиметься для зберігання тексту, введеного користувачем.
    cout << "Enter your text: ";
    getline(cin, text);
    // може читати весь текст

    cout << "Words with an odd number of consonants: ";
    processString(text);
    // Ця функція обробляє текст, виводить слова з непарною кількістю приголосних, і підраховує кількість слів, які починаються з голосної букви.

    cout << "Text without numbers: " << removeNumbers(text) << endl;
    // removeNumbers викликається з рядком text як аргументом, і її результат (рядок без чисел) виводиться на екран.

    return 0;
}
