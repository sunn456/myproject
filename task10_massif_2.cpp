#include <iostream>
using namespace std;

void transformArray(int arr[], int n) {
    int temp[n];
    
    int j = 0;
    for(int i = 0; i < n; i += 2) {
        temp[j++] = arr[i];
        // Цикл, який проходить через масив arr, збираючи елементи з парних позицій (індекси 0, 2, 4, ...), та розміщує їх послідовно у тимчасовому масиві temp.
    }

    for(int i = 1; i < n; i += 2) {
        // Аналогічний цикл for, але ітеруємося по непарним індексам масиву arr.
        temp[j++] = arr[i];
    }

    for(int i = 0; i < n; i++) {
        // Цикл for, який ітерується через усі елементи масиву temp.

        arr[i] = temp[i];
    }
}

int main() {
    int arr[] = {-3, -6, 43, -7, 641, 92, 0, 2, -12, 0, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    transformArray(arr, n);

    for(int i = 0; i < n; i++) {
        //Цикл for для виведення зміненого масиву на екран.
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
