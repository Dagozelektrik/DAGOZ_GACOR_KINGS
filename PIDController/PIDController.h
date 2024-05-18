
#ifndef PIDCONTROLLER_H
#define PIDCONTROLLER_H
#include <iostream>
#include <string>

class PIDController
{
public:
    PIDController();
    void init(int mode, float kp, float ti, float td, float ff, float fc, float cp, bool is_active);
    double clamp(double val, double min, double max);
    double compute_action(double target, double feedback, float ff);
    void setActive(bool command_active);
    double filter_Kalman(double v1);
    float errorIntegral, errorDerivative;
    double err,targett;


private:
    /// ci = -ai/a0, di = bi/a0 in discrete-time PID
    double Kp,Ki,Kd;
    double prev_err_[2], prev_out_[2];
    double prev_ril_err[3];
    unsigned long samplingTime;
    bool is_active_;

    //Kalman Filter
    float v1Filt, v1Prev;
    float kalmanFilterData;
    float Xt, Xt_update, Xt_prev, Pt, Pt_update, Pt_prev, Kt, R, Q;

};

#endif
