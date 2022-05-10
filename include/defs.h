/**
 * defs.h
 *
 * By Nikolaus J. Reichert <nikolaus@njreichert.ca>
 *
 * Various definitions and macros.
 */

#ifndef _DEFS_H
#define _DEFS_H

#include <string>

/* Defines */
#define DISPLAY_SIZE 4

/* Constants */
const std::string HELP_PRINT = R"(
Usage:
 ccal [options]

Options:
 -h, --help         Print a help statement.
 -v, --version      Print the current version.
 -c                 Evaluate and print the following RPN Statement.
)"

/* TODO: Define and verify in CMakeList.txt. */
const std::string VERSION_PRINT = R"(
ccal Version %PROJECT_VERSION%
By Nikolaus J. Reichert <nikolaus@njreichert.ca>
)"

/* Change this to redefine the standard datatype used. */
typedef double OpType;

/* Functions that act on only one operand on the stack (negation, sqrt, etc... */
typedef OpType (*OneFunc)(OpType);

/* Likewise, functions that take two operands (+ - * /)... */
typedef OpType (*TwoFunc)(OpType, OpType);

/* And operations on the stack itself. */
typedef void (*StackOp)(std::vector<OpType> &);

#endif

