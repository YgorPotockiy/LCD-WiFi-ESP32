#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Set the LCD I2C address and dimensions
WebServer server(80);

// Including header files
#include "webSite.h"

const char* ssid = "Your SSID";
const char* password = "Password of your network";

void ClearHalfDisplay(int column, int row);
void handleSubmit();
void handleRefreshDisplay();
void handleCSS();
void handleRoot();
void handleNotFound();
void setupServer();
void WiFiStart();

void setup() {
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.clear();
  WiFiStart();
  setupServer();
}

void loop() {
  server.handleClient();
}

void WiFiStart(){
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

void ClearHalfDisplay(int column, int row){
  // SORRY FOR THIS FUNCTION, I DIDN'T KNOW HOW TO CLEAR ONLY ONE LINE

  lcd.setCursor(column, row);
  lcd.print("                "); // Clear the line
  lcd.setCursor(column, row);
}

void handleSubmit() {
  if (server.hasArg("text")) {
    String text = server.arg("text");
    server.send(200, "text/html", index_html);
    Serial.println("Received text: " + text);
    ClearHalfDisplay(0, 0);
    lcd.print(text);
  }
  if (server.hasArg("text2")) {
    String text2 = server.arg("text2");
    server.send(200, "text/html", index_html);
    Serial.println("Received text2: " + text2);
    ClearHalfDisplay(0, 1);
    lcd.print(text2);
  }
}

void handleRefreshDisplay(){
  server.send(200, "text/html", index_html);
  Serial.println("Command to clear display received");
  ClearHalfDisplay(0, 0);
  ClearHalfDisplay(0, 1);
}

void handleCSS(){
  server.send(200, "text/css", main_css);
}

void handleRoot(){
  server.send(200, "text/html", index_html);
}

void handleNotFound(){
  server.send(404, "text/plain", "Not found");
}

void setupServer(){
  server.on("/", handleRoot);
  server.on("/main.css", handleCSS);
  server.on("/submit", handleSubmit);
  server.on("/refresh/button", handleRefreshDisplay);
  server.onNotFound(handleNotFound);
  server.begin();
  Serial.println("HTTP server started");
}
