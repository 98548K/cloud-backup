extern double FRONT_WHEEL;
extern double SIDE_WHEEL;
extern double X;
extern double Y;
extern int positionTracking();
void setDrivePosition(double x, double y, double startHeading);
void turnToPosition(double x, double y, vex::directionType dir);
void driveToPosition(double x, double y, vex::directionType dir);