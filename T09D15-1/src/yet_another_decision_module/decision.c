#include "decision.h"

#include <math.h>

#include "../data_libs/data_stat.h"

int make_decision(double *data, int n) {
    int decision = 1;

    double m = mean(data, n);
    double sigma = sqrt(variance(data, n));
    double max_value = max(data, n);
    double min_value = min(data, n);

    decision &= (min_value <= m + 3 * sigma) && (max_value >= m - 3 * sigma) && (m >= GOLDEN_RATIO);

    return decision;
}