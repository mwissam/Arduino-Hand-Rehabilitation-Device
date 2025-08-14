#ifndef Robojax_L298N_DC_motor_H
#define Robojax_L298N_DC_motor_H

#include "Arduino.h"

class Robojax_L298N_DC_motor
{
public:
    Robojax_L298N_DC_motor(int IN1,int IN2,int ENA);
    Robojax_L298N_DC_motor(int IN1,int IN2,int ENA, boolean debug);	
	
    Robojax_L298N_DC_motor(int IN1,int IN2,int ENA,int IN3,int IN4,int ENB);	
    Robojax_L298N_DC_motor(int IN1,int IN2,int ENA,int IN3,int IN4,int ENB, boolean debug);	
	
    Robojax_L298N_DC_motor(int IN1,int IN2,int ENA,int IN3,int IN4,int ENB,int IN5,int IN6,int ENC);	
    Robojax_L298N_DC_motor(int IN1,int IN2,int ENA,int IN3,int IN4,int ENB,int IN5,int IN6,int ENC, boolean debug);

    Robojax_L298N_DC_motor(int IN1,int IN2,int ENA,int IN3,int IN4,int ENB,int IN5,int IN6,int ENC,int IN7,int IN8,int END);	
    Robojax_L298N_DC_motor(int IN1,int IN2,int ENA,int IN3,int IN4,int ENB,int IN5,int IN6,int ENC,int IN7,int IN8,int END, boolean debug);

    Robojax_L298N_DC_motor(int IN1,int IN2,int ENA,int IN3,int IN4,int ENB,int IN5,int IN6,int ENC,int IN7,int IN8,int END,int IN9,int IN10,int ENE);	
    Robojax_L298N_DC_motor(int IN1,int IN2,int ENA,int IN3,int IN4,int ENB,int IN5,int IN6,int ENC,int IN7,int IN8,int END,int IN9,int IN10,int ENE, boolean debug);
    
    void rotate(int motor, int value, int dir);
    void begin();
    void brake(int motor);
    void demo(int motor);
	
private:
    void printDebug1(int motor, int p1, int v1, int p2, int v2, int dir, int speed);
    void printDebug2(int motor1, int p1, int v1, int p2, int v2, int dir1, int speed1, int motor2, int p3, int v3, int p4, int v4, int dir2, int speed2) ;
    
    int _in1, _in2, _enA, _in3, _in4,  _enB, _in5, _in6,  _enC, _in7, _in8,  _enD, _in9, _in10,  _enE;
    boolean _debug = false;
    boolean _dual;
 
    int toPWM(int v);   
};

#endif