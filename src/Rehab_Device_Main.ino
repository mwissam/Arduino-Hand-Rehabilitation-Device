#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <Robojax_L298N_DC_motor.h>

#define ST_DISPLAY_MAINMENU 0
#define ST_WAIT 1
#define ST_SETLEVEL 2
#define ST_SETLEVEL2 3
#define ST_SETLEVEL3 4
#define ST_SETLEVEL4 5
#define ST_SETLEVEL5 6

// motor 1 settings
#define IN1 40
#define IN2 28
#define ENA 8 // ~this pin must be PWM enabled pin

// motor 2 settings
#define IN3 36
#define IN4 34
#define ENB 9 // ~this pin must be PWM enabled pin

// motor 3 settings
#define IN5 32
#define IN6 30
#define ENC 10 // ~this pin must be PWM enabled pin

// motor 4 settings
#define IN7 28
#define IN8 26
#define END 11 // ~this pin must be PWM enabled pin

// motor 5 settings
#define IN9 26
#define IN10 24
#define ENE 12// ~this pin must be PWM enabled pin

const int CCW = 2; // Clockwise
const int CW = 1; // Counterclockwise

#define motor1 1// do not change
#define motor2 2// do not change
#define motor3 3// do not change
#define motor4 4// do not change
#define motor5 5// do not change

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {45, 43, 41, 39}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {37, 35, 33, 31}; //connect to the column pinouts of the keypad
// initialize the library with the numbers of the interface pins
LiquidCrystal_I2C lcd(0x3F, 20, 4);

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
Robojax_L298N_DC_motor motor(IN1, IN2, ENA,IN3, IN4, ENB,IN5, IN6, ENC,IN7, IN8, END,IN9, IN10, ENE, true);
// the state of our application; start with main menu display
byte currentState = ST_DISPLAY_MAINMENU;

// The direction of the motors
int motor1Direction=CW; //Clockwise
int motor1revDirection =CCW; //Counterclockwise

int motor2Direction=CW; //Clockwise
int motor2revDirection =CCW; //Counterclockwise

int motor3Direction=CW; //Clockwise
int motor3revDirection =CCW; //Counterclockwise

int motor4Direction=CW; //Clockwise
int motor4revDirection =CCW; //Counterclockwise

int motor5Direction=CW; //Clockwise
int motor5revDirection =CCW; //Counterclockwise

const int motor1switch1 = 40;// limit switch for direction change
const int motor1switch2 = 42;// limit switch for direction change
const int motor2switch1 = 44;// limit switch for direction change
const int motor2switch2 = 46;// limit switch for direction change
const int motor3switch1 = 48;// limit switch for direction change
const int motor3switch2 = 50;// limit switch for direction change
const int motor4switch1 = 52;// limit switch for direction change
const int motor4switch2 = 53;// limit switch for direction change
const int motor5switch1 = 51;// limit switch for direction change
const int motor5switch2 = 49;// limit switch for direction change

int motorDuration = 0;
int motorLevel = 0;
int prevMotorLevel = 0;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(20, 4);
  Serial.begin(9600);

  //Limit Switch 1 and 2 for the motor 1
  pinMode(motor1switch1, INPUT_PULLUP);
  pinMode(motor1switch2, INPUT_PULLUP);

  //Limit Switch 1 and 2 for the motor 2
  pinMode(motor2switch1, INPUT_PULLUP);
  pinMode(motor2switch2, INPUT_PULLUP);

  //Limit Switch 1 and 2 for the motor 3
  pinMode(motor3switch1, INPUT_PULLUP);
  pinMode(motor3switch2, INPUT_PULLUP);

  //Limit Switch 1 and 2 for the motor 4
  pinMode(motor4switch1, INPUT_PULLUP);
  pinMode(motor4switch2, INPUT_PULLUP);

  //Limit Switch 1 and 2 for the motor 5
  pinMode(motor5switch1, INPUT_PULLUP);
  pinMode(motor5switch2, INPUT_PULLUP);

  motor.begin();
}

