#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// Configurations des capteurs
#define DHTPIN 4         // Broche du capteur DHT22
#define DHTTYPE DHT22    // Type de DHT (DHT22 dans ce cas)
#define ONE_WIRE_PIN 5   // Broche du capteur DS18B20
#define PULSE_SENSOR_PIN 34 // Broche du capteur Pulse Sensor

DHT dht(DHTPIN, DHTTYPE);
OneWire oneWire(ONE_WIRE_PIN);
DallasTemperature sensors(&oneWire);

// Informations Wi-Fi
const char* ssid = "Votre_SSID";
const char* password = "Votre_MotDePasse";

// Informations MQTT
const char* mqtt_server = "IP_Raspberry_Pi"; // Exemple : "192.168.1.100"
const char* mqtt_topic = "iot-m/data";
WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);

  // Initialiser les capteurs
  dht.begin();
  sensors.begin();

  // Connexion Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connecté");

  // Connexion au broker MQTT
  client.setServer(mqtt_server, 1883);
  while (!client.connected()) {
    Serial.print("Connexion à MQTT...");
    if (client.connect("ESP32_Client")) {
      Serial.println("connecté");
    } else {
      Serial.print("échec, rc=");
      Serial.print(client.state());
      delay(2000);
    }
  }
}

void loop() {
  if (!client.connected()) {
    while (!client.connect("ESP32_Client")) {
      delay(1000);
    }
  }

  // Lire les données des capteurs
  float temp_dht = dht.readTemperature();
  float hum_dht = dht.readHumidity();

  sensors.requestTemperatures();
  float temp_ds18b20 = sensors.getTempCByIndex(0);

  int pulse_value = analogRead(PULSE_SENSOR_PIN);

  // Vérifiez si les données sont valides
  if (!isnan(temp_dht) && !isnan(hum_dht) && temp_ds18b20 != DEVICE_DISCONNECTED_C) {
    // Formater les données en JSON
    char payload[100];
    sprintf(payload, 
      "{\"temp_dht\": %.2f, \"humidity_dht\": %.2f, \"temp_ds18b20\": %.2f, \"pulse\": %d}", 
      temp_dht, hum_dht, temp_ds18b20, pulse_value
    );

    // Publier les données sur le topic MQTT
    client.publish(mqtt_topic, payload);
    Serial.println(payload);
  } else {
    Serial.println("Erreur dans la lecture des capteurs !");
  }

  delay(5000); // Attendre 5 secondes avant la prochaine publication
}
