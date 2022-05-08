/**
 * io.h
 *
 * By Nikolaus J. Reichert <nikolaus@njreichert.ca>
 *
 * Definitions for I/O related functions.
 */

#include <string>
#include <vector>

#include "defs.h"

/**
 * @brief runs though a given line of input (without '\n') and interprets it.
 *
 * @param line The line in question.
 * @param stack A reference to the calculator's current stack.
 *
 * @returns true if 'quit' or 'exit' was not input.
 */
bool parse_input(std::string line, std::vector<OpType> &stack);

/**
 * @brief Prints out the top DISPLAY_SIZE items in the stack, and a prompt for input.
 *
 * @param stack The stack to print.
 */
void print_state(const std::vector<OpType> &stack);

