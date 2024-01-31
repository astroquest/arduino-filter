**To Do**
- Better packaging/file structure.
- Include high-pass filter.
- Include complementary filter (low, high).
- Expand Kalman filter functionality to EKF, UKF, easily support different dynamic models.
- Keywords for Arduino IDE.
- Include tests.

**Current State**
- Working 1st and 2nd order low-pass filter, and 1D linear Kalman filter.
- User can instantiate the classes using cycle time and filter coefficients (time constant, damping ratio, model parameters).
- Data can be processed iteratively using the `update()` function.
