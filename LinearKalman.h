#ifndef LINEARKALMAN_H
#define LINEARKALMAN_H

#include <Filter.h>

/*
    Linear 1D Kalman filter, which assumes the process model x_k = a x_k-1 + b u_k-1
    By default the process model is x_k = x_k-1
*/

constexpr double state_cov_default = 10;
constexpr double process_noise_cov_default = 0;
constexpr double measurement_noise_cov_default = 0;

class LinearKalman : public Filter {
    public:
        LinearKalman(double, double = process_noise_cov_default, double = measurement_noise_cov_default, double = 1, double = 0);

        double update(double, double);
        double update(double) override;

    private:
        void init() override;
        void init(double, double);
        double predict(double);
        double predict();
        double correct(double, double);

        double p = state_cov_default;
        double q;
        double r;

        double coeffs[2];  // vector not really supported for arduino
};

#endif