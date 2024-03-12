#include "macierz.hpp"

// Konstruktor domy�lny inicjuje macierz jako macierz zerow�.
Macierz::Macierz() {
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            tab[i][j] = 0.0;
}

// Konstruktor kopiuj�cy
Macierz::Macierz(const Macierz& copy) {
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            tab[i][j] = copy.tab[i][j];
}

// Destruktor
Macierz::~Macierz() {
    // Tu nie potrzebujemy nic robi�, poniewa� nie ma dynamicznej alokacji pami�ci.
}

// Operator przypisania
Macierz& Macierz::operator=(const Macierz& copy) {
    if (this != &copy) {
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                tab[i][j] = copy.tab[i][j];
    }
    return *this;
}

// Operator dodawania
Macierz Macierz::operator+(const Macierz& copy) const {
    Macierz result;
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            result.tab[i][j] = tab[i][j] + copy.tab[i][j];
    return result;
}

// Operator mno�enia przez macierz
Macierz Macierz::operator*(const Macierz& copy) const {
    Macierz result;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            result.tab[i][j] = 0.0;
            for (int k = 0; k < 2; ++k) {
                result.tab[i][j] += tab[i][k] * copy.tab[k][j];
            }
        }
    }
    return result;
}

// Operator mno�enia przez skalar
Macierz Macierz::operator*(const double x) const {
    Macierz result;
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            result.tab[i][j] = tab[i][j] * x;
    return result;
}

// Operator por�wnania
bool Macierz::operator==(const Macierz& copy) const {
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            if (tab[i][j] != copy.tab[i][j])
                return false;
    return true;
}

// Operator dodawania i przypisania
Macierz& Macierz::operator+=(const Macierz& copy) {
    *this = *this + copy;
    return *this;
}

// Operator mno�enia i przypisania macierzy
Macierz& Macierz::operator*=(const Macierz& copy) {
    *this = *this * copy;
    return *this;
}

// Operator mno�enia przez skalar i przypisania
Macierz& Macierz::operator*=(const double x) {
    *this = *this * x;
    return *this;
}

// Metoda ustawiaj�ca warto�� elementu
void Macierz::set(int i, int j, double x) {
    if (i >= 0 && i < 2 && j >= 0 && j < 2)
        tab[i][j] = x;
}

// Metoda pobieraj�ca warto�� elementu
double Macierz::get(int i, int j) const {
    if (i >= 0 && i < 2 && j >= 0 && j < 2)
        return tab[i][j];
    return 0.0; // Zwraca 0.0, je�li indeksy s� poza zakresem.
}

// Metoda transponuj�ca macierz
void Macierz::transpozycja() {
    std::swap(tab[0][1], tab[1][0]);
}

// Przyjacielski operator wyj�cia
std::ostream& operator<<(std::ostream& s, const Macierz& m) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            s << m.tab[i][j] << " ";
        }
        s << std::endl;
    }
    return s;
}