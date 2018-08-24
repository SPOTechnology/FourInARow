const int sensor[7] = {22, 23, 24, 25, 26, 27, 28};
const int horDoor[7] = {29, 30, 31, 32, 33, 34, 35};
const int vertDoor[7] = {36, 37, 38, 39, 40, 41, 42};

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 7; ++i) {
    pinMode(sensor[i], INPUT);
    pinMode(horDoor[i], OUTPUT);
    pinMode(vertDoor[i], OUTPUT);
    digitalWrite(horDoor[i], HIGH);
    digitalWrite(vertDoor[i], HIGH);
  }
  // Open serial communications and wait for port to open
  Serial.begin(9600);
  while (!Serial);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    bool vert;
    bool Open;
    int number;
    bool fail = false;
    String input = Serial.readString();
    if (input) {
      if (input[0] == 'o') {
        Open = true;
      } else if (input[0] == 'c') {
        Open = false;
      } else {
        fail = true;
      }
      if (input[1] == 'v') {
        vert = true;
      } else if (input[1] == 'h') {
        vert = false;
      } else {
        fail = true;
      }
      if (input[2] >= '0' && input[2] <= '6') {
        number = input[2] - 48;
      } else {
        fail = true;
      }
    }

    if (!fail) {
      if (vert) {
        digitalWrite(vertDoor[number], Open ? LOW : HIGH);
        Serial.print(Open ? "Opened " : "Closed ");
        Serial.print("vertDoor: ");
        Serial.println(number);
      } else {
        digitalWrite(horDoor[number], Open ? LOW : HIGH);
        Serial.print(Open ? "Opened " : "Closed ");
        Serial.print("horDoor: ");
        Serial.println(number);
      }
    } else {
      Serial.println("fail");
    }
  }



  for(int i = 0; i < 7; ++i){
    if(digitalRead(sensor[i]) == LOW){
      Serial.println(i);
    }
  }
}

//input format >> _-_ >> o/c, v/h, 0-6

