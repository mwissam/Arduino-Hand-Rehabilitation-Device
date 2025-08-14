#include "Arduino.h"
#include "Robojax_L298N_DC_motor.h"

// -- constructor 1 for single motor
Robojax_L298N_DC_motor::Robojax_L298N_DC_motor(int IN1,int IN2,int ENA)
{
    // -- pin settings
   _in1=IN1;
   _in2=IN2;
   _enA=ENA;
}

Robojax_L298N_DC_motor::Robojax_L298N_DC_motor(int IN1,int IN2,int ENA, boolean debug)
{
    // -- pin settings
   _in1 = IN1;
   _in2 = IN2;
   _enA = ENA;
   _debug = debug;
}

// -- constructor 2 for dual motor
Robojax_L298N_DC_motor::Robojax_L298N_DC_motor(int IN1,int IN2,int ENA,int IN3,int IN4,int ENB)
{
    // -- pin settings
   _in1=IN1;
   _in2=IN2;
   _enA=ENA;
   _in3=IN3;
   _in4=IN4;
   _enB=ENB;
   if( IN3 && IN4  && ENB)
   _dual = true;      
 
}

// -- constructor 2 for dual motor with debug
Robojax_L298N_DC_motor::Robojax_L298N_DC_motor(int IN1,int IN2,int ENA,int IN3,int IN4,int ENB,boolean debug)
{
    // -- pin settings
   _in1=IN1;
   _in2=IN2;
   _enA=ENA;
   _in3=IN3;
   _in4=IN4;
   _enB=ENB;
   _debug = debug;   
   if( IN3 && IN4  && ENB)
   _dual = true;     
 
}

// -- constructor 3 for triple motor
Robojax_L298N_DC_motor::Robojax_L298N_DC_motor(int IN1,int IN2,int ENA,int IN3,int IN4,int ENB,int IN5,int IN6,int ENC)
{
    // -- pin settings
   _in1=IN1;
   _in2=IN2;
   _enA=ENA;
   _in3=IN3;
   _in4=IN4;
   _enB=ENB;
   _in5=IN5;
   _in6=IN6;
   _enC=ENC;
   if( IN5 && IN6  && ENC)
   _dual = true;      
 
}

// -- constructor 3 for triple motor with debug
Robojax_L298N_DC_motor::Robojax_L298N_DC_motor(int IN1,int IN2,int ENA,int IN3,int IN4,int ENB,int IN5,int IN6,int ENC,boolean debug)
{
    // -- pin settings
   _in1=IN1;
   _in2=IN2;
   _enA=ENA;
   _in3=IN3;
   _in4=IN4;
   _enB=ENB;
   _in5=IN5;
   _in6=IN6;
   _enC=ENC;
   _debug = debug;   
   if( IN5 && IN6  && ENC)
   _dual = true;     
 
}

// -- constructor 4 for quadruple motor
Robojax_L298N_DC_motor::Robojax_L298N_DC_motor(int IN1,int IN2,int ENA,int IN3,int IN4,int ENB,int IN5,int IN6,int ENC,int IN7,int IN8,int END)
{
    // -- pin settings
   _in1=IN1;
   _in2=IN2;
   _enA=ENA;
   _in3=IN3;
   _in4=IN4;
   _enB=ENB;
   _in5=IN5;
   _in6=IN6;
   _enC=ENC;
   _in7=IN7;
   _in8=IN8;
   _enD=END;
   if( IN7 && IN8  && END)
   _dual = true;      
 
}

// -- constructor 4 for quadruple motor with debug
Robojax_L298N_DC_motor::Robojax_L298N_DC_motor(int IN1,int IN2,int ENA,int IN3,int IN4,int ENB,int IN5,int IN6,int ENC,int IN7,int IN8,int END,boolean debug)
{
    // -- pin settings
   _in1=IN1;
   _in2=IN2;
   _enA=ENA;
   _in3=IN3;
   _in4=IN4;
   _enB=ENB;
   _in5=IN5;
   _in6=IN6;
   _enC=ENC;
   _in7=IN7;
   _in8=IN8;
   _enD=END;
   _debug = debug;   
   if( IN7 && IN8  && END)
   _dual = true;     
 
}

// -- constructor 5 for quintuple motor
Robojax_L298N_DC_motor::Robojax_L298N_DC_motor(int IN1,int IN2,int ENA,int IN3,int IN4,int ENB,int IN5,int IN6,int ENC,int IN7,int IN8,int END,int IN9,int IN10,int ENE)
{
    // -- pin settings
   _in1=IN1;
   _in2=IN2;
   _enA=ENA;
   _in3=IN3;
   _in4=IN4;
   _enB=ENB;
   _in5=IN5;
   _in6=IN6;
   _enC=ENC;
   _in7=IN7;
   _in8=IN8;
   _enD=END;
   _in9=IN9;
   _in10=IN10;
   _enE=ENE;
   if( IN9 && IN10  && ENE)
   _dual = true;      
 
}

