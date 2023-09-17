// 16. Дан цілочисельний масив з кількістю елементів n.
//  «Стисніть» масив, викинувши з нього кожен другий елемент.
// Примітка: додатковий масив не використовувати.

#include <iostream>
using namespace std;

int main() {
    const int MAX_SIZE = 100;
    int mass[MAX_SIZE];
    int n;

    // Введення кількості елементів у масиві
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    //// Введення елементів масиву
    //cout << "Введите элементы массива:" << endl;
    //for (int i = 0; i < n; i++) {
    //    cin >> mass[i];
    //}


    // Заповнення масиву випадковими числами
    for (int i = 0; i < n; i++) {
        mass[i] = rand() % 100 - 50;
    }
    cout << endl<< "Source array: " << endl;

    for (int i = 0; i < n; i++) {
        cout << mass[i] << " ";
    }
    cout << endl;

    // Індекс для відстеження поточної позиції у "стислому" масиві
    int compressedIndex = 0;

    // Проходимо по исходному массиву і копіюємо кожен перший елемент в "стислий" масив
    for (int i = 0; i < n; i += 2) {
        mass[compressedIndex] = mass[i];
        compressedIndex++;
    }

    // Виведення "стисненого" масиву
    cout << "Compressed array:" << endl;
    for (int i = 0; i < compressedIndex; i++) {
        cout << mass[i] << " ";
    }
    cout << endl;

    return 0;
}
