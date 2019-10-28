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

vex::motor LeftMotor(vex::PORT10, vex::gearSetting::ratio18_1, false);
vex::motor RightMotor (vex::PORT20, vex::gearSetting::ratio18_1, true);
vex::controller Controller1 = vex::controller();

#include "robot-config.h" 
int main() {        

    while (true) {          
        LeftMotor.spin(directionType::fwd, (Controller1.Axis3.value() + Controller1.Axis1.value())/2, velocityUnits::pct); //(Axis3+Axis4)/2;
        RightMotor.spin(directionType::fwd, (Controller1.Axis3.value() - Controller1.Axis1.value())/2, velocityUnits::pct);//(Axis3-Axis4)/2;

       task::sleep(10); 
    } 
    
}
