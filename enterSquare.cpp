#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "square.h"
#include "enterSquare.h"

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
