#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct DETAL {
    string name;
    string sort;
    int date[3];
    int quant;
    double cost;
};

void addRecord(vector<DETAL>& database) {
    DETAL newRecord;
    cout << "Введіть назву деталі: ";
    cin >> newRecord.name;
    //Читає назву деталі з консолі та зберігає в полі 
    cout << "Введіть сорт виробу: ";
    cin >> newRecord.sort;
    cout << "Введіть дату виготовлення (день місяць рік): ";
    cin >> newRecord.date[0] >> newRecord.date[1] >> newRecord.date[2];
    cout << "Введіть кількість: ";
    cin >> newRecord.quant;
    cout << "Введіть ціну одиниці: ";
    cin >> newRecord.cost;

    database.push_back(newRecord);
}

void editRecord(vector<DETAL>& database) {
    string name;
    cout << "Введіть назву деталі для редагування: ";
    cin >> name;

    for (DETAL& item : database) {
        if (item.name == name) {
            cout << "Введіть нову інформацію для цієї деталі: ";
            cin >> item.name >> item.sort;
            cout << "Введіть нову дату (день місяць рік): ";
            cin >> item.date[0] >> item.date[1] >> item.date[2];
            cout << "Введіть нову кількість: ";
            cin >> item.quant;
            cout << "Введіть нову ціну: ";
            cin >> item.cost;
            return;
        }
    }

    cout << "Деталь не знайдена." << endl;
}

void searchRecord(const vector<DETAL>& database) {
    string name;
    cout << "Введіть назву деталі для пошуку: ";
    cin >> name;

    for (const DETAL& item : database) {
        if (item.name == name) {
            cout << "Знайдено деталь: " << item.name << endl;
            cout << "Сорт: " << item.sort << ", Дата: "
                 << item.date[0] << "-" << item.date[1] << "-" << item.date[2]
                 << ", Кількість: " << item.quant << ", Ціна: " << item.cost << endl;
            return;
        }
    }

    cout << "Деталь не знайдена." << endl;
}

void deleteRecord(vector<DETAL>& database) {
    string name;
    cout << "Введіть назву деталі для видалення: ";
    cin >> name;

    for (size_t i = 0; i < database.size(); ++i) {
        if (database[i].name == name) {
            database.erase(database.begin() + i);
            cout << "Деталь видалена." << endl;
            return;
        }
    }

    cout << "Деталь не знайдена." << endl;
}

void saveToFile(const vector<DETAL>& database, const string& filename) {
    ofstream file(filename);
    for (const auto& item : database) {
        file << item.name << "," << item.sort << ","
             << item.date[0] << "-" << item.date[1] << "-" << item.date[2] << ","
             << item.quant << "," << item.cost << endl;
    }
    file.close();
}

void loadFromFile(vector<DETAL>& database, const string& filename) {
    ifstream file(filename);
    string line, token;
    while (getline(file, line)) {
        istringstream iss(line);
        // розділення рядків на окремі слова або числа.
        DETAL item;
        getline(iss, item.name, ',');
        getline(iss, item.sort, ',');
        getline(iss, token, '-');
        item.date[0] = stoi(token);
        getline(iss, token, '-');
        item.date[1] = stoi(token);
        getline(iss, token, ',');
        item.date[2] = stoi(token);
        getline(iss, token, ',');
        item.quant = stoi(token);
        getline(iss, token);
        item.cost = stod(token);
        database.push_back(item);
    }
    file.close();
}

int main() {
    vector<DETAL> database;
    string filename = "detal_database.txt";
    loadFromFile(database, filename);
    int choice;

    while (true) {
        cout << "\n1. Додати запис\n2. Редагувати запис\n3. Видалити запис\n4. Пошук запису\n5. Показати всі записи\n0. Вихід\nВаш вибір: ";
        cin >> choice;

        switch (choice) {
            // конструкія
            case 1:
                addRecord(database);
                break;
            case 2:
                editRecord(database);
                break;
            case 3:
                deleteRecord(database);
                break;
            case 4:
                searchRecord(database);
                break;
            case 5:
                for (const auto& item : database) {
                    cout << item.name << ", " << item.sort << ", "
                         << item.date[0] << "-" << item.date[1] << "-" << item.date[2] << ", "
                         << item.quant << ", " << item.cost << endl;
                }
                break;
            case 0:
                saveToFile(database, filename);
                return 0;
            default:
                cout << "Неправильний вибір. Спробуйте знову." << endl;
        }
    }

    return 0;
}
