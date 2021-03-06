/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/

#include "commands/GrabHatch.h"

#include "Robot.h"

GrabHatch::GrabHatch() {
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::m_subsystem);
}

// Called just before this Command runs the first time
void GrabHatch::Initialize() {
  // SetTimeout(4);  // set 4 second timeout
}

// Called repeatedly when this Command is scheduled to run
void GrabHatch::Execute() {
  bool state;
  state = Robot::m_subHatchGrab.GetHatchPos();
  state = !state;
  Robot::m_subHatchGrab.Set(state);
}

// Make this return true when this Command no longer needs to run execute()
bool GrabHatch::IsFinished() {
  // return true || IsTimedOut();
  return true;
}

// Called once after isFinished returns true
void GrabHatch::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GrabHatch::Interrupted() {}
