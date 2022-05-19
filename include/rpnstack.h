/**
 * rpnstack.h
 *
 * By Nikolaus J. Reichert <nikolaus@njreichert.ca>
 *
 * Definitions for an RPN Stack class.
 */

#include <vector>
#include <string>

#include "ops.h"

/**
 * TODO: Doxygen Comments for classes.
 */
class RPNStack {
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
     * @brief gets the nth item from the top of the stack.
     */
    double get(std::vector<double>::size_type n) const;
}