// -- constructor 5 for quintuple motor with debug
Robojax_L298N_DC_motor::Robojax_L298N_DC_motor(int IN1,int IN2,int ENA,int IN3,int IN4,int ENB,int IN5,int IN6,int ENC,int IN7,int IN8,int END,int IN9,int IN10,int ENE,boolean debug)
{
    // -- pin settings
   _in1=IN1;
   _in2=IN2;
   _enA=ENA;
   _in3=IN3;
   _in4=IN4;
   _enB=ENB;
   _in5=IN5;
   _in6=IN6;
   _enC=ENC;
   _in7=IN7;
   _in8=IN8;
   _enD=END;
   _in9=IN9;
   _in10=IN10;
   _enE=ENE;
   _debug = debug;   
   if( IN9 && IN10  && ENE)
   _dual = true;     
 
}

void Robojax_L298N_DC_motor::begin()
{
	pinMode(this->_in1, OUTPUT);
	pinMode(this->_in2, OUTPUT);
	pinMode(this->_enA, OUTPUT);	
	if(this->_debug)
	{
		Serial.println("Robojax.com L298N Motor Library");				
	}
  
      if(this->_dual)
	  {
		pinMode(this->_in3, OUTPUT);
		pinMode(this->_in4, OUTPUT);
		pinMode(this->_enB, OUTPUT);
			if(this->_debug)
			{				
				Serial.println("Dual Motor Demo");
			}		
		  
	  }else{
			if(this->_debug)
			{				
				Serial.println("Single Motor Demo");
			}		  
	  }

	if(this->_dual)
	  {
		pinMode(this->_in5, OUTPUT);
		pinMode(this->_in6, OUTPUT);
		pinMode(this->_enC, OUTPUT);
			if(this->_debug)
			{				
				Serial.println("Dual Motor Demo");
			}		
		  
	  }else{
			if(this->_debug)
			{				
				Serial.println("Single Motor Demo");
			}		  
	  }
	
	if(this->_dual)
	  {
		pinMode(this->_in7, OUTPUT);
		pinMode(this->_in8, OUTPUT);
		pinMode(this->_enD, OUTPUT);
			if(this->_debug)
			{				
				Serial.println("Dual Motor Demo");
			}		
		  
	  }else{
			if(this->_debug)
			{				
				Serial.println("Single Motor Demo");
			}		  
	  }
	if(this->_dual)
	  {
		pinMode(this->_in9, OUTPUT);
		pinMode(this->_in10, OUTPUT);
		pinMode(this->_enE, OUTPUT);
			if(this->_debug)
			{				
				Serial.println("Dual Motor Demo");
			}		
		  
	  }else{
			if(this->_debug)
			{				
				Serial.println("Single Motor Demo");
			}		  
	  }
}

