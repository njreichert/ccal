/**
 * command_line.cpp
 *
 * By Nikolaus J. Reichert <nikolaus@njreichert.ca>
 *
 * Defninitions for command-line parsing routines.
 */

#pragma once

#include <string>
#include <vector>

/**
 * @struct CommandOpts
 * @brief Options to pass back to the main program.
 *
 * @var CommandOpts::exit Whether the program should immediately exit.
 *     (We don't want to do anything if we call -h or -v.)
 *
 * @var CommandOpts::is_one_shot Whether the program should evaluate argv directly.
 *     In this case, ccal will print out the top of the stack after evaluation and exit.
 *
 * @var CommandOpts::no_escape Whether to disable TUI mode / escape sequences.
 */
typedef struct COMMAND_OPTS {
    bool exit;
    bool is_one_shot;
    bool no_escape;
} CommandOpts;

/**
 * @brief Determine whether any valid arguments are passed to argv.
 *
 * @param argv A reference to a vector of all arguments after the program name.
 *
 * @returns a struct which can be used to determine initial program state.
 */
CommandOpts parse_cmd_line_args(const std::vector<std::string> &argv);

/**
 * @brief Concatenates all command-line arguments after the program name into a string.
 *
 * @param argc The number of arguments.
 * @param argv All arguments passed by the operating system to main().
 *
 * @returns A string containing all arguments after the program name, space-delimited.
 */
std::string argv_to_string(int argc, char **argv);

