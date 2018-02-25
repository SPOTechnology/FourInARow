String read() {
  if (port.available() > 0) {
    String command = port.readStringUntil('\n');
    if (command != null) {
      command = trim(command);
      return command;
    }
  }
  return "empty";
}