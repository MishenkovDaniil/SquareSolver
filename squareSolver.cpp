#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <cmath>
#define INFSOLVES 4
//#define NDEBUG

void enterSquare (float *a, float *b, float *c);
int numberOfRoots (const float a, const float b, const float c);
void solveSquare (const float a, const float b, const float c, const int nRoots, float *x1, float *x2);

int main ()
{
    float a = 0;
    float b = 0;
    float c = 0;

    float x1 = 0;
    float x2 = 0;

    enterSquare (&a, &b, &c);

    int nRoots = numberOfRoots (a, b, c);

    solveSquare (a, b, c, nRoots, &x1, &x2);

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

int numberOfRoots (const float a, const float b, const float c)
{
    const float DISCR = b*b - 4*a*c;

    if ((a == 0) && (b == 0) && (c == 0))
    {
        return INFSOLVES;
    }
    else if (DISCR < 0)
    {
        return 0;
    }
    else if (DISCR == 0)
    {
         return 1;
    }
    else
    {
        return 2;
    }
}

void solveSquare (const float a, const float b, const float c, const int nRoots, float *x1, float *x2)
{
     const float DISCR = b*b - 4*a*c;
     const float ROOT_FROM_DISCR = sqrt(DISCR);

     switch (nRoots)
     {
        case 0: printf ("there is no solutions");
                break;
        case 1: *x1 = *x2 = -b / (2*a);
                printf ("the solution is x = %f.", *x1);
                break;
        case 2: *x1 = (-b + ROOT_FROM_DISCR)/(2*a);
                *x2 = (-b - ROOT_FROM_DISCR)/(2*a);
                printf ("the solutions are x = %f and x = %f\n", *x1, *x2);
                break;
        case INFSOLVES: printf ("any number");
                        break;
        default: printf ("ERROR");
                 break;
    }
}
