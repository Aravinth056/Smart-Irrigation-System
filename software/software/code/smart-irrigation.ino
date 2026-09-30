#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "Smart Irrigation"
#define BLYNK_AUTH_TOKEN "YOUR_BLYNK_AUTH_TOKEN"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Wi-Fi
char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

// Pin definitions
#define SOIL_PIN 34
#define DHT_PIN 4
#define DHT_TYPE DHT11

#define RELAY_PIN 26
#define RED_LED 27
#define GREEN_LED 25

// Components
DHT dht(DHT_PIN, DHT_TYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Soil moisture threshold
int soilDry = 2500;

// Temperature and humidity limits
float tempLimit = 35.0;
float humLimit = 80.0;

// Pump status
bool motorStatus = false;

BlynkTimer timer;

// -----------------------------
// Read sensors and control pump
// -----------------------------
void readSensors()
{
  int soilValue = analogRead(SOIL_PIN);

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity))
  {
    Serial.println("DHT sensor error");
    return;
  }

  Serial.print("Soil Moisture: ");
  Serial.println(soilValue);

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  // Irrigation control
  if (soilValue > soilDry &&
      temperature > tempLimit &&
      humidity < humLimit)
  {
    digitalWrite(RELAY_PIN, HIGH);
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);

    motorStatus = true;
  }
  else
  {
    digitalWrite(RELAY_PIN, LOW);
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);

    motorStatus = false;
  }

  // LCD display
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(temperature, 1);
  lcd.print("C H:");
  lcd.print(humidity, 0);
  lcd.print("%");

  lcd.setCursor(0, 1);

  if (motorStatus)
  {
    lcd.print("Moist:LOW P:ON");
  }
  else
  {
    lcd.print("Moist:OK P:OFF");
  }

  // Send data to Blynk
  Blynk.virtualWrite(V0, soilValue);
  Blynk.virtualWrite(V1, temperature);
  Blynk.virtualWrite(V2, humidity);
  Blynk.virtualWrite(V3, motorStatus);
}

// -----------------------------
// Manual pump control from Blynk
// -----------------------------
BLYNK_WRITE(V4)
{
  int value = param.asInt();

  if (value == 1)
  {
    digitalWrite(RELAY_PIN, HIGH);
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);

    motorStatus = true;
  }
  else
  {
    digitalWrite(RELAY_PIN, LOW);
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);

    motorStatus = false;
  }
}

// -----------------------------
// Setup
// -----------------------------
void setup()
{
  Serial.begin(115200);

  pinMode(RELAY_PIN, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  digitalWrite(RELAY_PIN, LOW);
  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, HIGH);

  dht.begin();

  Wire.begin();

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Smart Irrigation");

  lcd.setCursor(0, 1);
  lcd.print("System Starting");

  delay(2000);

  lcd.clear();

  // Connect to Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  // Read sensors every 2.5 seconds
  timer.setInterval(2500L, readSensors);
}

// -----------------------------
// Main loop
// -----------------------------
void loop()
{
  Blynk.run();
  timer.run();
}
