#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

char* myWriteAPIKey = "insertApiKey";
unsigned long myChannelNumber = "yourc channel number";
const char* server = "api.thingspeak.com";

const char *ssid =  "your ssid";     // replace with your wifi ssid and wpa2 key
const char *pass =  "your pass";

WiFiClient client;

#define MQPIN 0

int sensorValue;

int genRandom(){
  return (rand()%(20-0+1))+0; //upper-lower+1
}

void setup()
{
  Serial.begin(9600);      // sets the serial port to 9600
  Serial.println("Connecting to ");
       Serial.println(ssid);
 
 
       WiFi.begin(ssid, pass);
 
      while (WiFi.status() != WL_CONNECTED) 
     {
            delay(500);
            Serial.print(".");
     }
      Serial.println("");
      Serial.println("WiFi connected");

 
  ThingSpeak.begin(client );
}

void loop()
{
  sensorValue = analogRead(0);       // read analog input pin 0
  Serial.println(sensorValue, DEC);  // prints the value read

  //Change the fieldValue for each Node!.
  ThingSpeak.setField(1, sensorValue);

  //genRandom for testing Purposes!.
  //ThingSpeak.setField(2, sensorValue + genRandom());
  //ThingSpeak.setField(3, sensorValue + genRandom());
  //ThingSpeak.setField(4, sensorValue + genRandom());
    //ThingSpeak.setField(5, sensorValue + genRandom());
    //ThingSpeak.setField(6, sensorValue + genRandom());
    //ThingSpeak.setField(7, sensorValue + genRandom());
    //ThingSpeak.setField(8, sensorValue + genRandom());

  ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);  
  delay(20000);                        
}


