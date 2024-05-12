#ifndef CPPLIB_FRACTION_H
#define CPPLIB_FRACTION_H

#include <iosfwd> // for std::ostream

#ifdef SINGLE
using sInt = int32_t; // signed 32-bit integer.
#else
using sInt = int64_t; // signed 64-bit integer.
#endif

class Fraction
{
    sInt d_num; // Numerator.
    sInt d_den; // Denominator.

  public: // Constructor.
    explicit Fraction(sInt numerator, sInt denominator = 1);
    Fraction(Fraction const &other);   // Copy constructor.
    Fraction(Fraction &&tmp) noexcept; // Move constructor.

    sInt &num();               // Return/edit the numerator.
    sInt &denom();             // Return/edit the denominator.
    sInt const &num() const;   // Return the numerator.
    sInt const &denom() const; // Return the denominator.
    double approx() const;     // Return the decimal value.

    Fraction &operator=(Fraction const &other);     // Copy-assignment.
    Fraction &operator=(Fraction &&other) noexcept; // Move-assignment.

    friend std::ostream &operator<<(std::ostream &out, Fraction const &obj);
    friend std::ostream &operator<<(std::ostream &out, Fraction &&obj);

    Fraction &operator+=(Fraction const &rhs); // Add Fraction.
    Fraction &operator-=(Fraction const &rhs); // Subtract Fraction.
    Fraction &operator*=(Fraction const &rhs); // Multiply Fraction.
    Fraction &operator/=(Fraction const &rhs); // Divide Fraction.

    Fraction &operator+=(sInt scalar); // Add scalar.
    Fraction &operator-=(sInt scalar); // Subtract scalar.
    Fraction &operator*=(sInt scalar); // Multiply scalar.
    Fraction &operator/=(sInt scalar); // Divide scalar.

    bool operator==(Fraction const &other) const; // Compare w. Fraction.
    bool operator!=(Fraction const &other) const; // Compare w. Fraction.
    bool operator<(Fraction const &other) const;  // Compare w. Fraction.
    bool operator>(Fraction const &other) const;  // Compare w. Fraction.
    bool operator<=(Fraction const &other) const; // Compare w. Fraction.
    bool operator>=(Fraction const &other) const; // Compare w. Fraction.

  private:
    void normalize(); // Normalize fraction.
};

// Constructor.
inline Fraction::Fraction(sInt numerator, sInt denominator)
    : d_num(numerator)
    , d_den(denominator)
{
    normalize();
}

// Copy constructor.
inline Fraction::Fraction(Fraction const &other)
    : d_num(other.d_num)
    , d_den(other.d_den)
{
}

// Move constructor.
inline Fraction::Fraction(Fraction &&tmp) noexcept
    : d_num(tmp.d_num)
    , d_den(tmp.d_den)
{
    tmp.d_num = 1; // Leave the temporary
    tmp.d_den = 1; // object in a valid state.
}

// Return/edit the numerator.
inline sInt &Fraction::num()
{
    return d_num;
}

// Return/edit the denominator.
inline sInt &Fraction::denom()
{
    return d_den;
}

// Return the numerator.
inline sInt const &Fraction::num() const
{
    return d_num;
}

// Return the denominator.
inline sInt const &Fraction::denom() const
{
    return d_den;
}

// Return the decimal value.
inline double Fraction::approx() const
{
    return static_cast<double>(d_num) / d_den;
}

// Copy-assignment operator.
inline Fraction &Fraction::operator=(Fraction const &other)
{
    return *this = Fraction{other};
}

// Add two Fractions.
inline Fraction &Fraction::operator+=(Fraction const &rhs)
{
    d_num = d_num * rhs.d_den + d_den * rhs.d_num;
    d_den *= rhs.d_den;
    normalize();
    return *this;
}

// Subtract two Fractions.
inline Fraction &Fraction::operator-=(Fraction const &rhs)
{
    d_num = d_num * rhs.d_den - d_den * rhs.d_num;
    d_den *= rhs.d_den;
    normalize();
    return *this;
}

