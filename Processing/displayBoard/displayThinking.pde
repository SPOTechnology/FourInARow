int reps;

void displayThinking() {
  ++reps;
  if (reps % 50 < 25) {
    pushMatrix();
    fill(0, 200, 0);
    textSize(350);
    text("THINKING", width/2, height/2-50);
    popMatrix();
  }
  if (reps > 50) {
    reps = 0;
  }
}
