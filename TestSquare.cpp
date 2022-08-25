#include "singleTester.h"
#include "square.h"

int main()
{
    Roots roots = {};

    TestSquareInf testSquareInf = {};
    testSquareInf.testCoeffs.a = 0;
    testSquareInf.testCoeffs.b = 0;
    testSquareInf.testCoeffs.c = 0;

    singleTester (&testSquareInf, &roots, INF_ROOTS);

    return 0;
}
