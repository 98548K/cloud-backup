/*#include "vex.h"

double path[] = {1, 2, 3, 4, 5, true};

int len() {
    int length = 0;
    while (path[length + 1] != true) {
        length += 1;
    }
    return length;
}

int purePursuitPath() {
    while (true) {
        error = desiredValue - frontTracking.position(turns) * (wheelRad * 2) * M_PI;
        integral += error;
        derivative = error - prevError;
        pwr = error * kP + integral * kI + derivative * kD;

        return std::cout << len() << std::endl;
    }
}*/