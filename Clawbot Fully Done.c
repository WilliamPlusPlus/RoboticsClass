#pragma config(Motor,  port1,           leftMotor,     tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port5,           clawMotor,     tmotorVex269, openLoop, reversed)
#pragma config(Motor,  port7,           armMotor,      tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port10,          rightMotor,    tmotorVex393, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*----------------------------------------------------------------------------------------------------*\
|*                                - Clawbot Single Joystick Control -                                 *|
|*                                      ROBOTC on VEX 2.0 Cortex                                      *|
|*                                                                                                    *|
|*  This program uses a single joystick, either right or left to drive the robot. Use notes below     *|
|*  to reconfigure which joystick is used. The joystick buttons are used to raise and lower the arm.	*|
|*  The joystick buttons are used to open and close the claw.																					*|
|*																																																		*|
|*                                        ROBOT CONFIGURATION                                         *|
|*    NOTES:                                                                                          *|
|*    1)	Ch1 is the X axis and Ch2 is the Y axis for the RIGHT joystick.                             *|
|*    2)	Ch3 is the Y axis and Ch4 is the X axis for the LEFT joystick.                              *|
|*		3)	Button 5U and 5L are on the front left side of the joystick.																*|
|*		3)	Button 6U and 6L are on the front right side of the joystick.																*|
|*                                                                                                    *|
|*    MOTORS & SENSORS:                                                                               *|
|*    [I/O Port]        [Name]          [Type]                               [Description]            *|
|*    Motor - Port 1   rightMotor    VEX 393 Motor                         Right drive motor          *|
|*    Motor - Port 5   clawMotor     VEX 393 Motor w/ Motor Controler 29   Claw motor                 *|
|*    Motor - Port 7   armMotor      VEX 393 Motor w/ Motor Controler 29   Arm motor                  *|
|*    Motor - Port 10  leftMotor     VEX 393 Motor                         Left drive motor           *|
\*----------------------------------------------------------------------------------------------------*/

//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main ()
{

float speedControl = 1;

	while(1 == 1)
	{
		motor[leftMotor]  = (vexRT[Ch2] *speedControl);  // (y + x)/2
		motor[rightMotor] = (vexRT[Ch3] * speedControl);   // (y - x)/2

// Raise, lower or do not move arm
		if(vexRT[Btn5U] == 1)       	//If button 5U is pressed...
		{
			motor[armMotor] = 127;    	//...raise the arm.
		}
		else if(vexRT[Btn5D] == 1)  	//Else, if button 5D is pressed...
		{
			motor[armMotor] = -127;   	//...lower the arm.
		}
		else                      		//Else (neither button is pressed)...
		{
			motor[armMotor] = 0;      	//...stop the arm.
		}

// Open, close or do not more claw
		if(vexRT[Btn6U] == 1)       	//If Button 6U is pressed...
		{
			motor[clawMotor] = 127;  		//...close the gripper.
		}
		else if(vexRT[Btn6D] == 1)  	//Else, if button 6D is pressed...
		{
			motor[clawMotor] = -127; 		//...open the gripper.
		}
		else                      		//Else (neither button is pressed)...
		{
			motor[clawMotor] = 0;    		//...stop the gripper.
		}

		if (vexRT(Btn8U) == 1) {
			speedControl = 0.2;
		} else {
		speedControl = 1;
	}

	if (vexRT(Btn8D) == 1) {
		speedControl = 0;
		} else {
			speedControl = 1;
		}
	}
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
