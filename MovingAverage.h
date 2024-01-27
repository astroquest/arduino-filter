#ifndef MOVINGAVERAGE_H
#define MOVINGAVERAGE_H

#include <Filter.h>

/*
    Moving average filter
*/

class MovingAverage : public Filter {
    public:
        MovingAverage(double, double);
        MovingAverage(double);

        void init() override;
        double update(double) override;

    private:
        double coeffs[2];

        double samples;
};

#endif