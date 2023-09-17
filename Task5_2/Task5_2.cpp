// Task5_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Функція для створення та заповнення двовимірного масиву випадковими числами
int** createAndFillArray(int& rows, int& cols) {
    cout << "Enter the number of lines: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    int** array = new int* [rows];
    for (int i = 0; i < rows; i++) {
        array[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            array[i][j] = rand() % 100; // Заповнюємо випадковими числами від 0 до 99
        }
    }

    return array;
}

// Функція для виведення двовимірного масиву на екран
void printArray(int** array, int rows, int cols) {
    cout << "Two-dimensional array:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << array[i][j] << "\t";
        }
        cout << endl;
    }
}

// Функція для видалення парних стовпців із двовимірного масиву
void deleteEvenColumns(int**& array, int& rows, int& cols) {
    int newCols = cols / 2; // Нова кількість стовпців після видалення парних
    int** newArray = new int* [rows];

    for (int i = 0; i < rows; i++) {
        newArray[i] = new int[newCols];
        int newColIndex = 0;

        for (int j = 0; j < cols; j += 2) {
            newArray[i][newColIndex] = array[i][j];
            newColIndex++;
        }
    }

    // Звільняємо пам'ять від вихідного масиву
    for (int i = 0; i < rows; i++) {
        delete[] array[i];
    }
    delete[] array;

    array = newArray;
    cols = newCols;
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    int** array;
    int rows, cols;

    array = createAndFillArray(rows, cols);
    printArray(array, rows, cols);

    deleteEvenColumns(array, rows, cols);

    cout << "After removing paired columns:" << endl;
    printArray(array, rows, cols);

    // Звільняємо пам'ять від двовимірного масиву
    for (int i = 0; i < rows; i++) {
        delete[] array[i];
    }
    delete[] array;

    return 0;
}
