#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <cmath>
#define INF_ROOTS 4
//#define NDEBUG

struct Coeff
{
        double a = 0;
        double b = 0;
        double c = 0;
};

struct Roots
{
    double x1 = 0;
    double x2 = 0;
};

void enterSquare (Coeff *square);
int solveSquare (Coeff *square, Roots *x);
void printSquare (const int nRoots, Roots *x);

int main ()
{
    Coeff square = {};
    Coeff *psquare = &square;

    Roots x = {};
    Roots *proots = &x;

    enterSquare (psquare);

    int nRoots = solveSquare (psquare, proots);

    printSquare (nRoots, proots);

    return 0;
}

void enterSquare (Coeff *square)
{
  printf ("enter X squared coefficient: ");
  scanf ("%lf", &(*square).a);
  assert(std::isfinite((*square).a));

  printf ("enter X coefficient: ");
  scanf ("%lf", &(*square).b);
  assert (std::isfinite((*square).b));

  printf ("enter absolute term: ");
  scanf ("%lf", &(*square).c);
  assert (std::isfinite((*square).c));
}

int solveSquare (Coeff *square, Roots *x)
{
    double a = (*square).a;
    double b = (*square).b;
    double c = (*square).c;

    assert (&(*x).x1 != nullptr);
    assert (&(*x).x2 != nullptr);
    assert (&(*x).x1 != &(*x).x2);

    double discr = b*b - 4*a*c;

    if ((a == 0) && (b == 0) && (c == 0))
    {
        return INF_ROOTS;
    }
    else if (discr < 0)
    {
        return 0;
    }
    else if (discr == 0)
    {
         (*x).x1 = (*x).x2 = -b / (2 * a);

         return 1;
    }
    else
    {
        double rootFromDiscr = sqrt (discr);

        (*x).x1 = (-b + rootFromDiscr) / (2 * a);
        (*x).x2 = (-b - rootFromDiscr) / (2 * a);

        return 2;
    }
}

void printSquare (const int nRoots, Roots *x)
{
    assert (&(*x).x1 != nullptr);
    assert (&(*x).x2 != nullptr);
    assert (&(*x).x1 != &(*x).x2);

    switch (nRoots)
     {
        case 0:
            printf ("there is no solutions");
            break;
        case 1:
            printf ("the solution is x = %.2lf.", (*x).x1);
            break;
        case 2:
            printf ("the solutions are x = %.2lf and x = %.2lf\n", (*x).x1, (*x).x2);
            break;
        case INF_ROOTS:
            printf ("any number");
            break;
        default:
            assert (0);
            break;
    }
}
