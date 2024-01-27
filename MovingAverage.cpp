#include <MovingAverage.h>

MovingAverage::MovingAverage(double cycle_time, double tau) {
    this->cycle_time = cycle_time;
    this->tau = tau;
    this->samples = tau / cycle_time;

    init();
}

MovingAverage::MovingAverage(double samples) {
    this->samples = samples;

    init();
}

void MovingAverage::init() {
    coeffs[1] = 1/samples;
    coeffs[0] = 1 - coeffs[1];
}

double MovingAverage::update(double in) {
    double out = coeffs[0] * prev_out + coeffs[1] * in;

    prev_out = out;

    return out;
}