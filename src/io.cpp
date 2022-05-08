/**
 * io.cpp
 *
 * By Nikolaus J. Reichert <nikolaus@njreichert.ca>
 *
 * I/O related functions.
 */

/*
 * Already included in io.h:
 *
 * <string>
 * <vector>
 *
 * "defs.h"
 */
#include "io.h"
#include "util.h"

bool parse_input(std::string line, std::vector<OpType> &stack)
{
    std::string current_token;
    std::string::size_type delimiter_pos; /* TODO: Replace with iterators. */
    bool has_token = true;
    
    while (has_token) {
        delimiter_pos = line.find(" ");

        /* i.e.: No spaces found in remaining string. */
        if (delimiter_pos == std::string::npos) {
            delimiter_pos = line.size();
            has_token = false; /* Will not have any more after this. */
        }
        
        current_token = line.substr(0, delimiter_pos);

        /* Erase current token, AND delimeter. */
        /* TODO: Check. This should not go out of bounds if we are at the end of the string. */
        line.erase(0, delimiter_pos + 1); 

        if (is_numeric(current_token)) {
            stack.push_back(std::stod(current_token));
        } else {
            /* TODO: Apply commands. */
        }

            
    }
    /* If we have gotten here, we haven't seen quit yet. */
    return true;
}

