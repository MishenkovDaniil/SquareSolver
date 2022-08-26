/**
 * \file
 * \brief compare values if they are equal, the first one is greater or lower
 */

 #include <math.h>

#include "compare.h"

int is_equal (const double val1, const double val2, const double threshold)
{
    return fabs (val1 - val2) <= threshold;
}

int is_lower (const double val1, const double val2, const double threshold)
{
    if (!is_equal (val1, val2, threshold))
    {
        return val1 < val2;
    }
    else
    {
        return 0;
    }
}

int is_greater (const double val1, const double val2, const double threshold)
{
    return (is_equal (val1, val2, threshold)) ? 0 : (val1 > val2);
}

