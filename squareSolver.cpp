#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <cmath>
#define INFSOLVES 4
//#define NDEBUG

void enterSquare (float *a, float *b, float *c);
int solveSquare (const float a, const float b, const float c, float *x1, float *x2);
void printSquare (const int nRoots, float *x1, float *x2);

int main ()
{
    float a = 0;
    float b = 0;
    float c = 0;

    float x1 = 0;
    float x2 = 0;

    enterSquare (&a, &b, &c);

    int nRoots = solveSquare (a, b, c, &x1, &x2);

    printSquare (nRoots, &x1, &x2);

    return 0;
}

void enterSquare (float *a, float *b, float *c)
{
  printf ("enter X squared coefficient: ");
  scanf ("%f", a);
  assert(std::isfinite(*a));

  printf ("enter X coefficient: ");
  scanf ("%f", b);
  assert (std::isfinite(*b));

  printf ("enter absolute term: ");
  scanf ("%f", c);
  assert (std::isfinite(*c));
}

int solveSquare (const float a, const float b, const float c, float *x1, float *x2)
{
    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);

    float discr = b*b - 4*a*c;

    if ((a == 0) && (b == 0) && (c == 0))
    {
        return INFSOLVES;
    }
    else if (discr < 0)
    {
        return 0;
    }
    else if (discr == 0)
    {
         *x1 = *x2 = -b / (2*a);

         return 1;
    }
    else
    {
        float rootFromDiscr = sqrt (discr);

        *x1 = (-b + rootFromDiscr) / (2*a);
        *x2 = (-b - rootFromDiscr) / (2*a);

        return 2;
    }
}

void printSquare (const int nRoots, float *x1, float *x2)
    {
     switch (nRoots)
     {
        case 0: printf ("there is no solutions");
                break;
        case 1: printf ("the solution is x = %.2f.", *x1);
                break;
        case 2: printf ("the solutions are x = %.2f and x = %.2f\n", *x1, *x2);
                break;
        case INFSOLVES: printf ("any number");
                        break;
        default: printf ("ERROR");
                 break;
    }
   }
