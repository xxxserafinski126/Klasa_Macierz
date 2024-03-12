#include "macierz.hpp"
#include <iostream>

int main() {
    // Przykładowe użycie klasy Macierz
    Macierz m1;
    Macierz m2;

    // Ustawienie wartości elementów macierzy m1 i m2
    m1.set(0, 0, 1.0);
    m1.set(0, 1, 2.0);
    m1.set(1, 0, 3.0);
    m1.set(1, 1, 4.0);

    m2.set(0, 0, 2.0);
    m2.set(0, 1, 3.0);
    m2.set(1, 0, 4.0);
    m2.set(1, 1, 5.0);

    // Dodawanie macierzy
    Macierz m3 = m1 + m2;
    std::cout << "Dodawanie macierzy:\n" << m3;

    // Mnożenie macierzy
    Macierz m4 = m1 * m2;
    std::cout << "Mnozenie macierzy:\n" << m4;

    // Transpozycja macierzy
    m1.transpozycja();
    std::cout << "Transpozycja macierzy m1:\n" << m1;

    return 0;
}