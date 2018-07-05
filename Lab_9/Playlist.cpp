#include "stdafx.h"
#include "Playlist.h"

Playlist::Playlist(string name)
{
	this->name = name;
}

Playlist::~Playlist()
{
}

string Playlist::GetName() { return name; }

void Playlist::AddSong(Song* song) { songs.push_back(song); }

void Playlist::RemoveSong(int songIndex) { songs.erase(songs.begin() + songIndex); }

vector<Song*>* Playlist::GetSongs() { return &songs; }
