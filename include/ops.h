/**
 * ops.h
 *
 * By Nikolaus J. Reichert <nikolaus@njreichert.ca>
 *
 * functions for operations.
 */

#ifndef _OPS_H
#define _OPS_H

#include <unordered_map>
#include <string>
#include <cmath>
#include <vector>

#include "defs.h"

/*
 * These functions are going to seem a bit obvious,
 * so no documentation here. Mostly they are wrappers
 * for operators so they fit with other functions (like
 * those from <cmath>).
 */

/* One-argument functions */ 
/**
 * @brief Returns the factorial of a given operand.
 *
 * @throws std::invalid_argument if the number is not an integer.
 */
double factorial(double a);

/* Two-argument functions */
/* TODO */

/* Commands */
/**
 * @brief Destructively sums all elements of the given stack together, saving to its end.
 * 
 * @param stack The stack in question.
 */
void sum_and_clear(std::vector<double> &stack);

#endif

