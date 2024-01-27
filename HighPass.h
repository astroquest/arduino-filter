#ifndef HIGHPASS_H
#define HIGHPASS_H

#include <Filter.h>

/*
    1st order high-pass filter with 1st order low-pass filter cutoff
*/

class HighPass : public Filter {
    public:
        HighPass(double, double);

        void init() override;
        double update(double) override;

    private:
        double coeffs[2];

        double prev_out = 0;
};

#endif