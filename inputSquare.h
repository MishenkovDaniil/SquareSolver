/**
 * \file
 */

#ifndef INPUT_SQUARE_H
#define INPUT_SQUARE_H

#include "square.h"

/// state numerical values for error situations
enum errors
{
    NO_ERROR = 0,        ///< state value for expected situations
    INPUT_ERROR = -1,    ///< state value for error situation
    BUFFER_OVERFLOW = -2 ///< state value for buffer overflow situation
};

/**
 * Scan and enter the coeficients of square equality.
 * \param [out] buffer array of input information
 * \param [in]  size   max size of input information, size of buffer
 * \param [out] coeffs coefficients which will be entered
 * \return             execution status of function (0 if the coefficients were entered right, else - ERROR)
 */
int enterSquare (char buffer[], const int size, Coeffs *coeffs);

#endif /* INPUT_SQUARE_H */
