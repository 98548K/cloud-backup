#include "vex.h"

void Red_5_Ring() {
    Clamp.set(true);
    setDrivePosition(-60, 10, 197);
    Claw.setPosition(30, deg);
    Claw.spinFor(900, deg, false);
    wait(1, sec);
    Claw.spinFor(-900, deg, false);
    wait(1, sec);
    Claw.stop();
    wait(1, sec);
    driveToPosition(-24, 24, reverse);
    Clamp.set(false);
}