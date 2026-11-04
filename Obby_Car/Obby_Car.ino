#include <Adafruit_MotorShield.h>
#include <Servo.h>

Servo myservo;

//create motor shield object and 4 motors
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *Motor1 = AFMS.getMotor(1);
Adafruit_DCMotor *Motor2 = AFMS.getMotor(2);
Adafruit_DCMotor *Motor3 = AFMS.getMotor(3);
Adafruit_DCMotor *Motor4 = AFMS.getMotor(4);

// defines pins numbers
const int trigPin = 11;
const int echoPin = 12;

// defines variables
long duration;
int distance;


//the setup
void setup() {
  Serial.begin(9600);
  Serial.println("Riverbot DC Motor test!");

  myservo.attach(10);

  // definitely correct this.
  pinMode(8, OUTPUT); // turns on the thing
	pinMode(trigPin, OUTPUT);// Sets the trigPin as an Output
	pinMode(echoPin, INPUT); // Sets the echoPin as an Input
	digitalWrite(8, HIGH);// makes the sonar pinger turn on

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




// the backward movement
void go_back() {
  Motor1->setSpeed(100);
  Motor2->setSpeed(100);
  Motor3->setSpeed(100);
  Motor4->setSpeed(100);

  Motor1->run(FORWARD);
  Motor2->run(FORWARD);
  Motor3->run(FORWARD);
  Motor4->run(FORWARD);
}

// the brakes
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

//the forward movement
void go_forward() {
  Motor1->setSpeed(100);
  Motor2->setSpeed(100);
  Motor3->setSpeed(100);
  Motor4->setSpeed(100);

  Motor1->run(BACKWARD);
  Motor2->run(BACKWARD);
  Motor3->run(BACKWARD);
  Motor4->run(BACKWARD);
}

// turns
void turn(bool direction,int angle) {
  Motor1->setSpeed(100);
  Motor2->setSpeed(100);
  Motor3->setSpeed(100);
  Motor4->setSpeed(100);
  // turns right by 45 degrees * angle number
  if (direction == true){
    Motor1->run(FORWARD);
    Motor2->run(FORWARD);
    Motor3->run(BACKWARD);
    Motor4->run(BACKWARD);
    delay(465 * angle);
    go_not();
  }
  //turns left by 45 degrees * angle number
  else{
    Motor1->run(BACKWARD);
    Motor2->run(BACKWARD);
    Motor3->run(FORWARD);
    Motor4->run(FORWARD);
    delay(465 * angle);
    go_not();
  }
}

// goes forward or backward measured in meters
void gobymeter(bool directy, float meters){
  if (directy == false) {
    go_back();
    delay(5000*meters);
    go_not();
  }
  if (directy == true){
    go_forward();
    delay(3550*meters);
    go_not();
  }
}

void sonar(){
  // Clears the trigPin
	digitalWrite(trigPin, LOW);
	delayMicroseconds(2);

	// Sets the trigPin on HIGH state for 10 micro seconds
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);

	// Reads the echoPin, returns the sound wave travel time in microseconds
	duration = pulseIn(echoPin, HIGH);

	// Calculating the distance
	distance = duration * 0.034 / 2;

	// Prints the distance on the Serial Monitor
	Serial.print("Distance: ");
	Serial.println(distance);
}

//the routine
void loop() {
  sonar();
  while (distance >= 30){
    go_forward();
    sonar();
  }
  go_not();
  turn(false,2);
  gobymeter(true,1);
  go_not();
  delay(5000);

}
