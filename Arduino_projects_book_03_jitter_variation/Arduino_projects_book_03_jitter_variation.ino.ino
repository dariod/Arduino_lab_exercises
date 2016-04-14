// Define constants
const int sensorPin = A0;
const int tempStep = 3;

// Define variables
float baselineTemp = 18.0;
int sensorVal = 0;
float voltage = 0.0;
float temperature = 0.0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // open a serial port

  for (int pinNumber = 2; pinNumber < 5; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }

  // initialize the baselineTemp
  sensorVal = analogRead(sensorPin);
  voltage = (sensorVal / 1024.0) * 5.0;
  baselineTemp = (voltage - .5) * 100;
}

// We want to print the temperature only when it chages
int sensorValOld = -10;

void loop() {
  // put your main code here, to run repeatedly:

  // Read the sensor value
  sensorVal = analogRead(sensorPin);

  // convert ADC reading to voltage
  float voltage = (sensorVal / 1024.0) * 5.0;

  // convert voltage to temperature (Celsius)
  float temperature = (voltage - .5) * 100;

  // print to console the values
  Serial.print("Sensor value: ");
  Serial.print(sensorVal);

  Serial.print(", Volts: ");
  Serial.print(voltage);

  Serial.print(", degrees C: ");
  Serial.print(temperature);
  Serial.print(" (Baseline: ");
  Serial.print(baselineTemp);
  Serial.print(", step: ");
  Serial.print(tempStep);
  Serial.println(")");

  // change the LEDs statuses

  if (temperature <= baselineTemp) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if (baselineTemp + tempStep <= temperature && temperature < baselineTemp + 2 * tempStep) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if (baselineTemp + 2 * tempStep <= temperature && temperature < baselineTemp + 3 * tempStep) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  } else if (baselineTemp + 3 * tempStep <= temperature) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
  delay(500);
}
