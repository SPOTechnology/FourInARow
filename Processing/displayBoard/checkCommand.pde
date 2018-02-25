void checkCommand() {
  String command = read();
  if (!command.equals("empty")) {
    if (command.equals("openVert")) {
      while (command.equals("empty") || command.equals("openVert")) {
        command = read();
      }
      vertDoor[Integer.parseInt(command)].dOpen();
      spot[Integer.parseInt(command)] = false;
      return;
    }
    if (command.equals("closeVert")) {
      while (command.equals("empty") || command.equals("closeVert")) {
        command = read();
      }
      vertDoor[Integer.parseInt(command)].dClose();
      return;
    }  
    if (command.equals("openHor")) {
      while (command.equals("empty") || command.equals("openHor")) {
        command = read();
      }
      horDoor[Integer.parseInt(command)].dOpen();
      return;
    }  
    if (command.equals("closeHor")) {
      while (command.equals("empty") || command.equals("closeHor")) {
        command = read();
      }
      horDoor[Integer.parseInt(command)].dClose();
      return;
    }  
    if (command.equals("onSpot")) {
      while (command.equals("empty") || command.equals("onSpot")) {
        command = read();
      }
      spot[Integer.parseInt(command)] = true;
      return;
    }  
    if (command.equals("offSpot")) {
      while (command.equals("empty") || command.equals("offSpot")) {
        command = read();
      }
      spot[Integer.parseInt(command)] = false;
      return;
    }  
    if (command.equals("board")) {
      for (int x = 0; x < 7; ++x) {
        command = read();
        while (command.equals("empty")) {
          command = read();
        }
        char[] board = command.toCharArray();
        for (int y = 0; y < 6; ++y) {
          brd[6-x][5-y] = int(board[y])-48;
        }
      }
      return;
    }  
    if (command.equals("YouWin")) {
      win();
      return;
    }  
    if (command.equals("YouLose")) {
      lose();
      return;
    }  
    if (command.equals("Tie")) {
      lose();
      return;
    }  
    if (command.equals("reset")) {
      reset();
      return;
    }  
    if (command.equals("M")) {
      program = "Minimax";
      displayProgram();
      return;
    }  
    if (command.equals("N")) {
      program = "Neural\nNetwork";
      displayProgram();
      return;
    }  
    if (command.equals("A")) {
      program = "Alpha-Beta";
      displayProgram();
      return;
    }  
    if (command.equals("B")) {
      program = "Benimax";
      displayProgram();
      return;
    }  
  }
}