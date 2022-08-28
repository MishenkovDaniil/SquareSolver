/**
 * \file
 * \brief consists from string comparing function
 */

#include  <ctype.h>
#include <stdio.h>
#include <assert.h>

#include "isEqualStrings.h"

int isEqualStrings (const char str1[], const char str2[])
{
    assert (str1);
    assert (str2);

    int i = 0;
    while (isspace (str1[i]) != 0)
    {
        i++;
    }

    for (int j = 0; str1[i] != ' ' && str1[i] != '\t' && str1[i] != '\0';j++, i++)
    {
        if (str1[i] != str2[j])
        {
            return 0;
        }
    }
    return 1;
}
