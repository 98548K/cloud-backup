#include "vex.h"

bool clamped = false;
bool chomped = false;
bool doinked = false;
const char * autoClampToggleSelection = "Off";
double clawKP = 0.3;
int clawTarget = 0;
const char * colorSortColor = "Off ";


using namespace vex;
using namespace std;
using signature = vision::signature;
using code = vision::code;

//manual controls
void toggleClamp() {
    if (clamped == true) {
        clamped = false;
        wait (.22, sec);
    }
    else if (clamped == false) {
        clamped = true;
        wait (.22, sec);
    }
    Clamp.set(clamped);
}


void toggleClawUpState() {
    clawTarget++;

    if (clawTarget == 3) {
        clawTarget = 1;
    }
}



void toggleDoinker() {
    if (doinked == true) {
        doinked = false;
        wait (.22, sec);
    }
    else if (doinked == false) {
        doinked = true;
        wait (.22, sec);
    }
    Doinker.set(doinked);
}


void toggleTeeth() {
    if (chomped == true) {
        chomped = false;
        wait (.22, sec);
    }
    else if (chomped == false) {
        chomped = true;
        wait (.22, sec);
    }
    Teeth.set(chomped);
}


void clawDown() {
    clawTarget = 0;
}


int elevate() {
    while (true) {
        Claw.spinTo(380, deg);
        wait (20, msec);
    }
}

void elevation() {
    task elevateTask = task(elevate);
}





float targetAngle;
float clawError;



void usercontrol(void) {
    Drivetrain.setStopping(coast);
    //Drivetrain.setVelocity(100, pct);
    //Intakes.setVelocity(100, pct);
    clawTracking.setPosition(0, deg);
    LeftDriveSmart.setStopping(coast);
    RightDriveSmart.setStopping(coast);
    Claw.setVelocity(100, pct);
    ringOptical.setLightPower(100, pct);
    goalOptical.setLightPower(100, pct);
    Claw.setMaxTorque(100, pct);


    float clawPositions[3] = {
        58,
        10,
        58,
    };



    task colorSortingBlue = task (colorSortBlue);
    task colorSortingRed = task (colorSortRed);
    task clampGoalViaOpticalSensor(clampGoal);

    colorSortingBlue.suspend();
    colorSortingRed.suspend();
    clampGoalViaOpticalSensor.suspend();


  while (1) {
    Drivetrain.setStopping(coast);
    LeftDriveSmart.setStopping(coast);
    RightDriveSmart.setStopping(coast);
    //task clampGoalViaOpticalSensor(clampGoal);

    //Claw set code:
    targetAngle = clawPositions[clawTarget];
    //clawError = targetAngle - clawTracking.angle(deg);

    //red_detected();

    colorSort.set(false);

    /*if (std::abs(clawError) >= 1) {
        Claw.spin(fwd, clawError * clawKP, pct);
    }
    else {
        Claw.stop(hold);
    }*/
    //

    //manual toggle and controls
    if (Controller1.ButtonR2.pressing()) {
        toggleClawUpState();
        //wait (.22, sec);
        ClawRotate(targetAngle);
    }
    Controller1.ButtonUp.pressed(clawDown);
    if (Controller1.ButtonY.pressing()) {
        clampGoalViaOpticalSensor.suspend();
        toggleClamp();
        if (autoClampToggleSelection == "On ") {
            clampGoalViaOpticalSensor.resume();
        }
    }
    if (Controller1.ButtonDown.pressing()) {
        toggleTeeth();
    }
    Controller1.ButtonRight.pressed(toggleDoinker);
    Controller1.ButtonB.pressed(elevation);
    if (Controller1.ButtonLeft.pressing()) {
        Drivetrain.setDriveVelocity(50, pct);
        Drivetrain.driveFor(-7.5, inches);
        Claw.spinFor(450, deg, false);
        wait (.5, sec);
        Drivetrain.driveFor(-3, inches);
        Claw.spinFor(-450, deg);
        Drivetrain.setDriveVelocity(100, pct);
    }






    //Color sort toggle code
    if (Controller1.ButtonA.pressing()) {
        if (colorSortColor == "Off ") {
            colorSortColor = "Red ";
            colorSortingBlue.suspend();
            colorSortingRed.resume();
            wait (.22, sec);
        }
        else if (colorSortColor == "Red ") {
            colorSortColor = "Blue";
            colorSortingBlue.resume();
            colorSortingRed.suspend();
            wait (.22, sec);
        }
        else if (colorSortColor == "Blue") {
            colorSortColor = "Off ";
            colorSortingBlue.suspend();
            colorSortingRed.suspend();
            wait (.22, sec);
        }
        else {
            colorSortColor = "Off ";
        }
    }


    Controller1.Screen.setCursor(3, 1);
    Controller1.Screen.print(colorSortColor);



    if (Controller1.ButtonX.pressing()) {
        //confirm();

        if (autoClampToggleSelection == "Off") {
            autoClampToggleSelection = "On ";
            clampGoalViaOpticalSensor.resume();
            wait (.22, sec);
        }
        else if (autoClampToggleSelection == "On ") {
            autoClampToggleSelection = "Off";
            clampGoalViaOpticalSensor.suspend();
            wait (.22, sec);
        }
        else {
            colorSortColor = "Off";
        }
    }


    Controller1.Screen.setCursor(3, 8);
    Controller1.Screen.print("goal optical ");
    Controller1.Screen.print(autoClampToggleSelection);
    


    

    wait(20, msec); 
                    
  }
}