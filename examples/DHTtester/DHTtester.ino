#include <DHT_TAI.h>


#define DHTPIN 2     // what pin we're connected to

void setup() {
  Serial.begin(115200);
  Serial.println("DHTxx test!");
}

void loop() {
  float h, t;
  DHT_read(DHTPIN, &h, &t);

  // check if returns are valid, if they are NaN (not a number) then something went wrong!
  if (isnan(t) || isnan(h)) {
    Serial.println("Failed to read from DHT");
  } else {
    Serial.print("Humidity: ");
    Serial.print(h);
    Serial.print(" %\t");
    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.println(" *C");
  }
}
