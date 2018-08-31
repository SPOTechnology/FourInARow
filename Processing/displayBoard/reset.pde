void reset() {
  over = false;
  for (int x = 0; x < 7; ++x) {
    horDoor[x].dClose();
    vertDoor[x].dClose();
  }
  for (int x = 0; x < 7; ++x) {
    spot[x] = false;
  }
  for (int x = 0; x < 7; ++x) {
    for (int y = 0; y < 6; ++y) {
      brd[x][y] = 0;
    }
  }
}
