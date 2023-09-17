//Зрушити циклічно на M елементів вправо
//Елемент рівний середньому арифметичному елементів масиву

#include <iostream>
#include <stdlib.h>

using namespace std;

const int MAX_SIZE = 100;

//Функція для виведення масиву
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    
    int mass[MAX_SIZE];
    int n;

    cout << "Enter the number of array elements (no more " << MAX_SIZE << " ): ";
    cin >> n;

    // Заповнення масиву випадковими числами
    for (int i = 0; i < n; i++) {
        mass[i] = rand() % 100 - 50;
    }

    cout << "Source array:" << endl;
    printArray(mass, n);

    // Перестановка елементів масиву циклічно на M елементів праворуч
    int M;
    cout << "Enter the number of elements for the cyclic shift: ";
    cin >> M;

    int temp[MAX_SIZE];
    for (int i = 0; i < n; i++) {
        temp[(i + M) % n] = mass[i];
    }

    for (int i = 0; i < n; i++) {
        mass[i] = temp[i];
    }

    cout << "Array after cyclic shift by " << M << " elements to the right:" << endl;
    printArray(mass, n);

    // Пошук елемента, що дорівнює середньому арифметичному елементів масиву
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += mass[i];
    }
    int average = sum / n;

    int comparisons = 0;
    int index = -1;

    for (int i = 0; i < n; i++) {
        comparisons++;
        if (mass[i] == average) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        cout << "The first element, equal to the arithmetic mean of the array elements, is at position " << index << " and is equal " << mass[index] << endl;
        cout << "This search required " << comparisons << " comparisons" << endl;
    }
    else {
        cout << "An element equal to the arithmetic mean of the array elements was not found" << endl;
    }

    return 0;
}
