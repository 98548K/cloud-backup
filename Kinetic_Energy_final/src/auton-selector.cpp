#include "vex.h"

int quadrant = 0;
const char*  auton = "[NULL]";


void quadrant0() {
  Brain.Screen.setFont(monoXL);
  Brain.Screen.printAt(251,40,"Skills       ");
  Brain.Screen.printAt(251,100,"Calibrate   ");
  Brain.Screen.printAt(251,160,"Other red   ");
  Brain.Screen.printAt(251,220,"Other blue  ");
}

void quadrant1() {
  Brain.Screen.setFont(monoXL);
  Brain.Screen.printAt(251,40,"Blue 4 ring  ");
  Brain.Screen.printAt(251,100,"Blue 5 ring ");
  Brain.Screen.printAt(251,160,"Blue win pt ");
  Brain.Screen.printAt(251,220,"Blue 6 ring ");
}


void quadrant2() {
  Brain.Screen.setFont(monoXL);
  Brain.Screen.printAt(251,40,"Blue 2 ring  ");
  Brain.Screen.printAt(251,100,"Blue 3 ring ");
  Brain.Screen.printAt(251,160,"Bsig win pt ");
  Brain.Screen.printAt(251,220,"Blue goal   ");
}


void quadrant3() {
  Brain.Screen.setFont(monoXL);
  Brain.Screen.printAt(251,40,"Red 2 ring   ");
  Brain.Screen.printAt(251,100,"Red 3 ring  ");
  Brain.Screen.printAt(251,160,"Rsig win pt ");
  Brain.Screen.printAt(251,220,"Red goal    ");
}


void quadrant4() {
  Brain.Screen.setFont(monoXL);
  Brain.Screen.printAt(251,40,"Red 4 ring   ");
  Brain.Screen.printAt(251,100,"Red 5 ring  ");
  Brain.Screen.printAt(251,160,"Red  win pt ");
  Brain.Screen.printAt(251,220,"Red 6 ring  ");
}


void field() {
  //This is the field
  Brain.Screen.setFillColor(black);
  Brain.Screen.drawRectangle(0, 0, 250,240);
}


void selection() {
  //This is the selection menu
  Brain.Screen.setPenColor(white);
  Brain.Screen.drawRectangle(250, 0, 250,60);
  Brain.Screen.drawRectangle(250, 60, 250,60);
  Brain.Screen.drawRectangle(250, 120, 250,60);
  Brain.Screen.drawRectangle(250, 180, 250,60);
  Brain.Screen.setPenColor(green);
  Brain.Screen.setFont(monoXL);
}


void field_stripes() {
  //This is the field stripes
  Brain.Screen.setPenColor(white);
  Brain.Screen.setFillColor(white);
  //Left middle line
  Brain.Screen.drawLine(120, 0, 120,240);
  //Right middle line
  Brain.Screen.drawLine(130, 0, 130,240);
  //Left line
  Brain.Screen.drawLine(32.5, 0, 32.5,240);
  //Right line
  Brain.Screen.drawLine(217.5, 0, 217.5,240);
}


void ladder() {
  //This is the ladder
  Brain.Screen.setFillColor(green);
  Brain.Screen.setPenColor(green);
  Brain.Screen.drawLine(125, 180, 185,120);
  Brain.Screen.drawLine(125, 60, 185,120);
  Brain.Screen.drawLine(125, 60, 65,120);
  Brain.Screen.drawLine(125, 180, 65,120);
}


void rings() {
  //This is the rings
 
  //Blue rings
  Brain.Screen.setPenColor(blue);
  Brain.Screen.setFillColor(blue);
  //Right mid-field blue
  Brain.Screen.drawCircle(200, 120, 8);
  //Left mid-field blue
  Brain.Screen.drawCircle(30, 120, 8);
  //2 ring left
  Brain.Screen.drawCircle(85, 215, 8);
  Brain.Screen.drawCircle(50, 215, 8);
  //3 ring left
  Brain.Screen.drawCircle(85, 25, 8);
  Brain.Screen.drawCircle(117, 15, 8);
  Brain.Screen.drawCircle(117, 35, 8);
  //Red rings
  Brain.Screen.setPenColor(red);
  Brain.Screen.setFillColor(red);
  //Right mid-field red
  Brain.Screen.drawCircle(220, 120, 8);
  //Left mid-field red
  Brain.Screen.drawCircle(50, 120, 8);
  //2 ring right
  Brain.Screen.drawCircle(165, 215, 8);
  Brain.Screen.drawCircle(200, 215, 8);
  //3 ring right
  Brain.Screen.drawCircle(165, 25, 8);
  Brain.Screen.drawCircle(134, 15, 8);
  Brain.Screen.drawCircle(134, 35, 8);
}


