
#include <LiquidCrystal.h>
int ledPin = 8;  // this means buzzer.
int flexPin0 = A0; //pin A0 to read analog input
int flexPin1 = A1; 
int flexPin2 = A2; 
int flexPin3 = A3; 

//Variables:
int flexPin0value = 0; //save analog value
int flexPin1value = 0;
int flexPin2value = 0;
int flexPin3value = 0;


// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  
    Serial.begin(9600);       //Begin serial communication
    pinMode(flexPin0, INPUT);  //set analog pin A0 input
    pinMode(flexPin1, INPUT);
    pinMode(flexPin2, INPUT);
    pinMode(flexPin3, INPUT);
  
  lcd.begin(16, 2); 
}

void loop() {
  
  flexPin0value = analogRead(flexPin0);         //Read and save analog value from potentiometer
  Serial.println(flexPin0value);               //Print value
  
    flexPin1value = analogRead(flexPin1); 
    flexPin2value = analogRead(flexPin2);
    flexPin3value = analogRead(flexPin3);


if((flexPin0value < 1000) && (flexPin1value > 920) && (flexPin2value > 830) && (flexPin3value > 1000)) 
  { //buzzer 
    lcd.clear();
    digitalWrite(ledPin,LOW);
  digitalWrite(ledPin,HIGH);
  lcd.print("ALERT!");
  lcd.setCursor(0, 1);
  lcd.print("Reach up to me");
  }
else if((flexPin0value > 1000)&& (flexPin1value < 950) && (flexPin2value > 900)&& (flexPin3value > 980))
  {lcd.clear();
  digitalWrite(ledPin,LOW);
     lcd.print("I need");
   lcd.setCursor(0, 1);
   lcd.print("WATER.");
  }  
else if((flexPin0value > 1000) && (flexPin1value > 900) && (flexPin2value < 890) && (flexPin3value > 1000))
  { lcd.clear();
  digitalWrite(ledPin,LOW);
   lcd.print("EMEREGENCY!");
   lcd.setCursor(0, 1);
   lcd.print("I need Help.");
  }   

else if((flexPin0value > 1000) && (flexPin1value > 900) && (flexPin2value > 900)&& (flexPin3value < 1000))
  { digitalWrite(ledPin,LOW);
  lcd.clear();
  lcd.print("I want to use");
   lcd.setCursor(0, 1);
   lcd.print("WASHROOM.");
  } 
    
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
//  else{
//     lcd.clear();
//     digitalWrite(ledPin,LOW);, 0+



+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//     
//  }
  lcd.setCursor(0, 0);
   delay(100);
  // print the number of seconds since reset:
 // lcd.print(millis() / 1000);
}
 
