#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "square.h"
#include "enterSquare.h"
#include "cleanBuffer.h"
#include "scanInBuffer.h"

void enterSquare (char buffer[], const int size, Coeffs *coeffs)
{
    cleanBuffer (buffer, size);

    printf ("enter coefficients of square equality through a space: ");

    scanInBuffer (buffer, size); // error
    sscanf (buffer, "%lf %lf %lf", &coeffs->a, &coeffs->b, &coeffs->c);

    assert (isfinite(coeffs->a));
    assert (isfinite(coeffs->b));
    assert (isfinite(coeffs->c));
}
