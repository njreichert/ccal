/**
 * ops.cpp
 *
 * By Nikolaus J. Reichert <nikolaus@njreichert.ca>
 *
 * Implemenation for various operations.
 */

#include <string>
#include <vector>
#include <numeric>
#include <stdexcept>

#include "ops.h"
#include "defs.h"
#include "util.h"

void sum_and_clear(std::vector<double> &stack)
{
    double sum = std::accumulate(stack.begin(), stack.end(), double());
    stack.clear();
    stack.push_back(sum);
}

double factorial(double a)
{
    double total = 1;

    if (!is_int(a)) {
        throw std::invalid_argument(std::to_string(a)); /* TODO: Find a way to pass the arg safely. */
    }

    while (a > 0) {
       total *= a--;
    }

    return total;
}

