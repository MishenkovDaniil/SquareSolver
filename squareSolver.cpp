#include <stdio.h>
#include <math.h>
//#define NDEBUG
#include <assert.h>

void solve_square (const float a, const float b, const float c);

int main ()
{
    float a = 0;
    float b = 0;
    float c = 0;

    printf ("enter X squared coefficient: ");
    scanf ("%f", &a);

    printf ("enter X coefficient: ");
    scanf ("%f", &b);

    printf ("enter absolute term: ");
    scanf ("%f", &c);

    solve_square (a, b, c);

    return 0;
}

void solve_square (const float a, const float b, const float c)
{
    assert ((b*b - 4*a*c) >= 0);
    
    float rootFromD = sqrt(b*b - 4*a*c);

    float x1 = (-b + rootFromD)/2;
    float x2 = (-b - rootFromD)/2;
    
    if (x1 == x2)
    {
        printf ("the solution is x = %f\n", x1);
    }
    else
    {
        printf ("the solutions are x = %f and x = %f\n", x1, x2);
    }
}
