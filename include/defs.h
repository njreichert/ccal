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
#include <vector>

#ifndef VERSION
#define VERSION "ERROR"
#endif

/* Defines */
#define DISPLAY_SIZE 4

/* Constants */
const std::string HELP_PRINT = R"(Usage:
 ccal [options] [statement]

Options:
 -h, --help         Print a help statement.
 -v, --version      Print the current version.

Statements:
 Statements are only executed in the absence of other options.)";

const std::string VERSION_PRINT = R"(ccal Version )" VERSION R"(
By Nikolaus J. Reichert <nikolaus@njreichert.ca>)";

/* Functions that act on only one operand on the stack (negation, sqrt, etc... */
typedef double (*OneFunc)(double);

/* Likewise, functions that take two operands (+ - * /)... */
typedef double (*TwoFunc)(double, double);

/* And operations on the stack itself. */
typedef void (*StackOp)(std::vector<double> &);

#endif

