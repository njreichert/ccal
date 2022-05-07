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
OpType add(OpType a, OpType b);

OpType subtract(OpType a, OpType b);

OpType multiply(OpType a, OpType b);

OpType divide(OpType a, OpType b);

const std::unordered_map<std::string, OneFunc> one_arg_ops = {};

const std::unordered_map<std::string, TwoFunc> two_arg_ops = {
    {"+", [](OpType a, OpType b){ return a + b; }},
    {"-", [](OpType a, OpType b){ return a - b; }},
    {"*", [](OpType a, OpType b){ return a * b; }},
    {"/", [](OpType a, OpType b){ return a / b; }}
};

#endif
