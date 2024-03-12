#include "macierz.hpp"


Macierz::Macierz() {
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            tab[i][j] = 0.0;
}


Macierz::Macierz(const Macierz& copy) {
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            tab[i][j] = copy.tab[i][j];
}


Macierz::~Macierz() {
  
}


Macierz& Macierz::operator=(const Macierz& copy) {
    if (this != &copy) {
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                tab[i][j] = copy.tab[i][j];
    }
    return *this;
}


Macierz Macierz::operator+(const Macierz& copy) const {
    Macierz result;
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            result.tab[i][j] = tab[i][j] + copy.tab[i][j];
    return result;
}

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


Macierz Macierz::operator*(const double x) const {
    Macierz result;
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            result.tab[i][j] = tab[i][j] * x;
    return result;
}


bool Macierz::operator==(const Macierz& copy) const {
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            if (tab[i][j] != copy.tab[i][j])
                return false;
    return true;
}


Macierz& Macierz::operator+=(const Macierz& copy) {
    *this = *this + copy;
    return *this;
}


Macierz& Macierz::operator*=(const Macierz& copy) {
    *this = *this * copy;
    return *this;
}


Macierz& Macierz::operator*=(const double x) {
    *this = *this * x;
    return *this;
}


void Macierz::set(int i, int j, double x) {
    if (i >= 0 && i < 2 && j >= 0 && j < 2)
        tab[i][j] = x;
}


double Macierz::get(int i, int j) const {
    if (i >= 0 && i < 2 && j >= 0 && j < 2)
        return tab[i][j];
    return 0.0; // Zwraca 0.0, jeœli indeksy s¹ poza zakresem.
}


void Macierz::transpozycja() {
    std::swap(tab[0][1], tab[1][0]);
}


std::ostream& operator<<(std::ostream& s, const Macierz& m) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            s << m.tab[i][j] << " ";
        }
        s << std::endl;
    }
    return s;
}
