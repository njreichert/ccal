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
 */

#include <stdexcept>

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

