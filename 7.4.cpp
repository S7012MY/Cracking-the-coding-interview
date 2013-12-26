/*
 * Design a chess game using object oriented principles
 */

#include <cstdlib>
#include <list>
using namespace std;

enum color{black,white};

 class piece {
 private:
 	int x,y;
 	color piece_color;
 public:
 	int get_x() {return x;}
 	int get_y() {return y;}
 	color get_color(){return piece_color;}
 	void set_x(int nx) {x=nx;}
 	void set_y(int ny) {y=ny;}
 	void move(int new_x,int new_y) {
 		set_y(new_y);
 		set_x(new_x);
 	}
 	virtual bool is_valid_move(int,int)=0;
 };

class king:public piece {
 	bool is_valid_moove(int new_x,int new_y) {
 		if(abs(new_x-get_x())>1 || abs(new_y-get_y())>1) return false;
 		return true;
 	}
};

class position {
private:
 	list<piece*> white,black;
 public:
 	bool check_mate();
};

class player {
private:
	enum color player_color;
public:
	color get_color() {return player_color;}
	position move(position p);
};

class game {
private:
	position current_pos;
	enum color current_player;
	player bp,wp;
public:
	game();
	void set_pieces();
	void new_game() {
		set_pieces();
		current_player=white;
	}
	void begin_game() {
		while(!current_pos.check_mate()) {
			if(current_player==white){
				current_pos=wp.move(current_pos);
				current_player=black;
			}
			else {
				current_pos=bp.move(current_pos);
				current_player=white;
			}
		}
	}
};

int main() {

}