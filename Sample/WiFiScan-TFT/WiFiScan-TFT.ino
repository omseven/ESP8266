
/*   
 NodeMCU With 2.2″ TFT SPI
 Sample     : WiFi Scanner 
 Date       : 06.28.2016
 Version    : 1.0
 Code       : https://github.com/omseven/ESP8266/
------------------------------------------------
 TFT Pin       NodeMCU Pin         Use
  GND             GND             Ground
  VCC            3.3V             Power
  RST             D2            LCD Reset
  D/C             D1            LCD Control
  CS              D8             LCD Data
 MOSI             D7             LCD Data           
 SCK              D6             LCD Clock
 MISO             D5             LCD Data    
----------------------------------------------
*/
#include "ESP8266WiFi.h"
#include <UTFT.h>
#include <SPI.h> // not necessary if Arduino IDE version >=1.6.6

// Declare which fonts we will be using
extern uint8_t SmallFont[];
extern uint8_t BigFont[];
 
// Modify the line below to match your display and wiring:
UTFT myGLCD ( ILI9341_S5P, 15, 4, 5 );

void setup() {

 // Setup the LCD
    myGLCD.InitLCD (  );
    myGLCD.setFont ( SmallFont );    
    myGLCD.clrScr (  );
    myGLCD.setColor ( 255, 0, 0 );
    myGLCD.fillRect ( 0, 0, 319, 13 );
    myGLCD.setColor ( 64, 64, 64 );
    myGLCD.fillRect ( 0, 226, 319, 239 );
    myGLCD.setColor ( 255, 255, 255 );
    myGLCD.setBackColor ( 255, 0, 0 );
    myGLCD.print ( String("* WiFi Scaner *"), CENTER, 1 );
    myGLCD.setBackColor ( 64, 64, 64 );
    myGLCD.setColor ( 255, 255, 0 );
    myGLCD.print ( String("Development By OMSEVEN"), CENTER, 227 );
    myGLCD.setColor ( 0, 0, 255 );
    myGLCD.drawRect ( 0, 14, 319, 225 );
    
  Serial.begin(115200);

  // Set WiFi to station mode and disconnect from an AP if it was previously connected
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  Serial.println("Setup done");
}

void loop() {
  
  Serial.println("scan start");

  // WiFi.scanNetworks will return the number of networks found
  int n = WiFi.scanNetworks();
  Serial.println("scan done");
  // Clear the screen and draw the frame
      myGLCD.setColor ( 0, 0, 0 );
      myGLCD.fillRect ( 1, 50, 318, 224 );
  if (n == 0){
    Serial.println("no networks found");
    myGLCD.setColor ( 255, 255, 0 );
    myGLCD.setBackColor ( 0, 0, 0 );
    myGLCD.setFont(BigFont); // Allows 15 rows of 20 characters
    myGLCD.print ( String("no networks found"), CENTER, 20 );
  }
  else{
    Serial.print(n);
    Serial.println(" Networks Found");
    myGLCD.setColor ( 128, 255, 0 );
    myGLCD.setBackColor ( 0, 0, 0 );
    myGLCD.setFont(BigFont); // Allows 15 rows of 20 characters
    myGLCD.print ( String("Networks Found"), CENTER, 20 );
    for (int i = 0; i < n; ++i)
    {
   // Show LCD SSID and RSSI for each network found
      myGLCD.printNumI(i+1, 12, 20);
      myGLCD.printNumI(i+1, 12, ((i+1)*20)+40);
      myGLCD.print ( String(":"), 30, ((i+1)*20)+40 );
      myGLCD.print ( String(WiFi.SSID(i)), 50, ((i+1)*20)+40 );
      myGLCD.print ( String(WiFi.RSSI(i)), 220, ((i+1)*20)+40 );
      myGLCD.print ( String("dB"), 275, ((i+1)*20)+40 );
    // Print SSID and RSSI for each network found   
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i));
      Serial.print(")");
      
      delay(10);
    }
  }
  Serial.println("");

  // Wait a bit before scanning again
  delay(5000);
}
