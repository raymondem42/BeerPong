//including the stepper library
#include <Stepper.h>

// a variable to read incoming serial data into
int incomingByte; 

//use johnathan to reset the stepper before using for the first time

//the angle we ae going to get from the serial monitor
float xAngle;
float yAngle;

//we are going to convert the xAngle steps for the motor
float x;
float y;

//stepper one 
int dirA1 = 1;
int dirB1 = 2;
int pwmA1 = 3;
int pwmB1 = 4;

//stepper two 
int dirA2 = 5;
int dirB2 = 6;
int pwmA2 = 7;
int pwmB2 = 8;

//stepper three
int dirA3 = 9;
int dirB3 = 10;
int pwmA3 = 11;
int pwmB3 = 12;

//relay
int shoot = 13;

/*
 * We might need to use this for the motor speed on the h-bridge
int ENA = 3;
int ENB = 4; 
*/

//declaring the steppers
Stepper stepper1(200, dirA1, dirB1);
Stepper stepper2(200, dirA2, dirB2);
Stepper stepper3(200, dirA3, dirB3);


void setup() 
{
  Serial.begin(9600);

  //declaring things
  pinMode(pwmA1, OUTPUT);
  pinMode(pwmB1, OUTPUT);

  pinMode(pwmA2, OUTPUT);
  pinMode(pwmB2, OUTPUT);

  pinMode(pwmA3, OUTPUT);
  pinMode(pwmB3, OUTPUT);
  
  pinMode (shoot, OUTPUT);


  //making the pwm as always high
  pinMode(pwmA1, HIGH);
  pinMode(pwmB1, HIGH);

  pinMode(pwmA2, HIGH);
  pinMode(pwmB2, HIGH);

  pinMode(pwmA3, HIGH);
  pinMode(pwmB3, HIGH);

  //setting the relay to start as low
  pinMode(shoot, LOW);
    /*
   * we might need this for the motor speed with an h-bridge
  pinMode (ENA, OUTPUT);
  pinMode (ENB, OUTPUT);
  */
}

void loop() 
{

  if (Serial.available() > 0) {
      incomingByte = Serial.read();

     if (Serial.read() == 'X'){
      xAngle = Serial.parseInt();  // read the x angle
      if (Serial.read() == 'Y')
        yAngle = Serial.parseInt(); // read the y angle
    }
      
  if (incomingByte == 'H') {
    // getting the steps for the motors
    // consider doing this instead
    // xAngle = xAngle/1.8;
      x = xAngle/1.8;
      y = yAngle/1.8;
    
    // moving the steppers
      stepper1.step(x);
      stepper2.step(y);
      stepper3.step(y);
      delay(500);

     // shooting the ball
      Serial.print("this is for my bros");
      digitalWrite(shoot, HIGH);      //Switch Solenoid ON
      delay(1000);
      digitalWrite(shoot, LOW);

      //reset the motors
      stepper1.step(-x);
      stepper2.step(-y);
      stepper3.step(-y);
      delay(500);
  }
  }
}