// -- the rotate function
void Robojax_L298N_DC_motor::rotate(int motor, int value, int dir) {
	if(dir ==1){
		if(motor ==1)
		{
			digitalWrite(this->_enA, LOW);// see page 7 of datasheet. You must keep ENABLE pin low before applying changes to IN			
			digitalWrite(this->_in1, LOW);
			digitalWrite(this->_in2, HIGH);
			this->printDebug1(motor, this->_in1,LOW,this->_in2,HIGH, dir, value );					
		}
		else if(motor ==2)
		{
				digitalWrite(this->_enB, LOW);// see page 7 of datasheet. You must keep ENABLE pin low before applying changes to IN			
				digitalWrite(this->_in3, LOW);
				digitalWrite(this->_in4, HIGH);
			this->printDebug1(motor, this->_in3,LOW,this->_in4,HIGH, dir, value );					
		}
		else if(motor ==3){
				digitalWrite(this->_enC, LOW);// see page 7 of datasheet. You must keep ENABLE pin low before applying changes to IN				
				digitalWrite(this->_in5, LOW);
				digitalWrite(this->_in6, HIGH);	
			this->printDebug1(motor, this->_in5,LOW,this->_in6,HIGH, dir, value );					
		}
		else if(motor ==4){
				digitalWrite(this->_enD, LOW);// see page 7 of datasheet. You must keep ENABLE pin low before applying changes to IN				
				digitalWrite(this->_in7, LOW);
				digitalWrite(this->_in8, HIGH);	
			this->printDebug1(motor, this->_in7,LOW,this->_in8,HIGH, dir, value );					
		}
		else
		{
				digitalWrite(this->_enE, LOW);// see page 7 of datasheet. You must keep ENABLE pin low before applying changes to IN			
				digitalWrite(this->_in9, LOW);
				digitalWrite(this->_in10, HIGH);
			this->printDebug1(motor, this->_in9,LOW,this->_in10,HIGH, dir, value );					
		}
	}else{
		if(motor ==1)
		{
				digitalWrite(this->_enA, LOW);// see page 7 of datasheet. You must keep ENABLE pin low before applying changes to IN				
				digitalWrite(this->_in1, HIGH);
				digitalWrite(this->_in2, LOW);
			this->printDebug1(motor, this->_in1,HIGH,this->_in2,LOW, dir, value );					
		}
		else if(motor ==2)
		{
				digitalWrite(this->_enB, LOW);// see page 7 of datasheet. You must keep ENABLE pin low before applying changes to IN				
				digitalWrite(this->_in3, HIGH);
				digitalWrite(this->_in4, LOW);
			this->printDebug1(motor, this->_in3,HIGH,this->_in4,LOW, dir, value );					
		}
		else if(motor ==3){
				digitalWrite(this->_enC, LOW);// see page 7 of datasheet. You must keep ENABLE pin low before applying changes to IN				
				digitalWrite(this->_in5, HIGH);
				digitalWrite(this->_in6, LOW);	
			this->printDebug1(motor, this->_in5,HIGH,this->_in6,LOW, dir, value );					
		}
		else if(motor ==4){
				digitalWrite(this->_enD, LOW);// see page 7 of datasheet. You must keep ENABLE pin low before applying changes to IN				
				digitalWrite(this->_in7, HIGH);
				digitalWrite(this->_in8, LOW);	
			this->printDebug1(motor, this->_in7,HIGH,this->_in8,LOW, dir, value );					
		}
		else{
				digitalWrite(this->_enE, LOW);// see page 7 of datasheet. You must keep ENABLE pin low before applying changes to IN				
				digitalWrite(this->_in9, HIGH);
				digitalWrite(this->_in10, LOW);	
			this->printDebug1(motor, this->_in9,HIGH,this->_in10,LOW, dir, value );					
		}
	}

    int enPin;
		if(motor ==1)
		{
			enPin= this->_enA;
		}
		else if(motor ==2)		
		{
			enPin= this->_enB;
		}
		else if(motor ==3)		
		{
			enPin= this->_enC;
		}
		else if(motor ==4){
			enPin= this->_enD;
		}
		else{
			enPin= this->_enE;
		}
    if(value >=0 && value <=100 ){
		
		analogWrite(enPin, toPWM(value));
	}else{
			if(this->_debug)
			{
				Serial.print("***** Speed Value must be between 0 and 100");
			}			
	}
}//rotate

void Robojax_L298N_DC_motor::demo(int motor){
  //slowly speed up the motor to 100% in CCW
  			if(this->_debug)
			{
				Serial.print("**** Demo: Speeding Motor ");
				Serial.print(motor);
				Serial.println(" from 0% to 100%");				
			}
  for(int i=0; i <= 100; i++)
  {
   this->rotate(motor, i, 1);//CW direction
    delay(100);    
  }	
  delay(2000);
  			if(this->_debug)
			{
				Serial.print("**** Demo: Slowing Motor ");
				Serial.print(motor);
				Serial.println(" from 100% to 0%");				
			}  
  //slowly speed up the motor to 100% in CW
  for(int i=100; i >=0; i--)
  {
   this->rotate(motor, i, 2);//CCW direction
    delay(100);    
  }	
  delay(2000);
  this->brake(motor);
  			if(this->_debug)
			{
				Serial.print("**** Demo: Brake applied to Motor ");
				Serial.println(motor);
			}    
  delay(2000);  
  
  this->rotate(motor, 50, 2);
  			if(this->_debug)
			{
				Serial.print("**** Demo: Motor ");
				Serial.print(motor);
				Serial.print(" runs  at 50% in CW");				
			}    
  delay(3000);
  this->brake(motor);
  delay(2000);
 
  this->rotate(motor, 80, 1);
  			if(this->_debug)
			{
				Serial.print("**** Demo: Motor ");
				Serial.print(motor);
				Serial.print(" runs  at 80% in CCW");				
			}   
  delay(3000); 
  this->brake(motor);
  			if(this->_debug)
			{
				Serial.print("**** Demo: Brake applied to Motor ");
				Serial.println(motor);
			}     
  delay(2000);  
  
  this->rotate(motor, 20, 2);
  			if(this->_debug)
			{
				Serial.print("**** Demo: Motor ");
				Serial.print(motor);
				Serial.print(" runs  at 20% in CW");				
			}   
  delay(3000); 
  this->brake(motor);
  			if(this->_debug)
			{
				Serial.print("**** Demo: Brake applied to Motor ");
				Serial.println(motor);
			}     
  delay(2000); 	
}

