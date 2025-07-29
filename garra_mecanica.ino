#include "VarSpeedServo.h"

// Definição dos servos do braço robótico
VarSpeedServo servo1; // base
VarSpeedServo servo2; // extensão
VarSpeedServo servo3; // altura
VarSpeedServo servo4; // garra

// Definição dos pinos dos joysticks (conforme código anterior)
int potpin1 = A2; // right_X
int potpin2 = A5; // right_Y
int potpin3 = A3; // left_X
int potpin4 = A4; // left_Y

int val1;
int val2;
int val3;
int val4;

// Define os valores iniciais de posição de cada servo, dentro dos limites definidos
static int s1 = 70;  // base (0 a 180)
static int s2 = 110; // extensão (40 a 180)
static int s3 = 100; // altura (18 a 123)
static int s4 = 60;  // garra (0 a 65)

void setup()
{
  Serial.begin(9600);

  // Ajuste dos servos nos pinos conforme código anterior
  servo1.attach(A1); // base
  servo2.attach(A0); // extensão
  servo3.attach(6);  // altura
  servo4.attach(9);  // garra

  // Move todo o braço para a posição inicial
  servo1.write(s1);   
  servo2.write(s2);   
  servo3.write(s3);   
  servo4.write(s4);   
}

void loop()
{
  // Leitura dos joysticks
  val1 = analogRead(potpin1); // right_X (A2)
  val2 = analogRead(potpin2); // right_Y (A5)
  val3 = analogRead(potpin3); // left_X  (A3)
  val4 = analogRead(potpin4); // left_Y  (A4)

  // Controle da base do braço (servo1)
  if (val1 < 100)
  {
    s1 = s1 - 2;
    if (s1 < 0) s1 = 0;
    servo1.write(s1);
    delay(50);
  }
  if (val1 > 900)
  {
    s1 = s1 + 2;
    if (s1 > 180) s1 = 180;
    servo1.write(s1);
    delay(50);
  }

  // Controle da extensão do braço (servo2)
  if (val2 > 900)
  {
    s2 = s2 - 2;
    if (s2 < 40) s2 = 40;
    servo2.write(s2);
    delay(50);
  }
  if (val2 < 100)
  {
    s2 = s2 + 2;
    if (s2 > 180) s2 = 180;
    servo2.write(s2);
    delay(50);
  }

  // Controle da altura do braço (servo3)
  if (val3 < 100)
  {
    s3 = s3 - 2;
    if (s3 < 18) s3 = 18;
    servo3.write(s3);
    delay(50);
  }
  if (val3 > 900)
  {
    s3 = s3 + 2;
    if (s3 > 123) s3 = 123;
    servo3.write(s3); 
    delay(50);
  }

  // Controle da garra (servo4)
  if (val4 < 100)
  {
    s4 = s4 - 2;
    if (s4 < 0) s4 = 0;
    servo4.write(s4);
    delay(50);
  }
  if (val4 > 900)
  {
    s4 = s4 + 2;
    if (s4 > 65) s4 = 65;
    servo4.write(s4);
    delay(50);
  }

  // Exibe os valores lidos na porta serial
  Serial.print(val1);
  Serial.print("  :  ");
  Serial.print(val2);
  Serial.print("  :  ");
  Serial.print(val3);
  Serial.print("  :  ");
  Serial.print(val4);
  Serial.println();
}