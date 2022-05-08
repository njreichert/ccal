/**
 * util.h
 *
 * By Nikolaus J. Reichert <nikolaus@njreichert.ca>
 *
 * Definitions for various utilities.
 */

#include <string>
#include <vector>

#include "defs.h"

/**
 * @brief Checks if a given string will be interpreted correctly as a double via stod().
 *
 * @param str The string in question.
 *
 * @returns true if the string is parseable as a double.
 */
bool is_numeric(std::string str);

/**
 * @brief Attempts to pop off the top of the given stack, returning zero if it is empty.
 *
 * NB: Will modify stack!
 *
 * @param stack: The stack in question.
 *
 * @returns OpType's zero-equivalent, or stack.back() if the stack has it.
 */
OpType pop_or_zero(std::vector<OpType> stack);
