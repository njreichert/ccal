/**
 * io.cpp
 *
 * By Nikolaus J. Reichert <nikolaus@njreichert.ca>
 *
 * I/O related functions.
 */

/*
 * Already included in io.h:
 *
 * <string>
 * <vector>
 *
 * "defs.h"
 * "rpnstack.h"
 */

#include <iostream>
#include <stdexcept>

#include "io.h"
#include "ops.h"
#include "util.h"

/**
 * @brief Attempts to clear n lines from the terminal, using ascii escape codes.
 *
 * Here, `n` starts from the cursor's current line.
 */
void ansi_clear_lines(size_t n);

bool parse_input(const std::vector<std::string> &op_list, RPNStack &stack)
{
    for (const std::string &s : op_list) {
        if (s == "q" || s == "quit" || s == "exit") {
            return false;
        }
        stack.apply_input(s);
    }

    /* If we have gotten here, we haven't seen quit yet. */
    return true;
}

void ansi_clear_lines(size_t n)
{
    for (size_t i = 0; i < n; i++) {
        /* First clear the line (2K) then move up one line (1F). */
        std::cout << "\033[2K" << "\033[1F" << std::flush;
    }
}

void print_state(const RPNStack &stack, bool is_first_print)
{
    if (!is_first_print) {
        /* One line for status, DISPLAY_SIZE for stack, one for prompt. */
        ansi_clear_lines(DISPLAY_SIZE + 2); 
    }
    
    /* TODO: Build off of this. */
    if (stack.is_error()) {
        std::cout << "Error\n";
    } else {
        std::cout << "Normal\n";
    }

    for (std::vector<double>::size_type i = DISPLAY_SIZE; i > 0; i--) {
        std::cout << i << ":\t" << stack.get(i - 1) << '\n';
    }

    std::cout << "> " << std::flush;
}

