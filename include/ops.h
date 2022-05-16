/**
 * ops.h
 *
 * By Nikolaus J. Reichert <nikolaus@njreichert.ca>
 *
 * functions for operations.
 */

#ifndef _OPS_H
#define _OPS_H

#include <unordered_map>
#include <string>
#include <cmath>
#include <vector>

#include "defs.h"

/*
 * These functions are going to seem a bit obvious,
 * so no documentation here. Mostly they are wrappers
 * for operators so they fit with other functions (like
 * those from <cmath>).
 */

/* TODO: Replace simple ops with something else (maybe lambdas?) */

/* One-argument functions */ 
/**
 * @brief Returns the factorial of a given operand.
 *
 * @throws std::invalid_argument if the number is not an integer.
 */
OpType factorial(OpType a);

/* Two-argument functions */
/* TODO */

/* Commands */
/**
 * @brief Destructively sums all elements of the given stack together, saving to its end.
 * 
 * @param stack The stack in question.
 */
void sum_and_clear(std::vector<OpType> &stack);

/* TODO: Possibly relocate as an externally-linked variable? also set up namespaces? */
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

#endif

