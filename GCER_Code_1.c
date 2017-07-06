#include <kipr/botball.h>
#include <math.h>
/*this is the right program to go up the ramp*/
int down_sync = 500;
int down_2 = 1900;
int up_0 = 1300;
int up_2 = 1100;
int up = 700;
const int LMOTOR=3;
const int GRABBER=0;
const int ELEVATOR=2;
const int RMOTOR=1;
const int LINEAR_SLIDE=0;
const int MAX_SLIDE_VAL=4060;
const int MIN_SLIDE_VAL=125;
void sync(double position, double rate, double wait); //syncronizes servos automatically; rate sets speed (1500 max); msleep wait is optional
void initialize();
void linefollow(int t);
// you are racist !!!

void orange()
{
 int i=0;
    for(i;i<20;i++)
    {
        
    }
}
int main()
{
    enable_servos();
    set_servo_position(1,1000);
    msleep(100);
   //setpwm(100);
    msleep(100);
    //note assuming the robot starts facing a direction so it does not have to turn
	mav(LMOTOR,-1500);
    mav(RMOTOR,1500);
    msleep(3000);
    
    //grabbing all of the poms
		ao();
    msleep(100);
    int t=seconds()+5;
    while(seconds() < t)
    {
        while(analog(5) > 3000)
        {
            mav(LMOTOR, -1500);
            mav(RMOTOR, 500);
            mav(GRABBER,-1200);
            msleep(10);
        }
        while(analog(5) < 3000)
        {
            mav(LMOTOR, -500);
            mav(RMOTOR, 1500);
            mav(GRABBER,-1200);
            msleep(10);
        }
    }
    mav(LMOTOR, -1500);
    mav(RMOTOR, 1500);
    msleep(500);
    ao();
    msleep(100);
    freeze(LMOTOR);
    msleep(100);
    freeze(RMOTOR);
    msleep(100);
    mav(GRABBER,-1200);
    msleep(3000);
    mav(LMOTOR, -1500);
    mav(RMOTOR, 600);
    msleep(800);
    t=seconds()+32;
        while(seconds() < t)
    {
        while(analog(5) > 3000)
        {
            //mav(LMOTOR, -125);
            mav(RMOTOR, 43);
            mav(GRABBER,-1200);
            msleep(10);
        }
		    ao();
            msleep(100);
        while(analog(5) < 3000)
        {
            mav(LMOTOR, -43);
            //mav(RMOTOR, 125);
            mav(GRABBER,-1200);
            msleep(10);
        }

    }
    ao();
    msleep(100);
    mav(GRABBER,-1500);
    msleep(15000);
    ao();
    msleep(100);
    upDown(MAX_SLIDE_VAL,1500);
    msleep(1000);
    ao();
    msleep(100);
    set_servo_position(1,494);
    msleep(1000);
    int i=0;
    for(i;i<105;i++)
    {
     set_servo_position(1,540);
        msleep(10);
        set_servo_position(1,494);
        msleep(10);
    }
    msleep(100);
    return 0;
}

void upDown(int endVal, int speed)
{
    while(analog(LINEAR_SLIDE)<endVal)
    {
     mav(ELEVATOR,speed);
      msleep(10);
    }
}
    
//line follows while trying to grab poms
void grab(int t)
{
	ao();
    msleep(100);
    while(seconds() < t)
    {
        while(analog(5) > 3000)
        {
            mav(LMOTOR, -1500);
            mav(RMOTOR, 500);
            mav(GRABBER,-900);
            msleep(10);
        }
        while(analog(5) < 3000)
        {
            mav(LMOTOR, -500);
            mav(RMOTOR, 1500);
            mav(GRABBER,-900);
            msleep(10);
        }
    }
}

void initialize() // initial setups
{
    //enable_servo();
}

//lmao no comments
void sync(double position, double rate , double wait)
{
    int count = 1;
    while (count < position)
    {
        set_servo_position(2, 1900 - position); //1900
        set_servo_position(3, 500 + position); //500
        count = count + 1;
        msleep(100 / rate);
    }
    msleep(wait);
}


