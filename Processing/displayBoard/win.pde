void win() {
  over = true;
  background(0, 255, 0);
  drawGrid();
  showDisks();
  for (int i = 0; i < 7; ++i) {
    horDoor[i].show();
    vertDoor[i].show();
  }  
  pushMatrix();
  fill(0);
  textSize(350);
  text("YOU WIN", width/2, height/2-50);
  popMatrix();
}
