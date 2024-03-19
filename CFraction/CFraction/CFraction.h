#pragma once
class Fraction {
    int _numerator;       // числитель
    int _denominator;     // заменатель
public:
    Fraction();
    Fraction(const Fraction& F1);
    Fraction(int numerator, int denumirator);
    /*Fraction(float num);*/
    void set_numerator(int numerator);
    void set_denominator(int denuminator);
    int get_numerator();
    int get_denuminator();

    void print();
    void Do_easier();
    Fraction operator=(const Fraction& fr);

    bool operator!=(const Fraction& fr);
    bool operator>=(const Fraction& fr);
    bool operator<=(const Fraction& fr);
    bool operator<(const Fraction& fr);
    bool operator>(const Fraction& fr);

    Fraction operator+(const Fraction& fr1);
    void operator+=(const Fraction& fr1);

    Fraction operator-(const Fraction& fr);
    void operator-=(const Fraction& fr);
};