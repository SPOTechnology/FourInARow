const int sensor[7] = {22, 23, 24, 25, 26, 27, 28};
const int horDoor[7] = {29, 30, 31, 32, 33, 34, 35};
const int vertDoor[7] = {36, 37, 38, 39, 40, 41, 42};
const int loadedPin = 53;

void setup() {
  for (int i = 0; i < 7; ++i) {
    pinMode(sensor[i], INPUT);
    pinMode(horDoor[i], OUTPUT);
    pinMode(vertDoor[i], OUTPUT);
    digitalWrite(horDoor[i], HIGH);
    digitalWrite(vertDoor[i], HIGH);
  }
  pinMode(loadedPin, INPUT);
  Serial.begin(9600);
  while (!Serial);
}

void loop() {
  if (Serial.available()) {
    int col = Serial.readString().toInt();
    Serial.println(col);
    drop(col);
  }
  for (int i = 0; i < 7; ++i) {
    if (digitalRead(sensor[i]) == LOW) {
      Serial.print("Sensor: ");
      Serial.println(i);
    }
  }
}

void vert(String str, int gate) {
  if (str == "open") {
    digitalWrite(vertDoor[gate], LOW);
    Serial.println("openVert");
    Serial.println(gate);
  } else {
    digitalWrite(vertDoor[gate], HIGH);
    Serial.println("closeVert");
    Serial.println(gate);
  }
}

void hor(String str, int gate) {
  if (str == "open") {
    digitalWrite(horDoor[gate], LOW);
    Serial.println("openHor");
    Serial.println(gate);
  } else {
    digitalWrite(horDoor[gate], HIGH);
    Serial.println("closeHor");
    Serial.println(gate);
  }
}

void spot (String str, int col) {
  if (str == "on") {
    Serial.println("onSpot");
    Serial.println(col);
  } else {
    Serial.println("offSpot");
    Serial.println(col);
  }
}

void drop(int col) {
  while (digitalRead(loadedPin) == HIGH);
  delay(1000);
  for (int i = 6; i > col + 1; --i) {
    hor("open", i);
    spot("off", i);
    spot("on", i - 1);
    delay(1300);
    hor("close", i);
  }
  vert("open", col);
  hor("open", col + 1);
  spot("off", col + 1);
  spot("on", col);
  delay(1300);
  hor("close", col + 1);
  vert("close", col);
  spot("off", col);
  delay(1500);
  spot("on", 6);
}
