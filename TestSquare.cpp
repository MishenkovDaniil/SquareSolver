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


    testSquareInf.testCoeffs.a = 0;
    testSquareInf.testCoeffs.b = 1;
    testSquareInf.testCoeffs.c = 0;

    testSquareInf.realRoots.x1 = 0;

    singleTester (&testSquareInf, &roots, 1);


    testSquareInf.testCoeffs.a = 0;
    testSquareInf.testCoeffs.b = 0;
    testSquareInf.testCoeffs.c = 23;

    singleTester (&testSquareInf, &roots, 0);


    testSquareInf.testCoeffs.a = 4;
    testSquareInf.testCoeffs.b = 0;
    testSquareInf.testCoeffs.c = 0;

    testSquareInf.realRoots.x1 = 0;

    singleTester (&testSquareInf, &roots, 1);


    testSquareInf.testCoeffs.a =  1.0000000001;
    testSquareInf.testCoeffs.b =  2.0000000001;
    testSquareInf.testCoeffs.c = -3.0000000001;

    testSquareInf.realRoots.x1 = 1;
    testSquareInf.realRoots.x2 = -3;

    singleTester (&testSquareInf, &roots, 2);


    testSquareInf.testCoeffs.a =  1.0000000001;
    testSquareInf.testCoeffs.b =  2.0000000001;
    testSquareInf.testCoeffs.c = -3.0000000001;

    testSquareInf.realRoots.x1 = -3;
    testSquareInf.realRoots.x2 = 1;

    singleTester (&testSquareInf, &roots, 2);


    testSquareInf.testCoeffs.a = 0;
    testSquareInf.testCoeffs.b = 1;
    testSquareInf.testCoeffs.c = 2;

    testSquareInf.realRoots.x1 = 1;
    testSquareInf.realRoots.x2 = 0;

    singleTester (&testSquareInf, &roots, 1);

    return 0;
}
