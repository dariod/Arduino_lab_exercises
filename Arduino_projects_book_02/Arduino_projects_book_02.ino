int switchState=0;


void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT);
  
  // Blink LEDs when starting
  digitalWrite(3, LOW); // Green LED
  digitalWrite(4, HIGH);  // Red LED
  digitalWrite(5, HIGH);  // Red LER
  
  delay(100);
  digitalWrite(4, LOW);  // Red LED
  digitalWrite(5, LOW);  // Red LER

  delay(100); 
  digitalWrite(4, HIGH);  // Red LED
  digitalWrite(5, HIGH);  // Red LER

  delay(100);
  digitalWrite(4, LOW);  // Red LED
  digitalWrite(5, LOW);  // Red LER

  delay(100);
}

void loop() {
  // put your main code here, to run repeatedly:
  switchState = digitalRead(2);
  if ( switchState == LOW ) {
    // Button is not pressed
    digitalWrite(3, HIGH); // Green LED
    digitalWrite(4, LOW);  // Red LED
    digitalWrite(5, LOW);  // Red LER
  } else {
    // The button is pressed
    digitalWrite(3, LOW);  // Greeen LED
    digitalWrite(4, LOW);  // Red LED
    digitalWrite(5, HIGH); // Red LED

    delay(250);
    
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);

    delay(250);
  }
}
