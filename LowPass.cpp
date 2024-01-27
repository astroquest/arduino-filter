#include "Arduino.h"
#include <LowPass.h>

LowPass::LowPass(double cycle_time, double tau) {
    this->cycle_time = cycle_time;
    this->tau = tau;

    init();
}

void LowPass::init() {
    coeffs[0] = exp(-cycle_time / tau);
    coeffs[1] = 1 - coeffs[0];
}

double LowPass::update(double in) {
    double out = coeffs[0] * prev_out + coeffs[1] * in;

    prev_out = out;

    return out;
}