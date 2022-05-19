/**
 * rpnstack.h
 *
 * By Nikolaus J. Reichert <nikolaus@njreichert.ca>
 *
 * Definitions for an RPN Stack class.
 */

#include <unordered_map>
#include <vector>
#include <string>

#include "defs.h"
#include "ops.h"

/**
 * TODO: Doxygen Comments for classes.
 */
class RPNStack {
    friend double sum_and_clear(RPNStack &stack);
    friend double clear(RPNStack &stack);
private:
    /* 
     * TODO: Make this function template oriented!
     *
     * Some things that need to be figured out:
     * 1. How to deal with functions in the standard library that may
     *    or may not support types associated with the template.
     */
    std::vector<double> m_stack;
    
    bool m_is_error;
    bool m_is_radians; /* I only intend to support radians or degrees. */

public:
    /**
     * @brief Attempts to apply the given one-argument function to the stack.
     *
     * @throws TODO: Figure out what to throw here.
     * @param s The token to parse a function against.
     *
     * @returns The value at the top of the stack after the operation completes.
     */
    double apply_input(const std::string &s);

    /**
     * @brief Getter for m_is_error.
     */
    bool is_error() const;
    
    /**
     * @brief Setter for m_is_error.
     */
    void is_error(bool error);

    /**
     * @brief Getter for m_is_radians.
     */
    bool is_radians() const;

    /**
     * @brief Setter for m_is_radians.
     */
    void is_radians(bool radians);

    /**
     * @brief Wrapper for this->m_stack.size().
     */
    std::vector<double>::size_type size() const;

    /**
     * @brief Gets the nth item from the top of the stack.
     */
    double get(std::vector<double>::size_type n) const;

    /**
     * @brief attempts to destructively pop the top of the stack.
     *
     * NB: Returns zero if the stack is empty.
     *
     * @returns The top of the stack, or zero if empty.
     */
    double pop_or_zero();

    /**
     * @brief Pushes to the stack.
     */
    void push(double d);
};

/* Functions that act on only one operand on the stack (negation, sqrt, etc... */
typedef double (*OneFunc)(double);

/* Likewise, functions that take two operands (+ - * /)... */
typedef double (*TwoFunc)(double, double);

/* And operations on the stack itself. */
typedef double (*StackOp)(RPNStack &);



namespace RPNHelpers {
    /**
     * @brief Destructively sums the stack.
     *
     * @param stack: The stack to sum.
     *
     * @returns The sum of the stack returned.
     */
    double sum_and_clear(RPNStack &stack);

    /**
     * @brief Clears the stack.
     *
     * @param stack: The stack to sum.
     *
     * @returns zero.
     */
    double clear(RPNStack &stack);

    const std::unordered_map<std::string, OneFunc> one_arg_ops = {
        {"sqrt", [](double a){ return std::sqrt(a); }},
        {"exp", [](double a){ return std::exp(a); }},
        {"sin", [](double a){ return std::sin(a); }},
        {"cos", [](double a){ return std::cos(a); }},
        {"tan", [](double a){ return std::tan(a); }},
        {"arcsin", [](double a){ return std::asin(a); }},
        {"arccos", [](double a){ return std::acos(a); }},
        {"arctan", [](double a){ return std::atan(a); }},
        {"log", [](double a){ return std::log10(a); }}, /* Yes, log10. log_e == ln. */
        {"ln", [](double a){ return std::log(a); }},
        {"log2", [](double a){ return std::log2(a); }},
        {"abs", [](double a){ return std::abs(a); }},
        {"inv", [](double a){ return (1 / a); }},
        {"!", factorial}
    };

    const std::unordered_map<std::string, TwoFunc> two_arg_ops = {
        {"+", [](double a, double b){ return a + b; }},
        {"-", [](double a, double b){ return a - b; }},
        {"*", [](double a, double b){ return a * b; }},
        {"/", [](double a, double b){ return a / b; }},
        
        /* TODO: Find a way to combine these two, as they're just semantics. */
        {"^", [](double a, double b){ return std::pow(a, b); }},
        {"pow", [](double a, double b){ return std::pow(a, b); }},
        {"nroot", [](double a, double b){ return std::pow(b, (1 / a)); }}
    };

    const std::unordered_map<std::string, StackOp> stack_ops = {
        {"clear", clear},
        {"sum", sum_and_clear}
    };

    const std::unordered_map<std::string, double> constants = {
        {"pi", std::asin(1) * 2},
        {"e", std::exp(1)}
    };
}

