#include "vex.h"


int currentVelocity = 100;

//task clampGoalViaOpticalSensor(clampGoal);


int clampGoal() {
    while (true) {
        goal_detected();
        //clampGoalViaOpticalSensor.resume();
        wait (20, msec);
    }
}



int colorSortRed() {
    while (true) {
        red_detected();
        wait (20, msec);
    }
}


int catchRedRing() {
    while (true) {
        if (ringOptical.hue() > 10 && ringOptical.hue() < 20) {
            IntakesMotorB.stop();
       }
       else if (ringOptical.hue() > 10 && ringOptical.hue() < 20) {
            IntakesMotorB.stop();
       }
        wait (10, msec);
    }
}


int colorSortBlue() {
    while (true) {
        blue_detected();
        wait (20, msec);
    }
}



int colorSortRedInAuton() {
    while (true) {
        auton_red_detected();
        wait (20, msec);
    }
}




int colorSortBlueInAuton() {
    while (true) {
        auton_blue_detected();
        wait (20, msec);
    }
}



void clampOn() {
    task clampGoalViaOpticalSensor(clampGoal);
    clampGoalViaOpticalSensor.resume();
    Clamp.set(false);
    Drivetrain.stop();
}

void clampOff() {
    task clampGoalViaOpticalSensor(clampGoal);
    clampGoalViaOpticalSensor.suspend();
    Clamp.set(true);
}


void limitSwitchTrigger() {
    Clamp.set(false);
}




void confirm() {
    if (colorSortColor == "Off ") {
    }
    else if (colorSortColor == "Red ") {
        task colorSortingRed = task (colorSortRed);
    }
    else if (colorSortColor == "Blue") {
        task colorSortingBlue = task (colorSortBlue);
    }
    else {
    }
}



//Color sort function
void blue_detected() {
    if (ringOptical.hue() > 170 && ringOptical.hue() < 220) {
        colorSort.set(true);
        //wait (.02, sec);
        //colorSort.set(false);
   }
   else if (ringOptical.hue() > 170 && ringOptical.hue() < 220) {
        colorSort.set(true);
        //wait (.02, sec);
        //colorSort.set(false);
   }
}

void red_detected() {
    if (ringOptical.hue() > 10 && ringOptical.hue() < 20) {
        colorSort.set(true);
        //wait (.02, sec);
        //colorSort.set(false);
   }
   else if (ringOptical.hue() > 10 && ringOptical.hue() < 20) {
        colorSort.set(true);
        //wait (.02, sec);
        //colorSort.set(false);
   }
}






void auton_blue_detected() {
    if (ringOptical.hue() > 170 && ringOptical.hue() < 220) {
        colorSort.set(true);
        wait (.02, sec);
        colorSort.set(false);
   }
   else if (ringOptical.hue() > 170 && ringOptical.hue() < 220) {
        colorSort.set(true);
        wait (.02, sec);
        colorSort.set(false);
   }
}

void auton_red_detected() {
    if (ringOptical.hue() > 10 && ringOptical.hue() < 20) {
        colorSort.set(true);
        wait (.02, sec);
        colorSort.set(false);
   }
   else if (ringOptical.hue() > 10 && ringOptical.hue() < 20) {
        colorSort.set(true);
        wait (.02, sec);
        colorSort.set(false);
   }
}














//Auton goal sensor
void goal_detected() {
    if (/*goalOptical.hue() > 45 && goalOptical.hue() < 85 && goalOptical.isNearObject() && */limitSwitch.pressing()) {    
            Clamp.set(false);
    }
}





void reset_both_sides(double SameVelocity) {
    LeftDriveSmart.setVelocity(SameVelocity, pct);
    RightDriveSmart.setVelocity(SameVelocity, pct);
}

void curve_turn(double LeftVelocity,double RightVelocity, double InchesTraveled, double ResetVelocity) {
    LeftDriveSmart.setVelocity(LeftVelocity, pct);
    RightDriveSmart.setVelocity(RightVelocity, pct);
    Drivetrain.driveFor(InchesTraveled, inches, false);
    wait(1, sec);
    Drivetrain.stop();
    reset_both_sides(ResetVelocity);
}

int setClaw() {
    while (true) {
        clawError = 60 - clawTracking.angle(deg);
        if (std::abs(clawError) >= 1) {
            Claw.spin(fwd, clawError * clawKp, pct);
        }
        else {
            Claw.stop(hold);
        }
    }
}



void spinClawTo(double angle) {
    while (true) {
        if (clawTracking.position(deg) > angle && clawTracking.position(deg) < angle + 10) {
            Claw.stop(hold);
            break;
        }
        if (clawTracking.position(deg) > angle) {
            Claw.spin(reverse);
        }
        else if (clawTracking.position(deg) < angle + 10) {
            Claw.spin(fwd);
        }
    }
}