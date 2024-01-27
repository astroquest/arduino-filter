#ifndef FILTER_H
#define FILTER_H

#include <Arduino.h>

constexpr double default_zeta = 0.5 * pow(2, 0.5);

class Filter {
    protected:
        virtual void init() = 0;
        virtual double update(double) = 0;

        double cycle_time;
        double tau;
        double zeta;

        double prev_out = 0;
};

#endif