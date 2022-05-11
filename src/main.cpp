/**
 * main.cpp
 *
 * By Nikolaus J. Reichert <nikolaus@njreichert.ca>
 *
 * TODO: Add description
 */

#include <iostream>
#include <ostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "io.h"
#include "ops.h"
#include "defs.h"
#include "command_line.h"
#include "util.h"

using std::vector;
using std::string;

int main(int argc, char *argv[])
{
    std::string str_argv = argv_to_string(argc, argv); 
    CommandOpts options = parse_cmd_line_args(str_argv);
    
    string current_line;
    bool running = true;

    /*
     * Main idea: We always at least want to read from items 0-3 so we can print them.
     */
    vector<OpType> stack;
    
    if (!options.exit) {
        if (options.is_one_shot) {
            try {
                parse_input(options.one_shot_statement, stack);
                std::cout << pop_or_zero(stack) << std::endl;
            } catch (const std::exception &e) { /* TODO: See below. */
                std::cout << "Error: invalid statement." << std::endl; /* TODO: For sure? */
            }
        } else {
            while(running) {
                print_state(stack);
                std::getline(std::cin, current_line);

                if (current_line[current_line.size() - 1] == '\n') {
                    current_line.erase(current_line.size() - 1);
                }

                try {
                    running = parse_input(current_line, stack);
                } catch (const std::exception &e) { /* TODO: Choose a different exception class. */
                    std::cout << "Some error has occurred." << std::endl;
                }
            }
        }

    }

    return 0;
}

