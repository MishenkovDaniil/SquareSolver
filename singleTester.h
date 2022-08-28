/**
 * \file
 * \brief Header with information needed to test square equality.
 */

#ifndef SINGLE_TESTER_H
#define SINGLE_TESTER_H

#include "square.h"

struct TestSquareInf
{
    struct Coeffs testCoeffs{};
    struct Roots realRoots{};
};

/**
 * test a single square equality
 * \param [in] testSquareInf coeffs and real roots of square equality
 * \param [in] roots         roots received by a program
 * \param [in] real_nRoots   real number of roots
 */
void singleTester (TestSquareInf *testSquareInf, Roots *roots, const int real_nRoots);

#endif /* SINGLE_TESTER_H */
