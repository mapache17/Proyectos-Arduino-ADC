int valorAnterior = 0; 
String estadoProceso = ""; 

void setup()
{
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop()
{
  int valorNuevo = analogRead(0);
  
  if (valorNuevo >= 0 and valorNuevo <= 307){
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    estadoProceso = "Proceso OK";
    if (valorAnterior != valorNuevo){
      Serial.println(estadoProceso);
      valorAnterior = valorNuevo;
    }
  }
  
  if (valorNuevo > 307 and valorNuevo <= 716){
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    estadoProceso = "Verifique tanque";
    if (valorAnterior != valorNuevo){
      Serial.println(estadoProceso);
      valorAnterior = valorNuevo;
    }
  }
  
  if (valorNuevo > 716 and valorNuevo <= 1023){
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    estadoProceso = "Salga de inmediato";
    if (valorAnterior != valorNuevo){
      Serial.println(estadoProceso);
      valorAnterior = valorNuevo;
    }
  }

  delay(20);
}