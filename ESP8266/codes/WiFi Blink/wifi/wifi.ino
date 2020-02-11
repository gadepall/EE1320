#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server(80); // Create a webserver object listens HTTP request on port 80

const char* ssid = "B603"; //Enter Wi-Fi SSID
const char* password =  "RESEARCH"; //Enter Wi-Fi Password

void setup(){
  Serial.begin(115200); //Begin Serial at 115200 Baud
  WiFi.begin(ssid, password);  //Connect to the WiFi network
  
  while (WiFi.status() != WL_CONNECTED) {  //Wait for connection
      delay(500);
      Serial.println("Waiting to connect...");
  }
  
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //Print the local IP

  server.on("/", HTTP_GET, handleRoot);        // Call 'handleRoot' function
  server.on("/login", HTTP_POST, handleLogin); // Call 'handleLogin' function when a POST request made to "/login"
  server.onNotFound(handleNotFound);           // call function "handleNotFound" when unknown URI requested

  server.begin();                            // start the server
  Serial.println("HTTP server started");
}

void loop(){
  server.handleClient();                     // Listen for HTTP requests
}

void handleRoot() {                          // When URI / is requested, make login Webpage
  server.send(200, "text/html", "<form action=\"/login\" method=\"POST\"><input type=\"text\" name=\"uname\" placeholder=\"Username\"></br><input type=\"password\" name=\"pass\" placeholder=\"Password\"></br><input type=\"submit\" value=\"Login\"></form><p>Try 'User1' and 'Pass1' ...</p>");
}

void handleLogin() {                         //Handle POST Request
  if( ! server.hasArg("uname") || ! server.hasArg("pass") 
      || server.arg("uname") == NULL || server.arg("pass") == NULL) { // Request without data
    server.send(400, "text/plain", "400: Invalid Request");         // Print Data on screen
    return;
  }
  if(server.arg("uname") == "User1" && server.arg("pass") == "Pass1") { // If username and the password are correct
    server.send(200, "text/html", "<h1>Hello, " + server.arg("uname") + "!</h1><p>Login successful</p>");
  } else {                                                                              // Username and password don't match
    server.send(401, "text/plain", "401: Invalid Credentials");
  }
}

void handleNotFound(){
  server.send(404, "text/plain", "404: Not found"); // Send HTTP status 404 (Not Found)
}
