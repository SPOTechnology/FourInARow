void lose() {
  background(255, 0, 0);
  drawGrid();
  showDisks();
  for (int i = 0; i < 7; ++i) {
    horDoor[i].show();
    vertDoor[i].show();
  }
}