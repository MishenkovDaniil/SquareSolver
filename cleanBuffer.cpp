#include "cleanBuffer.h"

void cleanBuffer (char buffer[], const int size)
{
    for (int i = 0; i < size; i++)
    {
        buffer[i] = {0};
    }
}
