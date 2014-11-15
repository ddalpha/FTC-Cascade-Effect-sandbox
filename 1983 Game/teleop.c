#pragma config(Hubs,  S1, HTServo,  HTMotor,  HTMotor,  none)
#pragma config(Hubs,  S2, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Sensor, S3,     touchsensor,    sensorTouch)
#pragma config(Motor,  mtr_S1_C2_1,     belt,          tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motorE,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     leftFront,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     leftBack,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_1,     arm1,          tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_2,     arm2,          tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C2_1,     rightFront,    tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S2_C2_2,     rightBack,     tmotorTetrix, openLoop, reversed)
#pragma config(Servo,  srvo_S1_C1_1,    servo1,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
* teleop.c proivdes autonouse control of the robot.  It should NEVER reference
* any motors, sensors, or joystics directly.  Rather, it should call functions in
* drivebase.c, arm.c, and OI.c
*
* TO-DOs
*   o When you accomplish a task below, change the first character from 'o' to 'x'
*   o Replace joystick.joy1_y1 and joystick.joy1_y2 with calls to OI.c's,
*     tankDriveLeftThrottle(), tankDriveRightThrottle()
*   o Replace the joy1Btn calls with calls to OI.c's, isTankMode()
*   o Replace the joy1Btn calls with calls to OI.c's, isMecanumMode()
*/
#include "arm.c"
#include "JoystickDriver.c"
#include "drivebase.c"
#include "OI.c"
#include "latch.c"
#include "belt.c"

task main()
{
	while (true)
	{
		getJoystickSettings(joystick);

		if (OI_is_in_tank_drive(joystick)) //driving
		{
			tankdrive (joystick.joy1_y2, joystick.joy1_y1); //this should be OI_get_right_throttle and the likes, but when I do that, it throws errors
		}
		if (OI_is_in_translate_drive(joystick))
		{
			translatedrive (joystick.joy1_x1); //end driving
		}

	if (OI_should_open_latch(joystick)) //latch control
		{
			latch_open();
		}
		else if (OI_should_close_latch(joystick))
		{
			latch_close();
		}
		if (OI_should_move_belt(joystick))
		{
			belt_move();
		}
		if (OI_should_move_arm(joystick))
		{
			arm_move();
		}

	}
}
