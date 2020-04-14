#include <PS2X_lib.h>
PS2X ps2x;

int error = 0;
byte vibrate = 0;
const int LED3=4;
const int LED2=2;
const int LED1=3;
const int AIN1=11;
const int AIN2=10;
const int BIN1=9;
const int BIN2=7;
const int PWMA=6;
const int PWMB=5;

int vel=0;
int valy=0;
int valx=0;
int vely=0;
int velx=0;
int v=255;
int pos=0;
void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  Serial.begin(9600);
  error = ps2x.config_gamepad(8, 12, A0, 13,true,true);  //(clock, command, attention, data)
  if(error == 0)
  {
    Serial.println("Controller found and configured");
  }
  else
  {
    Serial.println("Error");
    Serial.println(error);
stop();

  }
  
}


void loop() {
   int temp;
  ps2x.read_gamepad(false,vibrate);
  vibrate = ps2x.Analog(PSAB_BLUE);
  
 valy=ps2x.Analog(PSS_LY), DEC;    
 valx=ps2x.Analog(PSS_RX), DEC;


 if(valy<120){
 if(valx<=135 && valx>=120){
  Serial.println("FORWARE"); 
  vel=map(valy , 0, 126, v, 0);
  velx=vel;
  vely=vel;
  forward();
 }
 //MOVIMIENTOS HIBRIDOS
 if(valx>135){
  Serial.println("FORDWARD AND RIGHT");  
  velx=map(valy , 0, 126, v, 0);
  vely=map(valx , 135, 255, v, 100);
  forward();
 }
 if(valx<120){
  Serial.println("FORWWWARD E LEFT"); 
  vely=map(valy , 0, 126, v, 0);
  velx=map(valx , 0, 127, 100, v);
  forward(); 
 }
 }
 
 if(valy>135 && valx<=135 && valx>=120){
  Serial.println("BACK");
  back();  
 }
 //MOVIMIENTOS HIBRIDOS
 if(valy>135 && valx>135){
  Serial.println("BACK AND RIGHT");  
  back();
 }
 if(valy>135 && valx<120){
  Serial.println("BACK AND LEFT"); 
  back(); 
 }
 if(valx>135 && valy<=135 && valy>=120){
  Serial.println("RIGHT");  
   right();
 }
 if(valx<120 && valy<=135 && valy>=120){
  Serial.println("LEFT"); 
  left();
 }
 if(valy<=135 && valy>=120 && valx<=135 && valx>=120){
    Serial.println("STOP");
    parar();
 }
    delay(50);
}
void  right(){
   digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  analogWrite(PWMA, vel);
  analogWrite(PWMB, vel);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  }
  void left(){
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  analogWrite(PWMA, vel);
  analogWrite(PWMB, vel);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  }
void forward(){
    digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  analogWrite(PWMA, velx);
  analogWrite(PWMB, vely);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  }
  void back(){
      digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  analogWrite(PWMA, vel);
  analogWrite(PWMB, vel);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  }
  void parar(){
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, HIGH);
  analogWrite(PWMA, 255);
  analogWrite(PWMB, 255);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, HIGH);
  }