void alliance_stakes() {
  Brain.Screen.setPenColor(blue);
  Brain.Screen.setFillColor(blue);
  Brain.Screen.drawCircle(250, 120, 4);
  Brain.Screen.setPenColor(red);
  Brain.Screen.setFillColor(red);
  Brain.Screen.drawCircle(0, 120, 4);
}


void goals() {
  //This is the middle of the field goal
  Brain.Screen.setFillColor(green);
  Brain.Screen.setPenColor(green);
  Brain.Screen.drawLine(130, 225, 120,225);
  Brain.Screen.drawLine(120, 225, 110,215);
  Brain.Screen.drawLine(110, 215, 110,205);
  Brain.Screen.drawLine(110, 205, 120,195);
  Brain.Screen.drawLine(130, 195, 120,195);
  Brain.Screen.drawLine(130, 195, 140,205);
  Brain.Screen.drawLine(140, 205, 140,215);
  Brain.Screen.drawLine(140, 215, 130,225);
  //Bottom right goal
  Brain.Screen.drawLine(170, 195, 160,195);
  Brain.Screen.drawLine(170, 165, 180,175);
  Brain.Screen.drawLine(180, 175, 180,185);
  Brain.Screen.drawLine(180, 185, 170,195);
  Brain.Screen.drawLine(170, 165, 160,165);
  Brain.Screen.drawLine(150, 175, 160,165);
  Brain.Screen.drawLine(150, 175, 150,185);
  Brain.Screen.drawLine(160, 195, 150,185);
  //Bottom left goal
  Brain.Screen.drawLine(90, 195, 80,195);
  Brain.Screen.drawLine(90, 165, 100,175);
  Brain.Screen.drawLine(100, 175, 100,185);
  Brain.Screen.drawLine(100, 185, 90,195);
  Brain.Screen.drawLine(90, 165, 80,165);
  Brain.Screen.drawLine(70, 175, 80,165);
  Brain.Screen.drawLine(70, 175, 70,185);
  Brain.Screen.drawLine(80, 195, 70,185);
  //Top left goal
  Brain.Screen.drawLine(90, 75, 80,75);
  Brain.Screen.drawLine(90, 45, 100,55);
  Brain.Screen.drawLine(100, 55, 100,65);
  Brain.Screen.drawLine(100, 65, 90,75);
  Brain.Screen.drawLine(90, 45, 80,45);
  Brain.Screen.drawLine(70, 55, 80,45);
  Brain.Screen.drawLine(70, 55, 70,65);
  Brain.Screen.drawLine(80, 75, 70,65);
  //Top right goal
  Brain.Screen.drawLine(170, 75, 160,75);
  Brain.Screen.drawLine(170, 45, 180,55);
  Brain.Screen.drawLine(180, 55, 180,65);
  Brain.Screen.drawLine(180, 65, 170,75);
  Brain.Screen.drawLine(170, 45, 160,45);
  Brain.Screen.drawLine(150, 55, 160,45);
  Brain.Screen.drawLine(150, 55, 150,65);
  Brain.Screen.drawLine(160, 75, 150,65);
}


void graphics() {
  Brain.Screen.clearScreen();
  field();
  selection();
  field_stripes();
  ladder();
  rings();
  alliance_stakes();
  goals();
}


