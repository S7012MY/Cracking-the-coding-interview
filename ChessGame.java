import java.util.ArrayList;

/**
 * Cracking the coding interview 7.4
 * Design a chess game using object oriented principles
 * Created by petrutrimbitas on 26/12/13.
 */

enum ChessColor {
    white,black
}

abstract class ChessPiece {
    protected int x,y;
    protected ChessColor pieceColor;
    abstract boolean isValidMove(int nx,int ny);
}

class Kting extends ChessPiece {
    boolean isValidMove(int nx,int ny) {
        if(Math.abs(nx-x)>1 || Math.abs(ny-y)>1) return false;
        return true;
    }
}

class Position {
    private ArrayList<ChessPiece> pieces;
    boolean validMoves(){return true;}
}

class Player {
    private ChessColor color;
    public Position move(Position p) {return p;}
}

public class ChessGame {
    private Player wp,bp;
    ChessColor currentPlayer;
    Position currentState;
    public void newGame() {
        currentState =new Position();
        currentPlayer=ChessColor.white;
    }
    public void beginGame() {
        while(currentState.validMoves()==true) {
            if(currentPlayer==ChessColor.white) {
                currentState=wp.move(currentState);
                currentPlayer=ChessColor.black;
            }else {
                currentState=bp.move(currentState);
                currentPlayer=ChessColor.white;
            }
        }
    }
}
