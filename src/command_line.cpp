/**
 * command_line.cpp
 *
 * By Nikolaus J. Reichert <nikolaus@njreichert.ca>
 *
 * Parsing routines for command line options.
 */

/*
 * Already included in command_line.h:
 *
 * <string>
 */

#include <iostream>
#include <vector>
#include <algorithm>

#include "defs.h"
#include "util.h"
#include "command_line.h"

CommandOpts parse_cmd_line_args(const std::vector<std::string> &args)
{
    CommandOpts opts{false, false};

    if (args.size() > 0) {
        if (args[0] == "-h" || args[0] == "--help") {
            std::cout << VERSION_PRINT << "\n" << std::endl;
            std::cout << HELP_PRINT << std::endl;
            opts.exit = true;
        } else if (args[0] == "-v" || args[0] == "--version") {
            std::cout << VERSION_PRINT << std::endl;
            opts.exit = true;
        } else if (args[0] == "-n" || args[0] == "--no-ansi") {
            opts.no_escape = true;
        } else if (is_numeric(args[0])) {
            /* 
             * Assuming for the time being that we are not parsing any arguments
             * when we want to do a one-shot calculation.
             */
            opts.is_one_shot = true;
        } else {
            std::cout << "ERROR: Invalid Argument." << std::endl;
            opts.exit = true; /* TODO: Add return code. */
        }
    }
    return opts;
}

std::string argv_to_string(int argc, char **argv)
{
    std::string output = "";
    for (int i = 1; i < argc; i++) {
        output += argv[i];
        
        if (i < argc - 1) {
            output += " ";
        }
    }

    return output;
}
