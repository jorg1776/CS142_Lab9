#ifndef PLAYLIS_H
#define PLAYLIST_H

#include "Song.h"
#include <string>
#include <vector>
using namespace std;

class Playlist
{
	public:
		Playlist(string name = "No name");
		~Playlist();
		string GetName();
		void AddSong(Song*);
		void RemoveSong(int songIndex);
		vector<Song*> GetSongs();
	private:
		string name;
		vector<Song*> songs;
};

#endif