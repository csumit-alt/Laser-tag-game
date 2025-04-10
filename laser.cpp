#include <SoftwareSerial.h>
#include <TinyGPS++.h>
#include <RH_ASK.h>
#include <SPI.h> 

// ---------------- Pin Definitions ----------------
#define LASER_PIN        5
#define HIT_SENSOR_PIN   2
#define LED_PIN          6
#define RELOAD_BUTTON    8
#define RF_DATA_PIN      12  
// RF data pin (connect to TX on 433MHz)

// GPS
SoftwareSerial gpsSerial(4, 9);  // RX, TX
TinyGPSPlus gps;

// RF Transmitter
RH_ASK rfDriver(2000, -1, RF_DATA_PIN);  // 2000bps, no RX, TX pin only

// Game Logic
int ammo = 100;
bool isHit = false;
unsigned long hitTime = 0;

void setup() {
  Serial.begin(9600);
  gpsSerial.begin(9600);
  
  pinMode(LASER_PIN, OUTPUT);
  pinMode(HIT_SENSOR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(RELOAD_BUTTON, INPUT_PULLUP);

  if (!rfDriver.init()) {
    Serial.println("RF init failed!");
  }

  digitalWrite(LASER_PIN, LOW);
}

void loop() {
  handleGPS();
  checkReloadButton();
  checkHitSensor();
  controlLaser();

  if (isHit && millis() - hitTime < 3000) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
    isHit = false;
  }
}

void controlLaser() {
  if (!isHit && ammo > 0) {
    digitalWrite(LASER_PIN, HIGH);
    delay(100);
    digitalWrite(LASER_PIN, LOW);
    ammo--;
    delay(100);
  }
}

void checkHitSensor() {
  if (digitalRead(HIT_SENSOR_PIN) == LOW && !isHit) {
    isHit = true;
    hitTime = millis();
    digitalWrite(LASER_PIN, LOW);
    sendHitData();
  }
}

void checkReloadButton() {
  if (digitalRead(RELOAD_BUTTON) == LOW) {
    ammo = 100;
    delay(500);  // Debounce
  }
}

void handleGPS() {
  while (gpsSerial.available()) {
    gps.encode(gpsSerial.read());
  }
}

void sendHitData() {
  char msg[100];

  if (gps.location.isUpdated()) {
    snprintf(msg, sizeof(msg), "HIT at %.6f,%.6f", gps.location.lat(), gps.location.lng());
  } else {
    snprintf(msg, sizeof(msg), "HIT at Unknown location");
  }

  rfDriver.send((uint8_t *)msg, strlen(msg));
  rfDriver.waitPacketSent();

  Serial.println(msg);
}
