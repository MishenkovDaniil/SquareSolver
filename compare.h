/**
 * \file
 * \brief Header with information about "compare" functions.
 */

#ifndef COMPARE_H
#define COMPARE_H

static const double THRESHOLD = 2e-10;

/**
 * Check if values are equal with some threshold.
 * \param [in] val1      the first comparable value
 * \param [in] val2      the second comparable value
 * \param [in] threshold a threshold took in account of compare
 * \return               execution status of function (1 if equal, 0 if not)
 */
int is_equal   (const double val1, const double val2, const double threshold = THRESHOLD);

/**
 * Check if the first value is lower than second with some threshold.
 * \param [in] val1      the first comparable value
 * \param [in] val2      the second comparable value
 * \param [in] threshold a threshold took in account of compare
 * \return               execution status of function (1 if val1 is lower, 0 if not)
 */
int is_lower   (const double val1, const double val2, const double threshold = THRESHOLD);

/**
 *Check if the first value is greater than second with some threshold.
 * \param [in] val1      the first comparable value
 * \param [in] val2      the second comparable value
 * \param [in] threshold a threshold took in account of compare
 * \return               execution status of function (1 if val1 is greater, 0 if not)
 */
int is_greater (const double val1, const double val2, const double threshold = THRESHOLD);

#endif /* COMPARE_H */
