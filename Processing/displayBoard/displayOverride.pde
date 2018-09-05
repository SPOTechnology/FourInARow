void displayOverride() {
  ++reps;
  if (reps % 50 < 25) {
    pushMatrix();
    fill(0, 200, 0);
    textSize(350);
    text("OVERRIDE", width/2, height/2-50);
    popMatrix();
  }
  if (reps > 50) {
    reps = 0;
  }
}
