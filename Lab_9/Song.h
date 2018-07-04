#ifndef SONG_H
#define SONG_H

#include <string>
using namespace std;

class Song
{
	public:
		Song(string name = "No name", string lyrics = "No lyrics");
		~Song();
		string GetName();
		string GetLyrics();
		int GetNumTimesPlayed();
	private:
		string name;
		string lyrics;
		int timesPlayed;
};

#endif 

