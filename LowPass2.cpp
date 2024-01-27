#include "Arduino.h"
#include <LowPass2.h>

LowPass2::LowPass2(double cycle_time, double tau, double zeta) {
    this->cycle_time = cycle_time;
    this->tau = tau;
    this->zeta = zeta;

    init();
}

void LowPass2::init() {
        double s1 = tau / cycle_time;
        double s2 = 4 * zeta * s1;
        double s3 = 4 * pow(s1, 2);

        coeffs[2] = 1 / (s3 + s2 + 1);
        coeffs[0] = - coeffs[2] * (-2 * s3 + 2);
        coeffs[1] = - coeffs[2] * (s3 - s2 + 1);
}

double LowPass2::update(double in) {
    double out = coeffs[0] * prev_out
                + coeffs[1] * past_out
                + coeffs[2] * (in + prev_in + past_in);

    past_out = prev_out;
    prev_out = out;
    past_in = prev_in;
    prev_in = in;

    return out;
}