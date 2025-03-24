#include "vex.h"


void autonomous(void) {
    ringOptical.setLightPower(100, pct);
    //goalOptical.setLightPower(100, pct);
    Drivetrain.setStopping(brake);
    frontTracking.setPosition(0, deg);
    task clampGoalViaOpticalSensor(clampGoal);
    clampGoalViaOpticalSensor.suspend();
    if (auton == "Skills") {
        task colorSortingBlue = task(colorSortBlueInAuton);
        task clampGoalInAuton = task (clampGoal);
        skills_auton();
    }
    else if (auton == "Blue 4 ring") {
        task colorSortingRed = task(colorSortRedInAuton);
        task clampGoalInAuton = task (clampGoal);
        Blue_4_ring();
    }
    else if (auton == "Blue 5 ring") {
        task colorSortingRed = task(colorSortRedInAuton);
        task clampGoalInAuton = task (clampGoal);
        Blue_5_ring();
    }
    else if (auton == "Bsig win pt") {
        task colorSortingRed = task(colorSortRedInAuton);
        task clampGoalInAuton = task (clampGoal);
        Bsig_win_point();
    }
    else if (auton == "Blue 6 ring") {
        task colorSortingRed = task(colorSortRedInAuton);
        task clampGoalInAuton = task (clampGoal);
        Blue_6_ring();
    }
    else if (auton == "Blue 2 ring") {
        task colorSortingRed = task(colorSortRedInAuton);
        task clampGoalInAuton = task (clampGoal);
        Blue_2_ring();
    }
    else if (auton == "Blue 3 ring") {
        task colorSortingRed = task(colorSortRedInAuton);
        task clampGoalInAuton = task (clampGoal);
        Blue_3_ring();
    }
    else if (auton == "Blue win pt") {
        task colorSortingRed = task(colorSortRedInAuton);
        task clampGoalInAuton = task (clampGoal);
        Blue_win_point();
    }
    else if (auton == "Blue goal") {
        task colorSortingRed = task(colorSortRedInAuton);
        task clampGoalInAuton = task (clampGoal);
        Blue_goal();
    }
    else if (auton == "Red 4 ring") {
        task colorSortingBlue = task(colorSortBlueInAuton);
        task clampGoalInAuton = task (clampGoal);
        Red_4_ring();
    }
    else if (auton == "Red 5 ring") {
        task colorSortingBlue = task(colorSortBlueInAuton);
        task clampGoalInAuton = task (clampGoal);
        Red_5_ring();
    }
    else if (auton == "Rsig win pt") {
        task colorSortingBlue = task(colorSortBlueInAuton);
        task clampGoalInAuton = task (clampGoal);
        Rsig_win_point();
    }
    else if (auton == "Red 6 ring") {
        task colorSortingBlue = task(colorSortBlueInAuton);
        task clampGoalInAuton = task (clampGoal);
        Red_6_ring();
    }
    else if (auton == "Red 2 ring") {
        task colorSortingBlue = task(colorSortBlueInAuton);
        task clampGoalInAuton = task (clampGoal);
        Red_2_ring();
    }
    else if (auton == "Red 3 ring") {
        task colorSortingBlue = task(colorSortBlueInAuton);
        task clampGoalInAuton = task (clampGoal);
        Red_3_ring();
    }
    else if (auton == "Red win pt") {
        task colorSortingBlue = task(colorSortBlueInAuton);
        task clampGoalInAuton = task (clampGoal);
        Red_win_point();
    }
    else if (auton == "Red goal") {
        task colorSortingBlue = task(colorSortBlueInAuton);
        task clampGoalInAuton = task (clampGoal);
        Red_goal();
    }
    else if (auton == "Other red") {
        task colorSortingBlue = task(colorSortBlueInAuton);
        task clampGoalInAuton = task (clampGoal);
        Other_red();
    }
    else if (auton == "Other_blue") {
        task colorSortingBlue = task(colorSortBlueInAuton);
        task clampGoalInAuton = task (clampGoal);
        Other_blue();
    }
    else {
        turnToHeading(180);
        turnToHeading(0);
        //driveIn(24);
        //driveIn(-24);

        //driveToPosition(0, 60, fwd);
    }
}