void showDisks() {
  for (int x = 0; x < 7; ++x) {
    for (int y = 0; y < 6; ++y) {
      float diskX = map(x, 0, 6, 555, 1335);
      float diskY = map(y, 0, 5, 955, 305);
      noStroke();
      fill(0);
      ellipse(diskX, diskY, 125, 125);
      if (brd[x][y] == 1) {
        noStroke();
        fill(255, 0, 0);
        ellipse(diskX, diskY, 120, 120);
      } else if (brd[x][y] == 2) {
        noStroke();
        fill(255, 225, 0);
        ellipse(diskX, diskY, 120, 120);
      } else {
        fill(200);
        ellipse(diskX, diskY, 120, 120);
      }
    }
  }
  for (int x = 0; x < 7; ++x) {
    if (spot[x] == true) {
      noStroke();
      fill(255, 225, 0);
      ellipse(map(x, 0, 6, 555, 1335), map(x, 0, 6, 122, 62), 120, 120);
      fill(0);
      textSize(55);
      textAlign(CENTER, CENTER);
      text(x, map(x, 0, 6, 554, 1334), map(x, 0, 6, 118, 58));
    }
  }
}