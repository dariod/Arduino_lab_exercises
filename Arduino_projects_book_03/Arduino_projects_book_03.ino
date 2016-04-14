// Define constants
const int sensorPin = A0;
const float baselineTemp = 18.0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // open a serial port
  
  for(int pinNumber = 2; pinNumber < 5; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }

}

// We want to print the temperature only when it chages
int sensorValOld = -10;

void loop() {
  // put your main code here, to run repeatedly:
  
  // Read the sensor value
  int sensorVal = analogRead(sensorPin);

  // If the sensor value changed from last time, print the new value on the console  
  if (abs(sensorVal - sensorValOld) >= 2) {
    sensorValOld=sensorVal;
  
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
    Serial.println(temperature);

    // change the LEDs statuses
    
    if (temperature < baselineTemp) {
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
    } else if (baselineTemp + 1 <= temperature && temperature < baselineTemp + 2) {
      digitalWrite(2, HIGH);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
    } else if (baselineTemp + 2 <= temperature && temperature < baselineTemp + 3) {
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
    } else if (baselineTemp + 3 <= temperature) {
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
    }
    delay(5);
  }
}
