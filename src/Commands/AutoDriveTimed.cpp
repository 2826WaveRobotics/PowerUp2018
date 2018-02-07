// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.



#include "AutoDriveTimed.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

AutoDriveTimed::AutoDriveTimed(double power, double heading, double timeout) : frc::TimedCommand(timeout) {
    // Use requires() here to declare subsystem dependencies
    // eg. requires(Robot::chassis.get());
	Requires(Robot::drivePID.get());

	m_power = power;
	m_heading = heading;
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void AutoDriveTimed::Initialize() {
	Robot::drivePID->SetPIDs(c_straightP, c_straightI, c_straightD);
}

// Called repeatedly when this Command is scheduled to run
void AutoDriveTimed::Execute() {
	Robot::drivePID->DriveStraight(m_power, m_heading);
}

// Called once after command times out
void AutoDriveTimed::End() {
	Robot::drivePID->ArcadeDrive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoDriveTimed::Interrupted() {

}
