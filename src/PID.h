#ifndef PID_H
#define PID_H

class PID {
  /*
   * Reference value
   */

  double reference;
  /*
  * Errors
  */
  double error;
  double error_old;
  double error_sum;
  double error_total;
  /*
  * Coefficients
  */ 
  double Kp;
  double Ki;
  double Kd;

  /*
   * Controlls
   */

  double proportional;
  double derivative;
  double integral;
  /*
   * Saturation limits
   */
  bool   hasSaturation;
  double saturation_min;
  double saturation_max;

  /*
   * Last timestamp
   */

  long long int oldTimestamp;
public:
  double getProportional() const;

private:
  long long int newTimestamp;
public:
  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd);

  /*
   *
   */
  void setReference(double reference);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte, long long int timestamp);


  /*
   * Calculates controll output
   */
  double CalculateControl();

  /*
  * Define the saturation values
  */
  void SetSaturation(double min, double max);

  /*
   * remove saturation
   */
  void ClearSaturation();

  /*
  * Calculate the total PID error.
  */
  double TotalError();

  double getDerivative() const;

  double getIntegral() const;
};

#endif /* PID_H */
