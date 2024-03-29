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
#include <type_traits>
#include <unordered_map>
#include <vector>

#include "io.h"
#include "defs.h"
#include "command_line.h"
#include "util.h"
#include "rpnstack.h"

int main(int argc, char *argv[])
{
    std::vector<std::string> argv_vec = string_to_vec(argv_to_string(argc, argv));
    CommandOpts options = parse_cmd_line_args(argv_vec);
    
    std::string current_line;
    bool running = true;

    RPNStack stack;

    if (!options.exit) {
        if (options.is_one_shot) {
            try {
                parse_input(argv_vec, stack);
                std::cout << stack.pop_or_zero() << std::endl;
            } catch (const std::exception &e) { /* TODO: See below. */
                std::cout << "Error: invalid statement." << std::endl; /* TODO: For sure? */
            }
        } else {
            if (!options.no_escape) {
                setup_screen();
            }

            print_state(stack, options.no_escape);
            while(running) {
                std::getline(std::cin, current_line);
                std::vector<std::string> op_list = string_to_vec(current_line);
                
                running = parse_input(op_list, stack);
                print_state(stack, options.no_escape);
            }
        }
    }
    return 0;
}

