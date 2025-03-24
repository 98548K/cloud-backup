#include "vex.h"

double clawKp = 0.7;//0.7
double clawKi = 0.0;//0.0
double clawKd = 0.0;//0.0

double kP = 0.0;//3.9
double kI = 0.0;//3.5
double kD = 0.0;//0.4

double turnKP = 0.72459954;//0.7256969
double turnKI = 0.0;//0.0005
double turnKD = 0.0;//5.5765578
double wheelRad = 1.0;//1.0

double turnTolerance = 0.0;//0.0
double driveTolerance = 0.0;//0.0
double clawTolerance = 1.0;//0.0

double driveIntegralLimit = 20.0;//20.0
double turnIntegralLimit = 30.0;//30.0


//Function for determining the turn direction. Credit to Caleb Carlson for making this function easy to find (https://www.vexforum.com/t/turning-with-pid-how-to-find-the-shortest-turn/110258/6)
double constrainAngle(double x) {
    x = fmod(x + 180, 360);
    if (x < 0)
        x += 360;
    return x - 180;
}

//PID class initialization
class PID {
    //Declaring all instances in the class. (eg. PID math variables)
    private:
        //Declaring multiplication constants
        double p, i, d;
        //Declaring sensor math variables
        double desiredValue;
        double error;
        double integral = 0;
        double derivative;
        double pwr;
        double prevError;
        //Declaring what instance of motor control it is
        bool isTurning;
        bool isDriving;
        bool isClaw;

    //PID class parameter setup
    public:
        PID(double P, double I, double D, double DesiredValue, bool IsDriving, bool IsTurning, bool IsClaw) {
            p = P;
            i = I;
            d = D;

            desiredValue = DesiredValue;
            error = DesiredValue;
            isTurning = IsTurning;
            isDriving = IsDriving;
            isClaw = IsClaw;
        }

        void run() {
            integral = 0;
            error = 0;
            while (true) {
                

                //PID math
                integral += error;
                //

                //Stops using integral in the power once the condition is met
                if (error <= turnTolerance && error >= turnTolerance  && isTurning) {
                    integral = 0;
                }
                if (std::abs(error) < turnIntegralLimit && isTurning) {
                    integral = 0;
                } else if (std::abs(error) < driveIntegralLimit && !isTurning) {
                    integral = 0;
                }

                //More PID math
                derivative = error - prevError;
                prevError = error;
                pwr = error * p + integral * i + derivative * d;
                //

                
                //Class initialization for turning
                if (isTurning) {
                    error = constrainAngle(desiredValue - Inertial1.heading(deg));
                    LeftDriveSmart.spin(fwd, pwr, pct);
                    RightDriveSmart.spin(reverse, pwr, pct);
                    if (Inertial1.heading(deg) > desiredValue - turnTolerance && Inertial1.heading(deg) < desiredValue + turnTolerance) break;
                }

                //Class initialization for driving
                else if (isDriving) {
                    error = desiredValue - frontTracking.position(turns) * (wheelRad * 2) * M_PI;
                    LeftDriveSmart.spin(fwd, pwr, pct);
                    RightDriveSmart.spin(fwd, pwr, pct);
                    if (error == 0) break;
                    if (error >= -driveTolerance && error <= driveTolerance) break;
                }


                //Class initialization for claw
                else if (isClaw) {
                    error = desiredValue - clawTracking.position(deg);
                    Claw.spin(fwd, pwr, pct);
                    if (error == 0) break;
                    if (error >= -clawTolerance && error <= clawTolerance) break;
                }

                //Terminates if within tolerance
                if ((error == turnTolerance && isTurning) || (error == driveTolerance && isDriving)) break;
                if (error == 0) break;
                wait (15, msec);
            }
            LeftDriveSmart.stop(hold);
            RightDriveSmart.stop(hold);
            Claw.stop(hold);
        }
};

//Drive PID function
void driveIn(double driveDist) {
    frontTracking.setPosition(0, turns);
    PID drivePID(kP, kI, kD, driveDist, true, false, false);
    drivePID.run();
}

//Turn PID function
void turnToHeading(double turnHeading) {
    PID turnPID(turnKP, turnKI, turnKD, turnHeading, false, true, false);
    turnPID.run();
}

//Claw PID function
void ClawRotate(double rotationValue) {
    PID clawPID(clawKp, clawKi, clawKp, rotationValue, false, false, true);
    clawPID.run();
}