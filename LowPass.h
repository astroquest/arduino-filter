#ifndef LOWPASS_H
#define LOWPASS_H

#include <Filter.h>

/*
    1st order low-pass filter
*/

class LowPass : public Filter {
    public:
        LowPass(double, double);

        void init() override;
        double update(double) override;

    private:
        double coeffs[2];
};

#endif