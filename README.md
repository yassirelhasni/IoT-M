# IoT-M
A medical IoT system to monitor biometric data (temperature, heart rate, oxygen saturation) in real time via sensors connected to ESP32s. This data is transmitted to a Raspberry Pi 4, which relays it to a cloud platform for storage and visualization.
So in this project, we will learn how to make IoT Based Patient Health Monitoring System Project. We will use the MAX30100/102 Pulse Oximeter sensor to measure the Heart Rate/Pulse(BPM) as well as the Blood Oxygen Level(SpO2). We will use a DS18B20 Temperature Sensor to measure the temperature of the body. Similarly Patient needs to be placed in a room with a certain temperature and humidity level so that he doesn’t feel uncomfortable. In order to do that we need to monitor the room temperature and humidity as well. So we will be using DHT11 Humidity & Temperature Sensor.
To build this project, you will need the following components: an ESP32 board (1 unit), a MAX30100 Pulse Oximeter Sensor (1 unit), a DS18B20 temperature sensor (1 unit), a DHT11 temperature and humidity sensor (1 unit), a 4.7K resistor (1 unit), and a breadboard (1 unit).
# MAX30100 Pulse Oximeter Sensor
The sensor is integrated pulse oximetry and heart-rate monitor sensor solution. It combines two LED’s, a photodetector, optimized optics, and low-noise analog signal processing to detect pulse and heart-rate signals. It operates from 1.8V and 3.3V power supplies and can be powered down through software with negligible standby current, permitting the power supply to remain connected at all times.
![MAX30100-300x300](https://github.com/user-attachments/assets/c88313ce-160a-495c-b24d-3f554c4b1c04)

The device has two LEDs, one emitting red light, another emitting infrared light. For pulse rate, only the infrared light is needed. Both the red light and infrared light is used to measure oxygen levels in the blood. When the heart pumps blood, there is an increase in oxygenated blood as a result of having more blood. As the heart relaxes, the volume of oxygenated blood also decreases. By knowing the time between the increase and decrease of oxygenated blood, the pulse rate is determined.

It turns out, oxygenated blood absorbs more infrared light and passes more red light while deoxygenated blood absorbs red light and passes more infrared light. This is the main function of the MAX30100: it reads the absorption levels for both light sources and stored them in a buffer that can be read via I2C.

# DS18B20 Temperature Sensor
This is a pre-wired and waterproofed version of the DS18B20 sensor. Handy for when you need to measure something far away, or in wet conditions. The Sensor can measure the temperature between -55 to 125°C (-67°F to +257°F). The cable is jacketed in PVC.

Because it is digital, there is no signal degradation even over long distances. These 1-wire digital temperature sensors are fairly precise, i.e ±0.5°C over much of the range. It can give up to 12 bits of precision from the onboard digital-to-analog converter. They work great with any microcontroller using a single digital pin.
![waterproof-temperature-sensor-ds18b20-300x249](https://github.com/user-attachments/assets/19ac0fec-f626-45b8-af4d-40c130b97480)

DS18B20 DATASHEET: 
[DS18B20.PDF](https://github.com/user-attachments/files/17990132/DS18B20.PDF)


# DHT11 Humidity & Temperature Sensor
The DHT11 is a basic, ultra low-cost digital temperature and humidity sensor. It uses a capacitive humidity sensor and a thermistor to measure the surrounding air, and spits out a digital signal on the data pin (no analog input pins needed).
![DHT11-Humidity-Temperature-Sensor-360x360](https://github.com/user-attachments/assets/43e484cb-f6f2-4d46-b9ce-1f0eb5b76135)

It’s fairly simple to use, but requires careful timing to grab data. The only real downside of this sensor is you can only get new data from it once every 2 seconds, so when using the library, sensor readings can be up to 2 seconds old.

# IoT Based Patient Health Monitoring on ESP32 Web Server
Now let us begin with the designing of IoT Based Patient Health Monitoring on ESP32 Web Server. So the circuit digram for interfacing MAX30100, DHT11 & DS18B20 with ESP32 is given below.

![Screenshot 2024-12-03 095146](https://github.com/user-attachments/assets/6c8433c0-eb4c-41ea-a1da-c4e56b3681a8)

-----------------------------------------------------------------------------------------------------------------------------
# IoT-M Mobile App

Similarly you can also view the Patient Health Status on Mobile Phone.
![WhatsApp Image 2024-12-03 at 20 06 43](https://github.com/user-attachments/assets/a71e619d-804f-4cb9-a5f8-8c085cd83671)

# ...


