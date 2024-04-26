#include <WiFi.h>
#include <WebServer.h>
#include <C:\Users\mengi\OneDrive\Documents\Arduino\CofeMachineAdapter\Arduino Code\Cofe_website_serving_v3\CofeWeb.h>
#define indicLED 15

// Replace with your network credentials
const char* ssid  = "Coffee_Machine";
const char* password = "12345";

IPAddress local_ip(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

WebServer server(80);



void setup() {
  Serial.begin(115200);
  pinMode(indicLED,OUTPUT);

  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);

  server.on("/", onConnect);
  server.on("/cofeOn", cofeOn);
  server.on("/cofeOff", cofeOff);
  server.onNotFound(notFound);

  server.begin();
  WiFi.begin(ssid, password);
}

void loop() {
  server.handleClient();
}

void onConnect(){
  digitalWrite(indicLED,HIGH);
  delay(3000);
  digitalWrite(indicLED,LOW);
  server.send(200, "text/html", webpage);
}
void cofeOn(){
  digitalWrite(indicLED,HIGH);
  delay(3000);
  digitalWrite(indicLED,LOW);
  server.send(200, "text/html", webpage);
}
void cofeOff(){
  digitalWrite(indicLED,HIGH);
  delay(3000);
  digitalWrite(indicLED,LOW);
}
void notFound(){
  server.send(404,"text/plain", "Page Not Found. We don't got a dino game, so hop to it.");
}
