#include <WiFi.h>
#include <WebServer.h>
#include <C:\Users\mengi\OneDrive\Documents\Arduino\CofeMachineAdapter\Arduino Code\Cofe_website_serving_v3\CofeWeb.h>
#include <Stepper.h>
#define indicLED 15

int motorSpeed = 10;
Stepper CofeStepper(2048, 5,19,18,21);



// Replace with your network credentials
const char* ssid  = "Coffee_Machine";
const char* password = "12345";

IPAddress local_ip(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

WebServer server(80);

void setup() {
  CofeStepper.setSpeed(motorSpeed);
  CofeStepper.step(0); //initialize position

  Serial.begin(115200);
  pinMode(indicLED,OUTPUT);

  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);

  server.on("/", onConnect);
  server.on("/cofeOn", cofeOn);
  //server.on("/cofeOff", cofeOff);
  server.onNotFound(notFound);

  server.begin();
  WiFi.begin(ssid, password);
}

void loop() {
  server.handleClient();
}

void onConnect(){ //basically the setup function when website is served
  digitalWrite(indicLED,HIGH);
  delay(3000);
  digitalWrite(indicLED,LOW);
  server.send(200, "text/html", webpage);
}
void cofeOn(){ //when brew button is pressed
  digitalWrite(indicLED,HIGH);
  CofeStepper.step(512);
  delay(3000);

  CofeStepper.step(-512);
  digitalWrite(indicLED,LOW);
  delay(3000);
  server.send(200, "text/html", webpage);
}
/*void cofeOff(){
  digitalWrite(indicLED,HIGH);
  delay(3000);
  digitalWrite(indicLED,LOW);
}*/
void notFound(){
  server.send(404,"text/plain", "Page Not Found. We don't got a dino game, so hop to it.");
}
