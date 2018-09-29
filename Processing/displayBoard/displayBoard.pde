import processing.serial.*;
Serial port;

VertDoor[] vertDoor = new VertDoor[7];
HorDoor[] horDoor = new HorDoor[7];

int[][] brd = new int[7][6];
boolean[] spot = new boolean[8];

boolean thinking = false;
boolean override = false;
boolean over = false;

String program = "Minimax";

void setup() {
  size(1920, 1080);
  port = new Serial(this, "/dev/ttyACM0", 9600);
  port.bufferUntil('\n');

  vertDoor[0] = new VertDoor(490, 200);
  vertDoor[1] = new VertDoor(620, 190);
  vertDoor[2] = new VertDoor(750, 180);
  vertDoor[2] = new VertDoor(750, 170);
  vertDoor[3] = new VertDoor(880, 160);
  vertDoor[4] = new VertDoor(1010, 150);
  vertDoor[5] = new VertDoor(1140, 140);
  vertDoor[6] = new VertDoor(1270, 130);

  horDoor[0] = new HorDoor(620, 190);
  horDoor[1] = new HorDoor(750, 180);
  horDoor[2] = new HorDoor(880, 170);
  horDoor[3] = new HorDoor(1010, 160);
  horDoor[4] = new HorDoor(1140, 150);
  horDoor[5] = new HorDoor(1270, 140);
  horDoor[6] = new HorDoor(1400, 130);

  reset();
}

void draw() {
  if (!over) {
    background(200);
    drawGrid();
  }
  checkCommand();
  if (!over) {
    showDisks();
    for (int i = 0; i < 7; ++i) {
      horDoor[i].show();
      vertDoor[i].show();
    }
    displayProgram();
    if (thinking) {
      displayThinking();
    }    
    if (override) {
      displayOverride();
    }
  }
}
