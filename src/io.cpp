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

#include "io.h"
#include "ops.h"
#include "util.h"
#include <iostream>
#include <stdexcept>

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

void print_state(const RPNStack &stack)
{
    for (std::vector<double>::size_type i = DISPLAY_SIZE; i > 0; i--) {
        std::cout << i << ":\t" << stack.get(i - 1) << '\n';
    }

    std::cout << "> " << std::flush;
}

