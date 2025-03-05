extern bool clamped;
extern bool chomped;
extern bool doinked;

extern double clawKp;

extern int clawTarget;

extern const char * colorSortColor;
extern const char * autoClampToggleSelection;

void usercontrol(void);
void toggleClawUpState();
void toggleSkillsClawUpState();
void clawDown();
void toggleClamp();
void toggleDoinker();
void toggleTeeth();


extern float targetAngle;
extern float clawError;
extern float clawPositions;
extern float skillsClawPositions;

int elevate();

void elevation();