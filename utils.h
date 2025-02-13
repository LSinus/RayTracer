//
// Created by Leonardo Sinibaldi on 11/02/25.
//

#ifndef UTILS_H
#define UTILS_H
#include <cmath>
#include <iostream>
#include <limits>
#include <memory>
#include <random>


// ----------- CONSTANTS ------------- //
const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.14159265358979323846;

// ----------- FUNCTIONS ------------- //

inline double deg_to_rad(double deg) {
    return deg * pi / 180.0;
}

inline double random_double() {
    static std::uniform_real_distribution<double> distribution(0.0, 1.0);
    static std::mt19937 generator;
    return distribution(generator);
}

inline double random_double(double min, double max) {
    return min + (max - min) * random_double();
}

#include "color.h"
#include "interval.h"
#include "ray.h"
#include "vec3.h"

#endif //UTILS_H
