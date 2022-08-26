/**
 * \file
 * \brief consists from solve equality functions
 */

#include <assert.h>
#include <math.h>

#include "square.h"
#include "compare.h"
#include "solveSquare.h"

int solveSquare (Coeffs *coeffs, Roots *roots)
{
    assert (roots);
    assert (coeffs);

    double a = coeffs->a;
    double b = coeffs->b;
    double c = coeffs->c;

    double discr = b*b - 4*a*c;

    if (is_equal (a, 0))
    {
        return solveLinear (b, c, roots);
    }
    else if (is_equal (c, 0))
    {
        roots->x1 = 0;
        if (is_equal (b, 0))
        {
            return 1;
        }
        else
        {
            roots->x2 = -b / a;

            return 2;
        }
    }
    else if (is_lower (discr, 0))
    {
        return 0;
    }
    else if (is_equal (discr, 0))
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

int solveLinear (const double b, const double c, Roots *roots)
{
    assert (roots);

    if (!is_equal (b, 0))
    {
        roots->x1 = roots->x2 = -c / b;

        return 1;
    }
    else if (is_equal (c, 0))
    {
        return INF_ROOTS;
    }
    else
    {
        return 0;
    }
}
