#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
const int PULL1=2;
const int PULL2=3;
const int PULL3=4;
const int PULL4=5;
const int BUZZER=6;
const int LED1=13;
const int LED2=A0;
const int SEG=6;
int pulsador1=1;
int pulsador2=1;
int pulsador3=1;
int pulsador4=1;

int s=0;
int m=0;
int h=0;
int i=0;
int j=0;
void setup() {
Serial.begin(9600);
pinMode(PULL1, INPUT);
pinMode(PULL2, INPUT);
pinMode(PULL3, INPUT);
pinMode(PULL4, INPUT);
pinMode(BUZZER, OUTPUT);
pinMode(LED1, OUTPUT);
pinMode(LED2, OUTPUT);
lcd.begin(8, 2);
}

void loop() {
for(h=0; h<24; h++){
  for(m=0; m<=59; m++){
    for(s=0; s<59; s++){
     pulsador1=digitalRead(PULL1);
     pulsador2=digitalRead(PULL2);
     pulsador3=digitalRead(PULL3);
     pulsador4=digitalRead(PULL4);
       if(pulsador1==0){
        h++;
        if(h>23)h=0;
        }
       if(pulsador2==0){
        m++;
        if(m>59)m=0;
        }
        if(pulsador3==0){
        h--;if(h<0)h=23;
        }
       if(pulsador4==0){
        m--;
        if(m<0)m=59;
        }
      lcd.begin(8, 2);  
      if(h<10)lcd.print(0);
      lcd.print(h);
      lcd.print(":");
      if(m<=9)lcd.print(0);
      lcd.print(m);
      lcd.print(":");
      if(s<=9)lcd.print(0);
      lcd.println(s);
      //ALARMA
      if(h==5 && m==0 && s<20){
        lcd.begin(8, 1);
         lcd.print("ALARMA");
        digitalWrite(6, HIGH);
        delay(50);
        }
        digitalWrite(6, LOW);
      //ENCENDER LUCES
      
      if(h==5 && m==30){
        lcd.begin(8, 1);
         lcd.print("LUCES ON");
        digitalWrite(LED1, HIGH);
        delay(50);
        }
        if(h==6 && m==0){
        lcd.begin(8, 1);
         lcd.print("LUCES OFF");
        digitalWrite(LED1, LOW);
        delay(50);
        }
        if(h==18 && m==0){
        lcd.begin(8, 1);
         lcd.print("LUCES ON");
        digitalWrite(LED1, HIGH);
        delay(50);
        }
        if(h==22 && m==0){
        lcd.begin(8, 1);
         lcd.print("LUCES OFF");
        digitalWrite(LED1, LOW);
        delay(50);
        }
        
        //CAFETERA
        if(h==5 && m==45){
        lcd.begin(8, 1);
         lcd.print("CAFE");
        digitalWrite(LED2, HIGH);
        delay(50);
        }
        if(h==6 && m==5 && s<20){
        lcd.begin(8, 1);
         lcd.print("CAFE LISTO");
          
        digitalWrite(LED2, LOW);
       digitalWrite(6, HIGH);
        delay(50);
        }
       
      delay(150);
      }
    }
  }
}
