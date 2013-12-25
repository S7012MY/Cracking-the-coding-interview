/*
 * Design a musical jukebox using object oriented principles
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class song {
private:
	int id,price;
	string title,artist;
public:
	song(/* ... */);
	int get_price() {return price;}
	string get_title(){return title;}
};

class play_list {
private:
	vector<song> song_list;
public:
	play_list();
	void add_song(song s) {
		song_list.push_back(s);
	}
	vector<song> get_songs() {return song_list;}
};

class jukebox {
private:
	vector<song> all_songs;
	int current_money;
public:
	jukebox();
	void add_song_to_jukebox(song s) {all_songs.push_back(s);}
	void set_song_prince();
	void add_money(int c) {current_money+=c;}


	song search_song_title(string s) {
		for(int i=0; i<all_songs.size(); ++i) if(all_songs[i].get_title()==s) return all_songs[i];
		throw 1;
	}
	void play_song(song s);

	void play_play_list(play_list S) {
		vector<song> v=S.get_songs();
		int cost=0;
		for(int i=0; i<v.size(); ++i) cost+=v[i].get_price();
		if(cost>current_money) cout<<"Add more money!";
		else for(int i=0; i<v.size(); ++i) play_song(v[i]);
	}
};

 int main() {

 }