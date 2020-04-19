#include <Servo.h>
#include <PS2X_lib.h>
Servo Servo_1;  
Servo Servo_2; 
Servo Direccion;  
Servo Motor_A;
Servo Motor_B; 
int pos = 0 ;
//COMUNICACION
PS2X ps2x;
int E = 0;
byte vibrate = 0;
int valy=0;
int valx=0;
int velocidad=1000;
int angulo=0;


void setup() {
Servo_1.attach(11);
Servo_2.attach(10);
Direccion.attach(9);
Direccion.write(120);
Servo_1.write(10);
Servo_2.write(140);
Motor_A.attach(7);
Motor_B.attach(4);
delay(5000);

  Serial.begin(9600);
   
  E= ps2x.config_gamepad(8,12,A0,13,true,true);  //(clock, command, attention, data)
  if(E == 0)
  {
    Serial.println("Controlador encontrado y configurado");
  }
  else
  {
    Serial.println("Error, mando no encontrado");
  }
  }
  
void loop() {
 //LEER VALORES PALANCA
  ps2x.read_gamepad(false,vibrate);
  vibrate = ps2x.Analog(PSAB_BLUE);
  valy=ps2x.Analog(PSS_LY), DEC;
  valx=ps2x.Analog(PSS_RX), DEC;  
 if(valy>=0 && valy<=126){
      velocidad=map(valy , 0, 126, 1500, 1000);
      adelante();
      }
  if(valx>=0 && valx<=126){
      angulo=map(valx , 0, 126, 100, 140);
      adelante();
      izquierda();
      Serial.println("iz");
      }
  if(valx>=128 && valx<=255){
      angulo=map(valx , 128, 255, 100, 140);
      adelante();
      derecha();
      Serial.println("der");
      }
     if(valx==127){
      Direccion.write(120);
      }
   if(valx==127 && valy==127){
    parar();
        Serial.println("Stop");
      } 
   if(ps2x.Button(PSB_PAD_UP)){
  agarrar();
  Serial.println("Close");
  }   
  if(ps2x.Button(PSB_PAD_DOWN)){
  soltar();
  Serial.println("Close");
  }     
  delay(200);     
      }
  //FUNCIONES
    
      void adelante(){
         Direccion.write(120);
         Motor_A.writeMicroseconds(velocidad);
         Motor_B.writeMicroseconds(1000);
        }
      void izquierda(){
        Direccion.write(angulo);
        }
      void derecha(){
        Direccion.write(angulo);
        }
      void parar(){
        Motor_A.writeMicroseconds(0);
        Motor_B.writeMicroseconds(0);
        }
      void agarrar(){
        Servo_1.write(40);
        Servo_2.write(110);
        }
      void soltar(){
        Servo_1.write(0);
        Servo_2.write(150);
        }