// Multiply two Fractions.
inline Fraction &Fraction::operator*=(Fraction const &rhs)
{
    d_num *= rhs.d_num;
    d_den *= rhs.d_den;
    normalize();
    return *this;
}

// Divide Fraction by scalar.
inline Fraction &Fraction::operator/=(Fraction const &rhs)
{
    d_num *= rhs.d_den;
    d_den *= rhs.d_num;
    normalize();
    return *this;
}

// Add scalar.
inline Fraction &Fraction::operator+=(sInt scalar)
{
    d_num += scalar * d_den;
    normalize();
    return *this;
}

// Subtract scalar.
inline Fraction &Fraction::operator-=(sInt scalar)
{
    d_num -= scalar * d_den;
    normalize();
    return *this;
}

// Multiply Scalar.
inline Fraction &Fraction::operator*=(sInt scalar)
{
    d_num *= scalar;
    normalize();
    return *this;
}

// Divide scalar.
inline Fraction &Fraction::operator/=(sInt scalar)
{
    d_den *= scalar;
    normalize();
    return *this;
}

// Compare w. Fraction.
inline bool Fraction::operator==(Fraction const &other) const
{
    return (d_num * other.d_den == other.d_num * d_den);
}

// Compare w. Fraction.
inline bool Fraction::operator!=(Fraction const &other) const
{
    return (d_num * other.d_den != other.d_num * d_den);
}

// Compare w. Fraction.
inline bool Fraction::operator>(Fraction const &other) const
{
    return (d_num * other.d_den > other.d_num * d_den);
}

// Compare w. Fraction.
inline bool Fraction::operator<(Fraction const &other) const
{
    return (d_num * other.d_den < other.d_num * d_den);
}

// Compare w. Fraction.
inline bool Fraction::operator>=(Fraction const &other) const
{
    return (d_num * other.d_den >= other.d_num * d_den);
}

// Compare w. Fraction.
inline bool Fraction::operator<=(Fraction const &other) const
{
    return (d_num * other.d_den <= other.d_num * d_den);
}

// Add two Fractions.
inline Fraction operator+(Fraction const &lhs, Fraction const &rhs)
{
    return Fraction{lhs} += rhs;
}

// Subtract two Fractions.
inline Fraction operator-(Fraction const &lhs, Fraction const &rhs)
{
    return Fraction{lhs} -= rhs;
}

// Multiply two Fractions.
inline Fraction operator*(Fraction const &lhs, Fraction const &rhs)
{
    return Fraction{lhs} *= rhs;
}

// Divide two Fractions.
inline Fraction operator/(Fraction const &lhs, Fraction const &rhs)
{
    return Fraction{lhs} /= rhs;
}

// Add scalar.
inline Fraction operator+(Fraction const &lhs, sInt scalar)
{
    return Fraction{lhs} += scalar;
}

// Add scalar.
inline Fraction operator+(sInt scalar, Fraction const &rhs)
{
    return Fraction{rhs} += scalar;
}

// Subtract scalar.
inline Fraction operator-(Fraction const &lhs, sInt scalar)
{
    return Fraction{lhs} -= scalar;
}

// Subtract scalar.
inline Fraction operator-(sInt scalar, Fraction const &rhs)
{
    return Fraction{rhs} -= scalar;
}

// Multiply scalar.
inline Fraction operator*(Fraction const &lhs, sInt scalar)
{
    return Fraction{lhs} *= scalar;
}

// Multiply scalar.
inline Fraction operator*(sInt scalar, Fraction const &rhs)
{
    return Fraction{rhs} *= scalar;
}

// Divide scalar.
inline Fraction operator/(Fraction const &lhs, sInt scalar)
{
    return Fraction{lhs} /= scalar;
}

// Divide scalar.
inline Fraction operator/(sInt scalar, Fraction const &rhs)
{
    return Fraction{scalar * rhs.denom(), rhs.num()};
}

#endif // FRACTION_H
