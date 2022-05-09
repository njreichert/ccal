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

#include "defs.h"

/*
 * These functions are going to seem a bit obvious,
 * so no documentation here. Mostly they are wrappers
 * for operators so they fit with other functions (like
 * those from <cmath>).
 */

/* TODO: Replace simple ops with something else (maybe lambdas?) */

/* One-argument functions */ 
/* TODO */

/* Two-argument functions */
/* TODO */

/* TODO: Possibly relocate as an externally-linked variable? also set up namespaces? */
const std::unordered_map<std::string, OneFunc> one_arg_ops = {
    {"sqrt", std::sqrt},
    {"exp", std::exp},
    {"sin", std::sin},
    {"cos", std::cos},
    {"tan", std::tan},
    {"arcsin", std::asin},
    {"arccos", std::acos},
    {"arctan", std::atan},
    {"log", std::log10}, /* Yes, log10. log_e == ln. */
    {"ln", std::log},
    {"log2", std::log2},
    {"abs", std::abs},
    {"inv", [](OpType a){ return (1 / a); }},
    {"nroot", [](OpType a, OpType b){ return std::pow(b, (1 / a)); }}
};

const std::unordered_map<std::string, TwoFunc> two_arg_ops = {
    {"+", [](OpType a, OpType b){ return a + b; }},
    {"-", [](OpType a, OpType b){ return a - b; }},
    {"*", [](OpType a, OpType b){ return a * b; }},
    {"/", [](OpType a, OpType b){ return a / b; }},
    /*
     * std::pow returns x^y. Since we are working off a stack, we want y^x
     * (so the power is at the top of the stack.
     */
    {"^", [](OpType a, OpType b){ return std::pow(b, a)}}
}

#endif

