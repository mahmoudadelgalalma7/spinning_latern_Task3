#define EN 10
#define IN1 9
#define IN2 8
int buttonPin = 2;
int motor_speed = 0;
int pedal = A0;
int buttonState = 0;        
int Led_Red_Pin = 13;                                    
int Led_Yellow_Ping = 12;                                

void setup()
{
  pinMode(IN1, OUTPUT); // motor pin 1
  pinMode(IN2, OUTPUT); // motor pin 2
  pinMode(EN, OUTPUT); // motor PWM pin
  pinMode(pedal,INPUT); // potentiometer pin
  pinMode(buttonPin,INPUT); // potentiometer pin
  pinMode(Led_Red_Pin, OUTPUT);
  pinMode(Led_Yellow_Ping, OUTPUT);

  Serial.begin(9600); 
}

void loop()
{
  
  buttonState = digitalRead(buttonPin);
  int pedalValue = analogRead(pedal);
  delay(500);
  
  
  motor_speed = map(pedalValue, 0, 1024, 0, 255);
 
  Serial.print("RPM: ");
  Serial.println(motor_speed);

 if (buttonState == HIGH) {
  if(motor_speed >= 0 && motor_speed <= 255)
       {
       digitalWrite(IN1, HIGH);
       digitalWrite(IN2, LOW);
       analogWrite(EN,motor_speed);
       }
 } else {

       digitalWrite(IN1, LOW);

 }

// Switch 
 if (buttonState == HIGH) {
    // turn LED on and Start Rotation:
    digitalWrite(Led_Red_Pin, HIGH);
    digitalWrite(Led_Yellow_Ping, LOW);
    delay(500);
    digitalWrite(Led_Red_Pin, LOW);
    digitalWrite(Led_Yellow_Ping, HIGH);

  } else {
    // turn LED off and End Rotation :
    digitalWrite(Led_Red_Pin, LOW);
    digitalWrite(Led_Yellow_Ping, LOW);

  }


}
