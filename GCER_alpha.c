//gcer beta
//ugh, here we go again
//help me pls

#include <kipr/botball.h>

const int cArm = 1;
const int cDown = 1700;
const int cUp =400;
const int cClaw = 0;
const int cOpen = 1400;
const int cClosed = 240; 
const int claw = 3;
const int open = 2012;
const int closed = 576;
const int arm = 0;

int z = 60;
int LMOTOR = 50;
int RMOTOR = 50;

void startUp()
{
    int done1 = 0;
    int done2 = 0;
    char ABC;
    while(done2==0)
    {
         done1 = 0;
    printf("1.Arm string down\n2.Botguy claw open\n3.Set up with button facing forward\nPress A to check straightnes, B to check light start, and C to win \n");
    
    while(ABC != 'A'  && ABC != 'C')
    {
        if(a_button()==1)
        {
            ABC='A';
            printf("I didn't give you consent to press my buttons you white male rapist\n");
            LMOTOR-=5;
        }
        if(c_button()==1)
        {
            ABC='C';
        }
    }
    
    switch(ABC)
    {
            case 'A':
            extra_buttons_show();
            msleep(10);
            printf("Press A to add 5 to left motor, B to add 5 to right motor, X to subtract 5 from left motor, Y to subtract 5 from right motor, C to test forward, Z to move on \n");  
            while(done1==0)
            {
                if(a_button()==1)
                {
                    z+=5;
                    printf(" %d \n\n", z);
                    msleep(500);
                }
                if(b_button()==1)
                {
                    RMOTOR+=1;
                    printf("LMOTOR: %d \n RMOTOR: %d \n\n", LMOTOR, RMOTOR);
                    msleep(500);
                }
                if(x_button()==1)
                {
                    LMOTOR-=1;
                    printf("LMOTOR: %d \n RMOTOR: %d \n\n", LMOTOR, RMOTOR);
                    msleep(500);
                }
                if(y_button()==1)
                {
                    z-=5;
                   printf(" %d \n\n", z);
                    msleep(500);
                }
                if(c_button()==1)
                {
                    while(get_create_lbump()==0 && get_create_rbump()==0)
                    {
                    create_drive_direct(LMOTOR, RMOTOR);
                    }
                    create_stop();
                }
                if(z_button()==1)
                {
                    done1=1;
                    ABC='N';
                }
                
                
            }
            break;
            
        case 'C':
        done2=1;    
           
        break;   
            
        default:
            printf("your code stinks \n");
    }
    }
    
}

void armdown() // will only work if arm is in up position 
{
    int pos = gmpc(1);
    
    while(gmpc(1) < pos+510)
    {
        mav(1,400);
    }
    freeze(1);
    msleep(100);
}

void armUp() // will only work if arm is in up position 
{
    int pos = gmpc(1);
    
    while(gmpc(1) > pos-30)
    {
        mav(0,1000);
        mav(1,-100);
    }
}

void ccw(int deg)
{
  set_create_normalized_angle(0);
  msleep(10);
  while(get_create_normalized_angle()<(deg * 0.3))
  {
    create_spin_CCW(200);
    msleep(10);
  }

}

void cw(int deg)
{
  printf("cw");
  set_create_normalized_angle(deg * 0.3);
  msleep(10);
  while(get_create_normalized_angle()>0)
  {
    create_spin_CW(200);
    msleep(10);
  }
}


void forward(int mm) //millimeters
{
    
  set_create_distance(0);
int x=0;    
  while(x<mm)
  {
      
      
   create_drive_straight(200);
      msleep(100);
      x=abs(get_create_distance());
      printf("%d \n \n", x);
  }
    create_stop();
    msleep(10);

}

void fast(int mm) //millimeters
{
    
  set_create_distance(0);
int x=0;    
  while(x<mm)
  {
      
      
   create_drive_straight(400);
      msleep(100);
      x=abs(get_create_distance());
      printf("%d \n \n", x);
  }
    create_stop();
    msleep(10);

}

void backward(int mm) //millimeters
{
    
  set_create_distance(0);
int x=0;    
  while(x<mm)
  {
      
      
   create_drive_straight(-200);
      msleep(100);
      x=abs(get_create_distance());
      printf("%d \n \n", x);
  }
    create_stop();
    msleep(10);

}

void depth()
{
  while(analog(0)>2000);
    {
    create_drive_direct(-750,-750);
    msleep(100);
    }
  while(analog(0)<2000);
    {
    create_drive_direct(-750,-750);
    msleep(100);
	}   
}

