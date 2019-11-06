/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\gomezs                                           */
/*    Created:      Thu Oct 24 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
using namespace vex;

vex::motor LeftMotor (vex::PORT10, vex::gearSetting::ratio18_1, false);
vex::motor RightMotor (vex::PORT20, vex::gearSetting::ratio18_1, true);
vex::motor Intake1 (vex::PORT5, vex::gearSetting::ratio18_1, false);
vex::motor Intake2 (vex::PORT6, vex::gearSetting::ratio18_1, true);
vex::motor Lift (vex::PORT7, vex::gearSetting::ratio18_1, true);
limit fullTower = limit(Brain.ThreeWirePort.A); 
limit towerUp = limit(Brain.ThreeWirePort.B);
vex::controller Controller1 = vex::controller();

#include "robot-config.h" 
int main() {        
    Intake1.spin(directionType::fwd, 75, velocityUnits::pct);
    Intake2.spin(directionType::fwd, 75, velocityUnits::pct);

    while (true) {          
        LeftMotor.spin(directionType::fwd, (Controller1.Axis3.value() + Controller1.Axis1.value())/1, velocityUnits::pct); //(Axis3+Axis4)/2;
        RightMotor.spin(directionType::fwd, (Controller1.Axis3.value() - Controller1.Axis1.value())/1, velocityUnits::pct);//(Axis3-Axis4)/2;
        if(fullTower.pressing())
        {
          Intake1.stop();
          Intake2.stop();
        }
        else if(Controller1.ButtonA.pressing())
        {
          Intake1.stop();
          Intake2.stop();
        }

        if(Intake1.isSpinning())
        {
          if(Controller1.ButtonA.pressing())
          {
            Intake1.stop();
            Intake2.stop();
          }
        }
        else
        {
          if(Controller1.ButtonA.pressing())
          {
            Intake1.spin(directionType::fwd, 75, velocityUnits::pct);
            Intake2.spin(directionType::fwd, 75, velocityUnits::pct);
          }
        }

        if(Controller1.ButtonB.pressing())
        {
          Lift.startRotateTo(720, rotationUnits::deg, 50, velocityUnits::pct);
        }

        if(towerUp.pressing())
        {
          if(Controller1.ButtonB.pressing())
          {
            Lift.startRotateTo(-720, rotationUnits::deg, 50, velocityUnits::pct);
          }
        }
       task::sleep(10); 
    } 
    
}
