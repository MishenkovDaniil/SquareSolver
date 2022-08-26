/**
 * \file
 */

#ifndef BUFFER_H
#define BUFFER_H

/**
 * Scan input information to buffer.
 * \param [out] buffer array of input information
 * \param [in]  size   max size of input information, size of buffer
 * \return             execution status of function
 */
int scanInBuffer (char buffer[], const int size);

/**
 * Clean buffer content.
 * \param [out] buffer array of input information //
 * \param [in]  size   max size of input information, size of buffer
 */
void cleanBuffer (char buffer[], const int size);

#endif /* BUFFER_H */
