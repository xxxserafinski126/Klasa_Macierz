#include <iostream>

class Macierz {
private:
    double tab[2][2]; // Prywatna tablica 2x2

public:
    // Konstruktor domyslny.
    Macierz();

    // Konstruktor kopiujacy.
    Macierz(const Macierz& copy);

    // Destruktor.
    ~Macierz();

    // Operator mnozenia macierzy.
    Macierz operator*(const Macierz& copy) const;

    // Operator dodawania macierzy.
    Macierz operator+(const Macierz& copy) const;

    // Operator mnozenia macierzy przez skalar.
    Macierz operator*(const double x) const;

    // Operator przypisania.
    Macierz& operator=(const Macierz& copy);

    // Operator porownania.
    bool operator==(const Macierz& copy) const;

    // Operator dodawania i przypisania.
    Macierz& operator+=(const Macierz& copy);

    // Operator mnozenia i przypisania macierzy.
    Macierz& operator*=(const Macierz& copy);

    // Operator mnozenia przez skalar i przypisania.
    Macierz& operator*=(const double x);

    // Przyjacielski operator wyjscia, umozliwiajacy wypisywanie macierzy.
    friend std::ostream& operator<<(std::ostream& s, const Macierz& m);

    // Metoda ustawiajaca wartosc elementu.
    void set(int i, int j, double x);

    // Metoda pobierajaca wartosc elementu.
    double get(int i, int j) const;

    // Metoda transponujaca macierz.
    void transpozycja();
};
