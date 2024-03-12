#include <iostream>

// Klasa Macierz reprezentuje macierz 2x2 i obs�uguje podstawowe operacje matematyczne na macierzach.
class Macierz {
private:
    double tab[2][2]; // Prywatna tablica 2x2 przechowuj�ca elementy macierzy.

public:
    // Konstruktor domy�lny.
    Macierz();

    // Konstruktor kopiuj�cy.
    Macierz(const Macierz& copy);

    // Destruktor.
    ~Macierz();

    // Operator mno�enia macierzy.
    Macierz operator*(const Macierz& copy) const;

    // Operator dodawania macierzy.
    Macierz operator+(const Macierz& copy) const;

    // Operator mno�enia macierzy przez skalar.
    Macierz operator*(const double x) const;

    // Operator przypisania.
    Macierz& operator=(const Macierz& copy);

    // Operator por�wnania.
    bool operator==(const Macierz& copy) const;

    // Operator dodawania i przypisania.
    Macierz& operator+=(const Macierz& copy);

    // Operator mno�enia i przypisania macierzy.
    Macierz& operator*=(const Macierz& copy);

    // Operator mno�enia przez skalar i przypisania.
    Macierz& operator*=(const double x);

    // Przyjacielski operator wyj�cia, umo�liwiaj�cy wypisywanie macierzy.
    friend std::ostream& operator<<(std::ostream& s, const Macierz& m);

    // Metoda ustawiaj�ca warto�� elementu.
    void set(int i, int j, double x);

    // Metoda pobieraj�ca warto�� elementu.
    double get(int i, int j) const;

    // Metoda transponuj�ca macierz.
    void transpozycja();
};
