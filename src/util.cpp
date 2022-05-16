/**
 * util.cpp
 *
 * By Nikolaus J. Reichert <nikolaus@njreichert.ca>
 *
 * Various utilities.
 */

/*
 * Already included in util.h:
 *
 * <string>
 * <vector>
 *
 * "defs.h"
 */

#include <stdexcept>
#include <cctype>
#include <algorithm>
#include <vector>

#include "util.h"

bool is_numeric(std::string str)
{
    bool numeric = true;

    /* TODO: This is horrible! */
    try {
        std::stod(str); /* Parse string as float. */
    } catch (const std::invalid_argument &e) {
        numeric = false;
    }

    return numeric;
}

bool is_int(OpType op)
{
    /* TODO: Find a better way to do this. */
    return (long) op == op;
}

OpType pop_or_zero(std::vector<OpType> &stack)
{
    OpType retval = OpType();

    if (stack.size() > 0) {
        retval = stack.back();
        stack.pop_back();
    }

    return retval;
}

void strip_string(std::string &str)
{
    while (str.size() > 0 && std::isspace(str.front())) {
        str.erase(0, 1);
    }

    while (str.size() > 0 && std::isspace(str.back())) {
        str.erase(str.size() - 1, str.size());
    }
}

std::vector<std::string> string_to_vec(std::string str)
{
    std::string::size_type curr = 0;
    std::string::size_type prev = 0;

    std::string current_word;

    std::vector<std::string> vec;

    while (curr != std::string::npos) {
        curr = str.find(" ", prev);

        if (curr == std::string::npos) {
            current_word = str.substr(prev, str.size() - prev);
        } else {
            current_word = str.substr(prev, curr - prev);
        }
        
        strip_string(current_word);

        if (current_word != "") {
            vec.push_back(current_word);
        }

        prev = curr + 1;
    }

    return vec;
}
