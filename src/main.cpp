/**
 * main.cpp
 *
 * By Nikolaus J. Reichert <nikolaus@njreichert.ca>
 *
 * TODO: Add description
 */

#include <iostream>
#include <unordered_map>

#include "ops.h"

int main(void)
{
    std::cout << "1 + 2 == " << two_arg_ops.at("+")(1, 2) << std::endl;
    return 0;
}

