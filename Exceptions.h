/**
 * @file Exceptions.h
 * @brief Declares custom exception classes for the shape parser.
 *
 * This file defines the interfaces for custom exceptions,
 * including FileOpenException and ParseException.
 *
 * @author [JWALIA RAVAL]
 * @date [4/13/26]
 */
#pragma once

#include <exception>
#include <string>
//File opening exception class
class FileOpenException : public std::exception {
private:
    std::string msg;

public:
    FileOpenException(const std::string& message) : msg(message) {}
    virtual const char* what() const noexcept override;
};
//Parseing exception class
class ParseException : public std::exception {
private:
    std::string msg;

public:
    ParseException(const std::string& message) : msg(message) {}
    virtual const char* what() const noexcept override;
};