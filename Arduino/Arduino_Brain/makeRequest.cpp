#include "Arduino.h"
#include <SPI.h>
#include <Ethernet.h>
#include "globals.h"

//default url :
// http://connect4.spotechnology.com:8080/cgi-bin/move?_0=000000&_1=000000&_2=000000&_3=000000&_4=000000&_5=000000&_6=000000&p=1

byte mac[] = {0x90, 0xA2, 0xDA, 0x0F, 0x98, 0x0F};

IPAddress house(192, 168, 2, 100); // -- Home -- numeric IP for www.connect4.spotechnology.com (12/2/2017) (no DNS)
IPAddress router(192, 168, 2, 10); // -- Router -- numeric IP for www.connect4.spotechnology.com (12/2/2017) (no DNS)
IPAddress school(172, 16, 110, 69); // -- School -- numeric IP for www.connect4.spotechnology.com (12/2/2017) (no DNS)
IPAddress gym(10, 1, 11, 195); // -- Gym -- numeric IP for www.connect4.spotechnology.com (12/2/2017) (no DNS)

IPAddress ip(192, 168, 2, 11);
EthernetClient client;

String address = "null";

char makeRequest(bool search) {
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    // try to congifure using IP address instead of DHCP:
    Ethernet.begin(mac, ip);
  }
  delay(500);
  //  if (client.connect(house, 80) && (address == "house" || address == "null")) {
  //    address = "house";
  //    getMove(address, search);
  //  } else if (client.connect(school, 80) && (address == "school" || address == "null")) {
  //    address = "school";
  //    getMove(address, search);
  //  } else if (client.connect(gym, 80) && (address == "gym" || address == "null")) {
  //    address = "gym";
  //    getMove(address, search);
  //  } else if (client.connect(router, 80) && (address == "router" || address == "null")) {
  //    address = "router";
  //    getMove(address, search);
  //  } else {
  //    Serial.println("connection failed");
  //    return 'e';
  //  }
  client.connect(router, 80);
  address = "router";
  getMove(address, search);
  char input[1000];
  int offset = 0;
  while (!client.connected()) {
    if (millis() - prevTime > 200) {
      prevTime = millis();
      if (digitalRead(overridePin) == HIGH) {
        Serial.println("O");
        while (digitalRead(overridePin) == HIGH);
      } else {
        Serial.println("U");
      }
    }
  }
  if (digitalRead(overridePin) == HIGH) {
    Serial.println("O");
    while (digitalRead(overridePin) == HIGH);
  } else {
    Serial.println("U");
  }
  while (client.connected()) {
    if (client.available()) {
      input[offset] = client.read();
      ++offset;
    }
  }
  if (!client.connected()) {
    if (millis() - prevTime > 200) {
      prevTime = millis();
      if (digitalRead(overridePin) == HIGH) {
        Serial.println("O");
        while (digitalRead(overridePin) == HIGH);
      } else {
        Serial.println("U");
      }
    }
    client.stop();
    for (int i = 0; i < 993; ++i) {
      if ((input[i] == 's') && (input[i + 1] == ' ') && (input[i + 2] == 't') && (input[i + 3] == 'o') && (input[i + 4] == ':') && (input[i + 5] == ' ')) {
        return input[i + 6];
      }
    }
  }
  return 'e';
}