void Robojax_L298N_DC_motor::brake(int motor){
	if(motor ==6)
	{	digitalWrite(this->_in9, LOW);
		digitalWrite(this->_in10, LOW);
		digitalWrite(this->_in7, LOW);
		digitalWrite(this->_in8, LOW);
		digitalWrite(this->_in5, LOW);
		digitalWrite(this->_in6, LOW);
		digitalWrite(this->_in3, LOW);
		digitalWrite(this->_in4, LOW);
		digitalWrite(this->_in1, LOW);
		digitalWrite(this->_in2, LOW);	
		digitalWrite(this->_enE, LOW);	
		digitalWrite(this->_enD, LOW);	
		digitalWrite(this->_enC, LOW);		
		digitalWrite(this->_enB, LOW);
		digitalWrite(this->_enA, LOW);
		if(this->_debug){
			Serial.println("**** All Motors Braked");
		}				
	}
	else if(motor ==5)
	{
		digitalWrite(this->_in9, LOW);
		digitalWrite(this->_in10, LOW);	
		digitalWrite(this->_enE, LOW);			
		if(this->_debug){
			Serial.println("Motor 5 Braked");
		}			
	}
	else if(motor ==4)
	{
		digitalWrite(this->_in7, LOW);
		digitalWrite(this->_in8, LOW);	
		digitalWrite(this->_enD, LOW);			
		if(this->_debug){
			Serial.println("Motor 4 Braked");
		}			
	}
	else if(motor ==3)
	{
		digitalWrite(this->_in5, LOW);
		digitalWrite(this->_in6, LOW);	
		digitalWrite(this->_enC, LOW);			
		if(this->_debug){
			Serial.println("Motor 3 Braked");
		}			
	}
	else if(motor ==2)
	{
		digitalWrite(this->_in3, LOW);
		digitalWrite(this->_in4, LOW);	
		digitalWrite(this->_enB, LOW);			
		if(this->_debug){
			Serial.println("Motor 2 Braked");
		}			
	}
	else{
		digitalWrite(this->_in1, LOW);
		digitalWrite(this->_in2, LOW);	
		digitalWrite(this->_enA, LOW);		
		if(this->_debug){
			Serial.println("Motor 1 Braked");
		}				
	}
}

int Robojax_L298N_DC_motor::toPWM(int v){
  return map(v, 0,100,0,255);
}

void Robojax_L298N_DC_motor::printDebug1(int motor, int p1, int v1, int p2, int v2, int dir, int speed)
{
			if(this->_debug)
			{
				if(dir ==1)
				{
					Serial.print("Motor ");
					Serial.print(motor);	
					Serial.print(" CW ");						
				}else{
					Serial.print("Motor ");
					Serial.print(motor);	
					Serial.print(" CCW ");						
				}
				Serial.print("at ");
				Serial.print(speed);				
				Serial.print("%");	
				
				Serial.print(" pin ");					
                Serial.print(p1);
				if(v1 ==1)
				{
					Serial.print(" HIGH ");					
				}else{
					Serial.print(" LOW ");						
				}			

				Serial.print(" pin ");					
                Serial.print(p2);
				if(v2 ==1)
				{
					Serial.println(" HIGH");					
				}else{
					Serial.println(" LOW");						
				}	
			}	
}

void Robojax_L298N_DC_motor::printDebug2(int motor1, int p1, int v1, int p2, int v2, int dir1, int speed1, int motor2, int p3, int v3, int p4, int v4, int dir2, int speed2)
{
			if(this->_debug)
			{
				if(dir1 ==1)
				{
					Serial.print("Motor ");
					Serial.print(motor1);	
					Serial.print(" CW ");					
				}else{
					Serial.print("Motor ");
					Serial.print(motor1);	
					Serial.print(" CCW ");						
				}
				Serial.print("at ");
				Serial.print(speed1);				
				Serial.print("%");	
				
				Serial.print(" pin ");					
                Serial.print(p1);
				if(v1 ==1)
				{
					Serial.print("HIGH");					
				}else{
					Serial.print("LOW");						
				}			

				Serial.print(" pin ");					
                Serial.print(p2);
				if(v2 ==1)
				{
					Serial.print("HIGH");					
				}else{
					Serial.println("LOW");						
				}	

				if(dir2 ==1)
				{
					Serial.print("Motor ");
					Serial.print(motor2);	
					Serial.print(" CW ");					
				}else{
					Serial.print("Motor ");
					Serial.print(motor2);	
					Serial.print(" CCW ");						
				}
				Serial.print("at ");
				Serial.print(speed2);				
				Serial.print("%");	
				
				Serial.print(" pin ");					
                Serial.print(p3);
				if(v3 ==1)
				{
					Serial.print("HIGH");					
				}else{
					Serial.print("LOW");						
				}			

				Serial.print(" pin ");					
                Serial.print(p4);
				if(v4 ==1)
				{
					Serial.print("HIGH");					
				}else{
					Serial.println("LOW");						
				}					
			}	
}