void loop() {
  updateState1();
  char key = keypad.getKey();
  switch (currentState)
  {
    case ST_DISPLAY_MAINMENU:
      // display title
      displayTitle();
      // switch to wait state
      currentState = ST_WAIT;
      break;
    case ST_WAIT:
      // if motor 1 setting selected
      if (key == '1')
      {
        Serial.print("Key: "); Serial.println(key);
        lcd.clear();
        lcd.setCursor(0, 1);
        lcd.print("Motor 1");
        if (motorLevel < prevMotorLevel) {
          motor1Direction = CCW;
        }
        else {
          motor1Direction = CW;
        }
        prevMotorLevel = motorLevel;
        // switch to ST_SETLEVEL state
        currentState = ST_SETLEVEL;
      }

      // if motor 2 setting selected
      if (key == '2')
      {
        Serial.print("Key: "); Serial.println(key);
        lcd.clear();
        lcd.setCursor(0, 1);
        lcd.print("Motor 2");
        if (motorLevel < prevMotorLevel) {
          motor2Direction = CCW;
        }
        else {
          motor2Direction = CW;
        }
        prevMotorLevel = motorLevel;
        // switch to ST_SETLEVEL2 state
        currentState = ST_SETLEVEL2;
      }
      // if motor 3 setting selected
      if (key == '3')
      {
        Serial.print("Key: "); Serial.println(key);
        lcd.clear();
        lcd.setCursor(0, 1);
        lcd.print("Motor 3");
        if (motorLevel < prevMotorLevel) {
          motor3Direction = CCW;
        }
        else {
          motor3Direction = CW;
        }
        prevMotorLevel = motorLevel;
        // switch to ST_SETLEVEL3 state
        currentState = ST_SETLEVEL3;
      }
      // if motor 4 setting selected
      if (key == '4')
      {
        Serial.print("Key: "); Serial.println(key);
        lcd.clear();
        lcd.setCursor(0, 1);
        lcd.print("Motor 4");
        if (motorLevel < prevMotorLevel) {
          motor4Direction = CCW;
        }
        else {
          motor4Direction = CW;
        }
        prevMotorLevel = motorLevel;
        // switch to ST_SETLEVEL4 state
        currentState = ST_SETLEVEL4;
      }
      // if motor 5 setting selected
      if (key == '5')
      {
        Serial.print("Key: "); Serial.println(key);
        lcd.clear();
        lcd.setCursor(0, 1);
        lcd.print("Motor 5");
        if (motorLevel < prevMotorLevel) {
          motor5Direction = CCW;
        }
        else {
          motor5Direction = CW;
        }
        prevMotorLevel = motorLevel;
        // switch to ST_SETLEVEL5 state
        currentState = ST_SETLEVEL5;
      }
      break;
    case ST_SETLEVEL:
      switch (key) {
        case '1':
          motorLevel = 1;
          lcd.setCursor(0, 1);
          lcd.print("Motor 1 ");
          lcd.print(" Level 1 ");
          motor.rotate(motor1, 100, motor1Direction); //run motor1 at 100% speed in CW direction
          delay(motorDuration);
          Serial.println(motorDuration);
          Serial.println(motorLevel);
          Serial.println(prevMotorLevel);
          motor.brake(1);
          currentState = ST_DISPLAY_MAINMENU;
          if (motorLevel > 0) {
            // Calculate the duration based on the motor level
            if (motorLevel > prevMotorLevel) {
              motorDuration = (motorLevel - prevMotorLevel) * 6 * 1000;
            } else {
              motorDuration = abs(motorLevel - prevMotorLevel) * 6 * 1000;
            }
          }
          break;
        case '2':
          motorLevel = 2;
          lcd.setCursor(0, 1);
          lcd.print("Motor 1 ");
          lcd.print(" Level 2 ");
          motor.rotate(motor1, 100, motor1Direction);
          delay(motorDuration);
          Serial.println(motorDuration);
          Serial.println(motorLevel);
          Serial.println(prevMotorLevel);
          motor.brake(1);
          currentState = ST_DISPLAY_MAINMENU;
          if (motorLevel > 0) {
            // Calculate the duration based on the motor level
            if (motorLevel > prevMotorLevel) {
              motorDuration = (motorLevel - prevMotorLevel) * 6 * 1000;
            } else {
              motorDuration = abs(motorLevel - prevMotorLevel) * 6 * 1000;
            }
          }
          break;
        case '3':
          motorLevel = 3;
          lcd.setCursor(0, 1);
          lcd.print("Motor 1 ");
          lcd.print(" Level 3 ");
          motor.rotate(motor1, 100, motor1Direction);
          delay(motorDuration);
          Serial.println(motorDuration);
          Serial.println(motorLevel);
          Serial.println(prevMotorLevel);
          motor.brake(1);
          currentState = ST_DISPLAY_MAINMENU;
          if (motorLevel > 0) {
            // Calculate the duration based on the motor level
            if (motorLevel > prevMotorLevel) {
              motorDuration = (motorLevel - prevMotorLevel) * 6 * 1000;
            } else {
              motorDuration = abs(motorLevel - prevMotorLevel) * 6 * 1000;
            }
          }
          break;
        case '4':
          motorLevel = 4;
          lcd.setCursor(0, 1);
          lcd.print("Motor 1 ");
          lcd.print(" Level 4 ");
          motor.rotate(motor1, 100, motor1Direction);
          delay(motorDuration);
          Serial.println(motorDuration);
          Serial.println(motorLevel);
          Serial.println(prevMotorLevel);
          motor.brake(1);
          currentState = ST_DISPLAY_MAINMENU;
          if (motorLevel > 0) {
            // Calculate the duration based on the motor level
            if (motorLevel > prevMotorLevel) {
              motorDuration = (motorLevel - prevMotorLevel) * 6 * 1000;
            } else {
              motorDuration = abs(motorLevel - prevMotorLevel) * 6 * 1000;
            }
          }
          break;
        case '5':
          motorLevel = 5;
          lcd.setCursor(0, 1);
          lcd.print("Motor 1 ");
          lcd.print(" Level 5 ");
          motor.rotate(motor1, 100, motor1Direction);
          delay(motorDuration);
          Serial.println(motorDuration);
          Serial.println(motorLevel);
          Serial.println(prevMotorLevel);
          motor.brake(1);
          currentState = ST_DISPLAY_MAINMENU;
          if (motorLevel > 0) {
            // Calculate the duration based on the motor level
            if (motorLevel > prevMotorLevel) {
              motorDuration = (motorLevel - prevMotorLevel) * 6 * 1000;
            } else {
              motorDuration = abs(motorLevel - prevMotorLevel) * 6 * 1000;
            }
          }
          break;
        default:
          lcd.setCursor(0, 1);
          lcd.print("Motor 1 ");
          lcd.print(" Level 0 ");
          break;
      }
      break;
    case ST_SETLEVEL2:
      switch (key) {
        case '1':
          motorLevel = 1;
          lcd.setCursor(0, 1);
          lcd.print("Motor 2 ");
          lcd.print(" Level 1 ");
          motor.rotate(motor2, 100, motor2Direction);
          delay(motorDuration);
          Serial.println(motorDuration);
          Serial.println(motorLevel);
          Serial.println(prevMotorLevel);
          motor.brake(2);
          currentState = ST_DISPLAY_MAINMENU;
          if (motorLevel > 0) {
            // Calculate the duration based on the motor level
            if (motorLevel > prevMotorLevel) {
              motorDuration = (motorLevel - prevMotorLevel) * 6 * 1000;
            } else {
              motorDuration = abs(motorLevel - prevMotorLevel) * 6 * 1000;
            }
          }
          break;
        case '2':
          motorLevel = 2;
          lcd.setCursor(0, 1);
          lcd.print("Motor 2 ");
          lcd.print(" Level 2 ");
          motor.rotate(motor2, 100, motor2Direction);
          delay(motorDuration);
          Serial.println(motorDuration);
          Serial.println(motorLevel);
          Serial.println(prevMotorLevel);
          motor.brake(2);
          currentState = ST_DISPLAY_MAINMENU;
          if (motorLevel > 0) {
            // Calculate the duration based on the motor level
            if (motorLevel > prevMotorLevel) {
              motorDuration = (motorLevel - prevMotorLevel) * 6 * 1000;
            } else {
              motorDuration = abs(motorLevel - prevMotorLevel) * 6 * 1000;
            }
          }
          break;
        case '3':
          motorLevel = 3;
          lcd.setCursor(0, 1);
          lcd.print("Motor 2 ");
          lcd.print(" Level 3 ");
          motor.rotate(motor2, 100, motor2Direction);
          delay(motorDuration);
          Serial.println(motorDuration);
          Serial.println(motorLevel);
          Serial.println(prevMotorLevel);
          motor.brake(2);
          currentState = ST_DISPLAY_MAINMENU;
          if (motorLevel > 0) {
            // Calculate the duration based on the motor level
            if (motorLevel > prevMotorLevel) {
              motorDuration = (motorLevel - prevMotorLevel) * 6 * 1000;
            } else {
              motorDuration = abs(motorLevel - prevMotorLevel) * 6 * 1000;
            }
          }
          break;
        case '4':
          motorLevel = 4;
          lcd.setCursor(0, 1);
          lcd.print("Motor 2 ");
          lcd.print(" Level 4 ");
          motor.rotate(motor2, 100, motor2Direction);
          delay(motorDuration);
          Serial.println(motorDuration);
          Serial.println(motorLevel);
          Serial.println(prevMotorLevel);
          motor.brake(2);
          currentState = ST_DISPLAY_MAINMENU;
          if (motorLevel > 0) {
            // Calculate the duration based on the motor level
            if (motorLevel > prevMotorLevel) {
              motorDuration = (motorLevel - prevMotorLevel) * 6 * 1000;
            } else {
              motorDuration = abs(motorLevel - prevMotorLevel) * 6 * 1000;
            }
          }
          break;
        case '5':
          motorLevel = 5;
          lcd.setCursor(0, 1);
          lcd.print("Motor 2 ");
          lcd.print(" Level 5 ");
          motor.rotate(motor2, 100, motor2Direction);
          delay(motorDuration);
          Serial.println(motorDuration);
          Serial.println(motorLevel);
          Serial.println(prevMotorLevel);
          motor.brake(2);
          currentState = ST_DISPLAY_MAINMENU;
          if (motorLevel > 0) {
            // Calculate the duration based on the motor level
            if (motorLevel > prevMotorLevel) {
              motorDuration = (motorLevel - prevMotorLevel) * 6 * 1000;
            } else {
              motorDuration = abs(motorLevel - prevMotorLevel) * 6 * 1000;
            }
          }
          break;
        default:
          lcd.setCursor(0, 1);
          lcd.print("Motor 2 ");
          lcd.print(" Level 0 ");
          break;
      }
      break;
    case ST_SETLEVEL3:
      switch (key) {
        case '1':
          motorLevel = 1;
          lcd.setCursor(0, 1);
          lcd.print("Motor 3 ");
          lcd.print(" Level 1 ");
          motor.rotate(motor3, 100, motor3Direction);
          delay(motorDuration);
          Serial.println(motorDuration);
          Serial.println(motorLevel);
          Serial.println(prevMotorLevel);
          motor.brake(3);
          currentState = ST_DISPLAY_MAINMENU;
          if (motorLevel > 0) {
            // Calculate the duration based on the motor level
            if (motorLevel > prevMotorLevel) {
              motorDuration = (motorLevel - prevMotorLevel) * 6 * 1000;
            } else {
              motorDuration = abs(motorLevel - prevMotorLevel) * 6 * 1000;
            }
          }
          break;
        case '2':
          motorLevel = 2;
          lcd.setCursor(0, 1);
          lcd.print("Motor 3 ");
          lcd.print(" Level 2 ");
          motor.rotate(motor3, 100, motor3Direction);//run motor1 at 60% speed in CW direction
          delay(motorDuration);
          Serial.println(motorDuration);
          Serial.println(motorLevel);
          Serial.println(prevMotorLevel);
          motor.brake(3);
          currentState = ST_DISPLAY_MAINMENU;
          if (motorLevel > 0) {
            // Calculate the duration based on the motor level
            if (motorLevel > prevMotorLevel) {
              motorDuration = (motorLevel - prevMotorLevel) * 6 * 1000;
            } else {
              motorDuration = abs(motorLevel - prevMotorLevel) * 6 * 1000;
            }
          }
          break;
        case '3':
          motorLevel = 3;
          lcd.setCursor(0, 1);
          lcd.print("Motor 3 ");
          lcd.print(" Level 3 ");
          motor.rotate(motor3, 100, motor3Direction);//run motor1 at 60% speed in CW direction
          delay(motorDuration);
          Serial.println(motorDuration);
          Serial.println(motorLevel);
          Serial.println(prevMotorLevel);
          motor.brake(3);
          currentState = ST_DISPLAY_MAINMENU;
          if (motorLevel > 0) {
            // Calculate the duration based on the motor level
            if (motorLevel > prevMotorLevel) {
              motorDuration = (motorLevel - prevMotorLevel) * 6 * 1000;
            } else {
              motorDuration = abs(motorLevel - prevMotorLevel) * 6 * 1000;
            }
          }
          break;
        case '4':
          motorLevel = 4;
          lcd.setCursor(0, 1);
          lcd.print("Motor 3 ");
          lcd.print(" Level 4 ");
          motor.rotate(motor3, 100, motor3Direction);//run motor1 at 60% speed in CW direction
          delay(motorDuration);
          Serial.println(motorDuration);
          Serial.println(motorLevel);
          Serial.println(prevMotorLevel);
          motor.brake(3);
          currentState = ST_DISPLAY_MAINMENU;
          if (motorLevel > 0) {
            // Calculate the duration based on the motor level
            if (motorLevel > prevMotorLevel) {
              motorDuration = (motorLevel - prevMotorLevel) * 6 * 1000;
            } else {
              motorDuration = abs(motorLevel - prevMotorLevel) * 6 * 1000;
            }
          }
          break;
        case '5':
          motorLevel = 5;
          lcd.setCursor(0, 1);
          lcd.print("Motor 3 ");
          lcd.print(" Level 5 ");
          motor.rotate(motor3, 100, motor3Direction);//run motor1 at 60% speed in CW direction
          delay(motorDuration);
          Serial.println(motorDuration);
          Serial.println(motorLevel);
          Serial.println(prevMotorLevel);
          motor.brake(3);
          currentState = ST_DISPLAY_MAINMENU;
          if (motorLevel > 0) {
            // Calculate the duration based on the motor level
            if (motorLevel > prevMotorLevel) {
              motorDuration = (motorLevel - prevMotorLevel) * 6 * 1000;
            } else {
              motorDuration = abs(motorLevel - prevMotorLevel) * 6 * 1000;
            }
          }
          break;
        default:
          lcd.setCursor(0, 1);
          lcd.print("Motor 3 ");
          lcd.print(" Level 0 ");
          break;
      }
      break;
    case ST_SETLEVEL4:
      switch (key) {
        case '1':
          motorLevel = 1;
          lcd.setCursor(0, 1);
          lcd.print("Motor 4 ");
          lcd.print(" Level 1 ");
          motor.rotate(motor4, 100, motor4Direction); //run motor1 at 60% speed in CW direction
          delay(motorDuration);
          Serial.println(motorDuration);
          Serial.println(motorLevel);
          Serial.println(prevMotorLevel);
          motor.brake(4);
          currentState = ST_DISPLAY_MAINMENU;
          if (motorLevel > 0) {
            // Calculate the duration based on the motor level
            if (motorLevel > prevMotorLevel) {
              motorDuration = (motorLevel - prevMotorLevel) * 6 * 1000;
            } else {
              motorDuration = abs(motorLevel - prevMotorLevel) * 6 * 1000;
            }
          }
          break;
        case '2':
          motorLevel = 2;
          lcd.setCursor(0, 1);
          lcd.print("Motor 4 ");
          lcd.print(" Level 2 ");
          motor.rotate(motor4, 100, motor4Direction); //run motor1 at 60% speed in CW direction
          delay(motorDuration);
          Serial.println(motorDuration);
          Serial.println(motorLevel);
          Serial.println(prevMotorLevel);
          motor.brake(4);
          currentState = ST_DISPLAY_MAINMENU;
          if (motorLevel > 0) {
            // Calculate the duration based on the motor level
            if (motorLevel > prevMotorLevel) {
              motorDuration = (motorLevel - prevMotorLevel) * 6 * 1000;
            } else {
              motorDuration = abs(motorLevel - prevMotorLevel) * 6 * 1000;
            }
          }
          break;
        case '3':
          motorLevel = 3;
          lcd.setCursor(0, 1);
          lcd.print("Motor 4 ");
          lcd.print(" Level 3 ");
          motor.rotate(motor4, 100, motor4Direction); //run motor1 at 60% speed in CW direction
          delay(motorDuration);
          Serial.println(motorDuration);
          Serial.println(motorLevel);
          Serial.println(prevMotorLevel);
          motor.brake(4);
          currentState = ST_DISPLAY_MAINMENU;
          if (motorLevel > 0) {
            // Calculate the duration based on the motor level
            if (motorLevel > prevMotorLevel) {
              motorDuration = (motorLevel - prevMotorLevel) * 6 * 1000;
            } else {
              motorDuration = abs(motorLevel - prevMotorLevel) * 6 * 1000;
            }
          }
          break;
        case '4':
          motorLevel = 4;
          lcd.setCursor(0, 1);
          lcd.print("Motor 4 ");
          lcd.print(" Level 4 ");
          motor.rotate(motor4, 100, motor4Direction); //run motor1 at 60% speed in CW direction
          delay(motorDuration);
          Serial.println(motorDuration);
          Serial.println(motorLevel);
          Serial.println(prevMotorLevel);
          motor.brake(4);
          currentState = ST_DISPLAY_MAINMENU;
          if (motorLevel > 0) {
            // Calculate the duration based on the motor level
            if (motorLevel > prevMotorLevel) {
              motorDuration = (motorLevel - prevMotorLevel) * 6 * 1000;
            } else {
              motorDuration = abs(motorLevel - prevMotorLevel) * 6 * 1000;
            }
          }
          break;
        case '5':
          motorLevel = 5;
          lcd.setCursor(0, 1);
          lcd.print("Motor 4");
          lcd.print(" Level 5");
          motor.rotate(motor4, 100, motor4Direction); //run motor1 at 60% speed in CW direction
          delay(motorDuration);
          Serial.println(motorDuration);
          Serial.println(motorLevel);
          Serial.println(prevMotorLevel);
          motor.brake(4);
          currentState = ST_DISPLAY_MAINMENU;
          if (motorLevel > 0) {
            // Calculate the duration based on the motor level
            if (motorLevel > prevMotorLevel) {
              motorDuration = (motorLevel - prevMotorLevel) * 6 * 1000;
            } else {
              motorDuration = abs(motorLevel - prevMotorLevel) * 6 * 1000;
            }
          }
          break;
        default:
          lcd.setCursor(0, 1);
          lcd.print("Motor 4 ");
          lcd.print(" Level 0 ");
          break;
      }
      break;
    case ST_SETLEVEL5:
      switch (key) {
        case '1':
          motorLevel = 1;
          lcd.setCursor(0, 1);
          lcd.print("Motor 5 ");
          lcd.print(" Level 1 ");
          motor.rotate(motor5, 100, motor5Direction); //run motor1 at 60% speed in CW direction
          delay(motorDuration);
          Serial.println(motorDuration);
          Serial.println(motorLevel);
          Serial.println(prevMotorLevel);
          motor.brake(5);
          currentState = ST_DISPLAY_MAINMENU;
          if (motorLevel > 0) {
            // Calculate the duration based on the motor level
            if (motorLevel > prevMotorLevel) {
              motorDuration = (motorLevel - prevMotorLevel) * 6 * 1000;
            } else {
              motorDuration = abs(motorLevel - prevMotorLevel) * 6 * 1000;
            }
          }
          break;
        case '2':
          motorLevel = 2;
          lcd.setCursor(0, 1);
          lcd.print("Motor 5 ");
          lcd.print(" Level 2 ");
          motor.rotate(motor5, 100, motor5Direction); //run motor1 at 60% speed in CW direction
          delay(motorDuration);
          Serial.println(motorDuration);
          Serial.println(motorLevel);
          Serial.println(prevMotorLevel);
          motor.brake(5);
          currentState = ST_DISPLAY_MAINMENU;
          if (motorLevel > 0) {
            // Calculate the duration based on the motor level
            if (motorLevel > prevMotorLevel) {
              motorDuration = (motorLevel - prevMotorLevel) * 6 * 1000;
            } else {
              motorDuration = abs(motorLevel - prevMotorLevel) * 6 * 1000;
            }
          }
          break;
        case '3':
          motorLevel = 3;
          lcd.setCursor(0, 1);
          lcd.print("Motor 5 ");
          lcd.print(" Level 3 ");
          motor.rotate(motor5, 100, motor5Direction); //run motor1 at 60% speed in CW direction
          delay(motorDuration);
          Serial.println(motorDuration);
          Serial.println(motorLevel);
          Serial.println(prevMotorLevel);
          motor.brake(5);
          currentState = ST_DISPLAY_MAINMENU;
          if (motorLevel > 0) {
            // Calculate the duration based on the motor level
            if (motorLevel > prevMotorLevel) {
              motorDuration = (motorLevel - prevMotorLevel) * 6 * 1000;
            } else {
              motorDuration = abs(motorLevel - prevMotorLevel) * 6 * 1000;
            }
          }
          break;
        case '4':
          motorLevel = 4;
          lcd.setCursor(0, 1);
          lcd.print("Motor 5 ");
          lcd.print(" Level 4 ");
          motor.rotate(motor5, 100, motor5Direction); //run motor1 at 60% speed in CW direction
          delay(motorDuration);
          Serial.println(motorDuration);
          Serial.println(motorLevel);
          Serial.println(prevMotorLevel);
          motor.brake(5);
          currentState = ST_DISPLAY_MAINMENU;
          if (motorLevel > 0) {
            // Calculate the duration based on the motor level
            if (motorLevel > prevMotorLevel) {
              motorDuration = (motorLevel - prevMotorLevel) * 6 * 1000;
            } else {
              motorDuration = abs(motorLevel - prevMotorLevel) * 6 * 1000;
            }
          }
          break;
        case '5':
          motorLevel = 5;
          lcd.setCursor(0, 1);
          lcd.print("Motor 5 ");
          lcd.print(" Level 5 ");
          motor.rotate(motor5, 100, motor5Direction); //run motor1 at 60% speed in CW direction
          delay(motorDuration);
          Serial.println(motorDuration);
          Serial.println(motorLevel);
          Serial.println(prevMotorLevel);
          motor.brake(5);
          currentState = ST_DISPLAY_MAINMENU;
          if (motorLevel > 0) {
            // Calculate the duration based on the motor level
            if (motorLevel > prevMotorLevel) {
              motorDuration = (motorLevel - prevMotorLevel) * 6 * 1000;
            } else {
              motorDuration = abs(motorLevel - prevMotorLevel) * 6 * 1000;
            }
          }
          break;
        default:
          lcd.setCursor(0, 1);
          lcd.print("Motor 5 ");
          lcd.print(" Level 0 ");
          break;
      }
      break;
  } // end_of_switch
} // end of the void loop

