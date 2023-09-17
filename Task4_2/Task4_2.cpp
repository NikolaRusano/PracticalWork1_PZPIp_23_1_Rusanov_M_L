// 16. ��� ������������� ����� � ������� �������� n.
//  ��������� �����, ��������� � ����� ����� ������ �������.
// �������: ���������� ����� �� ���������������.

#include <iostream>
using namespace std;

int main() {
    const int MAX_SIZE = 100;
    int mass[MAX_SIZE];
    int n;

    // �������� ������� �������� � �����
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    //// �������� �������� ������
    //cout << "������� �������� �������:" << endl;
    //for (int i = 0; i < n; i++) {
    //    cin >> mass[i];
    //}


    // ���������� ������ ����������� �������
    for (int i = 0; i < n; i++) {
        mass[i] = rand() % 100 - 50;
    }
    cout << endl<< "Source array: " << endl;

    for (int i = 0; i < n; i++) {
        cout << mass[i] << " ";
    }
    cout << endl;

    // ������ ��� ���������� ������� ������� � "��������" �����
    int compressedIndex = 0;

    // ��������� �� ��������� ������� � ������� ����� ������ ������� � "�������" �����
    for (int i = 0; i < n; i += 2) {
        mass[compressedIndex] = mass[i];
        compressedIndex++;
    }

    // ��������� "����������" ������
    cout << "Compressed array:" << endl;
    for (int i = 0; i < compressedIndex; i++) {
        cout << mass[i] << " ";
    }
    cout << endl;

    return 0;
}
