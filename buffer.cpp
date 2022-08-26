#include <stdio.h>
#include <assert.h>

#include "inputSquare.h"
#include "Buffer.h"

int scanInBuffer (char buffer[], const int size) //char *fgets (char *str, int n, FILE *stream)
{
    assert (buffer);

    int c = 0;
    for (int i = 0; (c = getchar ()) != EOF && c != '\n'; i++)
    {
        buffer [i] = c;
/*
        printf ("[%c]\t", c);
        printf ("[%d]\t", c);

        printf ("[%s]\n", buffer);
*/
        if (i > size)
        {
            return BUFFER_OVERFLOW;
        }
    }

    return NO_ERROR;
}

void cleanBuffer (char buffer[], const int size)
{
    assert (buffer);

    for (int i = 0; i < size; i++)
    {
        buffer[i] = {0};
    }
}
