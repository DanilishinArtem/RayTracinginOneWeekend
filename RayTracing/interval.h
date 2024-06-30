#pragma once
#ifndef INTERVAL_H
#define INTERVAL_H
// #include "rtweekend.h"

#include <limits>
using namespace std;
const double infinity_ = numeric_limits<double>::infinity();

class interval {
public:
    double min;
    double max;

    interval() : min(+infinity_), max(-infinity_) {}

    interval(double min, double max) : min(min), max(max) {}

    double size() const { return max - min; }

    bool contains(double x) const {
        return min <= x && x <= max;
    }

    bool surrounds(double x) const {
        return min < x && x < max;
    }

    double clamp(double x) const {
        if (x < min) return min;
        if (x > max) return max;
        return x;
    }

    static const interval empty, universe;
};

const interval interval::empty = interval(+infinity_, -infinity_);
const interval interval::universe = interval(-infinity_, +infinity_);

#endif