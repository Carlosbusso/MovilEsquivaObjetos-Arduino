 /*Este programa presenta el codigo de prueba para variacion de velocidad con PWM
 *Codigo realizado por EMIC-TRON canal en youtube: https://www.youtube.com/channel/UCoC2aZPoRzzQAit9s3d3AUw
 */
int IN1 = 4;    // Input1 conectada al pin 4 de Arduino
int IN2 = 5;    // Input2 conectada al pin 5 de Arduino
int ENA = 6;    // ENA conectada al pin 6 de Arduino
  void setup() {             
  pinMode (IN1, OUTPUT);     // Inicializa el pin 4  como salida digital.
  pinMode (IN2, OUTPUT);     // Inicializa el pin 5 como salida digital.
  pinMode (ENA, OUTPUT);     // Inicializa el pin 6 como salida digital.
  }
  void loop() {
 //Preparamos la salida para que el motor gire en un sentido
  digitalWrite (IN1,1);
  digitalWrite (IN2,0);
  // Aplicaremos señal PWM por el canal ENA y variaremos la velocidad del motor
  analogWrite(ENA,150);
  delay(2000);
  analogWrite(ENA,200);
  delay(2000);
  analogWrite(ENA,255);
  delay(2000);
  // Apagamos el motor y esperamos 2 seg
  analogWrite(ENA,0);
  delay(2000);
  }
