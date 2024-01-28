#ifndef LINEARKALMAN_H
#define LINEARKALMAN_H

/*
    Linear 1D Kalman filter, which assumes the process model x_k = a x_k-1 + b u_k-1
    By default the process model is x_k = x_k-1
*/

class LinearKalman : public Filter {
    public:
        LinearKalman(double, double, double, double = 1, double = 0);

        double update(double, double);
        double update(double) override;

    private:
        void init() override;
        double predict(double);
        double predict();
        double correct(double, double);

        double p = 10;
        double q = 0;
        double r = 0;

        double cycle_time;

        double coeffs[2];
};

#endif