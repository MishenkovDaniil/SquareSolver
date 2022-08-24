#ifndef SQUARE_H
#define SQUARE_H

enum square_consts
{
    INF_ROOTS = 4
};

struct Coeffs
{
    double a = 0;
    double b = 0;
    double c = 0;
};

struct Roots
{
    double x1  = 0;
    double x2  = 0;
};

void enterSquare (Coeffs *coeffs);

int solveSquare (Coeffs *coeffs, Roots *roots);
int solveLiner (const double b, const double c, Roots *roots);

void printSquare (int nRoots, Roots *roots);

#endif /* SQUARE_H */
