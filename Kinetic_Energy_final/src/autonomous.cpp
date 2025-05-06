#include "vex.h"


void autonomous(void) {
    ringOptical.setLightPower(100, pct);
    Drivetrain.setStopping(brake);
    frontTracking.setPosition(0, deg);
    if (auton == "Skills") {
        
    }
    else if (auton == "Blue 4 ring") {
        
    }
    else if (auton == "Blue 5 ring") {
        
    }
    else if (auton == "Bsig win pt") {
        
    }
    else if (auton == "Blue 6 ring") {
        
    }
    else if (auton == "Blue 2 ring") {
        
    }
    else if (auton == "Blue 3 ring") {
        
    }
    else if (auton == "Blue win pt") {
        
    }
    else if (auton == "Blue goal") {
        
    }
    else if (auton == "Red 4 ring") {
        
    }
    else if (auton == "Red 5 ring") {
        Red_5_Ring();
    }
    else if (auton == "Rsig win pt") {
        
    }
    else if (auton == "Red 6 ring") {
        
    }
    else if (auton == "Red 2 ring") {
        
    }
    else if (auton == "Red 3 ring") {
        
    }
    else if (auton == "Red win pt") {
        
    }
    else if (auton == "Red goal") {
        
    }
    else if (auton == "Other red") {
        
    }
    else if (auton == "Other_blue") {
        
    }
    else {
        //turnToHeading(90);
        //wait (1, sec);
        //turnToHeading(0);

        //driveIn(24);
        //turnToHeading(180);
        //wait (1, sec);
        //driveIn(-24);
        //turnToHeading(0);

        //driveToPosition(24, 24, fwd);
        //wait (1, sec);
        //driveToPosition(0, 0, reverse);
        //wait (1, sec);
        //driveToPosition(24, 24, fwd);
        
        //slowDrive(-24);
        //wait (2, sec);
        //slowDrive(24);

        Red_5_Ring();
    }
}