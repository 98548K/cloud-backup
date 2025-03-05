#include "vex.h"

void pre_auton(void) {
  vexcodeInit();
  Intakes.setVelocity(100, pct);
  Claw.setVelocity(100, pct);
  Drivetrain.setDriveVelocity(100, pct);
  selectable();
  //Inertial1.calibrate();



  /*if (auton == "Skills") {
      Inertial1.setHeading(217, deg);
  }
  else if (auton == "Blue 4 ring") {
    Inertial1.setHeading(217, deg);
  }
  else if (auton == "Blue 5 ring") {
    Inertial1.setHeading(217, deg);
  }
  else if (auton == "Bsig win pt") {
    Inertial1.setHeading(217, deg);
  }
  else if (auton == "Blue 6 ring") {
    Inertial1.setHeading(217, deg);
  }
  else if (auton == "Blue 2 ring") {
    Inertial1.setHeading(217, deg);
  }
  else if (auton == "Blue 3 ring") {
    Inertial1.setHeading(217, deg);
  }
  else if (auton == "Blue win pt") {
    Inertial1.setHeading(217, deg);
  }
  else if (auton == "Blue goal") {
    Inertial1.setHeading(217, deg);
  }
  else if (auton == "Red 4 ring") {
    Inertial1.setHeading(217, deg);
  }
  else if (auton == "Red 5 ring") {
    Inertial1.setHeading(217, deg);
  }
  else if (auton == "Rsig win pt") {
    Inertial1.setHeading(217, deg);
  }
  else if (auton == "Red 6 ring") {
    Inertial1.setHeading(217, deg);
  }
  else if (auton == "Red 2 ring") {
    Inertial1.setHeading(217, deg);
  }
  else if (auton == "Red 3 ring") {
    Inertial1.setHeading(217, deg);
  }
  else if (auton == "Red win pt") {
    Inertial1.setHeading(217, deg);
  }
  else if (auton == "Red goal") {
    Inertial1.setHeading(217, deg);
  }
  else if (auton == "Other red") {
    Inertial1.setHeading(217, deg);
  }
  else if (auton == "Other_blue") {
    Inertial1.setHeading(217, deg);
  }
  else {
    Inertial1.setHeading(217, deg);
  }
  wait (6, sec);
  Controller1.rumble("--");*/
}