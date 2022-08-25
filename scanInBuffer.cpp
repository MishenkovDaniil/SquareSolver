#include <stdio.h>
#include "interactivePanelEnums.h"
#include "scanInBuffer.h"

int scanInBuffer (char buffer[], const int MAXSIZE)
{
    char c = 0;
    for (int i = 0; (c = (char)getchar ()) != EOF && c != '\n'; i++)
    {
        buffer [i] = c;
        if (i > MAXSIZE)
        {
            return BUFFER_OVERFLOW;
        }
    }

    return 0;
}
