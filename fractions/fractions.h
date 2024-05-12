#ifndef CPPLIB_FRACTION_H
#define CPPLIB_FRACTION_H

#include <cstdint>
#include <iosfwd>
#include <vector>

namespace fractions
{

#ifdef SINGLE
using sInt = int_fast32_t;  // Signed 32-bit integer.
using uInt = uint_fast32_t; // Unsigned 32-bit integer.
#else
using sInt = int_fast64_t;  // Signed 64-bit integer.
using uInt = uint_fast64_t; // Unsigned 64-bit integer.
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

// Converts a fraction p/q to a continued fraction representation.
std::vector<uInt> fromfrac(Fraction const &frac);

// Converts a fraction p/q to a continued fraction representation.
std::vector<uInt> fromfrac(uInt p, uInt q);

// Converts a continued fraction back to a fraction p/q.
Fraction tofrac(std::vector<uInt> const &cf);

// Converts a square root N to a continued fraction representation.
// The optional lim is a limit for the number of coefficients in the continued fraction.
// If set to zero, will compute until full period is found.
std::vector<uInt> fromsqrt(uInt N, uInt lim = 0);

// Converts a continued fraction back to a square root sqrt(N).
// Returns an approximation of the square root as a decimal value.
// Note that unlike the fraction case, the continued fraction representation
// of a square root is periodic. Therefore, the number N resulting from this
// function will be an approximation.
double tosqrt_dec(std::vector<uInt> const &cf, uInt iter = 2);

// Converts a continued fraction back to a square root sqrt(N).
// Returns an approximation of the square root as a Fraction.
// Note that unlike the fraction case, the continued fraction representation
// of a square root is periodic. Therefore, the number N resulting from this
// function will be an approximation.
Fraction tosqrt_frac(std::vector<uInt> const &cf, uInt iter = 2);

} // namespace fractions

#endif // FRACTION_H