void displayTitle()
{
  // clear the lcd
  lcd.clear();
  // print the project title on the first line
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Select Motor number");
  lcd.setCursor(0, 1);
  lcd.print("and the level ");
}

//updateState start
void updateState1()
{
  // Limit switch 1 for motor 1
  if (digitalRead(motor1switch1) == LOW) {
    if (motor1Direction == CW)
    {
      motor1Direction = CCW; //
      Serial.println("*****Now CCW");
    } else {
      motor1Direction = CCW; //
      Serial.println("*****Now CCW");
    }
  }

  // Limit switch 2 for motor 1
  if (digitalRead(motor1switch2) == LOW)
  {
    if (motor1Direction == CCW)
    {
      motor1Direction = CW; //
      Serial.println("*****Now CW");
    } else {
      motor1Direction = CW; //
      Serial.println("*****Now CW");
    }
  }

  // Limit switch 1 for motor 2
  if (digitalRead(motor2switch1) == LOW) {
    if (motor2Direction == CW)
    {
      motor2Direction = CCW; //
      Serial.println("*****Now CCW");
    } else {
      motor2Direction = CCW; //
      Serial.println("*****Now CCW");
    }
  }

  // Limit switch 2 for motor 2
  if (digitalRead(motor2switch2) == LOW) {
    if (motor2Direction == CCW)
    {
      motor2Direction = CW; //
      Serial.println("*****Now CW");
    } else {
      motor2Direction = CW; //
      Serial.println("*****Now CW");
    }
  }

  // Limit switch 1 for motor 3
  if (digitalRead(motor3switch1) == LOW) {
    if (motor3Direction == CW)
    {
      motor3Direction = CCW; //
      Serial.println("*****Now CCW");
    } else {
      motor3Direction = CCW; //
      Serial.println("*****Now CCW");
    }
  }

  // Limit switch 2 for motor 3
  if (digitalRead(motor3switch2) == LOW) {
    if (motor3Direction == CCW)
    {
      motor3Direction = CW; //
      Serial.println("*****Now CW");
    } else {
      motor3Direction = CW; //
      Serial.println("*****Now CW");
    }
  }

  // Limit switch 1 for motor 4
  if (digitalRead(motor4switch1) == LOW) {
    if (motor4Direction == CW)
    {
      motor4Direction = CCW; //
      Serial.println("*****Now CCW");
    } else {
      motor4Direction = CCW; //
      Serial.println("*****Now CCW");
    }
  }

  // Limit switch 2 for motor 4
  if (digitalRead(motor4switch2) == LOW) {
    if (motor4Direction == CCW)
    {
      motor4Direction = CW; //
      Serial.println("*****Now CW");
    } else {
      motor4Direction = CW; //
      Serial.println("*****Now CW");
    }
  }

  // Limit switch 1 for motor 5
  if (digitalRead(motor5switch1) == LOW) {
    if (motor5Direction == CW)
    {
      motor5Direction = CCW; //
      Serial.println("*****Now CCW");
    } else {
      motor5Direction = CCW; //
      Serial.println("*****Now CCW");
    }
  }

  // Limit switch 2 for motor 5
  if (digitalRead(motor5switch2) == LOW) {
    if (motor5Direction == CCW)
    {
      motor5Direction = CW; //
      Serial.println("*****Now CW");
    } else {
      motor5Direction = CW; //
      Serial.println("*****Now CW");
    }
  }
}
