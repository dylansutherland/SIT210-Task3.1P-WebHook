// Include library for DHT22 temperature sensor
#include <Adafruit_DHT.h>

// Define which pin on board the sensor is connected to
#define DHTPIN 3 
// Define type of sensor
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() 
{
    Serial.begin(9600); 

	dht.begin();
}

void loop() 
{
    delay(2000);
    
    // Read humidity 
    float h = dht.getHumidity();
    // Read temperature as Celsius
	float t = dht.getTempCelcius();
    
    // Check if any reads failed and exit early (to try again).
	if (isnan(h) || isnan(t)) {
		Serial.println("Failed to read from DHT sensor!");
		return;
	}
    
    //Publish the temperature to ThingSpeak as a string
    String temp = String(t);
    Particle.publish("temp", temp, PRIVATE);
}
