/**
 * \file
 */

#ifndef SOLVE_SQUARE_H
#define SOLVE_SQUARE_H

#include "square.h"

/**
 * Solve square equality.
 * \param [in] coeffs entered square coefficients
 * \param [out] roots roots of square equality
 */
int solveSquare (Coeffs *coeffs, Roots *roots);

/**
 * Solve linear eqaulity.
 * \param [in] b X coefficient
 * \param [in] c absolute term
 * \param [out] roots roots of linear equality
 */
int solveLinear (const double b, const double c, Roots *roots);

#endif /* SOLVE_SQUARE_H */
