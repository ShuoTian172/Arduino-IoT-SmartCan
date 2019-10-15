#include "NewPing.h"



#define TRIGGER_PIN_1  9
#define ECHO_PIN_1     7
#define TRIGGER_PIN_2  3
#define ECHO_PIN_2     4
#define TRIGGER_PIN_3  6
#define ECHO_PIN_3     2
#define MAX_DISTANCE 400
#define MIN_DISTANCE 10
#define MAX_GAS 150 //120


//PhpocEmail email;
NewPing sonar_1(TRIGGER_PIN_1, ECHO_PIN_1, MAX_DISTANCE);
NewPing sonar_2(TRIGGER_PIN_2, ECHO_PIN_2, MAX_DISTANCE);
NewPing sonar_3(TRIGGER_PIN_3, ECHO_PIN_3, MAX_DISTANCE);
float distance_1;
float distance_2;
float distance_3;
int pre_status = 0;
int cur_status = 0;
int sent = 0;
 
void setup() {
  Serial.begin (9600);
  //Phpoc.begin(PF_LOG_SPI | PF_LOG_NET | PF_LOG_APP);
}
 
void loop() {
  
  distance_1 = sonar_1.ping_cm();
  distance_2 = sonar_2.ping_cm();
  distance_3 = sonar_2.ping_cm();
  // Send results to Serial Monitor
  Serial.print("Distance_1 = ");
  if (distance_1 >= 400 || distance_1 <= 2) {
    cur_status = 0;
    Serial.println("Out of range");
  }
  else {
    if (distance_1 <= MIN_DISTANCE) {
      cur_status = 1;
      Serial.println("it's full");
    }
    else{
      cur_status = 0;
      Serial.print(distance_1);
      Serial.println(" cm");
    }
    delay(500);
  }
  delay(500);
  
  /*
  // Got full for two times 
  if (pre_status == 1 && cur_status == 1 && sent == 0) {
    email.setOutgoingServer("smtp.gmail.com", 587);
    email.setOutgoingLogin("mwchiuu@gmail.com", "twedusuck");
 
    email.setFrom("mwchiuu@gmail.com ", "Sunny");
    email.setTo("arduinotestingg@gmail.com", "Sunny");
    
    email.setSubject("Mail from your trash can");  // Mail Subject
    
    // Mail Contents
    email.beginMessage();
    email.println("Hello!");
    email.println("Your trash can is full");
    email.println("Feel free to clean it up!");
    email.endMessage();                
 
    if (email.send() > 0){
      sent = 1;
      Serial.println("Your Mail has been sent successfully");
    }
    else
      Serial.println("Your Mail is not sent");
  }
  pre_status = cur_status;
  
  if (val > 130 && sent == 0) {
    email.setOutgoingServer("smtp.gmail.com", 587);
    email.setOutgoingLogin("mwchiuu@gmail.com", "twedusuck");
 
    email.setFrom("mwchiuu@gmail.com ", "Sunny");
    email.setTo("arduinotestingg@gmail.com", "Sunny");
    
    email.setSubject("Mail from your trash can");  // Mail Subject
    
    // Mail Contents
    email.beginMessage();
    email.println("Hello!");
    email.println("Your trash can smells bad");
    email.println("Feel free to clean it up!");
    email.endMessage();                
 
    if (email.send() > 0) {
      sent = 1;
      Serial.println("Your Mail has been sent successfully");
    }
    else
      Serial.println("Your Mail is not sent");
  }*/
  
  Serial.print("Distance_2 = ");
  if (distance_2 >= 400 || distance_2 <= 2) {
    Serial.println("Out of range");
  }

  else {
    if (distance_2 <= MIN_DISTANCE) {
      Serial.println("it's full");
    }
    else{
      Serial.print(distance_2);
      Serial.println(" cm");
    }
    delay(500);
  }
  delay(500);
  
  Serial.print("Distance_3 = ");
  if (distance_3 >= 400 || distance_3 <= 2) {
    Serial.println("Out of range");
  }
  else {
    if (distance_3 <= MIN_DISTANCE) {
    Serial.println("it's full");
    }
    else{
      Serial.print(distance_3);
      Serial.println(" cm");
    }
    delay(500);
  }
  delay(500);
  int val;
  val=analogRead(A5);//Read Gas value from analog 0
  Serial.println(val,DEC);//Print the value to serial port
  delay(100); 
}