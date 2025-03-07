//Functions and parameters
void blue_detected();
void red_detected();
void curve_turn(double LeftVelocity,double RightVelocity, double InchesTraveled, double ResetVelocity);
void reset_both_sides(double SameVelocity);
extern int colorSortRed();

extern int colorSortBlue();


extern int colorSortRedInAuton();

extern int catchRedRing();

extern int colorSortBlueInAuton();


extern int clampGoal();

void goal_detected();


void confirm();

void clampOn();

void clampOff();

void limitSwitchTrigger();

extern int currentVelocity;


void auton_blue_detected();

void auton_red_detected();


void setDriveTimeout(double timeoutValue);

extern int setClaw();

void spinClawTo(double angle);