#define rojo1 A3
#define amarillo2 A2
#define verde3 A1
#define verde4 8
#define verde5 9
#define verde6 10
#define verde7 11
#define amarillo8 12
#define rojo9 13
int BOTON_IZQ;
int BOTON_DER;
int aux = 5, vel = 400;
int direccion_der = 1;
int direccion_izq = 0;

void setup() {
  pinMode(rojo1, OUTPUT);
  pinMode(amarillo2, OUTPUT);
  pinMode(verde3, OUTPUT);
  pinMode(verde4, OUTPUT);
  pinMode(verde5, OUTPUT);
  pinMode(verde6, OUTPUT);
  pinMode(verde7, OUTPUT);
  pinMode(amarillo8, OUTPUT);
  pinMode(rojo9, OUTPUT);
  
  pinMode(A5, INPUT);
  pinMode(A4, INPUT);
}

void loop() {
  BOTON_IZQ = digitalRead(A5);
  BOTON_DER = digitalRead(A4);

  if (BOTON_DER == 1) {
    Serial.println("boton derecho");
  } else if (BOTON_IZQ == 1) {
    Serial.println("Boton derecho");
  }

  if (aux == 2 && BOTON_IZQ == 1){
    direccion_der = 1;
    direccion_izq = 0;
    vel = vel-50;
  }
  else if (aux == 8 && BOTON_DER == 1){
    direccion_der = 0;
    direccion_izq = 1;
  }
  else if (direccion_der == 1){
    aux++;
    PELOTA();
  }
  else if (direccion_izq == 1){
    aux--;
    PELOTA();
  } 
  delay(vel);
}

void PELOTA(){
  switch (aux) {
  case 1:
    digitalWrite(rojo1, HIGH);
    digitalWrite(amarillo2, LOW);
    break;
  case 2:
    digitalWrite(rojo1, LOW);
    digitalWrite(amarillo2, HIGH);
    digitalWrite(verde3, LOW);
    break;
  case 3:
    digitalWrite(amarillo2, LOW);
    digitalWrite(verde3, HIGH);
    digitalWrite(verde4, LOW);
    break;
  case 4:
    digitalWrite(verde3, LOW);
    digitalWrite(verde4, HIGH);
    digitalWrite(verde5, LOW);
    break;
  case 5:
    digitalWrite(verde4, LOW);
    digitalWrite(verde5, HIGH);
    digitalWrite(verde6, LOW);
    break;
  case 6:
    digitalWrite(verde5, LOW);
    digitalWrite(verde6, HIGH);
    digitalWrite(verde7, LOW);
    break;
  case 7:
    digitalWrite(verde6, LOW);
    digitalWrite(verde7, HIGH);
    digitalWrite(amarillo8, LOW);
    break;
  case 8:
    digitalWrite(verde7, LOW);
    digitalWrite(amarillo8, HIGH);
    digitalWrite(rojo9, LOW);
    break;
  case 9:
    digitalWrite(rojo9, HIGH);
    digitalWrite(amarillo8, LOW);
    break;
  
  default:
    digitalWrite(rojo9, HIGH);
    digitalWrite(rojo1, HIGH);
    delay(2000);
    digitalWrite(rojo9, LOW);
    digitalWrite(rojo1, LOW);
    aux = 5;
    vel = 400;
    break;
  }
}
