//Constantes para los pines.
const int SignalPin = 2;

//Constantes para las monedas.
const int uno_ctv = 1;
const int cinco_ctv = 3;
const int diez_ctv = 6;
const int veinticinco_ctv = 9;
const int cincuenta_ctv = 12;
const int dolar_ctv = 15;

//Variables.
volatile int pulso = 0;
//volatile unsigned long MillisUltPulso = 0;
unsigned long MillisUltPulso = 0;
int PulsosAcum = 0;
int CreditoAcum = 0;
int MaxTimePulse = 200;

void setup() {

// Inicializamos la comunicacion serial, para ver los resultados en el monitor.
Serial.begin(9600);

//Agregamos la interrupcion con el pin indicado.
attachInterrupt(digitalPinToInterrupt(SignalPin), coinInterrupt, RISING);
    
}

void loop() {
monedero();
}



void monedero(){
  //Calculamos los milisegundos de la ultima ejecusion menos el ultimo tiempo que se genero un pulso.
unsigned long lastTime = millis() - MillisUltPulso;

//Validamos si hay algun puslo, si es asi tambien se valida que el ultimo tiempo asignado sea mayor a la cantidad de milisegundos establecidos.
if((pulso > 0) && (lastTime >= MaxTimePulse)){

    //La cantidad de creditos es el contador y acumulador de pulsos, hasta que se cumpla alguna condicion.
    PulsosAcum = pulso;
    pulso = 0; 
}

//Validamos la moneda depositada.
switch (PulsosAcum){
  case uno_ctv:
    PulsosAcum = 0;
    CreditoAcum += 1;
    Serial.println("1");
    break;

  case cinco_ctv:
    PulsosAcum = 0;
    CreditoAcum += 5;
    Serial.println("5");
    break;
    
  case diez_ctv:
    PulsosAcum = 0;
    CreditoAcum += 10;
   Serial.println("10");
    break;

  case veinticinco_ctv:
    PulsosAcum = 0;
    CreditoAcum += 25;
   Serial.println("25");
    break;
    
  case cincuenta_ctv:
    PulsosAcum = 0;
    CreditoAcum += 50;
    Serial.println("50");
    break;

     case dolar_ctv:
    PulsosAcum = 0;
    CreditoAcum += 100;
    Serial.println("100");
    break;
  }
 
  }

// Interrupcion.
void coinInterrupt(){
 
  // Cada vez que insertamos una moneda valida, incrementamos el contador de monedas y encendemos la variable de control,
  pulso++;
  MillisUltPulso = millis();  
}
