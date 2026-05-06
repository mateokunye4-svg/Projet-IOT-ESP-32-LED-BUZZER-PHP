include <WiFi.h>
#include <HTTPClient.h>
#include <WebServer.h>

// ===== WIFI =====
const char* ssid = "TPSN035";
const char* password = "BTSSN2022";

// serveur PHP (envoi valeur)
const char* serverName = "http://192.168.100.173/btsciel/TP08/index.php";

// ===== SERVEUR WEB LOCAL =====
WebServer server(80);

// ===== PIN =====
int ledPin = 5;
int buzzerPin = 26;

// ===== TEMPS ENVOI =====
unsigned long lastSend = 0;
const unsigned long interval = 5000; // 5s

// =====================
// BOUTON LED
// =====================
void handleLED() {
  digitalWrite(ledPin, HIGH);
  delay(300);
  digitalWrite(ledPin, LOW);

  server.send(200, "text/plain", "LED OK");
}

// =====================
// BOUTON SON
// =====================
void handleSON() {
  ledcWriteTone(buzzerPin, 1000);
  delay(300);

  ledcWriteTone(buzzerPin, 500);
  delay(300);

  ledcWriteTone(buzzerPin, 0);

  server.send(200, "text/plain", "BUZZER OK");
}

// =====================
// ENVOI VALEUR ALEATOIRE
// =====================
void sendRandomValue() {
  if (WiFi.status() == WL_CONNECTED) {

    int valeur = random(0, 100);

    HTTPClient http;
    http.begin(serverName);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");

    String data = "valeur=" + String(valeur);
    int code = http.POST(data);

    Serial.print("Valeur envoyée: ");
    Serial.println(valeur);

    if (code > 0) {
      Serial.print("HTTP OK: ");
      Serial.println(code);
    } else {
      Serial.print("Erreur HTTP: ");
      Serial.println(code);
    }

    http.end();
  }
}

// =====================
// SETUP
// =====================
void setup() {
  Serial.begin(115200);

  pinMode(ledPin, OUTPUT);

  // buzzer (comme ton code fonctionnel)
  ledcAttach(buzzerPin, 2000, 8);

  WiFi.begin(ssid, password);

  Serial.print("Connexion WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnecté !");
  Serial.println(WiFi.localIP());

  randomSeed(analogRead(0));

  // routes serveur web
  server.on("/led", handleLED);
  server.on("/son", handleSON);

  server.begin();
}

// =====================
// LOOP
// =====================
void loop() {
  server.handleClient();

  // envoi toutes les 5 secondes sans bloquer le serveur
  if (millis() - lastSend >= interval) {
    lastSend = millis();
    sendRandomValue();
  }
}