#define BLYNK_TEMPLATE_ID "TMPL30I2LECiX"
#define BLYNK_TEMPLATE_NAME "IOT HOME"
#define BLYNK_AUTH_TOKEN "-75L71oz96CodDlcA2rNPs1_rrkg9vtD"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Replace with your network credentials
char ssid[] = "987654321";  // WiFi SSID
char password[] = "987654321";  // WiFi Password



static const uint8_t D0   = 16;
static const uint8_t D1   = 5;
static const uint8_t D2   = 4;
static const uint8_t D3   = 0;
static const uint8_t D4   = 2;
static const uint8_t D5   = 14;
static const uint8_t D6   = 12;
static const uint8_t D7   = 13;
static const uint8_t D8   = 15;

// Pin Definitions for the LEDs
const int led1Pin = D1;  // GPIO5
const int led2Pin = D2;  // GPIO4
const int led3Pin = D3;  // GPIO0

// Blynk virtual pins
#define VIRTUAL_PIN_1 V1
#define VIRTUAL_PIN_2 V2
#define VIRTUAL_PIN_3 V3

// Setup Blynk
BlynkTimer timer;

void setup() {
  // Start the serial monitor
  Serial.begin(115200);

  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Start Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, password);

  // Initialize LED pins
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);

  // Turn off LEDs initially
  digitalWrite(led1Pin, HIGH);
  digitalWrite(led2Pin, HIGH);
  digitalWrite(led3Pin, HIGH);
}

// Blynk virtual button handlers
BLYNK_WRITE(VIRTUAL_PIN_1) {
  int pinValue = param.asInt(); // Read the value of the virtual button (0 or 1)
  digitalWrite(led1Pin, !pinValue); // Turn the LED on/off
}

BLYNK_WRITE(VIRTUAL_PIN_2) {
  int pinValue = param.asInt(); // Read the value of the virtual button (0 or 1)
  digitalWrite(led2Pin, !pinValue); // Turn the LED on/off
}

BLYNK_WRITE(VIRTUAL_PIN_3) {
  int pinValue = param.asInt(); // Read the value of the virtual button (0 or 1)
  digitalWrite(led3Pin, !pinValue); // Turn the LED on/off
}

void loop() {
  Blynk.run();  // Run Blynk
  timer.run();  // Run Blynk Timer (if you want to use timers in the future)
}