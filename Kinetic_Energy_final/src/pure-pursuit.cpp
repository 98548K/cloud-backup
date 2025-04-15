#include "vex.h"

//Path list initialization
double pathCoords[1] = {7};

//PID math variables in case of PID implementation


int purePursuitPath() {
    while (true) {
        error = desiredValue - frontTracking.position(turns) * (wheelRad * 2) * M_PI;
        integral += error;
        derivative = error - prevError;
        pwr = error * kP + integral * kI + derivative * kD;
    }
}