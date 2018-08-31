void lose() {
  over = true;
  background(255, 0, 0);
  drawGrid();
  showDisks();
  for (int i = 0; i < 7; ++i) {
    horDoor[i].show();
    vertDoor[i].show();
  }
  pushMatrix();
  fill(0);
  textSize(350);
  text("YOU LOSE", width/2, height/2-50);
  popMatrix();
}
