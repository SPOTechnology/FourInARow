void setup() {
  // put your setup code here, to run once:
  const int sensor[7] = {22, 23, 24, 25, 26, 27, 28};
  for (int i = 0; i < 7; ++i) {
    pinMode(sensor[i], INPUT);
  }
  // Open serial communications and wait for port to open
  Serial.begin(9600);
  while (!Serial);
}

void loop() {
  for (int i = 0; i < 7; ++i) {
    if(digitalRead(sensor[i] == LOW){
      Serial.println(i);
    }
  }
}
