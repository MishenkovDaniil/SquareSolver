/**
 * \file
 */

#ifndef OUTPUT_SQUARE_H
#define OUTPUT_SQUARE_H

#include "square.h"

static const char OPT_HELP[]  = "help";  /// state option "help"
static const char OPT_QUIT[]  = "quit";  /// state option "quit"
static const char OPT_INFO[]  = "info";  /// state option "info"
static const char OPT_SOLVE[] = "solve"; /// state option "solve"

/// state numerical values for menu options
enum options
{
    HELP  = 1, ///< state value for "help" request
    QUIT  = 2, ///< state value for "quit" request
    INFO  = 3  ///< state value for "info" request
};

/**
 * Print the solution of square equality.  //
 * \param [in] nRoots amount of roots
 * \param [in]  roots values of roots
 */
void printSquare (const int nRoots, Roots *roots);

/**
 * Show user commands.
 * \param [in]  number number of showing case
 */
void showOption (const int number);

#endif /* OUTPUT_SQUARE_H */
