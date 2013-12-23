/*
 *
 * Design the data structures for a generic game of cards.
 * Explain how would you subclass it to implement particular card games
 *
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

enum card_color {spades,clubs,hearts,diamonds};

class card {
public:
	int value;
	card_color color;
	card(enum card_color c,int v) {
		color=c;
		value=v;
	}
};

class black_jack_card:public card {
	int get_value() {
		if(value==1) return 11;
		if(value<10) return value;
		return 10;
	}
};

class card_game {
private:
	vector<card> deck;
	int index;
public:
	card_game() {
		for(int i=1; i<=13; ++i) {
			deck.push_back(card(spades,i));
			deck.push_back(card(clubs,i));
			deck.push_back(card(hearts,i));
			deck.push_back(card(diamonds,i));
		}
		index=0;
	}

	void shuffle_deck() {
		random_shuffle(deck.begin(), deck.end());
	}

	void new_game() {
		shuffle_deck();
		index=0;
	}

	card deal_card() {
		if(index==deck.size()) {
			throw 1;
		}
		return deck[index++];
	}
};

class black_jack:public card_game {
public:
	black_jack(){
	}
};

int main() {
	black_jack *bj=new black_jack();
	bj->new_game();
}