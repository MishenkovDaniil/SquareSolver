#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "compare.h"
#include "square.h"
#include "square.h"

const double THRESHOLD = 2e-10;

int main ()
{
    Coeffs coeffs = {};
    Roots roots   = {};

    enterSquare (&coeffs);
    int nRoots = solveSquare (&coeffs, &roots);
    printSquare (nRoots, &roots);

    return 0;
}

void enterSquare (Coeffs *coeffs)
{
    printf ("enter X squared coefficient: ");
    scanf  ("%lf", &coeffs->a);
    assert (isfinite(coeffs->a));

    printf ("enter X coefficient: ");
    scanf  ("%lf", &coeffs->b);
    assert (isfinite(coeffs->b));

    printf ("enter absolute term: ");
    scanf  ("%lf", &coeffs->c);
    assert (isfinite(coeffs->c));
}

int solveSquare (Coeffs *coeffs, Roots *roots)
{
    assert (roots);
    assert (coeffs);

    double a = coeffs->a;
    double b = coeffs->b;
    double c = coeffs->c;

    double discr = b*b - 4*a*c;

    if (is_equal (a, 0, THRESHOLD))
    {
        return solveLiner (b, c, roots);
    }
    else if (is_lower (discr, 0, THRESHOLD))
    {
        return 0;
    }
    else if (is_equal (discr, 0, THRESHOLD))
    {
        roots->x1 = roots->x2 = -b / (2 * a);

        return 1;
    }
    else
    {
        double rootFromDiscr = sqrt (discr);

        roots->x1 = (-b + rootFromDiscr) / (2 * a);
        roots->x2 = (-b - rootFromDiscr) / (2 * a);

        return 2;
    }
}

int solveLiner (const double b, const double c, Roots *roots)
{
    if (!is_equal (b, 0, THRESHOLD))
    {
        roots->x1 = roots->x2 = -c / b;

        return 1;
    }
    else if (is_equal (c, 0, THRESHOLD))
    {
        return INF_ROOTS;
    }
    else
    {
        return 0;
    }
}

void printSquare (const int nRoots, Roots *roots)
{
    assert (roots);

    switch (nRoots)
     {
        case 0:
            printf ("there is no solutions");
            break;
        case 1:
            printf ("the solution is x = %.2lf.", roots->x1);
            break;
        case 2:
            printf ("the solutions are x = %.2lf and x = %.2lf\n", roots->x1, roots->x2);
            break;
        case INF_ROOTS:
            printf ("any number");
            break;
        default:
            assert (0);
            break;
    }
}

int is_equal (const double val1, const double val2, const double threshold)
{
    return fabs (val1 - val2) <= threshold;
}

int is_lower (const double val1, const double val2, const double threshold)
{
    if (!is_equal (val1, val2, threshold))
    {
        return val1 < val2;
    }
    else
    {
        return 0;
    }
}

int is_greater (const double val1, const double val2, const double threshold)
{
    return (is_equal (val1, val2, threshold)) ? 0 : (val1 > val2);
}
