#include <kipr/botball.h>

//! turnright FUNCTION REQUIRES NUMBER WITH ONE DECIMAL, EVEN .0

int m1=0; // represents motor in port 1
int m2=0;
int m3=0;
double val = 0;

const int red = 0;
const int green = 1;

#define L_wallaby 1 //Motor at left of wallaby
#define R_wallaby 2 //Motor at right of wallaby
#define F_wallaby 3 //Motor in front of wallaby
#define grabber 1 //grabber servo
#define claw 3 //claw servo
#define arm 2 //arm servo

void turnleft(double degrees);
void turnl(double dgrees);
void forward(double inches);
void forwardtick(double inches);
void ttpom(int color);
void open_claw();
void close_claw();
int choose();
void lf(int t);
void lfb(int t);
void up_claw();
void down_claw();
void up_new_claw();
void open_claw_new();
void turnright();
void backwards();
void lfleft(int inches);
void shake();

//! 90 degree turn:
//! USE DECIMAL POINTS FOR turnright FUNCTION

int main()
{
    //wait_for_light(___);   INITIALIZATION CODE
    shut_down_in(110);
    enable_servos();
    set_servo_position(1,450);//down back claw
    msleep(100);
    backwards(5.0);
    mav(1,0);
    mav(3,0);
    msleep(10);

    down_claw(); //FIRST POM
    msleep(1000);
    open_claw();
    msleep(500);
    forwardtick(10);
    mav(1,0);
    mav(3,0);
    msleep(10);
    close_claw();//first pom is grabbed
    msleep(1000);
    up_claw();
    msleep(1500);
    
    forwardtick(36);//FIRST POM PILE was two inches more
    down_claw();
    msleep(1500);
    open_claw_new(); // close_claw and open_claw functions cause program to not function
    msleep(500);
    lfleft(11);
    msleep(100);
    /*close_claw(); // closes claw
    msleep(300);
    up_new_claw(); */

    lf(2); //KEEP GOING FORWARD
    close_claw(); // closes claw
    msleep(300);
    up_new_claw();
    lf(17);
    msleep(100);

    up_new_claw(); //ALLIGNMENT
    turnleft(225);
    msleep(100);
    //turnleft(12);
    msleep(100);
    mav(2,1400);
    mav(3,-1400);
    msleep(3500);
    mav(2,-1000);
    mav(3,1000);
    msleep(1000);
    ao();
    //turnright(1.0);
    down_claw();
    msleep(1500);
    
    set_servo_position(1,1500);//up back claw GET THE BIN
    msleep(500);//backing up to grab bin
    mav(1,500);
    mav(3,-500);
    msleep(3500);
    set_servo_position(1,300);//down back claw
    msleep(1000);

    forwardtick(19);//DUMP THE FIRST PILE
    msleep(100);
    shake();
    msleep(1500);
    open_claw();
    msleep(300);
    close_claw();
    msleep(300);
    //down_claw();
    //open_claw();
    
    //turnleft(2);
    msleep(100); //ALLIGN
    mav(2,1400);
    mav(3,-1400);
    msleep(6000);
    mav(2,-1000);
    mav(3,1000);
    msleep(500);
    down_claw();
    open_claw();
    ao();
    
    //turnleft(10);
    forwardtick(13);//GET SECOND PILE
    close_claw();
    msleep(1000);
  
    backwards(10.0);

    shake();//DUMP SECOND PILE
    msleep(1500);
    open_claw();
    msleep(300);
    close_claw();
    msleep(300);
    //down_claw();
    open_claw();

    //turnleft(95);//GET THIRD PILE
    turnleft(120);
    backwards(7.0);
    mav(L_wallaby,-500);
    mav(R_wallaby,500);
    msleep(2800);
    freeze(R_wallaby);
    msleep(100);
    backwards(12.0);
    turnright(5.0);
    down_claw();
    msleep(1000);
    forwardtick(17);
    msleep(500);
    close_claw();
    msleep(1000);
    turnleft(10);
    
    shake();//DUMP THIRD PILE
    msleep(1500);
    open_claw();
    backwards(4.0);
    msleep(300);
    turnleft(3);
    down_claw();

    turnright(38.0); //GET FOURTH PILE
    forwardtick(18.0);
    close_claw();
    msleep(500);
    backwards(10.0);
    msleep(1000);
    open_claw();
    forwardtick(8.0);
    msleep(1000);
    close_claw();
    
    backwards(37.0); //DUMP FOURTH
    shake();
    msleep(1500);
    open_claw();

    backwards(5.0); //BACK TO STARTING BOX
    lfb(17);
    down_claw();
    msleep(1500);
    set_servo_position(1,960);//up back claw GET THE BIN
    msleep(1500);
    
    return 0;
}

