#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <ctype.h>

#include "square.h"
#include "inputSquare.h"
#include "outputSquare.h"
#include "Buffer.h"

int enterSquare (char buffer[], const int size, Coeffs *coeffs)
{
    assert (buffer);
    assert (coeffs);

    cleanBuffer (buffer, size);

    printf ("enter coefficients (3) of square equality through a space: "); //

    int scanStatus = scanInBuffer (buffer, size);
    if (scanStatus == BUFFER_OVERFLOW)
    {
        printf ("Error: buffer overflow\n");//
    }

    int nScanedValues = sscanf (buffer, "%lf %lf %lf", &coeffs->a, &coeffs->b, &coeffs->c);
    if (nScanedValues != 3)
    {
        return INPUT_ERROR;
    }

    assert (isfinite(coeffs->a));
    assert (isfinite(coeffs->b));
    assert (isfinite(coeffs->c));

    return 0;
}
