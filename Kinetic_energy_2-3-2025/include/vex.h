#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cmath>
#include <iostream>
#include <vex_task.h>

#include "v5.h"
#include "v5_vcs.h"

#include "robot-config.h"
#include "user-control.h"
#include "autonomous.h"
#include "pre-auton.h"
#include "auton-selector.h"
#include "other-functions.h"
#include "autons.h"
#include "PID.h"
#include "odometry.h"

#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)