/**
 * ops.cpp
 *
 * By Nikolaus J. Reichert <nikolaus@njreichert.ca>
 *
 * Implemenation for various operations.
 */

#include <vector>
#include <numeric>
#include <stdexcept>

#include "ops.h"
#include "defs.h"
#include "util.h"

void sum_and_clear(std::vector<OpType> &stack)
{
    OpType sum = std::accumulate(stack.begin(), stack.end(), OpType());
    stack.clear();
    stack.push_back(sum);
}

/* TODO
OpType factorial(OpType a)
{
    if (!is_int(a)) {
        throw std::invalid_argument;
    }

    while
*/
