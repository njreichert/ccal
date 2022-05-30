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
        /* First go up one line (1F) then clear the line (2K). */
        std::cout << "\033[1F" << "\033[2K" << std::flush;
    }
}

void setup_screen()
{
    /* 
     * Compensating for the user's '\n' here, so exiting will result 
     * in the prompt at the last line of the terminal at worst.
     */
    for (size_t i = 0; i < DISPLAY_SIZE + 2; i++) {
        std::cout << '\n';
    }
}

void print_state(const RPNStack &stack, bool no_escape)
{
    if (!no_escape) {
        /* One line for status, DISPLAY_SIZE for stack, one for prompt. */
        ansi_clear_lines(DISPLAY_SIZE + 2); 
    }

    std::cout << stack.error_msg() << '\n';

    for (std::vector<double>::size_type i = DISPLAY_SIZE; i > 0; i--) {
        std::cout << i << ":\t" << stack.get(i - 1) << '\n';
    }

    std::cout << "> " << std::flush;
}
