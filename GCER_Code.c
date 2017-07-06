/*
The most recent version 4/1*/
#include <kipr/botball.h>
const int RMOTOR=0;
const int LMOTOR=2;
const int DOWN=1650;
const int ARM=1;
const int CLAW=0;
const int OPEN=1800;
const int UP=420;
const int CLOSED=1192;

void slow_set_servo_position(int port, int position)
{
  while(get_servo_position(port)<position)
  {
    set_servo_position(port,get_servo_position(port)+10);
    msleep(10);
  }
}

void depth()
{
  while(analog(0)>2000);
  {
  	create_drive_direct(-200,-200);
	msleep(100);
  }
  while(analog(0)<2000)
  {
	create_drive_direct(-200,-200);
    msleep(100);
  }
}

void grab()
{
	slow_set_servo_position(ARM,DOWN);
	msleep(100);
	set_servo_position(CLAW,CLOSED);
	msleep(100);//grabbing hay 1
	slow_set_servo_position(ARM,UP);
	msleep(100);
	set_servo_position(CLAW,OPEN);
}
int main()
{
	//initial servo movement
	enable_servos();
	msleep(100);
	slow_set_servo_position(ARM,DOWN);
	msleep(100);
	set_servo_position(CLAW,CLOSED);
	msleep(100);//grabbing hay 1
	slow_set_servo_position(ARM,UP);
	msleep(100);
	set_servo_position(CLAW,OPEN);
	
	create_connect();
	msleep(100);//create movement staarts
	
	create_drive_direct(500,500);//moving out of starting box
	msleep(1000);
	
	create_drive_direct(-500,500);//strightening to grab hay
	msleep(500);
	create_drive_direct(500,500);
	msleep(3000);
	
	create_drive_direct(-500,-500);//moving to hay
	msleep(5000);
	create_drive_direct(-1500,-500);
	msleep(1000);
	create_drive_direct(500,-500);
	msleep(1300);
	create_drive_direct(500,500);
	msleep(1000);
	create_drive_direct(-500,-500);
	msleep(700);
	create_drive_direct(-500,500);
	msleep(2000);
	
	//grabs the three hay
	int i=0;
	for(i;i<3;i++)
	{
		depth();
		create_drive_direct(0,0);
		msleep(100);
		grab();
		msleep(100);
	}
	
	//straighten 
	create_drive_direct(500,500);
	msleep(1000);
	
	create_drive_direct(-500,-500);
	msleep(1000);
	
	create_drive_direct(500,-500);
	msleep(2000);
	
	create_drive_direct(500,500);
	msleep(10000);
	return 0;
}