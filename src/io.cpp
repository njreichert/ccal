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

const std::unordered_map<std::string, OneFunc> one_arg_ops = {
    {"sqrt", [](OpType a){ return std::sqrt(a); }},
    {"exp", [](OpType a){ return std::exp(a); }},
    {"sin", [](OpType a){ return std::sin(a); }},
    {"cos", [](OpType a){ return std::cos(a); }},
    {"tan", [](OpType a){ return std::tan(a); }},
    {"arcsin", [](OpType a){ return std::asin(a); }},
    {"arccos", [](OpType a){ return std::acos(a); }},
    {"arctan", [](OpType a){ return std::atan(a); }},
    {"log", [](OpType a){ return std::log10(a); }}, /* Yes, log10. log_e == ln. */
    {"ln", [](OpType a){ return std::log(a); }},
    {"log2", [](OpType a){ return std::log2(a); }},
    {"abs", [](OpType a){ return std::abs(a); }},
    {"inv", [](OpType a){ return (1 / a); }},
    {"!", factorial}
};

const std::unordered_map<std::string, TwoFunc> two_arg_ops = {
    {"+", [](OpType a, OpType b){ return a + b; }},
    {"-", [](OpType a, OpType b){ return a - b; }},
    {"*", [](OpType a, OpType b){ return a * b; }},
    {"/", [](OpType a, OpType b){ return a / b; }},
    
    /* TODO: Find a way to combine these two, as they're just semantics. */
    {"^", [](OpType a, OpType b){ return std::pow(a, b); }},
    {"pow", [](OpType a, OpType b){ return std::pow(a, b); }},
    {"nroot", [](OpType a, OpType b){ return std::pow(b, (1 / a)); }}
};

const std::unordered_map<std::string, StackOp> stack_ops = {
    {"clear", [](std::vector<OpType> &vec){ vec.clear(); }},
    {"sum", sum_and_clear}
};

const std::unordered_map<std::string, OpType> constants = {
    {"pi", std::asin(1) * 2},
    {"e", std::exp(1)}
};

bool parse_input(const std::vector<std::string> &op_list, std::vector<OpType> &stack)
{
    for (const auto &curr : op_list) {

        /* TODO: Add commands for changing operating modes. */
        if (is_numeric(curr)) {
            stack.push_back(std::stod(curr)); /* TODO: Not portable to other types! */
        } else if (one_arg_ops.find(curr) != one_arg_ops.end()) {
            OpType op_one = pop_or_zero(stack);

            stack.push_back(one_arg_ops.at(curr)(op_one));
        } else if (two_arg_ops.find(curr) != two_arg_ops.end()) {
            OpType op_two = pop_or_zero(stack);
            OpType op_one = pop_or_zero(stack);

            stack.push_back(two_arg_ops.at(curr)(op_one, op_two));
        } else if (constants.find(curr) != constants.end()) {
            stack.push_back(constants.at(curr));
        } else if (stack_ops.find(curr) != stack_ops.end()) {
            stack_ops.at(curr)(stack);
        } else if (curr == "exit" || curr == "quit" || curr == "q") {
            return false;
        } else {
            throw std::invalid_argument(curr);
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

