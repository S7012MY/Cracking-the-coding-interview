/**
 * Cracking the coding interview 7.8
 * Othello is played as follows: Each Othello piece is white on one side and black on the other
 * When a piece is surrounded by its opponents on both the left and right sides, or both the top and bottom,
 * it is said to be captured and its color is flipped On your turn, you must capture at least one of
 * your opponent’s pieces The game ends when either user has no more valid moves,
 * and the win is assigned to the person with the most pieces Implement the object oriented design for Othello
 * Created by petrutrimbitas on 26/12/13.
 */

class Board {
    private int[][] board;
    public void init() {}
    public int getWinner() {return 0;}
    public boolean canMove(int color) {return true;}
    public boolean isValidMove(String s){return true;}
    public void move(String s) {}
}

class OPlayer {
    int color;
    void move(Board b) {}
    public  String getMove() {return null;}
}

public class OthelloGame {
    private int currentPlayer;
    private Board board;
    private OPlayer[] players=new OPlayer[2];
    public  OthelloGame() {

    }
    private void initGame() {
        currentPlayer=0;
        board.init();
    }

    public void startGame() {
        initGame();
         while (true) {
             if(board.canMove(currentPlayer) || board.canMove(currentPlayer^=1)) {
                 String s=players[currentPlayer].getMove();
                 while(board.isValidMove(s)==false) s=players[currentPlayer].getMove();
                 board.move(s);
                 currentPlayer^=1;
             }else break;
         }
        System.out.println(board.getWinner());
    }
}
