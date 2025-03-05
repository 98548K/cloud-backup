#include "vex.h"

double clawKp = 0.7;//0.7
double clawKi = 0.0;//0.0
double clawKd = 0.0;//0.0
double kP = 3.9;//3.9
double kI = 3.5;//3.5
double kD = 0.4;//0.4
double turnKP = 0.5;//0.5
double turnKI = 0.0;//0.0
double turnKD = 1.0;//1.0
double wheelRad = 1;
double turnTolerance = 0.6;
double driveTolerance = 0.5;
double clawTolerance = 0.5;

class PID {
    private:
        double p, i, d;
        double desiredValue;
        double error;
        double integral = 0;
        double derivative;
        double pwr;
        double prevError;
        bool isTurning;
        bool isClaw;

    public:
        PID(double P, double I, double D, double DesiredValue, bool IsTurning, bool IsClaw) {
            p = P;
            i = I;
            d = D;

            desiredValue = DesiredValue;
            error = DesiredValue;
            isTurning = IsTurning;
            isClaw = IsClaw;
        }

        void run(double option) {
            integral = 0;
            error = 0;
            while (true) {
                

                error = desiredValue - option;
                integral += error;


                if (option < 90 && desiredValue > 270 && isTurning) {
                    error = (desiredValue - 180) - (option + 180);
                }
                
                
                else if ((option > 270 && desiredValue < 90) && isTurning) {
                    error = (desiredValue + 180) - (option - 180);
                }

                if (error > 180 && isTurning) {
                    error = -(360 - error);
                }
                else if (error < -180 && isTurning) {
                    error = 360 + error;
                }
            

                if (error <= turnTolerance && error >= turnTolerance  && isTurning) {
                    integral = 0;
                }
                //Doesn't start using integral in the power until the condition is met
                if (abs(error) < 30 && isTurning) {
                    integral = 0;
                } else if (abs(error) < 20 && !isTurning) {
                    integral = 0;
                }



                derivative = error - prevError;
                prevError = error;
                pwr = error * p + integral * i + derivative * d;

                
                if (isTurning && !isClaw) {
                    option = Inertial1.heading(deg);
                    LeftDriveSmart.spin(fwd, pwr, pct);
                    RightDriveSmart.spin(reverse, pwr, pct);
                    if (Inertial1.heading(deg) > desiredValue - turnTolerance && Inertial1.heading(deg) < desiredValue + turnTolerance) break;
                }

                else if (!isTurning && !isClaw) {
                    option = frontTracking.position(turns) * (wheelRad * 2) * M_PI;
                    LeftDriveSmart.spin(fwd, pwr, pct);
                    RightDriveSmart.spin(fwd, pwr, pct);
                    if (error == 0) break;
                    if (error >= -clawTolerance && error <= clawTolerance) break;
                }


                else if (isClaw) {
                    option = clawTracking.position(deg);
                    Claw.spin(fwd, pwr, pct);
                    if (error == 0) break;
                    if (error >= -clawTolerance && error <= clawTolerance) break;
                }
                wait (15, msec);
                if (error == turnTolerance || error == driveTolerance) break;
                if (error == 0) break;
            }
            LeftDriveSmart.stop(hold);
            RightDriveSmart.stop(hold);
            Claw.stop(hold);
        }
};


void driveIn(double driveDist) {
    frontTracking.setPosition(0, turns);
    double startDist = frontTracking.position(turns);
    PID drivePID(kP, kI, kD, driveDist, false, false);
    drivePID.run(startDist);
}

void turnToHeading(double turnHeading) {
    double currentHeading = Inertial1.heading(deg);
    PID turnPID(turnKP, turnKI, turnKD, turnHeading, true, false);
    turnPID.run(currentHeading);
}

void ClawRotate(double rotationValue) {
    double currentRotation = clawTracking.position(deg);
    PID clawPID(clawKp, clawKi, clawKp, rotationValue, false, true);
    clawPID.run(currentRotation);
}