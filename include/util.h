/**
 * util.h
 *
 * By Nikolaus J. Reichert <nikolaus@njreichert.ca>
 *
 * Definitions for various utilities.
 */

#include <string>

/**
 * @brief Checks if a given string will be interpreted correctly as a double via stod().
 *
 * @param str The string in question.
 *
 * @returns true if the string is parseable as a double.
 */
bool is_numeric(std::string str);

