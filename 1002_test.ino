#include <AsyncTCP.h>
#include "WiFi.h"
#include "SPIFFS.h"
#include "ESPAsyncWebServer.h"
 
const char* ssid = "B315-DB58";
const char* password =  "t25450089";
 
AsyncWebServer server(80);

void setup() {
//  Serial.begin(115200);
//  if(!SPIFFS.begin(true)){
//    Serial.println("An Error has occurred while mounting SPIFFS");
//    return;
//  }
//  
//  File file = SPIFFS.open("/index.html");
//  if(!file){
//    Serial.println("Failed to open file for reading");
//    return;
//  }
//  
//  Serial.println("File Content:");
//  while(file.available()){
//    Serial.write(file.read());
//  }
//  file.close();
  
  Serial.begin(115200);
   
  if(!SPIFFS.begin()){
       Serial.println("An Error has occurred while mounting SPIFFS");
       return;
  }
   
  WiFi.begin(ssid, password);
   
  while (WiFi.status() != WL_CONNECTED) {
      delay(1000);
      Serial.println("Connecting to WiFi..");
  }

  Serial.println(WiFi.status()); 
  Serial.println(WiFi.localIP());

  server.on("/html", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send(SPIFFS, "/index.html", "text/html");
  });

  server.begin();
}

void loop() {
  // put your main code here, to run repeatedly:

}
