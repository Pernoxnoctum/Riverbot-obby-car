#include <Adafruit_MotorShield.h>

//create motor shield object and 4 motors
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *Motor1 = AFMS.getMotor(1);
Adafruit_DCMotor *Motor2 = AFMS.getMotor(2);
Adafruit_DCMotor *Motor3 = AFMS.getMotor(3);
Adafruit_DCMotor *Motor4 = AFMS.getMotor(4);

void setup() {
  Serial.begin(9600);
  Serial.println("Riverbot DC Motor test!");

  //start the motor shield
  if (!AFMS.begin()) {
    Serial.println("Could not find Motor Shield. Check wiring");
    while (1)
      ;
  }
  Serial.println("Motor Shield found");

  //set motor speed to 100 (max=255)
  Serial.println("Set motor speed to 100 (max=255)");
  Motor1->setSpeed(100);
  Motor2->setSpeed(100);
  Motor3->setSpeed(100);
  Motor4->setSpeed(100);

  
}

void go_forward() {
  Motor1->setSpeed(100);
  Motor2->setSpeed(100);
  Motor3->setSpeed(100);
  Motor4->setSpeed(100);

  Motor1->run(FORWARD);
  Motor2->run(FORWARD);
  Motor3->run(FORWARD);
  Motor4->run(FORWARD);
}

void go_not() {
  Motor1->setSpeed(0);
  Motor2->setSpeed(0);
  Motor3->setSpeed(0);
  Motor4->setSpeed(0);

  Motor1->run(BRAKE);
  Motor2->run(BRAKE);
  Motor3->run(BRAKE);
  Motor4->run(BRAKE);
}

void go_back() {
  Motor1->setSpeed(100);
  Motor2->setSpeed(100);
  Motor3->setSpeed(100);
  Motor4->setSpeed(100);

  Motor1->run(BACKWARD);
  Motor2->run(BACKWARD);
  Motor3->run(BACKWARD);
  Motor4->run(BACKWARD);
}
void loop() {
  // put your main code here, to run repeatedly:
  go_forward();
  delay(4000);

  go_not();
  delay(5000);

  go_back();
  delay(4000);

  go_not();
  delay(5000);
 
}
