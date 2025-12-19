#include <ESP8266WiFi.h>


// Wi-Fi Credentials
const char* ssid = "iPhone";         // Replace with your Wi-Fi SSID
const char* password = "@&477103";   // Replace with your Wi-Fi password

#define BLYNK_TEMPLATE_ID "TMPL3BhA8QLSW"
#define BLYNK_TEMPLATE_NAME "tmi"
#define BLYNK_AUTH_TOKEN "foNIOfVvk-xcYF8SUxqIjelF51j2PyGH"
#include <BlynkSimpleEsp8266.h>

// Pins for the ultrasonic sensor
int trigPin = D4;
int echoPin = D6;

BlynkTimer timer;

void setup() {
  Serial.begin(9600);
  
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi");
  
  // Connect to Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, password);
  
  // Set a timer to send the sensor data every 5 seconds
  timer.setInterval(2500L, sendSensorStatus);
  
  // Configure sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  Blynk.run();
  timer.run();
}

// Function to measure distance and send status to Blynk
void sendSensorStatus() {
  // Send a pulse to start measuring distance
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measure the duration of the pulse to calculate distance
  long duration = pulseIn(echoPin, HIGH);
  float distance = (duration * 0.0343) / 2;

  // Determine slot status based on distance
  String slotStatus = (distance < 20) ? "Slot 3: occupied" : "Slot 3: free";
  
  // Print the status for debugging
  Serial.println(slotStatus);

  // Send the status to Virtual Pin V0 on Blynk
  Blynk.virtualWrite(V2, slotStatus);
}
