#include<Servo.h>                                                                          

Servo myServo;
int TRIG = 8;     // variable de tipo entero para la señal de salida
int ECO = 9;
int tiempo;
int distancia;

Servo myServo2;
int TRIG2 = 10;
int ECO2 = 11;
int tiempo2;
int distancia2;

void setup() {
  
   Serial.begin(9600); //para leer datos como la distancia y mostrarlos en el monitor serie
  
   pinMode(2,OUTPUT); 
   pinMode(3,OUTPUT);
   onOffLeds();
   
   pinMode(TRIG,OUTPUT); // trig sera una señal de salida es decir sale un sonido
   pinMode(ECO,INPUT);  // echo sera señal de entreda es decir donde entra el sonido
   myServo.attach(5);
   
   
   pinMode(TRIG2, OUTPUT);
   pinMode(ECO2, INPUT);

   myServo2.attach(6);
   myServo2.write(0);

}
void loop() {
 leerDistancia();
 leerDistancia2();    // aqui puse esta variable
  Serial.println(distancia);
  Serial.println(distancia2);
  delay(2000);
 if(distancia<10){ // el rango maximo de detectar un objeto es de 4m y minimo 2 cm 
  onOffLeds();
  abrirPuerta();
  delay(2000);  // tiempo que demora la señal en ir y regresar para abrir la puerta
  cerrarPuerta();
  delay(2000);
  }

  if(distancia2<10){ // el rango maximo de detectar un objeto es de 4m y minimo 2 cm 
  onOffLeds();
  abrirPuerta2();
  delay(2000);  // tiempo que demora la señal en ir y regresar para abrir la puerta
  cerrarPuerta2();
  delay(2000);
  }
}


void onOffLeds(){
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  delay(100);
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  delay(100);
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  delay(100);
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  }

// -----------------------------------
void leerDistancia(){
  digitalWrite(TRIG,HIGH);
  delay(1);
  digitalWrite(TRIG,LOW);
  tiempo = pulseIn(ECO,HIGH);
  distancia = tiempo / 58.2;  // en las formulas de fisica el tiempo tenemos que es t=d/v y a la vez es el que nos muestra la distancia en centimetros
 }

// -----------------------------

void cerrarPuerta(){
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  int angulo=0;
  do{
    angulo=angulo+1;
    myServo.write(angulo);
    delay(50);
    }while(angulo<90);
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);    
}


void abrirPuerta(){
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  int angulo =90;
  do{
    angulo=angulo-1;
    myServo.write(angulo);
    delay(50);
    }while(angulo>0);  
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  }

// ------------------------------
void leerDistancia2() {                //aqui puse esta nueva variable
  digitalWrite(TRIG2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG2, LOW);
  tiempo2 = pulseIn(ECO2, HIGH);
  distancia2 = tiempo2 / 58.2;
}


void abrirPuerta2() {      //aqui para abajo puse esta nueva variable
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  int angulo = 0;
  do {
    angulo += 1;
    myServo2.write(angulo);
    delay(50);
  } while (angulo <= 90);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
}

void cerrarPuerta2() {
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  int angulo = 90;
  do {
    angulo -= 1;
    myServo2.write(angulo);
    delay(50);
  } while (angulo >= 0);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
}



  
