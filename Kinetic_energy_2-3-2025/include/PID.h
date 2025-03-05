extern double clawKp;
extern double clawKi;
extern double clawKd;
extern double kP;
extern double kI;
extern double kD;
extern double turnKP;
extern double turnKI;
extern double turnKD;
extern double wheelRad;
extern double tolerance;
extern double turnTolerance;



extern double p, i, d;
extern double desiredValue;
extern double error;
extern double integral;
extern double derivative;
extern double pwr;
extern double prevError;
extern bool isTurning;
extern bool isClaw;


//PID(double P, double I, double D, double DesiredValue, bool IsTurning);



void driveIn(double driveDist);
extern double startDist;

void turnToHeading(double turnHeading);
extern double currentHeading;

void ClawRotate(double rotationValue);
extern double currentRotation;