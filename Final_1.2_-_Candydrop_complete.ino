//Candydrop by Candide Uyanze
//Adapted from Light-Controlled Servo by TechMartian: https://www.instructables.com/Light-Controlled-Servo/


// include the servo library
#include <Servo.h>

// create a servo object called candydrop, that controls the drop
Servo candydrop;

// variables //
int candydropPin = 8;
int lightsensordropPin = A0;
int LEDSomeonePin = 2;
int SensorSomeonePin = A1;

int closeAngle = 0;
int dropAngle = 100;

int moveRate = 10000;        //the time between updates in milliseconds

long candyWasDropped;


void setup() {
  // put your setup code here, to run once:

  // set the servo pin, as a servo output pin
  candydrop.attach(candydropPin);
  candydrop.write(closeAngle);

  // specify that LED is an output
  pinMode (LEDSomeonePin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly;
  
  // Read the light value of the light sensors
  int lightValue1 = analogRead(lightsensordropPin);
  int lightValue2 = analogRead(SensorSomeonePin);

  // map the light readings to the angle possible by the servo motor
  lightValue1 = map (lightValue1, 0, 1023, 0, 100);
  lightValue2 = map (lightValue2, 0, 1023, 0, 100);

  Serial.print ("Light1:");
  Serial.print (lightValue1);

  if (millis()-candyWasDropped>=moveRate)
    {candydrop.write (closeAngle);  
    }

  // if the light value is less than 10, drop the candy
  if (lightValue1 < 35)
    {candydrop.write (dropAngle);  
    candyWasDropped = millis();
    }
    
  if (lightValue2 < 35)
    {digitalWrite (LEDSomeonePin, HIGH);  
    }

  if (lightValue2 >= 35)
    {digitalWrite (LEDSomeonePin, LOW);  
    }

}
