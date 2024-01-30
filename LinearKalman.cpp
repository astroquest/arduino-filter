#include <LinearKalman.h>

LinearKalman::LinearKalman(double cycle_time, double process_noise_cov, double measurement_noise_cov, double a, double b)
    : q(process_noise_cov), r(measurement_noise_cov)
{
    this->cycle_time = cycle_time;

    init(a, b);
}

void LinearKalman::init(){}

void LinearKalman::init(double a, double b) {
    coeffs[0] = a;
    coeffs[1] = b;
}

double LinearKalman::predict(double action) {
    double out_pred = coeffs[0] * prev_out + coeffs[1] * action;
    p += cycle_time * q;

    return out_pred;
}

double LinearKalman::predict() {
    double out_pred = coeffs[0] * prev_out;
    p += cycle_time * q;

    return out_pred;
}

double LinearKalman::correct(double process, double out_pred) {
    double k = p / (p + r);
    double out_corr = out_pred + k * (process - out_pred);
    p = (1 - k) * p;

    return out_corr;
}

double LinearKalman::update(double process, double action) {
    double out_pred = predict(action);
    double out_corr = correct(process, out_pred);

    prev_out = out_corr;

    return out_corr;
}

double LinearKalman::update(double process) {
    double out_pred = predict();
    double out_corr = correct(process, out_pred);

    prev_out = out_corr;

    return out_corr;
}