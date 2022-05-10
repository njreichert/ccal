/**
 * command_line.cpp
 *
 * By Nikolaus J. Reichert <nikolaus@njreichert.ca>
 *
 * Parsing routines for command line options.
 */

#include <unordered_map>
#include <string>

#include "defs.h"
#include "command_line.h"

CommandOpts parse_argv(int argc, char **argv)
{
    CommandOpts opts = {.exit = false, .is_one_shot = false, .one_shot_start = 0};
    int i;
    while (i < argc && opts.exit == false) { /* Skip command name. */
        std::string current_arg = argv[i];

        if (current_arg == "-h" || current_arg == "--help") {
            std::cout << VERSION_PRINT << std::endl;
            std::cout << HELP_PRINT << std::endl;
            opts.exit = true;
        } else if (current_arg == "-v" || current_arg == "--version") {
            std::cout << VERSION_PRINT << std::endl();
            opts.exit = true;
        } else if (current_arg == "-c") {
            opts.is_one_shot = true;
            opts.one_shot_start = argc + 1;
        }
    }

    return opts;
}
