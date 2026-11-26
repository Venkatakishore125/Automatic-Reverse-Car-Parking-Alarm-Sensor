/*
  Automatic Reverse Car Parking Alarm Sensor
  Example implementation: Arduino Uno + HC-SR04 + active buzzer

  Wiring:
    HC-SR04 VCC  -> 5V
    HC-SR04 GND  -> GND
    HC-SR04 TRIG -> D9
    HC-SR04 ECHO -> D10
    Buzzer +     -> D6
    Buzzer -     -> GND

  Educational prototype only. Not a certified automotive safety system.
*/

const byte TRIG_PIN = 9;
const byte ECHO_PIN = 10;
const byte BUZZER_PIN = 6;

const unsigned long ECHO_TIMEOUT_US = 30000UL; // About 5 m max echo window
const unsigned long SAMPLE_INTERVAL_MS = 100UL;

const int FAR_THRESHOLD_CM = 150;
const int MEDIUM_THRESHOLD_CM = 100;
const int NEAR_THRESHOLD_CM = 50;
const int VERY_NEAR_THRESHOLD_CM = 20;

unsigned long lastSampleMs = 0;
unsigned long lastBeepMs = 0;
bool buzzerOn = false;

float measureDistanceCm() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(3);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  unsigned long duration = pulseIn(ECHO_PIN, HIGH, ECHO_TIMEOUT_US);
  if (duration == 0) {
    return -1.0f; // No echo / out of range
  }

  return duration / 58.0f;
}

void stopAlert() {
  noTone(BUZZER_PIN);
  buzzerOn = false;
}

void updateAlert(float distanceCm) {
  if (distanceCm < 0 || distanceCm > FAR_THRESHOLD_CM) {
    stopAlert();
    return;
  }

  if (distanceCm <= VERY_NEAR_THRESHOLD_CM) {
    tone(BUZZER_PIN, 2200);
    buzzerOn = true;
    return;
  }

  unsigned long intervalMs;
  if (distanceCm <= NEAR_THRESHOLD_CM) {
    intervalMs = 120;
  } else if (distanceCm <= MEDIUM_THRESHOLD_CM) {
    intervalMs = 350;
  } else {
    intervalMs = 700;
  }

  unsigned long now = millis();
  if (now - lastBeepMs >= intervalMs) {
    lastBeepMs = now;
    buzzerOn = !buzzerOn;
    if (buzzerOn) {
      tone(BUZZER_PIN, 2000);
    } else {
      noTone(BUZZER_PIN);
    }
  }
}

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(TRIG_PIN, LOW);

  Serial.begin(9600);
  Serial.println("Automatic Reverse Car Parking Alarm Sensor");
  Serial.println("Distance (cm) | Status");
}

void loop() {
  unsigned long now = millis();
  if (now - lastSampleMs < SAMPLE_INTERVAL_MS) {
    return;
  }
  lastSampleMs = now;

  float distanceCm = measureDistanceCm();

  Serial.print("Distance: ");
  if (distanceCm < 0) {
    Serial.println("No echo / out of range");
  } else {
    Serial.print(distanceCm, 1);
    Serial.print(" cm | ");
    if (distanceCm <= VERY_NEAR_THRESHOLD_CM) {
      Serial.println("STOP - very close");
    } else if (distanceCm <= NEAR_THRESHOLD_CM) {
      Serial.println("Very near");
    } else if (distanceCm <= MEDIUM_THRESHOLD_CM) {
      Serial.println("Near");
    } else if (distanceCm <= FAR_THRESHOLD_CM) {
      Serial.println("Object detected");
    } else {
      Serial.println("Clear");
    }
  }

  updateAlert(distanceCm);
}
