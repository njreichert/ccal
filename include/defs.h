/**
 * defs.h
 *
 * By Nikolaus J. Reichert <nikolaus@njreichert.ca>
 *
 * Various definitions and macros.
 */

#pragma once

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
 -n, --no-ansi      Disable TUI mode

Statements:
 Statements are only executed in the absence of other options.)";

const std::string VERSION_PRINT = R"(ccal Version )" VERSION R"(
By Nikolaus J. Reichert <nikolaus@njreichert.ca>)";

