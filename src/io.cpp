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

bool parse_input(std::string line, std::vector<OpType> &stack)
{
    std::string current_token;
    std::string::size_type delimiter_pos; /* TODO: Replace with iterators. */
    bool has_token = true;
    
    while (has_token) {
        delimiter_pos = line.find(" ");

        /* i.e.: No spaces found in remaining string. */
        if (delimiter_pos == std::string::npos) {
            delimiter_pos = line.size();
            has_token = false; /* Will not have any more after this. */
        }
        
        current_token = line.substr(0, delimiter_pos);

        /* Erase current token, AND delimeter. */
        /* TODO: Check. This should not go out of bounds if we are at the end of the string. */
        line.erase(0, delimiter_pos + 1); 

        /* TODO: Add commands for changing operating modes. */
        if (is_numeric(current_token)) {
            stack.push_back(std::stod(current_token));
        } else if (one_arg_ops.find(current_token) != one_arg_ops.end()) {
            OpType op_one = pop_or_zero(stack);

            stack.push_back(one_arg_ops.at(current_token)(op_one));
        } else if (two_arg_ops.find(current_token) != two_arg_ops.end()) {
            OpType op_two = pop_or_zero(stack);
            OpType op_one = pop_or_zero(stack);

            stack.push_back(two_arg_ops.at(current_token)(op_one, op_two));
        } else if (constants.find(current_token) != constants.end()) {
            stack.push_back(constants.at(current_token));
        } else if (stack_ops.find(current_token) != stack_ops.end()) {
            stack_ops.at(current_token)(stack);
        } else if (current_token == "exit" || current_token == "quit" || current_token == "q") {
            return false;
        } else {
            throw std::invalid_argument(current_token);
        }
    }
    /* If we have gotten here, we haven't seen quit yet. */
    return true;
}

void print_state(const std::vector<OpType> &stack)
{
    for (int i = DISPLAY_SIZE; i > stack.size(); i--) {
        std::cout << i << ":\t" << OpType() << std::endl;
    }

    if (stack.size() < DISPLAY_SIZE) {
        for (std::vector<OpType>::size_type i = 0; i < stack.size(); i++) {
            std::cout << stack.size() - i << ":\t" << stack[i] << std::endl;
        }
    } else {
        for (std::vector<OpType>::size_type i = DISPLAY_SIZE; i > 0; i--) {
            std::cout << i << ":\t" << stack[stack.size() - i] << std::endl;
        }
    }

    std::cout << "> " << std::flush;
}

