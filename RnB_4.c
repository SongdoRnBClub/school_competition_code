#pragma config(Sensor, in1,		 color1,				 sensorLineFollower)
#pragma config(Sensor, in2,		 color2,				 sensorLineFollower)
#pragma config(Sensor, in3,	 startbtn,			 sensorVexIQ_Touch)
//*!!Code automatically generated by 'ROBOTC' configuration wizard							 !!*//

#define LEFT port4
#define RIGHT port5
#define LEFT2 port6
#define RIGHT2 port7
#define rotate1 port2
//#define rotate2 port3

#define tapecolor 600
#define deg_rotate_time 1000//90deg rotate time
#define one_block_time 1500
#define speed 50

void turn_deg_right(int deg);
void turn_deg_left(int deg);
void start_competition();
void go_fr();
void go_rear();
void ball_isbig();

task brush(){
	for(;;){
					motor[rotate1]=127;
//					motor[rotate2]=127;
				 }
}
task ball(){
	for(;;){
		ball_isbig();
					}
}

task main()
{
	 start_competition();

	 startTask(brush);
	 startTask(ball);
	while(SensorValue(color2)<tapecolor)
	{
		go_fr();
	//	ball_isbig();
	}
	/*
	*
	*
	*make small robot
	*or cant do this
	*									*/


	/*turn_deg_left(90);//1st move
	while(SensorValue(color1)<tapecolor)
	{
		go_fr();
	}*/
	//turn_deg_right(90);//2nd move
	while(SensorValue(color2)<tapecolor)
	{
		go_rear();
	}
	turn_deg_left(90);
	clearTimer(T1);
	while(time1[T1]<300)
	{
	go_fr();
	}
	turn_deg_right(90);
	cleartimer(T1);
	while(SensorValue(color1)<tapecolor)
	{
	go_fr();
	}
	turn_deg_left(90);
	clearTimer(T1);
	while(SensorValue(color1)<tapecolor)
	{
	go_fr();
	}
	turn_deg_left(90);
	while(SensorValue(color1)<tapecolor)
	{
		go_fr();
	}
	turn_deg_right(90);
	clearTimer(T1);
	while(time1[T1]<500)
	{
		go_fr();
	}
}

void turn_deg_right(int deg)
{
	cleartimer(T1);
	int a=deg/90;
	while(time1[T1]<deg_rotate_time*a)
		{
		 motor[port4]=speed;
		 motor[port5]=-speed;
		 motor[port6]=speed;
		 motor[port7]=-speed;
		}
}
void turn_deg_left(int deg)
{
	cleartimer(T1);
	int a=deg/90;
	while(time1[T1]<deg_rotate_time*a)
		{
		 motor[port4]=-speed;
		 motor[port5]=speed;
		 motor[port6]=-speed;
		 motor[port7]=speed;
		}
}
void start_competition()
{
	for(;;)
		{
		while(SensorValue(startbtn) == 0)		// Loop while robot's bumper/touch sensor isn't pressed in
		{
		// Do nothing
		}
			if(SensorValue(startbtn) == 1)
			{
				break;
			}
	 }
}
void go_fr()
{
	for(;;)
	{
	motor[port4]=speed;
	motor[port5]=speed;
	motor[port6]=speed;
	motor[port7]=speed;
	}
}
void go_rear()
{
	for(;;)
	{
	motor[port4]=speed;
	motor[port5]=speed;
	motor[port6]=speed;
	motor[port7]=speed;
	}
}
void ball_isbig(){
if(sensorvalue(dist1)<80){
		motor[upbrush]=127;
		sleep(3000);
	}
}
