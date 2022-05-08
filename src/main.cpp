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

using std::vector;
using std::string;

int main(void)
{
    bool running = true;
    string current_line;

    /*
     * Main idea: We always at least want to read from items 0-3 so we can print them.
     */
    vector<OpType> stack;
    
    while(running) {
        for (int i = DISPLAY_SIZE; i > stack.size(); i--) {
            std::cout << i << ": " << OpType() << std::endl;
        }

        if (stack.size() < DISPLAY_SIZE) {
            for (std::vector<OpType>::size_type i = 0; i < stack.size(); i++) {
                std::cout << stack.size() - i << stack[i] << std::endl;
            }
        } else {
            for (std::vector<OpType>::size_type i = DISPLAY_SIZE; i > 0; i--) {
                std::cout << i << stack[i - 1] << std::endl;
            }
        }

        std::cout << "> " << std::flush;
        std::getline(std::cin, current_line);

        if (current_line[current_line.size() - 1] == '\n') {
            current_line.erase(current_line.size() - 1);
        }

        try {
            running = parse_input(current_line, stack);
        } catch(const std::exception &e) { /* TODO: Choose a different exception class. */
            std::cout << "Some error has occurred." << std::endl;
        }
    }

    return 0;
}

