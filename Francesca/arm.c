#pragma config(Sensor, S1,     Endofarm,       sensorTouch)
#pragma config(Sensor, S2,     Overshoot,      sensorTouch)
#pragma config(Sensor, S3,     Position1,      sensorTouch)
#pragma config(Motor,  motorA,          lift,          tmotorNXT, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	while(true)

	{
		if(SensorValue[S1] == 1)
		{
			motor[motorA] = 8;
		}

		if(SensorValue[S2] == 1)

			motor[motorA] = 0;

		if(SensorValue[S3] == 1)

			motor [motorA] = -10;

	}
}
