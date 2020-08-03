 /*Este programa presenta el codigo de un Movil Esquiva Objetos
 *La lectura de la distancia del sensor ultrasonido se restringe en el rango de 0 a 500 cm
 *Si la distancia se encuentra entre 10 y 500 el movil avanzara en linea recta
 *Si la distancia esta en el rango de 1 a 10 el movil retrocedera y girara
 *Codigo realizado por EMIC-TRON canal en youtube: https://www.youtube.com/channel/UCoC2aZPoRzzQAit9s3d3AUw
 */
int IN1 = 4;    // Input1 conectada al pin 4 de Arduino
int IN2 = 5;    // Input2 conectada al pin 5 de Arduino
int ENA = 6;    // ENA conectada al pin 6 de Arduino
int IN3 = 7;    // Input3 conectada al pin 7 de Arduino
int IN4 = 8;    // Input4 conectada al pin 8 de Arduino  
int ENB = 9;    // ENB conectada al pin 9 de Arduino
int ECHO = 11;  // ECHO al Arduino pin 11 de Arduino
int TRIG = 12;  // TRIG al Arduino pin 12 de Arduino
long duracion, distancia; 

 
void setup() {                
  Serial.begin (9600);       // inicializa el puerto serial
  pinMode (IN1, OUTPUT);     // Inicializa el pin 4  como salida digital.
  pinMode (IN2, OUTPUT);     // Inicializa el pin 5 como salida digital.
  pinMode (ENA, OUTPUT);     // Inicializa el pin 6 como salida digital.
  pinMode (IN3, OUTPUT);     // Inicializa el pin 7 como salida digital.
  pinMode (IN4, OUTPUT);     // Inicializa el pin 8 como salida digital.
  pinMode (ENB, OUTPUT);     // Inicializa el pin 9 como salida digital.
  pinMode (ECHO, INPUT);     // Inicializa el pin 11 como entrada (ECHO)
  pinMode (TRIG, OUTPUT);    // Inicializa el pin 12 como salida  (TRIGER)
  pinMode(13, OUTPUT);       // Inicializa el pin 13 como salida
  }
  
void loop() {
  
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);   // genera el pulso de TRIGER por 10ms
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  
  duracion = pulseIn(ECHO, HIGH);           //Lectura del sensor
  distancia = (duracion/2) / 29;            //Formula para calcular distancia en centimetros
  
  if (distancia >= 500 || distancia <= 0){  // Si la distancia es mayor a 500cm o menor a 0cm 
    Serial.println("---");                  // No mide nada
  }
  else {
    Serial.print(distancia);           // Imprime el valor de la distancia en el monitor serial
    Serial.println("cm");              // Imprime al lado de la distancia los centimetros "cm"
    digitalWrite(13, 0);               // Pin 13 en bajo
    
// Si la distancia esta en el rango de 1 a 10 el movil retrocedera y girara    
   if (distancia <= 10 && distancia >= 1) 
   {
    digitalWrite(13, 1);                // Pin 13 en alto
    Serial.println("Alarma.....");      // Imprime la palabra Alarma en el monitor serial
                                        // Codigo para retroceder 
    digitalWrite(IN1,1);                
    digitalWrite(IN2,0);
    digitalWrite(IN3,0);
    digitalWrite(IN4,1); 
    analogWrite(ENA,120);
    analogWrite(ENB,120);
    delay(1000);
                                        // Codigo para girar
    digitalWrite(IN1,0);
    digitalWrite(IN2,0);
    digitalWrite(IN3,1);
    digitalWrite(IN4,0); 
    analogWrite(ENB,110);
    delay(500);
    }

// Si la distancia se encuentra entre 10 y 500 el movil avanzara en linea recta
// Codigo para que el movil avance en linea recta
  else{
      Serial.print(distancia);           // Imprime el valor de la distancia en el monitor serial
      Serial.println("cm");              // Imprime al lado de la distancia los centimetros "cm"
      digitalWrite(IN1,0);
      digitalWrite(IN2,1);
      digitalWrite(IN3,1);
      digitalWrite(IN4,0); 
      analogWrite(ENB,110);
      analogWrite(ENA,120);
      delay(400);
    }
     }
}