void turnright(double d)// must be less than 90
{
    printf("entered turnright");
    cmpc(1); //clears motor tick counter for motor in port 1 (cmpc = clear_motor_position_counter)
    cmpc(2);
    cmpc(3);
    m1=0;
    m2=0;
    m3=0;

    printf("entered func turn \n");
    val=d*(-14.8);
    while(!(m1<d*(-14.8)))// while the motors have not reached there goal,
        //! while loop is used to stop program from continuing: adds more consistancy and control
    {
        if(m1<val)
        {
            printf("should be done");
        }
        /*mrp(2,1000,-1300); //make motor 1 move at 1000 speed with a tick goal of 1500 (mrp = move_relative_position)
         mrp(1,1000,-1300);
         mrp(3,1000,-1300);*/

        mav(1,-1000);
        mav(2,-1000);
        mav(3,-1000);
        msleep(10);
        
        m1= gmpc(1); //set motor in port 1 to current motor tick value (gmpc = get_motor_position_counter)
        m2= gmpc(2);
        m3= gmpc(3);
        
        printf("Final motor tick positions: Motor 1: %i, Motor 2: %i, Motor 3: %i \n",m1,m2,m3);
        printf("val is %f\n",d*(-14.8));
    }

    cmpc(1);
    cmpc(2);
    cmpc(3);
    
    freeze(1); //added to freeze motors to reduce drift
    freeze(2);
    freeze(3);

    printf("Final motor tick positions: Motor 1: %i, Motor 2: %i, Motor 3: %i ",m1,m2,m3);
    msleep(100);
}

void turnleft(double degrees) /*turns left*/
{
    cmpc(1); //clears motor tick counter for motor in port 1 (cmpc = clear_motor_position_counter)
    cmpc(2);
    cmpc(3);
    m1=0;
    m2=0;
    m3=0;

    printf("entered func turn \n");
    val=degrees*14.8;
    while((m1<degrees*14.8)&&(m2<degrees*14.8)&&(degrees*14.8))// while the motors have not reached there goal,
        //! while loop is used to stop program from continuing: adds more consistancy and control.
    {
        mrp(2,1000,1300); //make motor 1 move at 1000 speed with a tick goal of 1500 (mrp = move_relative_position)
        mrp(1,1000,1300);
        mrp(3,1000,1300);
        m1= gmpc(1); //set motor in port 1 to current motor tick value (gmpc = get_motor_position_counter)
        m2= gmpc(2);
        m3= gmpc(3);
    }

    cmpc(1);
    cmpc(2);
    cmpc(3);
    freeze(1); //added to freeze motors to reduce drift
    freeze(2);
    freeze(3);
    
    printf("Final motor tick positions: Motor 1: %i, Motor 2: %i, Motor 3: %i ",m1,m2,m3);
    msleep(100);
}

void forward(double inches)
{
    printf("entered func forward \n");
    cmpc(1);
    cmpc(2);
    cmpc(3);
    m1= gmpc(1); //set motor in port 1 to current motor tick value (gmpc = get_motor_position_counter)
    m2= gmpc(2);
    m3= gmpc(3);

    double val=inches*210;
    while((m1<val) && (m3<val))// while the motors have not reached there goal,
        //! while loop is used to stop program from continuing: adds more consistancy and control.
    {
        mrp(1,-1000,-1300);
        mrp(3,-1000,1300);
        mav(2,-50);
        m1= gmpc(1); //set motor in port 1 to current motor tick value (gmpc = get_motor_position_counter)
        m2= gmpc(2);
        m3= gmpc(3);
    }

    cmpc(1);
    cmpc(2);
    cmpc(3);
    freeze(1); //added to freeze motors to reduce drift
    freeze(2);
    freeze(3);
    printf("Final motor tick positions: Motor 1: %i, Motor 2: %i, Motor 3: %i ",m1,m2,m3);
}

void forwardtick(double inches)
{
    printf("entered func forward \n");
    cmpc(1);
    cmpc(2);
    cmpc(3);
    m1= gmpc(1); //set motor in port 1 to current motor tick value (gmpc = get_motor_position_counter)
    m2= gmpc(2);
    m3= gmpc(3);

    double val=(inches-4)*210;
  
    mav(1,0);
    mav(3,0);
    msleep(5);
    
    while((m1<val) && (m3<val))// while the motors have not reached there goal,
        //! while loop is used to stop program from continuing: adds more consistancy and control.
    {
        if(gmpc(1)>gmpc(3)) //left is 1
        {
            mrp(1,975,-1300);
            mrp(3,1000,1300);
        }
        else
        {
            mrp(1,1000,-1300);
            mrp(3,1300,1300);
        }

        m1= gmpc(1); //set motor in port 1 to current motor tick value (gmpc = get_motor_position_counter)
        m2= gmpc(2);
        m3= gmpc(3);
    }
    
    cmpc(1);
    cmpc(2);
    cmpc(3);
    freeze(1); //added to freeze motors to reduce drift
    freeze(2);
    freeze(3);
    printf("Final motor tick positions: Motor 1: %i, Motor 2: %i, Motor 3: %i ",m1,m2,m3);
}

