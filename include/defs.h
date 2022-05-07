/**
 * defs.h
 *
 * By Nikolaus J. Reichert <nikolaus@njreichert.ca>
 *
 * Various definitions and macros.
 */

#ifndef _DEFS_H
#define _DEFS_H

/* Change this to redefine the standard datatype used. */
typedef double OpType;

/* Functions that act on only one operand on the stack (negation, sqrt, etc... */
typedef OpType (*OneFunc)(OpType);

/* Likewise, functions that take two operands (+ - * /) */
typedef OpType (*TwoFunc)(OpType, OpType);

#endif

