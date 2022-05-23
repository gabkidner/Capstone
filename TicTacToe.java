public class TicTacToe{
  private char mySymbol;
  private char userSymbol;
  public TicTacToe(char playerSymbol){
    userSymbol = playerSymbol;
    if(playerSymbol == 'x'){
      mySymbol = 'o';
    }
    else{
      mySymbol = 'x';
    }
  }
  public void game(int space){
    
  }
}
