#include <stdio.h>
#include <math.h>
//#define NDEBUG
#include <assert.h>
#include <cmath>

enum square_consts {INF_ROOTS = 4};

struct Coeffs
{
    double a = 0;
    double b = 0;
    double c = 0;
};

struct Roots
{
    int nRoots = 0;
    double x1  = 0;
    double x2  = 0;
};

void enterSquare (Coeffs *coeffs);
void solveSquare (Coeffs *coeffs, Roots *roots);
int solveLiner (const double b, const double c, Roots *roots);
void printSquare (Roots *roots);

int main ()
{
    Coeffs coeffs = {};
    Roots roots   = {};

    enterSquare (&coeffs);
    solveSquare (&coeffs, &roots);
    printSquare (&roots);

    return 0;
}

void enterSquare (Coeffs *coeffs)
{
    printf ("enter X squared coefficient: ");
    scanf ("%lf", &coeffs->a);
    assert (std::isfinite(coeffs->a));

    printf ("enter X coefficient: ");
    scanf ("%lf", &coeffs->b);
    assert (std::isfinite(coeffs->b));

    printf ("enter absolute term: ");
    scanf ("%lf", &coeffs->c);
    assert (std::isfinite(coeffs->c));
}

void solveSquare (Coeffs *coeffs, Roots *roots)
{
    assert (roots);
    assert (coeffs);

    double a = coeffs->a;
    double b = coeffs->b;
    double c = coeffs->c;

    double discr = b*b - 4*a*c;

    if (a == 0)
    {
        roots->nRoots = solveLiner (b, c, roots);
    }
    else if (discr < 0)
    {
        roots->nRoots = 0;
    }
    else if (discr == 0)
    {
         roots->x1 = roots->x2 = -b / (2 * a);

         roots->nRoots = 1;
    }
    else
    {
        double rootFromDiscr = sqrt (discr);

        roots->x1 = (-b + rootFromDiscr) / (2 * a);
        roots->x2 = (-b - rootFromDiscr) / (2 * a);

        roots->nRoots = 2;
    }
}

int solveLiner (const double b, const double c, Roots *roots)
{
    if (b != 0)
    {
        roots->x1 = roots->x2 = -c / b;
        return 1;
    }
    else if (c == 0)
    {
        return INF_ROOTS;
    }
    else
    {
        return 0;
    }
}

void printSquare (Roots *roots)
{
    assert (roots);

    switch (roots->nRoots)
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
