/**
 * io.h
 *
 * By Nikolaus J. Reichert <nikolaus@njreichert.ca>
 *
 * Definitions for I/O related functions.
 */

#pragma once

#include <string>
#include <vector>

#include "defs.h"
#include "rpnstack.h"

/**
 * @brief runs though a given line of input (without '\n') and interprets it.
 *
 * @param op_list A reference to a vector containing the given line, split up by spaces.
 * @param stack A reference to the calculator's current stack.
 *
 * @returns true if 'quit' or 'exit' was not input.
 */
bool parse_input(const std::vector<std::string> &op_list, RPNStack &stack);

/**
 * @brief Prints out the top DISPLAY_SIZE items in the stack, and a prompt for input.
 *
 * @param stack The stack to print.
 */
void print_state(const RPNStack &stack);

