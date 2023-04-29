#include "header.h"

class Rational
{
public:
    Rational(int n = 0) : a(n), q(1) { change_a_and_q(); }
    Rational(int i, int j) : a(i), q(j) { change_a_and_q(); }
    Rational(double r) : q(BIG), a(r * BIG) { change_a_and_q(); }
    void print() const { cout << a << "/" << q << endl; }
    // operator double() { return static_cast<double>(a) / q; }
    void change_a_and_q()
    {
        unsigned int gcd = found_greatest_common_divisor(a, q);
        a /= gcd;
        q /= gcd;
        print();
    }
    unsigned int found_greatest_common_divisor(unsigned int a, unsigned int q)
    {
        if (a % q == 0)
            return q;
        if (q % a == 0)
            return a;
        if (a > q)
            return found_greatest_common_divisor(a % q, q);
        return found_greatest_common_divisor(a, q % a);
    }
    bool operator==(const double &c) { return (static_cast<double>(a) / q) == c; }
    bool operator==(const Rational &c) { return (a == c.a) && (q == c.q); }
    bool operator!=(const double &c) { return !((static_cast<double>(a) / q) == c); }
    bool operator!=(const Rational &c) { return !((a == c.a) && (q == c.q)); }
    bool operator<(const double &c) { return (static_cast<double>(a) / q) < c; }
    bool operator<(const Rational &c) { return (static_cast<double>(a) / q) < (static_cast<double>(c.a) / c.q); }
    bool operator>(const double &c) { return (static_cast<double>(a) / q) > c; }
    bool operator>(const Rational &c) { return (static_cast<double>(a) / q) > (static_cast<double>(c.a) / c.q); }
    bool operator<=(const double &c) { return (*this == c) || (*this < c); }
    bool operator<=(const Rational &c) { return (*this == c) || (*this < c); }
    bool operator>=(const double &c) { return (*this == c) || (*this > c); }
    bool operator>=(const Rational &c) { return (*this == c) || (*this > c); }

private:
    int a, q;
    enum
    {
        BIG = 1000
    };
};