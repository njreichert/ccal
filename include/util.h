/**
 * util.h
 *
 * By Nikolaus J. Reichert <nikolaus@njreichert.ca>
 *
 * Definitions for various utilities.
 */

#pragma once

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
 * @brief Checks if a given operand is effectively an integer.
 *
 * @param op The operand in question.
 *
 * @returns true if the operand is equivalent to an integer, otherwise false.
 */
bool is_int(double op);

/**
 * @brief Attempts to pop off the top of the given stack, returning zero if it is empty.
 *
 * NB: Will modify stack!
 *
 * @param stack: The stack in question.
 *
 * @returns double's zero-equivalent, or stack.back() if the stack has it.
 */
double pop_or_zero(std::vector<double> &stack);

/**
 * @brief appends every contiguous non-whitespace section of text to a vector.
 *
 * @param str The string in question.
 *
 * @returns a vector of all non-whitespace "words" in the given string.
 */
std::vector<std::string> string_to_vec(std::string str);

/**
 * @brief strip all whitespace from the given string.
 *
 * @param str The string to remove from (in place!)
 */
void strip_string(std::string &str);

