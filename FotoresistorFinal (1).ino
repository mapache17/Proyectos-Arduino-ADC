int resistenciaCons=1000;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A0, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  long valorFotoresistor = 0;
  valorFotoresistor= analogRead(0);
  
  long resMax=150000;
  long resMin=250;
  
  long valorMax=(resMax-resMin);
  long valorCAMporcentaje= (valorMax/100);

  long bitsMax =1023;
  long bitsMin= 0;
  long valorBitsT=(bitsMax-bitsMin);
  
  long porcentaje=((valorFotoresistor-bitsMin)*100)/(valorBitsT);
  //int porcentaje= (100/valorBitsT)*(valorPotenciometro);

  Serial.println("Porcentaje: ");
  Serial.println(porcentaje);
  //Serial.print("Resistencia: ");
  //Serial.println(((valorCAMporcentaje*(porcentaje))-valorCAMporcentaje*(100)-resMin)*-1);

  delay(100);
}
