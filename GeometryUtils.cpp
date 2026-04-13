#include "GeometryUtils.h"
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;
//Calcs for area
double calculateArea(double side) {
    if (side <= 0) {
        throw std::invalid_argument("Side cannot be zero or negative: " + std::to_string(side));
    }
    return side * side;
}

double calculateArea(double length, double width) {
    if (length <= 0 || width <= 0) {
        throw std::invalid_argument("Dimensions cannot be zero or negative: " + std::to_string(length) + ", " + std::to_string(width));
    }
    return length * width;
}

double calculateCircleArea(double radius) {
    if (radius <= 0) {
        throw std::invalid_argument("Radius cannot be zero or negative: " + std::to_string(radius));
    }
    const double PI = 3.1415926535;
    return PI * radius * radius;
}