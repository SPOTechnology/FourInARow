class VertDoor {
  int x;
  int y;
  boolean state = false;
  VertDoor(int _x, int _y) {
    x = _x;
    y = _y;
  }
  void dOpen() {
    state = true;
  }
  void dClose() {
    state = false;
  }
  void show() {
    strokeWeight(9);
    if (state) {
      stroke(0, 255, 0);
    } else {
      stroke(255, 0, 0);
    }
    line(x, x < 700 ? y - 10 : y, x+130, x < 700 ? y - 20 : y - 10);
  }
}

class HorDoor {
  int x;
  int y;
  boolean state = false;
  HorDoor(int _x, int _y) {
    x = _x;
    y = _y;
  }
  void dOpen() {
    state = true;
  }
  void dClose() {
    state = false;
  }
  void show() {
    strokeWeight(9);
    if (state) {
      stroke(0, 255, 0);
    } else {
      stroke(255, 0, 0);
    }
    line(x, y-10, x, y-100);
  }
}