/*
 * Rui Santos 
 * Complete Project Details http://randomnerdtutorials.com
 */
 
#include <TinyGPS.h>
#include <SoftwareSerial.h>

static const int RXPin = 7, TXPin = 6;
static const uint32_t GPSBaud = 9600;

// The TinyGPS++ object
TinyGPS gps;

// The serial connection to the GPS device
SoftwareSerial ss(RXPin, TXPin);

void setup(){
  Serial.begin(9600);
  ss.begin(GPSBaud);
}

void loop(){
  // This sketch displays information every time a new sentence is correctly encoded.
  while (ss.available() > 0){
    long latitude, longitude;
    unsigned long idadeInfo;
    Serial.println(".");
    if (gps.encode(ss.read())){
      gps.get_position(&latitude, &longitude, &idadeInfo);
    if (latitude != TinyGPS::GPS_INVALID_F_ANGLE) {
        Serial.print("Latitude: ");
        Serial.println(float(latitude) / 1000000, 6);
     }

     if (longitude != TinyGPS::GPS_INVALID_F_ANGLE) {
        Serial.print("Longitude: ");
        Serial.println(float(longitude) / 1000000, 6);
     }

     if (idadeInfo != TinyGPS::GPS_INVALID_AGE) {
        Serial.print("Idade da Informacao (ms): ");
        Serial.println(idadeInfo);
     }
    }
    
  }
}
