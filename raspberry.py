import paho.mqtt.client as mqtt
import requests
import json

BROKER = "localhost"  # Adresse du broker MQTT (ou IP du Raspberry Pi)
TOPIC = "iot-m/temperature"
API_ENDPOINT = "https://example-cloud.com/api/data"  # Remplacez par l'URL de votre cloud

# Fonction appelée lorsque des messages sont reçus
def on_message(client, userdata, msg):
    print(f"Message reçu sur {msg.topic}: {msg.payload.decode()}")
    data = json.loads(msg.payload.decode())

    # Envoyer les données au cloud
    response = requests.post(API_ENDPOINT, json=data)
    print(f"Cloud Response: {response.status_code} - {response.text}")

# Configuration MQTT
client = mqtt.Client()
client.on_message = on_message

client.connect(BROKER, 1883, 60)
client.subscribe(TOPIC)

print("Client MQTT en cours d'exécution...")
client.loop_forever()
