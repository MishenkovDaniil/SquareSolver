#include <stdio.h>
#include <assert.h>

#include "solveSquare.h"
#include "square.h"
#include "singleTester.h"
#include "compare.h"

void printFailedTest (Coeffs *testCoeffs, const int nRoots, Roots *roots,
                      const int real_nRoots, const double real_x1, const double real_x2);

void singleTester (TestSquareInf *testSquareInf, Roots *roots, const int real_nRoots)
{
    assert (testSquareInf);
    assert (roots);

    double real_x1 = testSquareInf->realRoots.x1;
    double real_x2 = testSquareInf->realRoots.x2;

    int nRoots = solveSquare (&testSquareInf->testCoeffs, roots);

    double x1 = roots->x1;
    double x2 = roots->x2;

    if ((nRoots == real_nRoots) &&
        ((is_equal (x1, real_x1) && is_equal (x2, real_x2)) ||
        (is_equal (x1, real_x2) && is_equal (x2, real_x1))))
    {
        printf ("SUCCESS\n\n\n");
    }
    else
    {
        printFailedTest (&testSquareInf->testCoeffs, nRoots, roots, real_nRoots, real_x1, real_x2);
    }
}

void printFailedTest (Coeffs *testCoeffs, const int nRoots, Roots *roots, const int real_nRoots, const double real_x1, const double real_x2)
{
    assert (roots);

    printf ("Failed: (%lf %lf %lf), nRoots = %d, x1 = %lf, x2 = %lf\n"
            "Expected: nRoots = %d, x1 = %lf, x2 = %lf\n\n\n",
            testCoeffs->a, testCoeffs->b, testCoeffs->c,
            nRoots, roots->x1, roots->x2, real_nRoots, real_x1, real_x2);
}
