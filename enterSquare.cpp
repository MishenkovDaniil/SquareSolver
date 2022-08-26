#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <ctype.h>
#include "square.h"
#include "enterSquare.h"
#include "Buffer.h"

int enterSquare (char buffer[], const int size, Coeffs *coeffs)
{
    assert (buffer);
    assert (coeffs);

    cleanBuffer (buffer, size);

    printf ("enter coefficients (3) of square equality through a space (default: 0 0 0): ");
    scanInBuffer (buffer, size); // error

    for (int i = 0; buffer[i] != '\0'; i++)
    {
        if (!(buffer[i] == ' '  ||
              buffer[i] == '\t' ||
              buffer[i] == '-'  ||
              buffer[i] == '+'  ||
              isdigit (buffer[i])))
        {
                return 0;
        }
    }

    sscanf (buffer, "%lf %lf %lf", &coeffs->a, &coeffs->b, &coeffs->c);

    assert (isfinite(coeffs->a));
    assert (isfinite(coeffs->b));
    assert (isfinite(coeffs->c));

    return 1;
}
