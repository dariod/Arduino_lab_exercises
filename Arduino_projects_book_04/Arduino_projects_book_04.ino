
// Decide wetehr the lamp is more bright when is darker or the other way round
// inverseMapping = 0 : more light means lamp brighter
// inverseMapping = 1 : less light means lamp brighter
const int inverseMapping = 1;

// Turn off serial
const int serialDebug = 0;

                        const int greenLEDPin = 9;
const int redLEDPin = 11;
const int blueLEDPin = 10 ;

const int redSensorPin = A0;
const int greenSensorPin = A2;
const int blueSensorPin = A1;

int redValue = 0;
int greenValue = 0;
int blueValue = 0;

int redSensorValue = 0;
int redSensorValueMin = 1023 ;
int redSensorValueMax = 0;

int greenSensorValue = 0;
int greenSensorValueMin = 1023 ;
int greenSensorValueMax = 0;

int blueSensorValue = 0;
int blueSensorValueMin = 1023 ;
int blueSensorValueMax = 0;


void setup() {
  Serial.begin(9600);

  pinMode(greenLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);

}

void loop() {

  redSensorValue = analogRead(redSensorPin);
  if (redSensorValue < redSensorValueMin) {
    redSensorValueMin = redSensorValue;
  }
  if (redSensorValue > redSensorValueMax) {
    redSensorValueMax = redSensorValue;
  }
  delay(5);  // The ADC takes a millisecond to perfomrn the read, thus we need a small delays between readings

  greenSensorValue = analogRead(greenSensorPin);
  if (greenSensorValue < greenSensorValueMin) {
    greenSensorValueMin = greenSensorValue;
  }
  if (greenSensorValue > greenSensorValueMax) {
    greenSensorValueMax = greenSensorValue;
  }
  delay(5);  // The ADC takes a millisecond to perfomrn the read, thus we need a small delays between readings

  blueSensorValue = analogRead(blueSensorPin);
  if (blueSensorValue < blueSensorValueMin) {
    blueSensorValueMin = blueSensorValue;
  }
  if (blueSensorValue > blueSensorValueMax) {
    blueSensorValueMax = blueSensorValue;
  }
  delay(5);  // The ADC takes a millisecond to perfomrn the read, thus we need a small delays between readings


  // Decide wether the mapping is direct or invers (lamp will turn on when it's dark)
  if (inverseMapping == 1) {
    redValue = map(redSensorValue, redSensorValueMax, redSensorValueMin, 0, 255);
    greenValue = map(greenSensorValue, greenSensorValueMax, greenSensorValueMin, 0, 255);
    blueValue = map(blueSensorValue, blueSensorValueMax, blueSensorValueMin, 0, 255);
  } else {
    redValue = map(redSensorValue, redSensorValueMin, redSensorValueMax, 0, 255);
    greenValue = map(greenSensorValue, greenSensorValueMin, greenSensorValueMax, 0, 255);
    blueValue = map(blueSensorValue, blueSensorValueMin, blueSensorValueMax, 0, 255);
  }

  analogWrite(redLEDPin, redValue);
  analogWrite(greenLEDPin, greenValue);
  analogWrite(blueLEDPin, blueValue);

  if (serialDebug == 1) {
    Serial.print("Sensors (R,G,B): ");
    Serial.print(redSensorValue);
    Serial.print(",");
    Serial.print(greenSensorValue);
    Serial.print(",");
    Serial.print(blueSensorValue);

    Serial.print("\tSensorsMin (R,G,B): ");
    Serial.print(redSensorValueMin);
    Serial.print(",");
    Serial.print(greenSensorValueMin);
    Serial.print(",");
    Serial.print(blueSensorValueMin);

    Serial.print("\tSensorsMax (R,G,B): ");
    Serial.print(redSensorValueMax);
    Serial.print(",");
    Serial.print(greenSensorValueMax);
    Serial.print(",");
    Serial.print(blueSensorValueMax);


    Serial.print("\tMapped values (R,G,B): ");
    Serial.print(redValue);
    Serial.print(",");
    Serial.print(greenValue);
    Serial.print(",");
    Serial.println(blueValue);
  }


}
