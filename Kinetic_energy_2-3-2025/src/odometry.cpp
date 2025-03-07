#include "vex.h"

double FRONT_WHEEL;
double SIDE_WHEEL;
double X;
double Y;

int positionTracking() {
    while (true) {
        FRONT_WHEEL = frontTracking.position(turns) * (wheelRad * 2) * M_PI;
        SIDE_WHEEL = sideTracking.position(turns) * (wheelRad * 2) * M_PI;
        if (Inertial1.heading(deg) > 315 && Inertial1.heading(deg) < 360 || Inertial1.heading(deg) > 0 && Inertial1.heading(deg) < 45) {
            X = SIDE_WHEEL/cos(Inertial1.heading(deg));
            Y = FRONT_WHEEL/cos(Inertial1.heading(deg));
        }
        else if (Inertial1.heading(deg) > 45 && Inertial1.heading(deg) < 135) {
            Y = SIDE_WHEEL/cos(Inertial1.heading(deg));
            X = FRONT_WHEEL/cos(Inertial1.heading(deg));
        }
        else if (Inertial1.heading(deg) > 135 && Inertial1.heading(deg) < 225) {
            X = SIDE_WHEEL/cos(Inertial1.heading(deg));
            Y = FRONT_WHEEL/cos(Inertial1.heading(deg));
        }
        else if (Inertial1.heading(deg) > 225 && Inertial1.heading(deg) < 315) {
            Y = SIDE_WHEEL/cos(Inertial1.heading(deg));
            X = FRONT_WHEEL/cos(Inertial1.heading(deg));
        }
        else {
            X = SIDE_WHEEL/cos(Inertial1.heading(deg));
            Y = FRONT_WHEEL/cos(Inertial1.heading(deg));
        }
    }
}