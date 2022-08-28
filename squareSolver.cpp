/**
 * \file
 * \brief consists from the main function that solves square equality
 */

#include <stdio.h>

#include "square.h"
#include "inputSquare.h"
#include "solveSquare.h"
#include "outputSquare.h"
#include "Buffer.h"
#include "isEqualStrings.h"

static const int BUFFER_SIZE = 20;

int main ()
{
    char buffer[BUFFER_SIZE] = {0};

    printf ("enter \"info\" to view possible options\n");

    for (;;)
    {
        cleanBuffer (buffer, BUFFER_SIZE);

        int status = scanInBuffer (buffer, BUFFER_SIZE);

        if (status == BUFFER_OVERFLOW)
        {
            showOption (BUFFER_OVERFLOW);
            break;
        }

        if (isEqualStrings (buffer, OPT_HELP))
        {
            showOption (HELP);
        }
        else if (isEqualStrings (buffer, OPT_INFO))
        {
            showOption (INFO);
        }
        else if (isEqualStrings (buffer, OPT_SOLVE))
        {
            Coeffs coeffs = {};
            Roots roots   = {};

            if (enterSquare (buffer, BUFFER_SIZE, &coeffs) == 0)
            {
                int nRoots = solveSquare (&coeffs, &roots);
                printSquare (nRoots, &roots);
            }
            else
            {
                showOption (INPUT_ERROR);
            }
        }
        else if (isEqualStrings (buffer, OPT_QUIT))
        {
            showOption (QUIT);
            break;
        }
        else
        {
            showOption (INPUT_ERROR);
        }
    }

    return 0;
}
