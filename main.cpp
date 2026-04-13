/**
 * @file main.cpp
 * @brief Main client program for the ShapeFile Parser.
 *
 * This program reads shape data from a file, validates it, and calculates
 * areas. It handles all file and data exceptions.
 *
 * @author [Your Name Here]
 * @date [Current Date]
 * @version 1.0
 */
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <stdexcept>

#include "GeometryUtils.h"
#include "Exceptions.h"
#include "FileUtils.h"

using namespace std;
//,ain for output/ filenames.
int main() {
    cout << fixed << setprecision(2);

    string filename;
    ifstream file;
    int lineNumber = 0;

    cout << "Enter filename: ";
    cin >> filename;

    try {
        openFileForReading(file, filename);
    }
    catch (const FileOpenException& e) {
        cerr << e.what() << endl;
        string altFilename;
        cout << "Enter alternative filename: ";
        cin >> altFilename;
        file.open(altFilename);
        if (!file.is_open()) {
            cerr << "Error: Failed to open alternative file. Exiting." << endl;
            return 1;
        }
    }

    cout << "--- Processing Shapes ---" << endl;
    string shapeType;

    while (file >> shapeType) {
        lineNumber++;
        try {
            if (shapeType == "square") {
                double side;
                file >> side;
                double area = calculateArea(side);
                cout << "Line " << lineNumber << ": Square Area: " << area << endl;
            }
            else if (shapeType == "rectangle") {
                double length, width;
                file >> length >> width;
                double area = calculateArea(length, width);
                cout << "Line " << lineNumber << ": Rectangle Area: " << area << endl;
            }
            else if (shapeType == "circle") {
                double radius;
                file >> radius;
                double area = calculateCircleArea(radius);
                cout << "Line " << lineNumber << ": Circle Area: " << area << endl;
            }
            else {
                // Clear any remaining values on this line for unknown shapes to avoid drift
                string remainder;
                getline(file, remainder);
                throw ParseException("Unknown shape type: " + shapeType);
            }
        }
        catch (const ParseException& e) {
            cerr << "Line " << lineNumber << ": Parse Error: " << e.what() << endl;
        }
        catch (const std::invalid_argument& e) {
            cerr << "Line " << lineNumber << ": Invalid Data: " << e.what() << endl;
        }
        catch (const std::exception& e) {
            cerr << "Line " << lineNumber << ": Unexpected Error: " << e.what() << endl;
        }
    }

    cout << "--- Processing Complete ---" << endl;
    file.close();

    return 0;
}