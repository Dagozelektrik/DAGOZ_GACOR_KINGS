
#include "PIDController.h"


PIDController::PIDController()
{
    //INI MUNGKIN GUNA
    prev_err_[0] = 0.;
    prev_err_[1] = 0.;
    prev_out_[0] = 0.;
    prev_out_[1] = 0.;
    double prev_ril_err[3] = {0.,0.,0.};
}

//FC= filter coeff, cp tuh 
void PIDController::init(int mode, float kp, float ti, float td, float ff, float fc, float cp, bool is_active)
{
    //INI GANTI JADI KP KI KD
    Kp = kp;
    Kd = td;
    Ki = ti;
    errorIntegral =0; 
    errorDerivative  = 0;
    err = 0;
    samplingTime = 5;//isi sama sampling time, seberapa lama compute actio dipanggil 
    prev_ril_err[0] = 0.;
    prev_ril_err[1] = 0.;
    prev_ril_err[2] = 0.;    
    //CARI TAU DEFINE MODE DIMANA, APAKAH DIKIRIM DARI COMPUTER, MODE 1 PI, MODE 2 PID 
    //BUAT BEBERAPA MODE PI, PID, INI KAYANYA BUAT NGITUNGIN KP KI KD LANGSUNG DECLARE AJA 
    
    v1Filt = 0;
    v1Prev = 0;
    R = 100;
    Q = 1;
    Pt_prev = 1;

    //INI PI 
    if (mode == 1) {
        Kp = Kp;
        Ki = Ki; 
  
        is_active_ = is_active;
    }


    // INI MAU PID 
    if(mode==2){
        
        Kp = Kp;
        Ki = Ki;
        Kd = Kd;
        is_active_ = is_active; 
    }

        prev_err_[0] = 0.;
        prev_err_[1] = 0.;
        prev_out_[0] = 0.;
        prev_out_[1] = 0.;
        is_active_ = is_active;
    }



//UNTUK CLAMPING, GA DIUBAH
double PIDController::clamp(double val, double min, double max)
{
    if (val >= max)
    {
        return max;
    }
    else if (val <= min)
    {
        return min;
    }
    else
    {
        return val;
    }
}


double PIDController::compute_action(double target, double feedback, float ff)
{
    //feedback = filter_Kalman(feedback);
    double ril_err = target - feedback; //ITUNG ERROR

    //MOVING AVERAGE 
    //err = (prev_ril_err[1] + prev_ril_err[0] + ril_err) / 3;

    //KALMAN FILTER 
    err = ril_err;
    targett = target;

    double out = 0.; 
    
    errorIntegral = errorIntegral + err;
    errorDerivative = (prev_err_[0] - err)/samplingTime;
    
    errorDerivative = clamp(errorDerivative, -5,5);
    

    //NGITUNG KELUARAN, TAPI PAKE DISKRIT
    if(is_active_)
    {
        out = errorIntegral * Ki + errorDerivative * Kd + err * Kp;

        //BEKAS DISKRIT 
        //out = c1_ * prev_out_[0] + c2_ * prev_out_[1] + d0_ * err + d1_ * prev_err_[0] + d2_ * prev_err_[1];
        
        //NGIRIM OUTPUT 
        out = clamp(out, -1., 1.);
    }

    //ITUNG PREVIOUS ERROR 
    prev_ril_err[1] = prev_ril_err[0];
    prev_ril_err[0] = ril_err;
    
    prev_err_[1] = prev_err_[0];
    prev_err_[0] = err;
    prev_out_[1] = prev_out_[0];
    prev_out_[0] = out;

    //INI KELUARAN RETURNNYA, HARUSNYA NGGA DIUBAH 
    if(is_active_) {
        if (target == 0) {
            return 0.0;
        }
        else return clamp(out + ff * target, -1., 1.); //FF TUH FEEDFORWARD, -1 SAMA 1 TUH CLAMPING MIN MAX
        }
    else { 
        return 0.0;
    }
}


// INI BIARIN AJA 
void PIDController::setActive(bool command_active) {
    is_active_ = command_active;
}

double PIDController::filter_Kalman(double v1){

    //WITH LOWPASS FILTER 
    // v1Filt = 0.854*v1Filt + 0.0728*(v1) + 0.0728*v1Prev;
    // v1Prev = v1;
    
    //WITHOUT LOWPASS FILTER 
    v1Filt = v1;

    // kalman
    Xt_update = Xt_prev;
    Pt_update = Pt_prev + Q;
    Kt = Pt_update / (Pt_update + R);
    Xt = Xt_update + (Kt * (v1Filt - Xt_update));
    Pt = (1 - Kt) * Pt_update;
    Xt_prev = Xt;
    Pt_prev = Pt;
    kalmanFilterData = Xt;
    v1 = Xt;

    return v1;
 }



