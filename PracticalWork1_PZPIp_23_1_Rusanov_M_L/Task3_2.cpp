//������� �������� ���������� ������� ������� F(x) �� ��������[a; b] � ������ h.��������� ����������� � ������ ������� ������ �������� ��� � �������� ���������, ������ � �������� �������� �������.
//������� 14 � ������ ���� �� �������� 3.2.
//���	�������	                           a	b	  c
//16  ctg(x / 2) + 1 / 2 sin?x            2	6.4	  0.2


#include <iostream>
#include <cmath>
#include <iomanip>

double F(double x) {
    return 1.0 / tan(x / 2) + 0.5 * sin(x);
}

int main() {
    double a = 2.0;
    double b = 6.4;
    double h = 0.2;

    std::cout << "|---------------|\n";
    std::cout << "|   x   |   F(x)   |\n";
    std::cout << "|---------------|\n";

    for (double x = a; x <= b; x += h) {
        double result = F(x);
        std::cout << "| " << std::setw(5) << x << " | " << std::setw(8) << result << " |\n";
    }

    std::cout << "|---------------|\n";

    return 0;
}