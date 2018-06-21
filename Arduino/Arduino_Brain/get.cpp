#include "Arduino.h"
#include "globals.h"

void getMove(String server, bool search) {
  char buff[300]; // buff is large enough to hold the entire formatted string
  sprintf(buff, "GET /cgi-bin/move?_0=%06ld&_1=%06ld&_2=%06ld&_3=%06ld&_4=%06ld&_5=%06ld&_6=%06ld&p=%01d&s=%01d HTTP/1.1", _0, _1, _2, _3, _4, _5, _6, program, search ? 1 : 0);
  String request = String(buff);
  client.println(request);

  /* 
  if (server == "house") {
    client.println("Host: 192.168.2.100");  //home
  } else if (server == "school") {
    client.println("Host: 172.16.110.69"); //school
  } else if (server == "gym") {
    client.println("Host: 10.1.11.195");  //gym
  } else if (server == "router") {
  */
    client.println("Host: 192.168.2.10");  //router
  //}

  client.println("Connection: close");
  client.println();
}

