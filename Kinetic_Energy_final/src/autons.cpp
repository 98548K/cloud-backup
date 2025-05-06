#include "vex.h"

void Red_5_Ring() {
    Clamp.set(true);
    setDrivePosition(-64.5, 17, 197);
    Claw.setPosition(30, deg);
    Claw.spinFor(900, deg, false);
    wait(1, sec);
    Claw.spinFor(-700, deg, false);
    wait(1, sec);
    Claw.stop();
    wait(1, sec);
    //driveToPosition(-37, 10, reverse);
    slowDriveToPosition(-24, 24, reverse);
    Clamp.set(false);
}