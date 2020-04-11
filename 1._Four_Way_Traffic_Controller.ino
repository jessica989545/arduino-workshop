/*

1. 3-6am: light traffic
2. 6-9am: medium traffic
3. 9am-9pm: heavy traffic
4. 9pm-3am: medium traffic

*/

int time_slot;         //values between 1 and 4
int redLED1 = 2;       //signal 1 red LED
int yellowLED1 = 3;    //signal 1 yellow LED
int greenLED1 = 4;     //signal 1 green LED
int redLED2 = 5;       //signal 2 red LED
int yellowLED2 = 6;    //signal 2 yellow LED
int greenLED2 = 7;     //signal 2 green LED
int redLED3 = 8;       //signal 3 red LED
int yellowLED3 = 9;    //signal 3 yellow LED
int greenLED3 = 10;    //signal 3 green LED
int redLED4 = 11;      //signal 4 red LED
int yellowLED4 = 12;   //signal 4 yellow LED
int greenLED4 = 13;    //signal 4 green LED

void setup() {
  Serial.begin(9600);
  pinMode(redLED1, OUTPUT);
  pinMode(yellowLED1, OUTPUT);
  pinMode(greenLED1, OUTPUT);
  pinMode(redLED2, OUTPUT);   
  pinMode(yellowLED2, OUTPUT);
  pinMode(greenLED2, OUTPUT);
  pinMode(redLED3, OUTPUT);
  pinMode(yellowLED3, OUTPUT);
  pinMode(greenLED3, OUTPUT);
  pinMode(redLED4, OUTPUT);
  pinMode(yellowLED4, OUTPUT);
  pinMode(greenLED4, OUTPUT);
}

void loop() {
  Serial.println("Enter the time slot (Enter a value between 1 and 4)");
  while(Serial.available()==0) {
  }
  time_slot = Serial.parseInt();
  if(time_slot == 1){
    for(int i=0; i<15; i++){
      digitalWrite(yellowLED1, HIGH);
      digitalWrite(yellowLED2, HIGH);
      digitalWrite(yellowLED3, HIGH);
      digitalWrite(yellowLED4, HIGH);
      delay(500);
      digitalWrite(yellowLED1, LOW);
      digitalWrite(yellowLED2, LOW);
      digitalWrite(yellowLED3, LOW);
      digitalWrite(yellowLED4, LOW);
      delay(500);
    }
  }
  if(time_slot == 2 || time_slot == 4){
    for(int i=0; i<10; i++){
      digitalWrite(greenLED1, HIGH);
      digitalWrite(redLED2, HIGH);
      digitalWrite(redLED3, HIGH);
      digitalWrite(redLED4, HIGH);
      delay(3000);
      digitalWrite(greenLED1, LOW);
      
      digitalWrite(yellowLED1, HIGH);
      delay(1000);
      digitalWrite(yellowLED1, LOW);
      
      digitalWrite(greenLED2, HIGH);
      digitalWrite(redLED1, HIGH);
      delay(3000);
      digitalWrite(greenLED2, LOW);
  
      digitalWrite(yellowLED2, HIGH);
      delay(1000);

      digitalWrite(redLED1, LOW);
      digitalWrite(yellowLED2, LOW);
      digitalWrite(redLED3, LOW);
      digitalWrite(redLED4, LOW);
    }
  }
  if(time_slot == 3){
    for(int i=0; i<10; i++){
      digitalWrite(redLED1, HIGH);
      digitalWrite(greenLED2, HIGH);
      digitalWrite(redLED3, HIGH);
      digitalWrite(greenLED4, HIGH);
      delay(3000);
      digitalWrite(greenLED2, LOW);
      digitalWrite(greenLED4, LOW);

      digitalWrite(yellowLED2, HIGH);
      digitalWrite(yellowLED4, HIGH);
      delay(1000);
      digitalWrite(redLED1, LOW);
      digitalWrite(yellowLED2, LOW);
      digitalWrite(redLED3, LOW);
      digitalWrite(yellowLED4, LOW);

      digitalWrite(greenLED1, HIGH);
      digitalWrite(redLED2, HIGH);
      digitalWrite(greenLED3, HIGH);
      digitalWrite(redLED4, HIGH);
      delay(3000);
      digitalWrite(greenLED1, LOW);
      digitalWrite(greenLED3, LOW);

      digitalWrite(yellowLED1, HIGH);
      digitalWrite(yellowLED3, HIGH);
      delay(1000);
      digitalWrite(yellowLED1, LOW);
      digitalWrite(redLED2, LOW);
      digitalWrite(yellowLED3, LOW);
      digitalWrite(redLED4, LOW);
    }
  }  
}
