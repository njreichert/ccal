/**
 * main.cpp
 *
 * By Nikolaus J. Reichert <nikolaus@njreichert.ca>
 *
 * TODO: Add description
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "io.h"
#include "ops.h"

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

