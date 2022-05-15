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

#include "defs.h"
#include "command_line.h"

/* 
 * TODO: make argv a container of strings, and change parse_input
 * to work on the same type.
 */
CommandOpts parse_cmd_line_args(const std::string &argv)
{
    CommandOpts opts{false, false, ""};
    int i;

    std::string::size_type pre = 0;
    std::string::size_type curr = 0;

    std::string current_arg = "";
        
    if (argv.size() > 0) {
        while (curr != std::string::npos && opts.exit == false && opts.is_one_shot == false) {
            curr = argv.find(" ", pre);

            if (curr != std::string::npos) {
                current_arg = argv.substr(pre, curr);
            } else {
                current_arg = argv.substr(pre, argv.size());
            }

            if (current_arg == "-h" || current_arg == "--help") {
                std::cout << VERSION_PRINT << "\n" << std::endl;
                std::cout << HELP_PRINT << std::endl;
                opts.exit = true;
            } else if (current_arg == "-v" || current_arg == "--version") {
                std::cout << VERSION_PRINT << std::endl;
                opts.exit = true;
            } else {
                /* 
                 * Assuming for the time being that we are not parsing any arguments
                 * when we want to do a one-shot calculation.
                 */
                opts.is_one_shot = true;
                opts.one_shot_statement = argv.substr(pre, argv.size());
            }
            
            pre = curr + 1;
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