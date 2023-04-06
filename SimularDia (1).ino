const int sensorPin = A0; 
int sensorValue = 0; 
int previousValue = 0; 
int hour = 6; // 
String message = ""; 

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Leemos el valor del fotoresistor
  sensorValue = analogRead(sensorPin);

  
  if (sensorValue > previousValue) {
    if (sensorValue >= 0 && sensorValue < 121) { // Rango para 6am - 7am
      message = "Son las 6 de la mañana";
      hour = 6;
    } else if (sensorValue >= 121 && sensorValue < 243) { // Rango para 7am - 8am
      message = "Son las 7 de la mañana";
      hour = 7;
    } else if (sensorValue >= 243 && sensorValue < 365) { // Rango para 8am - 9am
      message = "Son las 8 de la mañana";
      hour = 8;
    } else if (sensorValue >= 365 && sensorValue < 487) { // Rango para 9am - 10am
      message = "Son las 9 de la mañana";
      hour = 9;
    } else if (sensorValue >= 487 && sensorValue < 609) { // Rango para 10am - 11am
      message = "Son las 10 de la mañana";
      hour = 10;
    } else if (sensorValue >= 609 && sensorValue < 731) { // Rango para 11am - 12pm
      message = "Son las 11 de la mañana";
      hour = 11;
    } else if (sensorValue >= 731 && sensorValue < 1024) { // Rango para 12pm
      message = "Es mediodia";
      hour = 12;
    }
    
  } 
 
  else if (sensorValue < previousValue) {
    if (sensorValue >= 0 && sensorValue < 121) { // Rango para 6pm
      message = "Son las 6 de la tarde";
      hour = 18;
    } else if (sensorValue >= 121 && sensorValue < 243) { // Rango para 5pm - 6pm
      message = "Son las 5 de la tarde";
      hour = 17;
    } else if (sensorValue >= 243 && sensorValue < 365) { // Rango para 4pm - 5pm
      message = "Son las 4 de la tarde";
      hour = 16;
    } else if (sensorValue >= 365 && sensorValue < 487) { // Rango para 3pm - 4pm
      message = "Son las 3 de la tarde";
      hour = 15;
    } else if (sensorValue >= 487 && sensorValue < 609) { // Rango para 2pm - 3pm
      message = "Son las 2 de la tarde";
      hour = 14;
    } else if (sensorValue >= 609 && sensorValue < 731) { // Rango para 1pm - 2pm
      message = "Es la 1 de la tarde";
      hour = 13;
    } else if (sensorValue >= 731 && sensorValue < 1024) { // Rango para 1pm - 2pm
      message = "Es mediodia";
      hour = 13;
    }
    
    }
  	previousValue=sensorValue;
  	Serial.println(message);
    delay(20);
  }