#include <kipr/botball.h>
/*Created Jun 4, robot goes on Crater Rim */
//Motors and Servos:
#define lmotor 0
#define rmotor 2
#define flicker 0 //servo
#define front 1 //servo
#define back 2 //servo
#define end 3 //microservo
//Sensors:
#define tophat 0 //an
#define light 1 //an
#define button 0 //dig

void lineFollow()
{
  	printf("line follow ayy lmao\n");
	while(!(digital(0))) // im not sure about this implementation but honestly too tired to give a shit. test this later
	{
		if(analog(0) > 2000)
		{
			mav(lmotor, 730);
			mav(rmotor, 600);
			msleep(50);
		}
		
		else
		{
          	mav(lmotor, 650);
			mav(rmotor, 1000);
			msleep(50); // this can probably be faster
		}
	}
	printf("line follow donezo\n");
}

int main()
{
    wait_for_light(1);
    shut_down_in(115);
    enable_servos();
    //1) Grab Cubes
    /*set_servo_position(end, 300); //open grabbing part
  	msleep(100);
    set_servo_position(back, 300); //lower the lifting part
    msleep(700);
  	set_servo_position(end, 2000); //close grabbing part
  	set_servo_position(back, 1500); //raise the lifting part
    msleep(300);
  */set_servo_position(0, 2047);
  	set_servo_position(1, 1500);
    //2) Exit Starting Box
  	mav(lmotor, 1500);
  	mav(rmotor, 1500);
  	msleep(1950);
  
    printf("Get out\n");
    //3) Turn Towards Center of Field
	printf("Centerfold\n");
  	mav(lmotor, 1000);  
	mav(rmotor, -1000); // need to turn right edit values
	msleep(760);
    ao();
  	set_servo_position(front, 1850); //lower front part
  	msleep(300);
  
    //4) Align with Wall
    printf("...To the wall\n");
  	while(!(digital(button)))
    {
        mav(lmotor, 1200); //drive forwards until wall is hit
        mav(rmotor, 1200);
        msleep(700);
    }
    //5) Turn Towards Ramp
    printf("Turn\n");
  	mav(lmotor, -400); //drive backwards a little bit
    mav(rmotor, -400);
    msleep(600);
  
    mav(lmotor, -820);
	mav(rmotor, 850); // turn in front of our ramp
	msleep(820);
    
  	set_servo_position(1, 900);
  	msleep(300);	
  
  	mav(lmotor, 1000);  
	mav(rmotor, 1000); // drive up the ramp a little bit
  	msleep(2200);
  
  	set_servo_position(1, 1620);
    //6) Drive Up Ramp until Hits Edge
    printf("Up & up\n");
  	/*set_servo_position(front, 500); //raise front part a little bit (for some reason???)
    msleep(300);
  	while(!(digital(button)))
    {
        mav(lmotor, 600); //drive forwards until wall is hit
        mav(rmotor, 600);
        msleep(900);
    }*/
  	lineFollow();
    //
  	mav(lmotor, -300);
  	mav(rmotor, -300);
  	msleep(700);
  
	mav(lmotor, -500);
	mav(rmotor, 500);//turn left and check the solar array
  	while(analog(0) < 2000){msleep(10);}
  
  	mav(lmotor, -525);
  	mav(rmotor, -400);
  	msleep(500);
	
  	set_servo_position(1, 1645);
  	msleep(100);
  
  	mav(lmotor, 300);//push things
  	mav(rmotor, 305);
  	msleep(13000);
  
  	mav(lmotor, -100);
  	mav(rmotor, -100);
    	msleep(100);
  
	// spin arm to hit the thing
  	int i;
  	for(i=0; i < 3; i++)
    {
		set_servo_position(0, 2047);
  		msleep(600);
  		set_servo_position(0, 1066);
  		msleep(600);
    }
  
    ao();
    return 0;
}
