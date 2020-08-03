 /*Este programa permite la lectura de distancia de un sensor HC-SR04
 *La distancia de lectura se restringe en el rango de 0 a 500 cm
 *Si la distancia esta en el rango de 1 a 10 se prendera el led del pin 13
 *Codigo realizado por EMIC-TRON canal en youtube: https://www.youtube.com/channel/UCoC2aZPoRzzQAit9s3d3AUw
 */
int ECHO = 11;                    //  ECHO al Arduino pin 11
int TRIG = 12;                    //  TRIG al Arduino pin 12
long duracion, distancia; 

void setup() {   
  Serial.begin (9600);            // Inicializa el comunicacion serial
  pinMode (ECHO, INPUT);          // Inicializa el pin 11 como entrada (ECHO)
  pinMode (TRIG, OUTPUT);         // Inicializa el pin 12 como salida  (TRIGER)
  pinMode (13,   OUTPUT);         // Inicializa el pin 13 como salida
}

void loop() {
  //codigo para generar el pulso en el ultrasonido
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);                   //Genera el pulso de triger por 10ms
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  //
  duracion = pulseIn(ECHO, HIGH);             //Lectura del sensor
  distancia = (duracion/2) / 29;              //Formula para calcular distancia en centimetros
  
  if (distancia >= 500 || distancia <= 0){   // Si la distancia es mayor a 500cm o menor a 0cm 
  Serial.println("__");                      // No mide nada
  }
  else {
    Serial.print(distancia);                 // Imprime el valor de la distancia en el monitor serial
    Serial.println("cm");                    // Imprime al lado de la distancia los centimetros "cm"
    digitalWrite(13, LOW);                   // Pin 13 en bajo
    
  if (distancia <= 10 && distancia >= 1){
    digitalWrite(13, HIGH);                  // Pin 13 en alto
    Serial.println("Alarma...");             // Imprime la palabra Alarma en el monitor serial
  } 
  }
  delay(500);
  }
  
