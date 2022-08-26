#include <stdio.h>
#include "square.h"
#include "printSquare.h"
#include "solveSquare.h"
#include "enterSquare.h"
#include "Buffer.h"
#include "isEqualStrings.h"
#include "answer.h"

static const int BUFFER_SIZE = 10;

int main ()
{
    char buffer[BUFFER_SIZE] = {0};

    for (;;)
    {
        cleanBuffer (buffer, BUFFER_SIZE);

        int status = scanInBuffer (buffer, BUFFER_SIZE); //

        if (status == BUFFER_OVERFLOW)
        {
            printf ("Error: buffer overflow");
            break;
        }

        if (isEqualStrings (buffer, OPT_HELP))
        {
            Answer (HELP);
        }
        else if (isEqualStrings (buffer, OPT_INFO))
        {
            Answer (INFO);
        }
        else if (isEqualStrings (buffer, OPT_SOLVE))
        {
            Coeffs coeffs = {};
            Roots roots   = {};

            if (enterSquare (buffer, BUFFER_SIZE, &coeffs))
            {
                int nRoots = solveSquare (&coeffs, &roots);
                printSquare (nRoots, &roots);
            }
            else
            {
                Answer (ERROR);
            }
        }
        else if (isEqualStrings (buffer, OPT_QUIT))
        {
            Answer (QUIT);
            break;
        }
        else
        {
            Answer (ERROR);
        }
    }

    return 0;
}
