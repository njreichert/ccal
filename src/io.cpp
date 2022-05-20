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
        stack.parse_input(s);
    }

    /* If we have gotten here, we haven't seen quit yet. */
    return true;
}

void print_state(const std::vector<double> &stack)
{
    for (int i = DISPLAY_SIZE; i > stack.size(); i--) {
        std::cout << i << ":\t" << double() << std::endl;
    }

    if (stack.size() < DISPLAY_SIZE) {
        for (std::vector<double>::size_type i = 0; i < stack.size(); i++) {
            std::cout << stack.size() - i << ":\t" << stack[i] << std::endl;
        }
    } else {
        for (std::vector<double>::size_type i = DISPLAY_SIZE; i > 0; i--) {
            std::cout << i << ":\t" << stack[stack.size() - i] << std::endl;
        }
    }

    std::cout << "> " << std::flush;
}

