/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/ 

#include "OI.h"
#include <iostream>

OI::OI() {
    // Process operator interface input here.
  
    // Call switch gear command
    driverController_button_rbump->ToggleWhenPressed(new CmdSwitchGear());

    // Elevator testing
    //driverController_button_a->WhileActive(new CmdElevatorTestDown());
    //driverController_button_a->WhenReleased(new CmdElevatorTestStop());
    //driverController_button_y->WhileActive(new CmdElevatorTestUp());
    //driverController_button_y->WhenReleased(new CmdElevatorTestStop());
    // Maybe make a hold position on test if needed 

    // Reset elevator home position to zero.  Must be at the home position all the way down
    auxController_button_start->ToggleWhenPressed(new CmdElevatorResetHome());
  
    auxController_button_b->WhenPressed(new CmdCargoClampOpen());
    auxController_button_b->WhenReleased(new CmdCargoClampClose());

    //auxController_button_a->ToggleWhenPressed(new CmdCargoTilt());

  
    // Cargo intake shoot and stop
    cargoIntake->WhenActive(new CmdCargoIntake());
    cargoShoot->WhenActive(new CmdCargoShoot());
    cargoStop->WhenPressed( new CmdCargoStop());

    // Cargo tilt
    cargoTilt->WhenPressed(new CmdCargoTilt(true));
    cargoTilt->WhenReleased(new CmdCargoTilt(false));
  
    // Hatch grab and release
    auxController_button_lbump->WhenPressed(new CmdHatchRelease());
    auxController_button_lbump->WhenReleased(new CmdHatchGrab());
  

    // Hatch extend to deploy position while button is held return when released
    auxController_button_rbump->WhenPressed(new CmdHatchExt(2));
    auxController_button_rbump->WhenReleased(new CmdHatchExt(1));

    // Hatch return to home position
    auxController_button_x->ToggleWhenPressed(new CmdHatchExt(0));
  
    // Hatch extend to mid position
    auxController_button_y->ToggleWhenPressed(new CmdHatchExt(1));
  

    // Cargo extend to out position
    auxController_button_y->ToggleWhenPressed(new CmdCargoExtend(3));
 

    auxController_button_a->WhenPressed(new CmdCargoExtend(3));
    auxController_button_a->WhenReleased(new CmdCargoExtend(0));
  
}

// Checks controller triggers and presses internal button based on value 
void OI::PollController() {
// Cargo intake, shoot and stop
if(auxController->GetRawAxis(AXIS_R_TRIG) < 0.1 && auxController->GetRawAxis(AXIS_L_TRIG) < 0.1){
    cargoStop->SetPressed(true);
} 
else {
    cargoStop->SetPressed(false);
}
if( auxController->GetRawAxis(AXIS_R_TRIG) > 0.1 ){
        //std::cout << "R_trig = 1" << std::endl;
        cargoShoot->SetPressed(false);
        cargoIntake->SetPressed(true);
} 
else {
        cargoIntake->SetPressed(false);
        //std::cout << "R_trig = 0" << std::endl;
}


if( auxController->GetRawAxis(AXIS_L_TRIG) > 0.1){
        // Call Cargo Shoot Command
        cargoIntake->SetPressed(false);
        cargoShoot->SetPressed(true);
        //std::cout << "L_trig = 1" << std::endl;
} 
else {
        cargoShoot->SetPressed(false);
        //std::cout << "L_trig = 0" << std::endl;
}


    // Add more if statements
}