void touch() {
  while(true) {
    Brain.Screen.setFillColor(black);
      if (Brain.Screen.xPosition()< 250 && Brain.Screen.xPosition()> 125 && Brain.Screen.yPosition()< 120) {
        quadrant1();
        quadrant = 1;
      }
      else if (Brain.Screen.xPosition()< 250 && Brain.Screen.xPosition()> 125 && Brain.Screen.yPosition()> 120) {
        quadrant2();
        quadrant = 2;
      }
      else if (Brain.Screen.xPosition()> 0 && Brain.Screen.xPosition()< 125 && Brain.Screen.yPosition()> 120) {
        quadrant3();
        quadrant = 3;
      }
      else if (Brain.Screen.xPosition()> 0 && Brain.Screen.xPosition()< 125 && Brain.Screen.yPosition()< 120) {
        quadrant4();
        quadrant = 4;
      }
      //Side menu touch screen code
      if (quadrant == 0) {
        quadrant0();
        if (Brain.Screen.xPosition()> 250 && Brain.Screen.xPosition()< 480 && Brain.Screen.yPosition()< 60) {
          auton = "Skills";
        }
        else if (Brain.Screen.xPosition()> 250 && Brain.Screen.xPosition()< 480 && Brain.Screen.yPosition()< 120) {
          //DrivetrainInertial.calibrate();
          Brain.Screen.setFont(monoXL);
          Brain.Screen.printAt(251,100,"Calibrated");
        }
        else if (Brain.Screen.xPosition()> 250 && Brain.Screen.xPosition()< 480 && Brain.Screen.yPosition()< 180) {
          auton = "Other red";
        }
        else if (Brain.Screen.xPosition()> 250 && Brain.Screen.xPosition()< 480 && Brain.Screen.yPosition()< 240) {
          auton = "Other blue";
        }

    }
 
      if (quadrant == 1) {
        if (Brain.Screen.xPosition()> 250 && Brain.Screen.xPosition()< 480 && Brain.Screen.yPosition()< 60) {
          auton = "Blue 4 ring";
        }
        else if (Brain.Screen.xPosition()> 250 && Brain.Screen.xPosition()< 480 && Brain.Screen.yPosition()< 120) {
          auton = "Blue 5 ring";
        }
        else if (Brain.Screen.xPosition()> 250 && Brain.Screen.xPosition()< 480 && Brain.Screen.yPosition()< 180) {
          auton = "Blue win pt";
        }
        else if (Brain.Screen.xPosition()> 250 && Brain.Screen.xPosition()< 480 && Brain.Screen.yPosition()< 240) {
          auton = "Blue 6 ring";
        }
    }


      if (quadrant == 2) {
        if (Brain.Screen.xPosition()> 250 && Brain.Screen.xPosition()< 480 && Brain.Screen.yPosition()< 60) {
          auton = "Blue 2 ring";
        }
        else if (Brain.Screen.xPosition()> 250 && Brain.Screen.xPosition()< 480 && Brain.Screen.yPosition()< 120) {
          auton = "Blue 3 ring";
        }
        else if (Brain.Screen.xPosition()> 250 && Brain.Screen.xPosition()< 480 && Brain.Screen.yPosition()< 180) {
          auton = "Bsig win pt";
        }
        else if (Brain.Screen.xPosition()> 250 && Brain.Screen.xPosition()< 480 && Brain.Screen.yPosition()< 240) {
          auton = "Blue goal";
        }
    }
     
      if (quadrant == 3) {
        if (Brain.Screen.xPosition()> 250 && Brain.Screen.xPosition()< 480 && Brain.Screen.yPosition()< 60) {
          auton = "Red 2 ring";
        }
        else if (Brain.Screen.xPosition()> 250 && Brain.Screen.xPosition()< 480 && Brain.Screen.yPosition()< 120) {
          auton = "Red 3 ring";
        }
        else if (Brain.Screen.xPosition()> 250 && Brain.Screen.xPosition()< 480 && Brain.Screen.yPosition()< 180) {
          auton = "Rsig win pt";
        }
        else if (Brain.Screen.xPosition()> 250 && Brain.Screen.xPosition()< 480 && Brain.Screen.yPosition()< 240) {
          auton = "Red goal";
        }
    }


    if (quadrant == 4) {
        if (Brain.Screen.xPosition()> 250 && Brain.Screen.xPosition()< 480 && Brain.Screen.yPosition()< 60) {
          auton = "Red 4 ring";
        }
        else if (Brain.Screen.xPosition()> 250 && Brain.Screen.xPosition()< 480 && Brain.Screen.yPosition()< 120) {
          auton = "Red 5 ring";
        }
        else if (Brain.Screen.xPosition()> 250 && Brain.Screen.xPosition()< 480 && Brain.Screen.yPosition()< 180) {
          auton = "Red win pt";
        }
        else if (Brain.Screen.xPosition()> 250 && Brain.Screen.xPosition()< 480 && Brain.Screen.yPosition()< 240) {
          auton = "Red 6 ring";
        }

    }

    Brain.Screen.setFillColor(transparent);
    Brain.Screen.setFont(mono12);
    Brain.Screen.printAt(90, 125, auton);

      wait(20, msec);
 
  }
}

void selectable() {
  graphics();
  touch();
}