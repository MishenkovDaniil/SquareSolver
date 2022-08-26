/**
 * \file
 * \brief Header including information about square expression.
 */

#ifndef SQUARE_H
#define SQUARE_H

/// state value for not finite values
enum square_consts
{
    INF_ROOTS = 4 ///< state value if number of roots is infinity
};

/// state coeffs of square equality
struct Coeffs
{
    double a = 0; ///< X squared coefficient of equality
    double b = 0; ///< X coefficient of equality
    double c = 0; ///< absolute term
};

/// state roots of square equality
struct Roots
{
    double x1  = 0; ///< the first root of square equality
    double x2  = 0; ///< the second root of square equality
};

#endif /* SQUARE_H */
