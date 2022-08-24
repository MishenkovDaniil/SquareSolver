#ifndef COMPARE_H
#define COMPARE_H

static const double THRESHOLD = 2e-10;

int is_equal   (const double val1, const double val2, const double threshold = THRESHOLD);
int is_lower   (const double val1, const double val2, const double threshold = THRESHOLD);
int is_greater (const double val1, const double val2, const double threshold = THRESHOLD);

#endif /* COMPARE_H */
