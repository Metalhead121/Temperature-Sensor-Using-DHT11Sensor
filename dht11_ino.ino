#include "DHT.h"

#define DHTPIN 2 // Digital pin connected to the DHT sensor

#define DHTTYPE DHT11 // DHT 11
//#define DHTTYPE DHT22 // DHT 22 (AM2302), AM2321
//#define DHTTYPE DHT21 // DHT 21 (AM2301)
  

DHT dht(DHTPIN, DHTTYPE);

void setup()
{ 
  Serial.begin(9600);
  Serial.println(F("DHTxx test !"));

  dht.begin();
}
 void loop() 
 {
   delay(2000); //wait a few seconds between measurements.

   // Reading temperature or humidity takes about 250 milliseconds.
   // Sensor readings may also be up to 2 seconds 'old'(its a very slow sensor)
   float h = dht.readHumidity(); // Read humidity
   float t = dht.readTemperature(); // Read temperature as Celcius (the Default)
   float f = dht.readTemperature(true); // Read temperature as Fahrenheit (isFahrenheit = true)

   // Check if any reads failed and exit early (to try again).
   if (isnan(h) || isnan(t) || isnan(f))
   {
     Serial.println(F("Failed to read from DHT sensor!"));
     return;
   }

   // Compute heat index in Fahrenheit (the default)
   float hif = dht.computeHeatIndex(f,h);
   // Compute heat index in Celsius (isFahrenheit = false)
   float hic = dht.computeHeatIndex(t,h,false);

   //LOWEST TEMPERATURE CODE
   if(t<=33.00)
   {
     Serial.print("\n\nLOW TEMPERATURE\n\n");
   }
    //HIGHEST TEMPERATURE CODE
   if(t>=35.00)
   {
     Serial.print("\n\nHIGH TEMPERATURE\n\n");
   }

   Serial.print(F("Humidity: "));
   Serial.print(h);
   Serial.print(F("%  Temperature: "));
   Serial.print(t);
   Serial.print(F("°C "));
   Serial.print(f);
   Serial.print(F("°F  Heat index: "));
   Serial.print(hic);
   Serial.print(F("°C "));
   Serial.print(hif);
   Serial.println(F("°F"));
 }