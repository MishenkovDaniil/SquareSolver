#include <assert.h>
#include "isEqualStrings.h"

int isEqualStrings (const char str1[], const char str2[])
{
    assert (str1);
    assert (str2);

    for (int i = 0; str2[i] != '\0'; i++)
    {
        if (str1[i] != str2[i])
        {
            return 0;
        }
    }

    return 1;
}
