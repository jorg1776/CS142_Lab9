#include "stdafx.h"
#include "Song.h"


Song::Song(string name, string lyrics)
{
	this->name = name;
	this->lyrics = lyrics;
	this->timesPlayed = 0;
}


Song::~Song()
{
}

string Song::GetName() { return name; }

string Song::GetLyrics() { return lyrics; }

int Song::GetNumTimesPlayed() { return timesPlayed; }
