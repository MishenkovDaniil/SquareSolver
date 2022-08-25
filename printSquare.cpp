#include <stdio.h>
#include <assert.h>
#include "square.h"
#include "printSquare.h"

void printSquare (const int nRoots, Roots *roots)
{
    assert (roots);

    switch (nRoots)
     {
        case 0:
            printf ("there is no solutions\n");
            break;
        case 1:
            printf ("the solution is x = %.2lf.\n", roots->x1);
            break;
        case 2:
            printf ("the solutions are x = %.2lf and x = %.2lf\n", roots->x1, roots->x2);
            break;
        case INF_ROOTS:
            printf ("any number\n");
            break;
        default:
            assert (0);
            break;
    }
}
