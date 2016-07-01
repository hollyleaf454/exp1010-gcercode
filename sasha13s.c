#include <kipr/botball.h>
const int TOPHATL=1;
const int TOPHATR=0;


void plugin(int ticks1,int tick2)
{
  printf("function");
  cmpc(3);
  cmpc(1);

  int m1= gmpc(3); //set motor in port 1 to current motor tick value (gmpc = get_motor_position_counter)
  int m2= gmpc(1);
  
  
   mav(1,1500);
   mav(3,1500);
   msleep(10);
   m1= gmpc(3); //set motor in port 1 to current motor tick value (gmpc = get_motor_position_counter)
   m2= gmpc(1);
	while((m1<ticks1) && (m2<tick2))// while the motors have not reached there goal,
	//! while loop is used to stop program from continuing: adds more consistancy and control.
	{
		if(m1>m2) //left is 1
        {
          printf("1");
          mav(3,1475);
          mav(1,1500);
		  
        }//1 is right
		else if(m2>m1)
		{
          printf("2");
			mav(3,1500);
			mav(1,1475);
			
		}
		else
		{
          printf("3");
			mav(3,1500);
			mav(1,1500);
			
		}
      	m1= gmpc(3); //set motor in port 1 to current motor tick value (gmpc = get_motor_position_counter)
		m2= gmpc(1);
		printf("M1:%d M2:%d\n",m1,m2);
     }
	 }
	 
	 void lineFollow(int time)
     {
      int time2=0;
       while(time2<time)
       {
      while(analog(TOPHATL)>3000&&analog(TOPHATR)<3000)
      {
        //1 is right 3 is left
        mav(1,1000);
        mav(3,2000);
        msleep(100);
        time2 = time2 + 100;
      }
      while(analog(TOPHATR)>3000&&analog(TOPHATL)<3000)
      {
		mav(3,1000);
        mav(1,2000);
        msleep(100);
        time2 = time2 + 100;
      }
      while(analog(TOPHATR)>3000&&analog(TOPHATL)>3000)
      {
		mav(3,2000);
        mav(1,2000);
        msleep(100);
        time2 = time2 + 100;
      }
       
       }
     }
	 int main()
	 {
       	wait_for_light(3);
        shut_down_in(118);
        msleep(500);
		plugin(2000,2000);
        msleep(600);
		mav(1,2000);
       	mav(3,0);
        msleep(200);
        plugin(2000,2000);
        msleep(1000);
       	mav(1,2000);
       	mav(3,0);
        msleep(200);
       	plugin(1300,1300);
        msleep(1300);
       
      
         lineFollow(2000);
       
       msleep(500);
       plugin(500,500);
       msleep(100);
       mav(1,1500);
       	mav(3,0);
        msleep(700);
        plugin(1900,1900);
        msleep(1000);
       	int x=seconds()+6;
        while(seconds()<x)
        {
         mav(1,-1500);
         mav(3,1500);
         msleep(100);
         plugin(500,500);
         msleep(100);
         mav(1,-1500);
         mav(3,-1500);
         msleep(100);
        }
       msleep(100);
       //plugin(3000,3000);
       //msleep(3000);
       //msleep(100);
       mav(3,-1500);
       mav(1,-1500);
       msleep(2000);
       mav(3,-1500);
       mav(1,1500);
       msleep(1000);
       plugin(5000,5000);
       msleep(7000);
        x=seconds()+6;
        while(seconds()<x)
        {
         mav(1,1500);
         mav(3,-1500);
         msleep(100);
         plugin(500,500);
         msleep(100);
         mav(1,-1500);
         mav(3,-1500);
         msleep(100);
        }
        x=seconds()+6;
        while(seconds()<x)
        {
         mav(1,-1500);
         mav(3,1500);
         msleep(100);
         plugin(500,500);
         msleep(100);
         mav(1,-1500);
         mav(3,-1500);
         msleep(100);
        }
       	return 0;
	 }
