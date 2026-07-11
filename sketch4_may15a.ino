#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include "DHT.h"

// ---------------- WIFI ----------------
const char* ssid = "ThambuIQOO";
const char* password = "12345678";

// ---------------- TELEGRAM ----------------
#define BOTtoken "8738317028:AAHOH5qP1ei4CmA0dhE15SJMdB8fVm3ztTo"
#define CHAT_ID "1254832389"

WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

// ---------------- DHT SENSOR ----------------
#define DHTPIN 15
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

// ---------------- PINS ----------------
#define VIBRATION_PIN 34
#define BUZZER_PIN 23

void setup() {

  Serial.begin(115200);

  pinMode(VIBRATION_PIN, INPUT);

  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(BUZZER_PIN, LOW);

  dht.begin();

  // -------- WIFI --------
  WiFi.begin(ssid, password);

  Serial.print("Connecting");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi Connected!");

  client.setInsecure();

  bot.sendMessage(CHAT_ID,
                  "✅ Smart Hazard System Started",
                  "");
}

void loop() {

  float temperature = dht.readTemperature();

  float humidity = dht.readHumidity();

  int vibration = digitalRead(VIBRATION_PIN);

  // -------- CHECK DHT --------
  if (isnan(temperature) || isnan(humidity)) {

    Serial.println("DHT Sensor Error!");

    delay(2000);

    return;
  }

  Serial.println("------------");

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.print("Vibration: ");
  Serial.println(vibration);

  bool alert = false;

  String message = "⚠ ALERT ⚠\n\n";

  // -------- TEMP ALERT --------
  if (temperature > 33) {

    message += "🌡 High Temperature\n";
    message += String(temperature);
    message += " °C\n\n";

    alert = true;
  }

  // -------- HUMIDITY ALERT --------
  if (humidity > 50) {

    message += "💧 High Humidity\n";
    message += String(humidity);
    message += " %\n\n";

    alert = true;
  }

  // -------- VIBRATION ALERT --------
  // Most SW420 modules:
  // HIGH = vibration detected
  if (vibration == HIGH) {

    message += "📳 Vibration Detected\n\n";

    alert = true;
  }

  // -------- ALERT ACTION --------
  if (alert) {

    digitalWrite(BUZZER_PIN, HIGH);

    bot.sendMessage(CHAT_ID, message, "");

    delay(3000);

    digitalWrite(BUZZER_PIN, LOW);
  }

  delay(2000);
}