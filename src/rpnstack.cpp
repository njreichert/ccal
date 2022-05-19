/**
 * rpnstack.cpp
 *
 * By Nikolaus J. Reichert <nikolaus@njreichert.ca>
 *
 * Methods and related functions for the RPNStack function.
 */

#include "rpnstack.h"
#include <ctime>
#include <vector>

bool RPNStack::is_error() const
{
    return this->m_is_error;
}

void RPNStack::is_error(bool error)
{
    this->m_is_error = error;
}

bool RPNStack::is_radians() const
{
    return this->m_is_radians;
}

void RPNStack::is_radians(bool radians)
{
    this->m_is_radians = radians;
}

double RPNStack::get(std::vector<double>::size_type n)
{
    double retval = 0;

    if (n < this->size()) {
        retval = this->m_stack.at(n);
    }

    return retval;
}

double pop_or_zero()
{
    double retval = 0;

    if (this->size() > 0) {
        retval = this->get(0);
        this->m_stack.pop_back();
    }

    return retval;
}

std::vector<double>::size_type RPNStack::size() const
{
    return this->m_stack.size();
}

double RPNStack::apply_input(const std::string &s)
{
    try {
        


        this->is_error(false);
    } catch (const std::exception &e) {
        this->is_error(true); /* TODO: Be more descriptive. */
    }

    return this->get(0);
}

