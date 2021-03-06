/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/

#include "commands/CmdCargoShoot.h"

#include "Robot.h"

CmdCargoShoot::CmdCargoShoot() {
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::m_subCargoGrab);
}

// Called just before this Command runs the first time
void CmdCargoShoot::Initialize() {
  // SetTimeout(4);  // set 4 second timeout
}

// Called repeatedly when this Command is scheduled to run
void CmdCargoShoot::Execute() { 
	if(!bumpSwitch->Get()){
		Robot::m_subCargoGrab.Shoot(Robot::m_subCargoGrab.m_dShootingSpeed, Robot::m_subCargoGrab.m_dShootingSpeed);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool CmdCargoShoot::IsFinished() {
  // return true || IsTimedOut();
  // Robot::m_subCargoGrab.Stop();
  return true;
}

// Called once after isFinished returns true
void CmdCargoShoot::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdCargoShoot::Interrupted() {}
