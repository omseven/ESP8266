![enter image description here](https://cloud.githubusercontent.com/assets/16634570/16920749/29b3a92a-4d24-11e6-84ea-f480dbe1f524.png)

#Hosting a Telegram Bot on the ESP8266 

An Arduino IDE library around the Telegram Bot API to be used with ESP8266.

----------

## Introduction

This library provides an interface for [Telegram Bot API](https://core.telegram.org/bots/api). It is written using Arduino IDE and works using ESP8266.

----------

##Installing

You can download the library [here](https://github.com/omseven/ESP8266/tree/master/Libraries/ESPTelegramBot).

You can include a new .ZIP library into the Arduino IDE by selecting the menu: **Sketch / include Library / Add .Zip library**. 
You also have to install the [Arduino JSON](https://github.com/bblanchon/ArduinoJson) library from the [library manager](https://www.arduino.cc/en/Guide/Libraries#toc3).

----------

##Getting started

First thing to do is to create a new bot.

Be sure you have installed [Telegram](https://telegram.org/apps) on your phone or your laptop, then, in the search bar, look for [@botfather](https://telegram.me/botfather).

![enter image description here](https://cloud.githubusercontent.com/assets/16634570/16921068/56574166-4d25-11e6-95fc-8c4617685466.png)

Talk to him and use the **/newbot** command to create a new bot. The BotFather will ask you for a **name** and **username**, then generate an authorization **token** for your new bot.

The **Name** of your bot will be displayed in contact details and elsewhere.

The **Username** is a short name, to be used in mentions and telegram.me links. Your bot's username must end in ‘bot’, e.g. ‘tetris_bot’ or ‘TetrisBot’.   [See more ...](https://core.telegram.org/bots)

Now that we have our new bot we can set it to do what we want.

In this example we will make it turn on and off a LED by texting him a simple '**/ledon** or **/ledoff** ' message.


----------


## Examples


- [FlashledBot.ino](https://github.com/omseven/ESP8266/blob/master/Libraries/ESPTelegramBot/examples/FlashledBot/FlashledBot.ino) : Switch on and off the led of your ESP8266 Board.
-  [@FlashledBot](https://telegram.me/FlashledBot_bot) : Telegram Sample Bot.


