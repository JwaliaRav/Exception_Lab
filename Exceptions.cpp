/**
* @file Exceptions.cpp
 * @brief Implements the custom exception classes.
 *
 * This file provides the definitions for the constructors
 * and 'what()' methods for the custom exception classes.
 *
 * @author [Your Name Here]
 * @date [Current Date]
 */

#include "Exceptions.h"

const char* FileOpenException::what() const noexcept {
    return msg.c_str();
}

const char* ParseException::what() const noexcept {
    return msg.c_str();
}