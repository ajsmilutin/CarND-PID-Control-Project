#include <algorithm>
#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {
  hasSaturation = false;
  reference = 0;
  error = 0;
  error_sum = 0;
  error_total = 0;
  newTimestamp = 0;
}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  PID::Kp = Kp;
  PID::Kd = Kd;
  PID::Ki = Ki;
}

void PID::UpdateError(double cte, long long int timestamp) {

  oldTimestamp = newTimestamp;
  newTimestamp = timestamp;

  error_old = error;
  error = reference - cte;
  error_sum +=error;
  error_total += error*error;

}

double PID::TotalError() {
}

void PID::SetSaturation(double min, double max) {
  saturation_max = max;
  saturation_min = min;
  hasSaturation = true;
}

void PID::ClearSaturation() {
  hasSaturation = false;
}

void PID::setReference(double reference) {
  PID::reference = reference;
}

double PID::CalculateControl() {
  double deltaT = (newTimestamp - oldTimestamp)*1e-3;

  proportional = Kp*error;


  // if it has more than one sample

  if (oldTimestamp)
  {
    derivative = Kd * (error-error_old)/deltaT;
    integral = Ki*error_sum*deltaT;
  }
  else{
    derivative = 0;
    integral = 0;
  }

  double control = proportional + derivative + integral;
  if (hasSaturation){
    control = min(control, saturation_max);
    control = max(control, saturation_min);
  }
  return control;
}

double PID::getProportional() const {
  return proportional;
}

double PID::getDerivative() const {
  return derivative;
}

double PID::getIntegral() const {
  return integral;
}

