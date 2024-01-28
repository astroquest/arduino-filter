#include <LinearKalman.h>

LinearKalman::LinearKalman(double cycle_time, double q, double r, double a, double b) {
    this->cycle_time = cycle_time;
    this->q = q;
    this->r = r;

    coeffs[0] = a;
    coeffs[1] = b;

    init()
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