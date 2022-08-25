#include <stdio.h>
#include "solveSquare.h"
#include "square.h"
#include "singleTester.h"
#include "compare.h"

void printFailedTest (const int nRoots, Roots *roots, const int real_nRoots, const double real_x1, const double real_x2);

void singleTester (TestSquareInf *testSquareInf, Roots *roots, const int real_nRoots)
{
    double real_x1 = testSquareInf->realRoots.x1;
    double real_x2 = testSquareInf->realRoots.x2;

    double x1 = roots->x1;
    double x2 = roots->x2;

    int nRoots = solveSquare (&testSquareInf->testCoeffs, roots);

    if ((!(nRoots == real_nRoots))
        ||
       (!((nRoots == 1) &&     (is_equal (x1, real_x1)))
        ||
         ((nRoots == 2) && (!(((is_equal (x1, real_x1)) && (is_equal (x2, real_x2)))
                           || ((is_equal (x1, real_x2)) && (is_equal (x2, real_x1)))))))
    {
        printFailedTest (nRoots, roots, real_nRoots, real_x1, real_x2);
    }
    else
    {
        printf ("SUCCESS");
    }
}

void printFailedTest (const int nRoots, Roots *roots, const int real_nRoots, const double real_x1, const double real_x2)
{
    printf ("Failed: (%lf %lf %lf), nRoots = %d, x1 = %lf, x2 = %lf" \
            "Expected: nRoots = %d, x1 = %lf, x2 = %lf", nRoots, roots->x1, roots->x2, real_nRoots, real_x1, real_x2);
}
