import java.util.ArrayList;

/**
 * Cracking the coding interview 7.1
 * Design the data structures for a generic deck of cards Explain how you would sub- class it to implement particular
 * card games
 * Created by petrutrimbitas on 26/12/13.
 */

enum Color {
    spades,diamonds,hearts,clubs
}

abstract  class Card {
    protected int value=0;
    protected Color cardColor = null;
    public int getValue() {return value;}
    public Color getColor() {return cardColor;}
    public void setValue(int v) {value=v;}
    public Card(int v,Color cc) {
        value=v;
        cardColor=cc;
    }
}

class BlackjackCard extends Card {
    public BlackjackCard(int v, Color cc) {
        super(v, cc);
    }

    public int getValue() {
        if(value==1) return 11;
        if(value<10) return value;
        return 10;
    }
}

public abstract class DeckOfCards {
    private ArrayList<Card> deck;
    DeckOfCards() {

    }
    void shuffleDeck() {}
}
