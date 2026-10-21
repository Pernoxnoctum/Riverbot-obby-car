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


void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Motror 1 forward");
  Motor1->run(FORWARD);
  delay(5000);
  Motor1->run(BRAKE);
  
  Serial.println("Motror 2 forward");
  Motor2->run(FORWARD);
  delay(5000);
  Motor2->run(BRAKE);
  
  Serial.println("Motror 3 forward");
  Motor3->run(FORWARD);
  delay(5000);
  Motor3->run(BRAKE);
  
  Serial.println("Motror 1 forward");
  Motor1->run(FORWARD);
  delay(5000);
  Motor4->run(BRAKE);
  
  Serial.println("All forward");
  Motor1->run(FORWARD);
  Motor2->run(FORWARD);
  Motor3->run(FORWARD);
  Motor4->run(FORWARD);
  delay(5000);
  Motor1->run(BRAKE);
  Motor2->run(BRAKE);
  Motor3->run(BRAKE);
  Motor4->run(BRAKE);
}
