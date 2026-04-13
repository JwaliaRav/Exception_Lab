//
// Created by Christopher Vaughn on 10/29/25.
//
/**
 * @file FileUtils.cpp
 * @brief Implements utility functions for handling file operations.
 *
 * @author [Your Name Here]
 * @date [Current Date]
 * @version 1.0
 */

#include "FileUtils.h"
#include "Exceptions.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
//Void function for file reading/opening.
void openFileForReading(std::ifstream& file, std::string initialFilename) {
    file.open(initialFilename);

    if (!file.is_open()) {
        throw FileOpenException("Error: File could not be opened: " + initialFilename);
    }

    cout << "File opened successfully: " << initialFilename << endl;
}