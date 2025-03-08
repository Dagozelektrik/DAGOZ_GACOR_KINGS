
#ifndef PIDCONTROLLER_H
#define PIDCONTROLLER_H
#include <iostream>
#include <string>
//belajar git
class PIDController
{
public:
    PIDController();
    void init(int mode, float kp, float ti, float td, float ff, float fc, float cp, bool is_active, int motornum);
    double clamp(double val, double min, double max);
    double compute_action(double target, double feedback, float ff, float samplingTime);
    void setActive(bool command_active);
    double filter_Kalman(double v1);
    int sign(double val);
    double feed_forward_abs(double target);
    double extended_state_observer(double feedback, double input);
    float errorIntegral, errorDerivative;
    double err,targett;
    double out;
    double z1,z2,z3,h_disturb,obs_y;


private:
    /// ci = -ai/a0, di = bi/a0 in discrete-time PID
    double Kp,Ki,Kd;
    double prev_err_[2], prev_out_[2];
    double prev_ril_err[3];
    int motor_num;
    //unsigned long samplingTime;
    bool is_active_;

    float PD, I, PD_IIR;

    //Kalman Filter
    float v1Filt, v1Prev;
    float kalmanFilterData;
    float Xt, Xt_update, Xt_prev, Pt, Pt_update, Pt_prev, Kt, R, Q;

    //Extended State Observer - ESO
    
    double y, b;
    double l1,l2,l3;

    
    //IIR LPF
    //float b[3]; //Numerator Coefficent
    //float a[3]; //Denumeratro Coefficient
    //float x[3]; // Input history
    //float y[3]; // Output history

};

#endif