void backwards(double inches)
{
    printf("entered func forward \n");
    cmpc(1);
    cmpc(2);
    cmpc(3);
    m1= gmpc(1); //set motor in port 1 to current motor tick value (gmpc = get_motor_position_counter)
    m2= gmpc(2);
    m3= gmpc(3);

    double val=(inches-4)*-210;

    mav(1,0);
    mav(3,0);
    msleep(5);

    while((m1>val) && (m3>val))// while the motors have not reached there goal,
        //! while loop is used to stop program from continuing: adds more consistancy and control.
    {
        if(gmpc(1)>gmpc(3)) //left is 1
        {
            mrp(1,975,1300);
            mrp(3,1000,-1300);
        }
        else
        {
            mrp(1,1000,1300);
            mrp(3,1300,-1300);
        }

        m1= gmpc(1); //set motor in port 1 to current motor tick value (gmpc = get_motor_position_counter)
        m2= gmpc(2);
        m3= gmpc(3);
    }
    
    cmpc(1);
    cmpc(2);
    cmpc(3);
    freeze(1); //added to freeze motors to reduce drift
    freeze(2);
    freeze(3);

    printf("Final motor tick positions: Motor 1: %i, Motor 2: %i, Motor 3: %i ",m1,m2,m3);
}

//deprecated camera code
//turn to pom untill it is in the middle
void ttpom(int color)
{
    int xchecl=0;
    camera_open();
    camera_update();
    mav(1,0);
    mav(2,0);
    mav(3,0);
    msleep(100);

    while(/*get_object_center(color,0).x<54 || get_object_center(color,0).x>74*/ get_object_center(color,0).x>145 && xchecl==0)
    {
        if( get_object_center(color,0).x<50)
        {
            xchecl=1;
        }

        camera_update();

        if(get_object_count(color)>0)
        {
            printf("see %d \n",color);
        }

        mav(1,-400);
        mav(2,-400);
        mav(3,-400);
        msleep(10);
        camera_update();
        printf("(%d)",get_object_center(color,0).x);
    }
    
    printf("see middle \n");
    int x = get_object_center(color,0).x;
    printf("%d",x);
    /*
     open_claw();
     forward(8);
     close_claw();
     */
}

//more deprecated camera code
int choose()
{
    if((get_object_center(red,0).y < get_object_center(green,0).y)||(get_object_center(green,0).y==-1))
    {
        printf("red. ");
        return red;
    }
    else
    {
        printf("green. ");
        return green;
    }
}

//linefollowing
void lf(int inches)
{
    int t=inches*0.4;
    int time=seconds()+t;
    
    while(seconds()<time)
    {
        if(analog(0)>2800/*a*/)
        {
            //printf("on black");
            //mav(R_wallaby, 1000);
            mav(R_wallaby, 800);
            mav(L_wallaby, -250);
            mav(F_wallaby, 1000);
            msleep(100);
        }
        else
        {
            //printf("not on black");
            // mav(R_wallaby, -1000);
            mav(R_wallaby, -800);
            mav(L_wallaby, -1000);
            mav(F_wallaby, 500);
            msleep(100);
        }
    }
    ao();
}

void lfleft(int inches)
{
    int t=inches*0.4;
    int time=seconds()+t;
    
    while(seconds()<time)
    {
        if(analog(0)>2800/*a*/)
        {
            //printf("on black");
            //mav(R_wallaby, 1000);
            mav(R_wallaby, 800);
            mav(L_wallaby, -250);
            mav(F_wallaby, 1000);
            msleep(100);
        }
        else
        {
            //printf("not on black");
            // mav(R_wallaby, -1000);
            mav(R_wallaby, -200);
            mav(L_wallaby, -400);
            mav(F_wallaby, 500);
            msleep(100);
        }
    }
    ao();
}

void lfb(int inches)
{
    printf("lfb \n");
    int t=inches*0.4;
    int time=seconds()+t;

    while(seconds()<time)
    {
        if(analog(3)>2800/*a*/)
        {
            //printf("on black");
            //mav(R_wallaby, 1000);
            mav(R_wallaby, -500);
            mav(L_wallaby, 250);
            mav(F_wallaby, -1000);
            msleep(100);
        }
        else
        {
            //printf("not on black");
            // mav(R_wallaby, -1000);
            mav(R_wallaby, 500);
            mav(L_wallaby, 1000);
            mav(F_wallaby, -500);
            msleep(100);
        }
    }
    ao();
}

void open_claw()
{
    set_servo_position(3,889-71);
    msleep(300);
}

void open_claw_new()
{
    set_servo_position(3,1200-71);
    msleep(300);
}

void close_claw()
{
    set_servo_position(3,2047);
    msleep(50);
}

void up_claw()
{
    set_servo_position(2,300);
    msleep(200);
}

void down_claw()
{
    set_servo_position(2,1750);
    msleep(200);
}

void up_new_claw()
{
    set_servo_position(2,1000);
    msleep(200);
}

//?!
void shake()
{
    int i;
    for(i = 0; i < 4; i++)
    {
      set_servo_position(2,300);
      msleep(500);
      set_servo_position(2,550);
      msleep(500);
    }
}
