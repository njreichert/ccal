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
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
#include <regex>

#include "util.h"

/*
 * Match:
 * - zero or one +/- signs,
 * - At least one number,
 * - a dot, followed by at least one number (optional).
 */
static const std::regex decimal_num("[+-]{0,1}[0-9]+(\\.[0-9]+|)", std::regex::ECMAScript);

bool is_numeric(std::string str)
{
    /* TODO: Write tests for this. */
    return std::regex_match(str, decimal_num);
}

bool is_int(double op)
{
    return std::trunc(op) == op;
}

double pop_or_zero(std::vector<double> &stack)
{
    double retval = double();

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
