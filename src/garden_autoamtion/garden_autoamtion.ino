// Import required libraries
#include <Ultrasonic.h>
#include <LibPrintf.h>

// Define infrared sensor pin

#define IR 3

// Define temperature sensor analog input pins

#define temp1 A1
#define temp2 A5
#define temp3 A3

// Define pins for LED and buzzer alerts

#define yellow_led 8
#define BUZZER 12

// Define relay output pins
#define rele1 4
#define rele2 6
#define rele3 7

// Initialize ultrasonic sensor (Trigger: pin 11, Echo: pin 10)

Ultrasonic ultrasonic(11, 10);

void setup() {

  Serial.begin(9600);  // Initialize serial communication

  // Configure output pins for alerts and relays

  pinMode(yellow_led, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(rele1, OUTPUT);
  pinMode(rele2, OUTPUT);
  pinMode(rele3, OUTPUT);

  // Configure IR sensor pin as input

  pinMode(IR, INPUT);

  // Set up interrupt to disable relays when the IR sensor is triggered

  attachInterrupt(digitalPinToInterrupt(IR), disable_reles, RISING);
}

void loop() {

  // Read raw values from temperature sensors

  unsigned int sensor1 = analogRead(temp1);
  unsigned int sensor2 = analogRead(temp2);
  unsigned int sensor3 = analogRead(temp3);

  // Map raw sensor values to a 0–100 scale

  unsigned int temp_map = map(sensor1, 0, 1023, 0, 100);
  unsigned int temp_map_2 = map(sensor2, 0, 1023, 0, 100);
  unsigned int temp_map_3 = map(sensor3, 0, 1023, 0, 100);

  // Read distance from ultrasonic sensor

  int distance = ultrasonic.read();

  // Calculate time-of-flight (ToF) in microseconds

  float tof = distance * 58;

  // Debug procedure (manually activate if needed)
  //debug_sensors(temp_map, temp_map_2, temp_map_3, distance);

  // Condition: bucket is full

  if (distance > 0 && distance < 12 && tof > 0.3) {

    Serial.println("Bucket is full");

    // Call relay control lambda

    auto rele_control(temp_map, temp_map_2, temp_map_3);

  } else {

    // Condition: bucket is empty

    disable_reles();  // Disable all relays

    delay(5);  // Small delay before alert

    bucket_is_empty();  // Trigger alert procedure
  }
}