int main(){
    
    create_connect();
    msleep(10);
    create_full();
    msleep(10);
    startUp();
   
    enable_servos();
    msleep(10);
    set_servo_position(cArm,cUp);
    msleep(500);
    set_servo_position(cClaw,cClosed);
    msleep(500);
    set_servo_position(claw, open);
    msleep(500);
    
    //light start
    /*
    //wait_for_light(0);
    msleep(10);
        shut_down_in(119.5);
    msleep(20000);
   */
    
    //aligns against first wall near starting box
    backward(50);
    cw(15);
    backward(25);
    set_servo_position(cArm,cDown);
    msleep(500);
    ccw(190);
    //set_servo_position(cArm,cUp);
    //msleep(500);
    create_stop();
    create_drive_direct(-300,-300);
    msleep(4000);
    printf("yoi");
    
    //moves forward to get botguy
    forward(5);
     set_servo_position(cArm,cUp);
    msleep(500);
    
    //create_stop();
    fast(37);
    ccw(2);
    fast(100);
    create_stop();
    set_servo_position(cArm,cUp);
    msleep(500);
    cw(90);
    create_stop();
    create_drive_direct(-200,-200);
    msleep(2500);
    create_drive_direct(130,130);
    msleep(700);
    cw(85);
    create_stop();
   mav(1,500);
    msleep(2000);
    off(1);
    //set_servo_position(claw,closed);    for servo code
    //msleep(1000);  
    int pos = gmpc(claw);
    
    
    
    
    int tzme= seconds()+4;
    while(seconds()<tzme)
    {
        mav(claw,1500);
    }
    
    msleep(10);
    armUp();
    
    //moves to the side wall in the barn
    cw(10);
    backward(32);
    armUp();
    armUp();
     armUp();
    armUp();
    armUp();
   
    mav(arm,0);
    backward(40);
    cw(90);
    create_stop();
    create_drive_direct(-200,-200);
    msleep(5000);
    
    //goes to back wall in the barn
    forward(12);
    ccw(95);
    create_stop();
    create_drive_direct(-200,-200);
    msleep(4500);
    
   //cow pickup
    fast(17);
    cw(109);
    create_stop();
    set_servo_position(cClaw,cOpen);
    msleep(1000);
    set_servo_position(cArm,cDown);
    msleep(500);
    forward(36);
    create_stop();
    create_drive_direct(25,-25);
    msleep(500);
    create_stop();
    create_drive_direct(50,50);
    msleep(1100);
    create_stop();
    set_servo_position(cClaw,cClosed);  
    msleep(1000);
    set_servo_position(cArm,567);
    msleep(1500);
    
    
      //align against back wall again
    backward(9);
    create_stop();
    ccw(115);
    create_stop();
    create_drive_direct(-250,-250);
    msleep(1000);
    
    
    
    //get to the middle of the board
    fast(55);
    cw(90);
    create_drive_direct(-300,-300);
    msleep(2600);
    fast(58);
    ccw(106);
    
    create_stop();
    
    //go back to first side
    fast(80);
    create_stop();
    ccw(2);
    fast(30);
    ccw(215);
    create_stop();
    create_drive_direct(-300,-300);
    msleep(6000);
    
    //get in position for ramp acension
    cw(120);
    create_stop();
    forward(3);
    while(!(get_create_lbump() && get_create_rbump()))
    {
        create_drive_direct(200,200);
    }
    ccw(90);
    create_stop();
    create_drive_direct(-300,-300);
    msleep(500);
    forward(1);
    cw(1);
    
    
    
    
    
     while(!(get_create_lbump()))
    {
    create_drive_direct(300,300);
    }
    create_stop();
    mav(claw,-1000);
    msleep(1000);
    ccw(100);
     set_servo_position(cArm,cDown);
    msleep(500);
    set_servo_position(cClaw,cOpen);
    msleep(3000);
    
    return 0;
    
    
    
    
    
    
    
    
    /*
    //ramp
    create_drive_direct(1200,1200);
    msleep(800);
    
    int time = seconds()+5;
    while(seconds()<time){
        if(analog(5) < 3000){
            
            create_drive_direct(700,100);
            printf("I see white");
        }
        else{
           
            
            
             create_drive_direct(100,800);
          
            printf("I see black");
        }
    
    }
    
   // create_drive_direct(-100,100);
    //msleep(500);
    
    
if(analog(5) < 2500){
     while(analog(5)<2500){ 
         create_drive_direct(150,-150);
         create_stop();
         }
     
}
else
{
         
}
while(analog(5)>2500){ 
         create_drive_direct(-30,30);
         create_stop();
         }

    create_drive_direct(150,150);
    msleep(4000);
    create_stop();
   // msleep(500);
    
 
    while(analog(5)<2500)
    {
        create_drive_direct(100,-100);
    }
    
    int tyme = seconds() + 2;
    while(seconds()<tyme){
        if(analog(5) < 2000){
            
            create_drive_direct(240,75);
            printf("I see white");
        }
        else{
           
            
            
             create_drive_direct(75,240);
          
            printf("I see black");
        }
    
    }
    
      create_drive_direct(-150,-150);
    msleep(1300);
    create_stop();
    
    cw(10);
    create_stop();
    set_servo_position(cArm,cDown);
    msleep(500);
    set_servo_position(cClaw,cOpen);
    msleep(500);
    
    
     mav(claw,-1200);
    msleep(3000);
      
*/    
    return 0;
}


    
   





