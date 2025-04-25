#include "vex.h"


/*
Kasens tuning tips (numerical order of tuning):

1. kP values = make it as high as possible without it becoming unstable. Tune it until it has oscillated or goes back and forth for two rounds.
3. kI values = make it as high as possible without it becoming unstable. If it messes up you have the wrong value. Thats the best advice I can give.
2. kD values = make it as low as possible without it becoming unstable. Have it ramp itself down and try to do it without the abrupt stops and without any hint of oscillation or going back and forth.
*/


double clawKp = 0.7;//0.7
double clawKi = 0.0;//0.0
double clawKd = 0.0;//0.0

double kP = 4.57999999;//4.3
double kI = 1.0;//0.0
double kD = 16.52849199;//0.0

double turnKP = 0.50999999;//0.50999999
double turnKI = 0.000000000001;//0.000000000001
double turnKD = 1.26999994;//1.26999994

double wheelRad = 1.0;//1.0
double drivetrainWheelRad = 2.0;//2.0

double turnTolerance = 0.2;//0.1
double driveTolerance = 0.1;//0.0
double clawTolerance = 1.0;//0.0

double driveIntegralLimit = 20.0;//20.0
double turnIntegralLimit = 30.0;//30.0

double drivetrainDiameter = 13;



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
        //Declaring sensor math variables
        double desiredValue;
        double error;
        double integral;
        double derivative;
        double pwr;
        double prevError;
        double storedTrackingMeasurements;
        double storedHeading;
        double resetCurrentPosition;
        double turnDifference;
        //Declaring what instance of motor control it is
        bool isTurning;
        bool isDriving;
        bool isClaw;
        bool isOdomDrive;
    //PID class parameter setup
    public:
        PID(double DesiredValue, bool IsDriving, bool IsTurning, bool IsClaw, bool IsOdomDrive) {
            desiredValue = DesiredValue;
            error = DesiredValue;
            isTurning = IsTurning;
            isDriving = IsDriving;
            isClaw = IsClaw;
            isOdomDrive = IsOdomDrive;
        }

        void run() {
            integral = 0;
            error = 0;
            //This accounts for the tracking wheel measuremants in PID
            storedTrackingMeasurements = frontTracking.position(turns);

            storedHeading = Inertial1.heading(deg);
            while (true) {
                //This simmulates drive PID starting at 0
                resetCurrentPosition = frontTracking.position(turns) - storedTrackingMeasurements;

                //This is nescessarry for odometry to work so we don't have to reset the forward/sideways tracking position.
                //It instead starts where the tracking position is to 0 allowing it to use distance values instead of coordinate values

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
                //

                //Turn difference calculations for determing the distance between the left and right sides of the drivetrain
                turnDifference = 2 * ((drivetrainDiameter / 2) * radianHeading) * (sin(radianHeading / 2));

                

                //Class initialization for turning
                if (isTurning) {
                    error = constrainAngle(desiredValue - Inertial1.heading(deg));
                    pwr = error * turnKP + integral * turnKI + derivative * turnKD;
                    LeftDriveSmart.spin(fwd, pwr, pct);
                    RightDriveSmart.spin(reverse, pwr, pct);
                    if (error == 0) break;
                    if (error >= -turnTolerance && error <= turnTolerance);
                }

                //Class initialization for driving
                else if (isDriving) {
                    //This section is just drive PID
                    error = desiredValue - resetCurrentPosition * (wheelRad * 2) * M_PI;
                    pwr = error * kP + integral * kI + derivative * kD;
                    if (constrainAngle(storedHeading - Inertial1.heading(deg)) < 0) {
                        RightDriveSmart.spin(fwd, pwr--, pct);
                        LeftDriveSmart.spin(fwd, pwr++, pct);
                    }
                    else if (constrainAngle(storedHeading - Inertial1.heading(deg)) > 0) {
                        RightDriveSmart.spin(fwd, pwr++, pct);
                        LeftDriveSmart.spin(fwd, pwr--, pct);
                    }
                    if (error == 0) break;
                    if (error >= -driveTolerance && error <= driveTolerance) break;
                }

                //If it messes up the acceleration or measurement values use this
                //LeftDriveSmart.spin(fwd, pwr, pct);
                //RightDriveSmart.spin(fwd, pwr, pct);

                //Class initialization for driving with odometry so it keeps track of the correct position of the tracking wheel only when it's only using odom
                else if (isOdomDrive) {
                    error = desiredValue - frontTracking.position(turns) * (wheelRad * 2) * M_PI;
                    pwr = error * kP + integral * kI + derivative * kD;
                    if (constrainAngle(storedHeading - Inertial1.heading(deg)) < 0) {
                        RightDriveSmart.spin(fwd, pwr--, pct);
                        LeftDriveSmart.spin(fwd, pwr++, pct);
                    }
                    else if (constrainAngle(storedHeading - Inertial1.heading(deg)) > 0) {
                        RightDriveSmart.spin(fwd, pwr++, pct);
                        LeftDriveSmart.spin(fwd, pwr--, pct);
                    }
                    if (error == 0) break;
                    if (error >= -driveTolerance && error <= driveTolerance) break;
                }

                //Class initialization for claw
                else if (isClaw) {
                    error = desiredValue - clawTracking.position(deg);
                    pwr = error * clawKp + integral * clawKi + derivative * clawKd;
                    Claw.spin(fwd, pwr, pct);
                    if (error == 0) break;
                    if (error >= -clawTolerance && error <= clawTolerance) break;
                }

                //Terminates if within tolerance
                if ((error >= -driveTolerance && error <= driveTolerance && (isDriving || isOdomDrive)) || (error <= turnTolerance && error >= -turnTolerance && isTurning) || (error >= -clawTolerance && error <= clawTolerance && (isClaw))) break;
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
    double startHeading = Inertial1.heading(deg);
    PID drivePID(driveDist, true, false, false, false);
    drivePID.run();
}

//Turn PID function
void turnToHeading(double turnHeading) {
    PID turnPID(turnHeading, false, true, false, false);
    turnPID.run();
}

//Claw PID function
void ClawRotate(double rotationValue) {
    PID clawPID(rotationValue, false, false, true, false);
    clawPID.run();
}

//Drive PID function for odometry use so that it doesn't mess with encoder readings
void driveInOdom(double driveDist) {
    PID odomDrivePID(driveDist, false, false, false, true);
    odomDrivePID.run();
}
