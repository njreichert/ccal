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

#include <cmath>
#include <unordered_map>

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

void RPNStack::push(double d)
{
    this->m_stack.push_back(d);
}

std::vector<double>::size_type RPNStack::size() const
{
    return this->m_stack.size();
}

double RPNStack::apply_input(const std::string &s)
{
    try {
        if (is_numeric(s)) {
            this->push(std::stod(s)); /* TODO: Not portable to other types! */
        } else if (one_arg_ops.find(s) != one_arg_ops.end()) {
            double op_one = this->pop_or_zero();

            this->push(one_arg_ops.at(s)(op_one));
        } else if (two_arg_ops.find(s) != two_arg_ops.end()) {
            double op_two = this->pop_or_zero();
            double op_one = this->pop_or_zero();

            this->push(two_arg_ops.at(s)(op_one, op_two));
        } else if (constants.find(s) != constants.end()) {
            this->push(constants.at(s));
        } else if (stack_ops.find(s) != stack_ops.end()) {
            stack_ops.at(s)(this);
        }

        this->is_error(false);
    } catch (const std::exception &e) {
        this->is_error(true); /* TODO: Be more descriptive. */
    }

    return this->get(0);
}

double RPNHelpers::clear(RPNStack &stack)
{
    stack.m_stack.clear();
    return 0;
}

double RPNHelpers::sum_and_clear(RPNStack &stack)
{
    double sum = 0;

    for (const double &i : stack.m_stack) {
        sum += i;
    }

    RPNStack::clear(stack);

    return sum;
}

