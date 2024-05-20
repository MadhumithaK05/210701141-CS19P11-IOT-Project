int pirPin = 2;
int relayPin = 3;
int ldrPin = A0;
int pirState = LOW;
int fanState = LOW;
bool fanOn = false;
int ldrThreshold = 500; // LDR threshold value for LED control void setup() {
pinMode(pirPin, INPUT);
pinMode(relayPin, OUTPUT);
pinMode(ldrPin, INPUT);
digitalWrite(relayPin, fanState); // Set initial fan state Serial.begin(9600); // Initialize serial communication
}
void loop() {
pirState = digitalRead(pirPin); // Read the PIR sensor state // If motion is detected and fan is off, turn on the fan
if (pirState == HIGH && fanState == LOW) {
fanState = HIGH;
digitalWrite(relayPin, fanState); // Turn on the fan
fanOn = true; // Set the flag
Serial.println("Motion detected! Fan turned on."); // Print message delay(1000); // Delay to avoid multiple detections
}
// If no motion is detected and fan is on, turn off the fan
else if (pirState == LOW && fanState == HIGH && fanOn) {
fanState = LOW;
digitalWrite(relayPin, fanState); // Turn off the fan
fanOn = false; // Reset the flag
Serial.println("No motion detected. Fan turned off."); // Print message delay(1000); // Delay to avoid multiple detections
}
int ldrValue = analogRead(ldrPin); // Read the LDR sensor and control the LED
if (ldrValue > ldrThreshold) { digitalWrite(4, HIGH); // Turn on the LED
} else {
digitalWrite(4, LOW); // Turn off the LED
}
delay(100); // Delay for stability }
