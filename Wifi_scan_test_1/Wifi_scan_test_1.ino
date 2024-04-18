#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include "CofeWeb.h"
#define indicLED 15
#define light 35

AsyncWebServer server(80); //creates server object
//Servo myServo; //creates servo object

char* ssid = "HOME-1AF2";
char* psswrd = "49CCF2818B9449DB";



void setup() {
  Serial.begin(115200);
  pinMode(indicLED, OUTPUT);

  //myServo.attach(2); 
  //myServo.write(0); //initializes the servos position to 0 degrees or resets it
  
  bool connection = false;
  bool state = networkSearch(connection); //network search returns true or false
  if (state == true){
    connection = connectWiFi(state); //if the homeNetwork is found then it runs the connectWifi function.
  }
  Serial.println(WiFi.localIP());
  server.on("/", HTTP_GET, [](AsyncWebServerRequest* request) {
    Serial.println("ESP32 Web Server: New request received:");  // for debugging
    Serial.println("GET /");        // for debugging
    request->send(200, "text/html", "<html><body><h1>Hello, ESP32!</h1></body></html>");
  });
  server.begin(); //start server
}

//with arduino you have to define the datatype of your parameter when passing it into a function
//If the function returns a value, you must also define the datatype of the function when declaring it. E.g., there is a void before setup and loop. this means
//the voide datatype will be returned (meaning nothing). If you return an integer for example you must write int funcName(){}

bool networkSearch(bool connection){
  int networks = WiFi.scanNetworks();
  if (networks !=0 & connection == false){
    //prints how many networks there are and the flashing LED Indicates that there are networks present.
    Serial.println(networks); 
    Serial.println("Networks found");
    digitalWrite(indicLED, HIGH);
    delay(2000);
    digitalWrite(indicLED, LOW);
  }
  else{
    Serial.println("no networks found");
  }

  bool homeNetworkState = false; //only turns true when the home network Raya_fam is found
  int i = 0;

  while (homeNetworkState == false && i<networks){ //iterates for networks num amount of times and if homeNetwork hasn't changed. 
    if (WiFi.SSID(i) == ssid){
      homeNetworkState = true;
      Serial.println("Desired Network Found!");
      break;
    }
    ++i;
  }
  return homeNetworkState;
}

bool connectWiFi(bool state) {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, psswrd); //preset to home wifi address
  Serial.print("Connecting to WiFi ..");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(1000);
  }
  Serial.println('Wifi connected');
  bool connectedState = true;
  return connectedState;
}


void loop() {
}