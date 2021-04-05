#include <SoftwareSerial.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);


#define trig A1
#define echo A0
#define in1 10
#define in2 9 
#define in3 8 
#define in4 7

int distance=0;
int duration=0;
// SoftwareSerial  BT(10,11);
 //TX,  RX respeticvely
 String readvoice;

void printFwd(){
  //lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Frwd");
  if(distance<40)
      {
        lcd.setCursor(8,0);
        lcd.print("Obstacle");
        lcd.setCursor(8,1);
        lcd.print(distance);
        lcd.setCursor(14,1);
        lcd.print("cm");
        lcd.setCursor(0,1);
        lcd.print("Warning");
      }
}


void Initialize(){
  //lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Connected");
  delay(1000);
  lcd.clear();
  if(distance<40)
      {
        lcd.setCursor(8,0);
        lcd.print("Obstacle");
        lcd.setCursor(8,1);
        lcd.print(distance);
        lcd.setCursor(14,1);
        lcd.print("cm");
          lcd.setCursor(0,1);
        lcd.print("Warning");
      }
}

/*void dis(){
  //lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Disconnected");
}*/

void printBwd(){
  //lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Down");
  if(distance<40)
      {
        lcd.setCursor(8,0);
        lcd.print("Obstacle");
        lcd.setCursor(8,1);
        lcd.print(distance);
        lcd.setCursor(14,1);
        lcd.print("cm");
          lcd.setCursor(0,1);
        lcd.print("Warning");
      }
}

void printRight(){
  //lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Rght");
  if(distance<40)
      {
        lcd.setCursor(8,0);
        lcd.print("Obstacle");
        lcd.setCursor(8,1);
        lcd.print(distance);
        lcd.setCursor(14,1);
        lcd.print("cm");
          lcd.setCursor(0,1);
        lcd.print("Warning");
      }
}

void printLeft(){
  //lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Left");
  if(distance<40)
      {
        lcd.setCursor(8,0);
        lcd.print("Obstacle");
        lcd.setCursor(8,1);
        lcd.print(distance);
        lcd.setCursor(14,1);
        lcd.print("cm");
          lcd.setCursor(0,1);
        lcd.print("Warning");
      }
}

void printStop(){
  //lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Stop");
  if(distance<40)
      {
        lcd.setCursor(8,0);
        lcd.print("Obstacle");
        lcd.setCursor(8,1);
        lcd.print(distance);
        lcd.setCursor(14,1);
        lcd.print("cm");
          lcd.setCursor(0,1);
        lcd.print("Warning");
      }
}

 void setup() {
//  BT.begin(9600);
  Serial.begin(9600);
     pinMode(in1, OUTPUT);
     pinMode(in2, OUTPUT);
     pinMode(in3, OUTPUT);
     pinMode(in4, OUTPUT);
     pinMode(trig, OUTPUT);
     pinMode(echo, INPUT);
     lcd.begin(16,2);
     lcd.print("Hello");
     analogWrite(6,125);
      lcd.clear();
      lcd.setCursor(2,0);
      //lcd.print("Connected!!!");
      delay(800);
      lcd.setCursor(1,1);
      lcd.print("Ready To Go!!!");
      delay(1000);
      lcd.clear();
      lcd.setCursor(8,0);
      lcd.print("Obstacle");
      lcd.setCursor(0,0);
      lcd.print("Cmnd");
 }
  //----------------------------------------------//
  void loop() {
//    while  (Serial.available()){
//  //check if there is an available byte to read
//    delay(10); //Delay added to make thing stable 
//    char c = Serial.read();
//  //Conduct a serial read
//    readvoice += c; //build the string- "forward", "reverse","left" and "right"
//    }
    analogWrite(trig, 0);
    delayMicroseconds(2);
    analogWrite(trig, 200);
    delayMicroseconds(10);
    analogWrite(trig, 0);

    duration=pulseIn(echo,255);
    distance=duration*0.017;
    
    
    
    if ( Serial.available()) {
      analogWrite(trig, 0);
    delayMicroseconds(2);
    analogWrite(trig, 200);
    delayMicroseconds(10);
    analogWrite(trig, 0);

    duration=pulseIn(echo,255);
    distance=duration*0.017;
      //Initialize();
      //delay(1000);
     // lcd.setCursor(8,0);
     // lcd.print("Obstacle");
      lcd.setCursor(8,1);
      lcd.print(distance);
      lcd.setCursor(14,1);
      lcd.print("cm");*/
      
     if(distance<40)
      {
        lcd.setCursor(8,1);
        lcd.print(distance);
        lcd.setCursor(14,1);
        lcd.print("cm");
        lcd.setCursor(0,1);
        lcd.print("Warning");
        delay(150);
        lcd.print("");
        delay(100);
        lcd.print("Warning");
      }
            
      lcd.clear();
        char c = Serial.read();
        Serial.println(c);

     if(c == 'f')
     {
      Serial.println("UP");
      //left
       digitalWrite(in1, LOW); //bck
       digitalWrite(in2, HIGH); //fwd
      //right
       digitalWrite(in3, HIGH); //fwd
       digitalWrite(in4, LOW); //bck
       printFwd();
       delay(100);
       
     }

     else if(c == 'b'){
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4,HIGH);
        printBwd();
        delay(100);
     }

  else if (c == 'r')
  {
    digitalWrite (in1,LOW);
    digitalWrite (in2,HIGH);
    digitalWrite (in3,LOW);
    digitalWrite (in4,LOW);
    printRight();
   delay (100);
      
  
  }

 else if ( c == 'l')
 {
   digitalWrite (in1, LOW);
   digitalWrite (in2, LOW);
   digitalWrite (in3, HIGH);
   digitalWrite (in4, LOW);
   printLeft();
   delay (100);
     
 }

 else if (c == 's')
 {
   digitalWrite (in1, LOW);
   digitalWrite (in2, LOW);
   digitalWrite (in3, LOW);
   digitalWrite (in4, LOW);
   printStop();
   delay (100);
 }
 }
 /*else{
  dis();
 }*/ //Reset the variable
  }
    
  

 
