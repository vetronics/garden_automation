/*
  Debug flag:
  Set to 0 to disable debug output.
  Set to 1 to enable debug output and uncomment the call to debug_sensors()
  in garden_automation.ino (line 68).
*/

#define DEBUG_LEVEL 0

#if DEBUG_LEVEL > 0

// Debug procedure: prints sensor values with controlled delay for monitoring

void debug_sensors(unsigned int &temp_map, unsigned int &temp_map_2, unsigned int &temp_map_3, int &distance) {

  printf("Water level by ultrasonic tof:\n");

  delay(100);

  Serial.println(distance);

  printf("Temp sensor 1:\n");

  delay(200);

  Serial.println(temp_map);

  printf("Temp sensor 2:\n");

  delay(300);

  Serial.println(temp_map_2);

  printf("Temp sensor 3:\n");

  delay(400);

  Serial.println(temp_map_3);


}

#endif

// Procedure (lambda) to control relays based on temperature

auto rele_control = [](unsigned int &temp_map, unsigned int &temp_map_2, unsigned int &temp_map_3) {

  // millis variables
  
  int unsigned long t1, t2;

  t1 = millis();

  t2 = 0;

  if (temp_map > 0 && temp_map < 100 && t1 - t2 > 100 && t1 - t2 < 200) {


    digitalWrite(rele1, LOW);

  } else if (temp_map_2 > 0 && temp_map_2 < 100 && t1 - t2 > 200 && t1 - t2 < 300) {


    digitalWrite(rele2, LOW);

  } else if (temp_map_3 > 300 && temp_map_3 < 400) {


    digitalWrite(rele3, LOW);
  }

  digitalWrite(rele1, HIGH);
  digitalWrite(rele2, HIGH);
  digitalWrite(rele3, HIGH);

  t1 = t2;
};

// Procedure to alert the user when the bucket is empty using buzzer and LED

void bucket_is_empty() {

  // couter for loop

  int j;

  for (j = 8000; j > 0; j = j - 1000) {

    tone(BUZZER, j);  // Emit tone at decreasing frequencies

    delay(100);  // Tone duration

    noTone(BUZZER);  // Stop tone

    digitalWrite(yellow_led, !digitalRead(yellow_led));  // Toggle LED

    delay(500);  // Delay between blinks
  }
}

// Procedure to disable all relays (set output HIGH)

void disable_reles() {

  digitalWrite(rele1, HIGH);
  digitalWrite(rele2, HIGH);
  digitalWrite(rele3, HIGH);
}
