#include <iostream>

// Klasa Macierz reprezentuje macierz 2x2 i obsługuje podstawowe operacje matematyczne na macierzach.
class Macierz {
private:
    double tab[2][2]; // Prywatna tablica 2x2 przechowująca elementy macierzy.

public:
    // Konstruktor domyślny.
    Macierz();

    // Konstruktor kopiujący.
    Macierz(const Macierz& copy);

    // Destruktor.
    ~Macierz();

    // Operator mnożenia macierzy.
    Macierz operator*(const Macierz& copy) const;

    // Operator dodawania macierzy.
    Macierz operator+(const Macierz& copy) const;

    // Operator mnożenia macierzy przez skalar.
    Macierz operator*(const double x) const;

    // Operator przypisania.
    Macierz& operator=(const Macierz& copy);

    // Operator porównania.
    bool operator==(const Macierz& copy) const;

    // Operator dodawania i przypisania.
    Macierz& operator+=(const Macierz& copy);

    // Operator mnożenia i przypisania macierzy.
    Macierz& operator*=(const Macierz& copy);

    // Operator mnożenia przez skalar i przypisania.
    Macierz& operator*=(const double x);

    // Przyjacielski operator wyjścia, umożliwiający wypisywanie macierzy.
    friend std::ostream& operator<<(std::ostream& s, const Macierz& m);

    // Metoda ustawiająca wartość elementu.
    void set(int i, int j, double x);

    // Metoda pobierająca wartość elementu.
    double get(int i, int j) const;

    // Metoda transponująca macierz.
    void transpozycja();
};
