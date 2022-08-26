/**
 * \file
 * \brief consists from input information functions
 */

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

    int  nCh = 0;
    int nScanedValues = sscanf (buffer, "%lf %lf %lf%n", &coeffs->a, &coeffs->b, &coeffs->c, &nCh);

    if (nScanedValues != 3)
    {
        return INPUT_ERROR;
    }
    else
    {
        for (int i = nCh; (buffer [i]) != '\n' && (buffer[i]) != '\0'; i++)
        {
            if (!(isspace (buffer[i])))
            {
               return INPUT_ERROR;
               break;
            }
        }
    }

    assert (isfinite(coeffs->a));
    assert (isfinite(coeffs->b));
    assert (isfinite(coeffs->c));

    return 0;
}

