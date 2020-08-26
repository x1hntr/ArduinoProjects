//SALIDAS HACIA EL DISPLAY 7SEG
int a = 2;
int b = 3;
int c = 4;
int d = 5;
int e = 6;
int f = 7;
int g = 8;

//ENTRADAS PULSADORES
const int PULL1=9;
const int PULL2=10;
const int PULL3=11;

int pulsador1=0;
int pulsador2=0;
int pulsador3=0;

void setup(){
  //DECLARACION ENTRADAS Y SALIDAS
pinMode(a, OUTPUT);
pinMode(b, OUTPUT);
pinMode(c, OUTPUT);
pinMode(d, OUTPUT);
pinMode(e, OUTPUT);
pinMode(f, OUTPUT);
pinMode(g, OUTPUT);
pinMode(PULL1, INPUT);
pinMode(PULL2, INPUT);
pinMode(PULL3, INPUT);
}

void loop(){
  //LECTURA PULSADORES
   pulsador1=digitalRead(PULL1);
   pulsador2=digitalRead(PULL2);
  
  //iTERACCION OPCION 1 CONTEO ASCENDENTE
  if (pulsador1==1){
  for(int i=0; i<=9; i++){
  contar(i);
  delay(1000);
  pulsador3=digitalRead(PULL3);
    if (pulsador3==1){
      apagar();
      break;
    }
  }
  }
  //iTERACCION OPCION 2 CONTEO DESCENDENTE
  if (pulsador2==1){
  for(int i=9; i>=0; i--){
  contar(i);
  delay(1000);
  pulsador3=digitalRead(PULL3);
  if (pulsador3==1){
      apagar();
      break;
    }
  } 
  }
 //OPCION 3 APAGAR
 pulsador3=digitalRead(PULL3);
  if (pulsador3==1) apagar();
  
}
//FUNCION DE CONTEO
void contar(int i){
if (i==0) cero();
if (i==1) uno();
if (i==2) dos();
if (i==3) tres();
if (i==4) cuatro();
if (i==5) cinco();
if (i==6) seis();
if (i==7) siete();
if (i==8) ocho();
if (i==9) nueve();  
}
//A CONTINUACION SE PRESENTAN LOS NUMEROS DESDE 
// EL 0 HASTA EL 9 
void cero(){
digitalWrite(a,LOW);
digitalWrite(b,LOW);
digitalWrite(c,LOW);
digitalWrite(d,LOW);
digitalWrite(e,LOW);
digitalWrite(f,LOW);
digitalWrite(g,HIGH);
}
void uno(){
digitalWrite(a,HIGH);
digitalWrite(b,LOW);
digitalWrite(c,LOW);
digitalWrite(d,HIGH);
digitalWrite(e,HIGH);
digitalWrite(f,HIGH);
digitalWrite(g,HIGH);
}
void dos(){
digitalWrite(a,LOW);
digitalWrite(b,LOW);
digitalWrite(c,HIGH);
digitalWrite(d,LOW);
digitalWrite(e,LOW);
digitalWrite(f,HIGH);
digitalWrite(g,LOW);
}
void tres(){
digitalWrite(a,LOW);
digitalWrite(b,LOW);
digitalWrite(c,LOW);
digitalWrite(d,LOW);
digitalWrite(e,HIGH);
digitalWrite(f,HIGH);
digitalWrite(g,LOW);
}
void cuatro(){
digitalWrite(a,HIGH);
digitalWrite(b,LOW);
digitalWrite(c,LOW);
digitalWrite(d,HIGH);
digitalWrite(e,HIGH);
digitalWrite(f,LOW);
digitalWrite(g,LOW);
}
void cinco(){
digitalWrite(a,LOW);
digitalWrite(b,HIGH);
digitalWrite(c,LOW);
digitalWrite(d,LOW);
digitalWrite(e,HIGH);
digitalWrite(f,LOW);
digitalWrite(g,LOW);
}
void seis(){
  digitalWrite(a,LOW);
digitalWrite(b,HIGH);
digitalWrite(c,LOW);
digitalWrite(d,LOW);
digitalWrite(e,LOW);
digitalWrite(f,LOW);
digitalWrite(g,LOW);
}
void siete(){
  digitalWrite(a,LOW);
digitalWrite(b,LOW);
digitalWrite(c,LOW);
digitalWrite(d,HIGH);
digitalWrite(e,HIGH);
digitalWrite(f,HIGH);
digitalWrite(g,HIGH);
}
void ocho(){
  digitalWrite(a,LOW);
digitalWrite(b,LOW);
digitalWrite(c,LOW);
digitalWrite(d,LOW);
digitalWrite(e,LOW);
digitalWrite(f,LOW);
digitalWrite(g,LOW);
}
void nueve(){
digitalWrite(a,LOW);
digitalWrite(b,LOW);
digitalWrite(c,LOW);
digitalWrite(d,LOW);
digitalWrite(e,HIGH);
digitalWrite(f,LOW);
digitalWrite(g,LOW);
}
//FUNCION PARA APAGAR EL DISPLAY
void apagar(){
digitalWrite(a,HIGH);
digitalWrite(b,HIGH);
digitalWrite(c,HIGH);
digitalWrite(d,HIGH);
digitalWrite(e,HIGH);
digitalWrite(f,HIGH);
digitalWrite(g,HIGH);
}
