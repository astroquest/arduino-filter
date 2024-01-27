#ifndef LOWPASS2_H
#define LOWPASS2_H

#include <Filter.h>

/*
    2nd order low-pass filter
*/

class LowPass2 : public Filter {
    public:
        LowPass2(double, double, double = default_zeta);

        void init() override;
        double update(double) override;

    private:
        double coeffs[3];

        double past_out = 0;
        double prev_in = 0;
        double past_in = 0;
};

#endif