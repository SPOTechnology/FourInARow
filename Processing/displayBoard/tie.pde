void tie() {  
  over = true;
  background(0, 0, 255);
  drawGrid();
  showDisks();
  for (int i = 0; i < 7; ++i) {
    horDoor[i].show();
    vertDoor[i].show();
  }
  pushMatrix();
  fill(0);
  textSize(350);
  text("TIE", width/2, height/2-50);
  popMatrix();
}
