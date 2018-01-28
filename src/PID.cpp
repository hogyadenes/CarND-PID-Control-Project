#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {
  Kp_ = 0;
  Ki_ = 0;
  Kd_ = 0;
  prev_cte = 0;
  sum_cte = 0;
}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  Kp_ = Kp;
  Ki_ = Ki;
  Kd_ = Kd;
}

void PID::UpdateError(double cte) {
  double d_cte = cte - prev_cte;
  prev_cte = cte;
  sum_cte+= cte;

  p_error = Kp_ * cte;
  d_error = Kd_ * d_cte;
  i_error = Ki_ * sum_cte;
}

double PID::TotalError() {
  return p_error + d_error + i_error;
}

