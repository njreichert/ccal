/**
 * rpnstack.cpp
 *
 * By Nikolaus J. Reichert <nikolaus@njreichert.ca>
 *
 * Methods and related functions for the RPNStack function.
 */

/*
 * Already included in "rpnstack.h":
 *
 * <unordered_map>
 * <vector>
 * <string>
 *
 * "defs.h"
 */

#include <unordered_map>
#include <stdexcept>

#include "rpnstack.h"
#include "util.h"

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

double RPNStack::get(std::vector<double>::size_type n) const
{
    double retval = 0;

    if (n < this->size()) {
        retval = this->m_stack.at(n);
    }

    return retval;
}

double RPNStack::pop_or_zero()
{
    double retval = 0;

    if (this->size() > 0) {
        retval = this->get(0);
        this->m_stack.pop_back();
    }

    return retval;
}

double RPNStack::push(double d)
{
    this->m_stack.push_back(d);
    return this->get(0);
}

std::vector<double>::size_type RPNStack::size() const
{
    return this->m_stack.size();
}

double RPNStack::parse_stack_ops(const std::string &s)
{
    /* 
     * Using a jump table for direct operations on the stack caused a circular
     * dependency, hence why I'm doing it here.
     */

    if (s == "clear") {
        this->clear();
    } else if (s == "sum") {
        this->sum();
    } else {
        throw std::invalid_argument(s);
    }

    return this->get(0);
}

double RPNStack::apply_input(const std::string &s)
{
    try {
        if (is_numeric(s)) {
            this->push(std::stod(s)); /* TODO: Not portable to other types! */
        } else if (RPNHelpers::one_arg_ops.find(s) != RPNHelpers::one_arg_ops.end()) {
            double op_one = this->pop_or_zero();

            this->push(RPNHelpers::one_arg_ops.at(s)(op_one));
        } else if (RPNHelpers::two_arg_ops.find(s) != RPNHelpers::two_arg_ops.end()) {
            double op_two = this->pop_or_zero();
            double op_one = this->pop_or_zero();

            this->push(RPNHelpers::two_arg_ops.at(s)(op_one, op_two));
        } else if (RPNHelpers::constants.find(s) != RPNHelpers::constants.end()) {
            this->push(RPNHelpers::constants.at(s));
        } else {
            this->parse_stack_ops(s);
        }

        this->is_error(false);
    } catch (const std::exception &e) {
        this->is_error(true); /* TODO: Be more descriptive. */
    }

    return this->get(0);
}

double RPNStack::clear()
{
    this->m_stack.clear();
    return 0;
}

double RPNStack::sum()
{
    double sum = 0;

    for (const double &i : this->m_stack) {
        sum += i;
    }

    this->clear();

    return sum;
}
