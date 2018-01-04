//Initializing variables
int sensorA = A0;
int sensorB = A1;

int brakeA = 9;
int brakeB = 8;

int pwmA = 3;
int pwmB = 11;

int directionA = 12;
int directionB = 13;

void setup() {
  //setting pin modes
  pinMode(pwmA, OUTPUT);
  pinMode(pwmB, OUTPUT);
  pinMode(brakeA, OUTPUT);
  pinMode(brakeB, OUTPUT);
  pinMode(directionA, OUTPUT);
  pinMode(directionB, OUTPUT);
  Serial.begin(9600); //creates gui
  Serial.println("Enter a speed from 0 to 255"); //gives instructions
  
}


void loop() {
  //randomize(); uncomment this to select random speeds
  if (Serial.available()){
    
    int speed = Serial.parseInt(); //gets speed
    Serial.println(speed); //prints the speed entered
    if (speed >= 0 && speed <= 255){ //makes sure the speed entered is between 0 and 255, which is the range
      Serial.println("Activating now");
      //runs the motors
      runA(speed);
      runB(speed);

    }else{
      Serial.println("Please enter a valid value");
    }
    Serial.println("Enter a speed from 0 to 255");
  }
}

/*void radomize(){ //added functionality for randomization
    
    
   
        int speed = random(0, 255); //chooses a random speed from 0 to 255
        Serial.println(speed); //prints the speed to the GUI
        runA(speed); //runs motor
        runB(speed); //runs motor
        int timeDelay = random(1, 5); //randomizes the delay 
        delay(timeDelay*1000); //1000 is 1 second
         

}*/

void runA(int speed){
  digitalWrite(directionA, LOW); //sets direction of motor
  digitalWrite(brakeA, LOW); //stops break
  analogWrite(pwmA, speed); //sets speed
}

void runB(int speed){
  digitalWrite(directionB, LOW); //sets direction of motor
  digitalWrite(brakeB, LOW); //stops break
  analogWrite(pwmB, speed); //sets speed
}

void stopAll(){
  digitalWrite(brakeA, HIGH); //breaks motor
  digitalWrite(brakeB, HIGH); //breaks motor
}

