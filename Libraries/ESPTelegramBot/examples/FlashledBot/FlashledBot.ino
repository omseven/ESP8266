#include "ESPTelegramBot.h"
#include <ESP8266WiFi.h>

// Initialize Wifi connection to the AProuter
char ssid[] = "********";                                         // your network SSID (name)
char pass[] = "********";                                         // your network key  (pass)
													              
// Initialize Telegram BOT (Sample @FlashledBOT in telegram)
#define BOTtoken "134745667:AAETzUWRQdb9xbMX_s-q_50U6ffgXcW3ldg"  //token of FlashledBOT
#define BOTname "FlashledBot"                                     //name BOT
#define BOTusername "FlashledBot_bot"                             //username BOT

ESPTBot bot(BOTtoken, BOTname, BOTusername);

int Bot_mtbs = 1000;                                             //mean time between scan messages
long Bot_lasttime;                                               //last time messages' scan has been done
bool Start = false;


//function to Echo messages 
void Bot_ExecMessages() {
	for (int i = 1; i < bot.message[0][0].toInt() + 1; i++) {
		bot.message[i][5] = bot.message[i][5].substring(1, bot.message[i][5].length());
		if (bot.message[i][5] == "\/ledon") {
			digitalWrite(LED_BUILTIN, LOW);                      // turn the LED on (HIGH is the voltage level)
			bot.sendMessage(bot.message[i][4], "Led is ON", "");
		}
		if (bot.message[i][5] == "\/ledoff") {
			digitalWrite(LED_BUILTIN, HIGH);                    // turn the LED off (LOW is the voltage level)
			bot.sendMessage(bot.message[i][4], "Led is OFF", "");
		}
		if (bot.message[i][5] == "\/start") {
			String wellcome = "Wellcome to FlashLedBot, your personal Bot on ESP8266 board";
			String wellcome1 = "/ledon : Switch the Led ON";
			String wellcome2 = "/ledoff : Switch the Led OFF";
			bot.sendMessage(bot.message[i][4], wellcome, "");
			bot.sendMessage(bot.message[i][4], wellcome1, "");
			bot.sendMessage(bot.message[i][4], wellcome2, "");
			Start = true;
		}
	}
	bot.message[0][0] = "";                                     // All messages have been replied - reset new messages
}

// the setup function runs once when you press reset or power the board
void setup() {
	delay(1000);
	Serial.begin(115200);
	Serial.println("Booting");
	WiFi.mode(WIFI_STA);
	WiFi.begin(ssid, pass);
	while (WiFi.waitForConnectResult() != WL_CONNECTED) {
		Serial.println("Connection Failed! Rebooting...");
		delay(5000);
		ESP.restart();
	}
	if (WiFi.waitForConnectResult() == WL_CONNECTED) {
		Serial.println("");
		Serial.println("WiFi connected");
		Serial.println("IP address: ");
		Serial.println(WiFi.localIP());
	}
	bot.begin();                                // launch Bot functionalities
	pinMode(LED_BUILTIN, OUTPUT);               // initialize digital pin 2 as an output.
	digitalWrite(LED_BUILTIN, HIGH);            // turn off LED.
}

// the loop function runs over and over again until power down or reset
void loop() {

	if (millis() > Bot_lasttime + Bot_mtbs) {
		bot.getUpdates(bot.message[0][1]);     // launch API GetUpdates up to xxx message
		Bot_ExecMessages();                    // reply to message with Echo
		Bot_lasttime = millis();
	}
