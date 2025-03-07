#include "vex.h"
task clampGoalInAuton = task (clampGoal);
//task clawTask = task (setClaw);

task stopIntake = task(catchRedRing);

void skills_auton(){
    
    stopIntake.suspend();
    clampGoalInAuton.resume();
    clawTracking.setPosition(40, deg);

    Claw.spinFor(500, deg, false);
    wait (.5, sec);
    Claw.stop();
    Clamp.set(true);

    //20
    driveIn(-22);
    Claw.spinFor(-900, deg, false);
    wait (.1, sec);

    turnToHeading(90);
    wait (.1, sec);
    Intakes.spin(fwd);
    driveIn(22);
    wait (1, sec);
    turnToHeading(60);
    clampGoalInAuton.resume();

    wait (.1, sec);
    driveIn(28);
    wait (.1, sec);
    turnToHeading(0);//maybe change this to 1
    wait (.1, sec);
    Claw.setVelocity(100, pct);
    driveIn(16);
    wait (.1, sec);
    driveIn(-7);
    turnKP = 0.4;//0.5
    turnKI = 0.0;//0.0
    turnKD = 1.0;//1.0
    turnTolerance = 0.4;
    turnToHeading(270);
    turnTolerance = 0.6;
    turnKP = 0.5;//0.5
    turnKI = 0.0;//0.0
    turnKD = 1.0;//1.0
    wait (.1, sec);
    Intakes.spin(fwd);
    wait (.1, sec);

    //add these up to 50 or 55
    driveIn(40);
    wait (.1, sec);
    //if it messes up change this back to 10
    driveIn(10);

    driveIn(-5);
    wait (.1, sec);

    turnToHeading(315);
    turnTolerance = 0.8;
    turnToHeading(0);
    turnTolerance = 0.7;
    wait (.1, sec);
    driveIn(7);
    wait (.1, sec);
    turnToHeading(130);
    wait (.1, sec);
    clampGoalInAuton.suspend();
    driveIn(-9);
    Clamp.set(true);
    Intakes.spin(reverse);
    
    driveIn(11);


    turnToHeading(355);
    Inertial1.setHeading(355, deg);
    Clamp.set(true);
    wait (.1, sec);
    clampGoalInAuton.suspend();

    kP = 2.5;
    kI = 0.0;
    kD = 10.0;
    driveIn(-72);
    Clamp.set(false);
    kP = 3.9;//3.9
    kI = 3.5;//3.5
    kD = 0.4;//0.4
    Intakes.spin(fwd);


    wait (.1, sec);
    turnToHeading(90);
    wait (.1, sec);
    Intakes.spin(fwd);
    driveIn(18);
    wait (.1, sec);
    turnToHeading(125);
    wait (.1, sec);
    driveIn(34);
    wait (.1, sec);
    turnToHeading(180);

    wait (.1, sec);

    driveIn(8);

    wait (.1, sec);
    driveIn(-15);
    wait (.1, sec);
    turnToHeading(270);
    Intakes.spin(fwd);
    wait (.1, sec);

    driveIn(40);
    wait (.1, sec);
    driveIn(13);
    driveIn(-15);

    turnToHeading(217);
    driveIn(10);
    turnToHeading(55);
    driveIn(-12);
    clampGoalInAuton.suspend();
    Clamp.set(true);
    driveIn(10);
    turnToHeading(90);
    stopIntake.resume();
    //probably this
    Intakes.setVelocity(75, pct);
    driveIn(68);
    Intakes.setVelocity(100, pct);
    
    wait (.1, sec);
    turnToHeading(0);
    //clampGoalInAuton.resume();
    driveIn(30);
    wait (.1, sec);
    turnToHeading(270);
    wait (.1, sec);
    kP = 2.5;
    kI = 0.0;
    kD = 10.0;
    driveIn(-30.5);
    Clamp.set(false);
    kP = 3.9;//3.9
    kI = 3.5;//3.5
    kD = 0.4;//0.4
    wait (.1, sec);
    turnToHeading(350);
    clampGoalInAuton.suspend();
    Clamp.set(true);
    wait (.1, sec);
    driveIn(-29);
    wait (.1, sec);
    driveIn(30);
    wait (.1, sec);
    turnToHeading(165);
    //clampGoalInAuton.resume();
    kP = 2.5;
    kI = 0.0;
    kD = 9.0;
    driveIn(-22);
    Clamp.set(false);
    kP = 3.9;//3.9
    kI = 3.5;//3.5
    kD = 0.4;//0.4
    turnToHeading(320);
    Intakes.spin(fwd);
    stopIntake.suspend();
    driveIn(32);
    wait (.1, sec);
    turnToHeading(0);
    driveIn(30);
    turnToHeading(90);
    wait (.1, sec);
    driveIn(15);
    wait (.1, sec);
    driveIn(-11);
    turnToHeading(65);
    wait (.1, sec);
    driveIn(10);
    turnToHeading(245);
    clampGoalInAuton.suspend();
    Clamp.set(true);
    driveIn(-18);
    wait (.1, sec);
    driveIn(12);
    turnToHeading(40);
    Claw.spinFor(900, deg, false);
    wait (.5, sec);
    kP = 2.5;
    kI = 0.0;
    kD = 5.0;
    driveIn(-38);
}
void Blue_4_ring(){

}
void Blue_5_ring(){

}
void Bsig_win_point(){

}
void Blue_6_ring(){

}
void Blue_2_ring(){

}
void Blue_3_ring(){

}
void Blue_win_point(){
    
}
void Blue_goal(){
    
}
void Red_4_ring(){

}
void Red_5_ring(){

}
void Rsig_win_point(){

}
void Red_6_ring(){

}
void Red_2_ring(){

}
void Red_3_ring(){

}
void Red_win_point(){
    
}
void Red_goal(){
    clampGoalInAuton.resume();
    Inertial1.setHeading(115, deg);
    Clamp.set(true);
    IntakesMotorA.spin(fwd);
    Doinker.set(true);
    driveIn(30.5);
    Teeth.set(true);
    driveIn(-20);
    
}
void Other_red(){

}
void Other_blue(){

}

