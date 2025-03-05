#include "vex.h"
task clampGoalInAuton = task (clampGoal);
//task clawTask = task (setClaw);

void skills_auton(){
    
    //kP = 1.7;//1.5
    //kI = 0.0;//0.0
    //kD = 0.2;//0.2
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

    //Clamp.set(false);
    //kP = 3.0;//3.0
    //kI = 0.0;//0.03
    //kD = 0.4;//0.4

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
    turnToHeading(270);
    turnKP = 0.5;//0.5
    turnKI = 0.0;//0.0
    turnKD = 1.0;//1.0
    wait (.1, sec);
    Intakes.spin(fwd);
    wait (.1, sec);

    //add these up to 55
    driveIn(40);
    wait (.1, sec);
    driveIn(10);
    driveIn(-5);
    wait (.1, sec);

    turnToHeading(315);
    turnToHeading(0);
    wait (.1, sec);
    driveIn(7);
    wait (.1, sec);
    turnToHeading(130);
    wait (.1, sec);
    clampGoalInAuton.suspend();
    driveIn(-9);
    Clamp.set(true);

    
    driveIn(14);


    turnToHeading(355);
    Clamp.set(true);
    Inertial1.setHeading(355, deg);
    wait (.1, sec);
    clampGoalInAuton.resume();
    Intakes.spin(reverse);

    kP = 2.5;
    kI = 0.0;
    kD = 10.0;
    driveIn(-72);    
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
    driveIn(38);
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

