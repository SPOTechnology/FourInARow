void keyPressed() {
  if (key == 'a' || key == 'b'  || key == 'm' || key == 'n' || key == 'r') {
    port.write(key);
    return;
  }
  if (key >= '0' && key <= '6') {
    if (brd[int(key) - 48][5] == 0) {
      port.write(key);
      return;
    }
  }  
  background(0, 255, 0);
  drawGrid();
  showDisks();
  for (int i = 0; i < 7; ++i) {
    horDoor[i].show();
    vertDoor[i].show();
  }
}