#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct ITINERARY {
    string FIRST;   
    string FINAL;    
    int NUM;         
    double DISTANCE; 
};

void inputRoutes(ITINERARY ROUT[], int N) {
    for (int i = 0; i < N; ++i) {
        cout << "Введіть дані для маршруту " << i + 1 << ":\n";
        // і-номер поточного марш,дає номер марштруту 
        cout << "Початковий пункт: ";
        cin >> ROUT[i].FIRST;
        cout << "Кінцевий пункт: ";
        cin >> ROUT[i].FINAL;
        cout << "Номер маршруту: ";
        cin >> ROUT[i].NUM;
        cout << "Відстань (у км): ";
        cin >> ROUT[i].DISTANCE;
    }
}

bool compareByDistance(const ITINERARY &a, const ITINERARY &b) {
    return a.DISTANCE > b.DISTANCE;
}

void sortRoutesByDistance(ITINERARY ROUT[], int N) {
    sort(ROUT, ROUT + N, compareByDistance);
    // sort використовується для сортування масиву об'єктів типу ITINERARY. 
}

void displayRoute(const ITINERARY ROUT[], int N, int routeNumber) {
    bool found = false;
    for (int i = 0; i < N; ++i) {
        if (ROUT[i].NUM == routeNumber) {
            cout << "Маршрут №" << ROUT[i].NUM << ": " 
                 << ROUT[i].FIRST << " - " << ROUT[i].FINAL 
                 << ", Відстань: " << ROUT[i].DISTANCE << " км\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Маршрут з номером " << routeNumber << " не знайдено.\n";
    }
}

int main() {
    int N;
    cout << "Введіть кількість маршрутів: ";
    cin >> N;

    ITINERARY *ROUT = new ITINERARY[N];
    // Динамічне виділення пам'яті для масиву об'єктів типу ITINERARY розміром N. Вказівник ROUT вказує на початок цього масиву.
    inputRoutes(ROUT, N);
    // введення даних про марщ,Передається вказівник на масив ROUT та його розмір N

    sortRoutesByDistance(ROUT, N);

    int routeNumber;
    cout << "Введіть номер маршруту для виведення інформації: ";
    cin >> routeNumber;
    displayRoute(ROUT, N, routeNumber);

    

    return 0;
}
