#include <iostream>

// Klasa Macierz reprezentuje macierz 2x2 i obs³uguje podstawowe operacje matematyczne na macierzach.
class Macierz {
private:
    double tab[2][2]; // Prywatna tablica 2x2 przechowuj¹ca elementy macierzy.

public:
    // Konstruktor domyœlny.
    Macierz();

    // Konstruktor kopiuj¹cy.
    Macierz(const Macierz& copy);

    // Destruktor.
    ~Macierz();

    // Operator mno¿enia macierzy.
    Macierz operator*(const Macierz& copy) const;

    // Operator dodawania macierzy.
    Macierz operator+(const Macierz& copy) const;

    // Operator mno¿enia macierzy przez skalar.
    Macierz operator*(const double x) const;

    // Operator przypisania.
    Macierz& operator=(const Macierz& copy);

    // Operator porównania.
    bool operator==(const Macierz& copy) const;

    // Operator dodawania i przypisania.
    Macierz& operator+=(const Macierz& copy);

    // Operator mno¿enia i przypisania macierzy.
    Macierz& operator*=(const Macierz& copy);

    // Operator mno¿enia przez skalar i przypisania.
    Macierz& operator*=(const double x);

    // Przyjacielski operator wyjœcia, umo¿liwiaj¹cy wypisywanie macierzy.
    friend std::ostream& operator<<(std::ostream& s, const Macierz& m);

    // Metoda ustawiaj¹ca wartoœæ elementu.
    void set(int i, int j, double x);

    // Metoda pobieraj¹ca wartoœæ elementu.
    double get(int i, int j) const;

    // Metoda transponuj¹ca macierz.
    void transpozycja();
};
