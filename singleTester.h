/**
 *\file
 *\brief Header with information needed to test square equality.
 */

#ifndef SINGLE_TESTER_H
#define SINGLE_TESTER_H

#include "square.h"

struct TestSquareInf
{
    struct Coeffs testCoeffs{};
    struct Roots realRoots{};
};

void singleTester (TestSquareInf *testSquareInf, Roots *roots, const int real_nRoots);

#endif /* SINGLE_TESTER_H */
