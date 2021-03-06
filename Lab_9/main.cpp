/*
Jordan Gruenewald, Test-Out, jorgruenewald@gmail.com

Test 1: Testing play increase in song
Input: "add", "Paradise", "When she was just a girl", "STOP",
		"addp", "Playlist", "addsp", 0, 0,
		"list", "play", 0, "list"
Expected Output:
	List before play: 
		Paradise: "When she was just a girl", 0 play(s)
	List after play:
		Paradise: "When she was just a girl", 1 play(s)

Test 2: Testing deletion of song from library
Input : "add", "Paradise", "When she was just a girl", "Superheroes", "All her life she has seen", "STOP",
		"addp", "Playlist", "addsp", 0, 0, "addsp", 0, 1,
		"list", "play", 0,
		"delsl", 1,
		"list", "play", 0
Expected Output:
	List Before: 
		Paradise: "When she was just a girl", 0 play(s)
		Superheroes: "All her life she has seen", 0 play(s)
	Play "Playlist" Before: 
		When she was just a girl
		All her life she has seen
	List After:
		Paradise: "When she was just a girl", 1 play(s)
	Play "Playlist" After:
		When she was just a girl

Test 3: Testing playlist is deleted but song is still in library
Input: "add", "Paradise", "When she was just a girl", "STOP", 
		"addp", "Playlist", "addsp", 0, 0, list, 
		"delp", 0, listp, list
Expected Output:
	List of songs before deletion:
		Paradise: "When she was just a girl", 0 play(s)
	Listp before deletion:
		0: Playlist
	Listp after deletion:
		You have no playlists. Enter \"addp\" to add playlist.
	List of songs after deletion:
		Paradise: "When she was just a girl", 0 play(s)
*/

#include "stdafx.h"
#include "Song.h"
#include "Playlist.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<Song*> songs;
vector<Playlist*> playlists;

void DisplayOptions()
{
	cout << endl;
	cout << "add      Adds a list of songs to the library" << endl;
	cout << "list     Lists all the songs in the library" << endl;
	cout << "addp     Adds a new playlist" << endl;
	cout << "addsp    Adds a song to a playlist" << endl;
	cout << "listp    Lists all the playlists" << endl;
	cout << "play     Plays a playlist" << endl;
	cout << "delp     Deletes a playlist" << endl;
	cout << "delsp    Deletes a song from a playlist" << endl;
	cout << "delsl    Deletes a song from the library(and all playlists)" << endl;
	cout << "options  Prints this options menu" << endl;
	cout << "quit     Quits the program" << endl;
	cout << endl;
}

void ListPlaylists()
{
	if (playlists.size() > 0)
	{
		for (int i = 0; i < playlists.size(); i++)
		{
			Playlist playlist = *playlists.at(i);
			cout << "  " << i << ": " << playlist.GetName() << endl;
		}
	}
	else
	{
		cout << "You have no playlists. Enter \"addp\" to add playlist." << endl;
		cout << endl;
	}
}

void DeleteSongFromPlaylist()
{
	if (playlists.size() > 0)
	{
		ListPlaylists();
		int playlistNumber;
		cout << "Pick a playlist index number: ";
		cin >> playlistNumber;
		cin.ignore(256, '\n');

		Playlist* chosenPlaylist = playlists.at(playlistNumber);
		vector<Song*>* playlistSongs = chosenPlaylist->GetSongs();
		if (playlistSongs->size() > 0)
		{
			for (int i = 0; i < playlistSongs->size(); i++)
			{
				cout << "  " << i << ": " << playlistSongs->at(i)->GetName() << endl;
			}

			int songIndexToDelete;
			cout << "Pick a song index number to delete: ";
			cin >> songIndexToDelete;
			cin.ignore(256, '\n');

			playlistSongs->erase(playlistSongs->begin() + songIndexToDelete);
		}
		else
		{
			cout << "Playlist is empty. No songs to remove." << endl;
		}
	}
	else
	{
		cout << "You have no playlists. Enter \"addp\" to add playlist." << endl;
	}

	cout << endl;
}

void DeletePlaylist()
{
	if (playlists.size() > 0)
	{
		ListPlaylists();
		int playlistNumber;
		cout << "Pick a playlist index number: ";
		cin >> playlistNumber;
		cin.ignore(256, '\n');
		cout << endl;

		Playlist* chosenPlaylist = playlists.at(playlistNumber);
		delete chosenPlaylist;
		playlists.erase(playlists.begin() + playlistNumber);
	}
	else
	{
		cout << "You have no playlists to delete." << endl;
		cout << endl;
	}
}

void PlayPlaylist()
{
	if (playlists.size() > 0)
	{
		ListPlaylists();

		int playlistNumber;
		cout << "Pick a playlist index number: ";
		cin >> playlistNumber;
		cin.ignore(256, '\n');

		Playlist chosenPlaylist = *playlists.at(playlistNumber);

		if (chosenPlaylist.GetSongs()->size() > 0)
		{
			cout << endl;
			cout << "Playing first lines of playlist: " << chosenPlaylist.GetName() << endl;
			for (int i = 0; i < chosenPlaylist.GetSongs()->size(); i++)
			{
				Song* song = chosenPlaylist.GetSongs()->at(i);
				cout << song->GetLyrics() << endl;
				song->IncrementPlays();
			}
		}
		else
		{
			cout << "Playlist is empty. Enter \"addsp\" to add songs to playlist" << endl;
		}
	}
	else
	{
		cout << "You have no playlists. Enter \"addp\" to add playlist." << endl;
	}

	cout << endl;
}

void AddSongToPlaylist()
{
	if (playlists.size() > 0)
	{
		ListPlaylists();
		int playlistNumber;
		cout << "Pick a playlist index number: ";
		cin >> playlistNumber;

		Playlist* chosenPlaylist = playlists.at(playlistNumber);

		if (songs.size() > 0)
		{
			for (int i = 0; i < songs.size(); i++)
			{
				Song song = *songs.at(i);
				cout << "  " << i << ": " << song.GetName() << endl;
			}

			int songNumber;
			cout << "Pick a song index number: ";
			cin >> songNumber;

			Song* chosenSong = songs.at(songNumber);
			chosenPlaylist->AddSong(chosenSong);
		}
		else
		{
			cout << "You have no songs to add. Enter \"add\" to add songs." << endl;
		}

		cin.ignore(256, '\n');
	}
	else
	{
		cout << "You have no playlists. Enter \"addp\" to add playlist." << endl;
	}

	cout << endl;
}

void AddPlaylist()
{
	Playlist* newPlaylist;
	string playlistName;

	cout << "Playlist name: ";
	getline(cin, playlistName);

	newPlaylist = new Playlist(playlistName);
	playlists.push_back(newPlaylist);

	cout << endl;
}

void ListSongs()
{
	if (songs.size() > 0)
	{
		for (int i = 0; i < songs.size(); i++)
		{
			Song song = *songs.at(i);
			cout << song.GetName() << ": \"" << song.GetLyrics() << "\", " << song.GetNumTimesPlayed() << " play(s)." << endl;
		}
	}
	else
	{
		cout << "You have no songs. Enter \"add\" to add songs." << endl;
	}

	cout << endl;
}

void DeleteSong()
{
	if (songs.size() > 0)
	{
		for (int i = 0; i < songs.size(); i++)
		{
			cout << i << ": " << songs.at(i)->GetName() << endl;
		}

		int songIndex;
		cout << "Pick a song index number: ";
		cin >> songIndex;
		cin.ignore(256, '\n');

		Song* songToDelete = songs.at(songIndex);

		if (playlists.size() > 0)
		{
			//iterate through all playlists to find song to delete
			for (int i = 0; i < playlists.size(); i++)
			{
				Playlist* playlist = playlists.at(i);

				for (int j = 0; j < playlist->GetSongs()->size(); j++)
				{
					Song* songInPlaylist = playlist->GetSongs()->at(j);

					if (songInPlaylist == songToDelete)
					{
						playlist->GetSongs()->erase(playlist->GetSongs()->begin() + j); //delete song from playlist
					}
				}
			}
		}

		songs.erase(songs.begin() + songIndex);
		delete songToDelete;
	}
	else
	{
		cout << "You have no songs to delete." << endl;
	}

	cout << endl;
}

void AddSong()
{
	cout << "Read in Song names and first lines (type \"STOP\" when done):" << endl;

	Song* newSong;
	string songName;
	string lyrics;

	do
	{
		cout << "Song Name: ";
		getline(cin, songName);

		if (songName != "STOP")
		{
			cout << "Song's first line: ";
			getline(cin, lyrics);

			newSong = new Song(songName, lyrics);
			songs.push_back(newSong);
		}

	} while (songName != "STOP");

	cout << endl;
}

void HandleOption(string option)
{
	if (option == "add")
	{
		AddSong();
	}
	else if (option == "list")
	{
		ListSongs();
	}
	else if (option == "addp")
	{
		AddPlaylist();
	}
	else if (option == "addsp")
	{
		AddSongToPlaylist();
	}
	else if (option == "listp")
	{
		ListPlaylists();
	}
	else if (option == "play")
	{
		PlayPlaylist();
	}
	else if (option == "delp")
	{
		DeletePlaylist();
	}
	else if (option == "delsp")
	{
		DeleteSongFromPlaylist();
	}
	else if (option == "delsl")
	{
		DeleteSong();
	}
	else if (option == "options")
	{
		DisplayOptions();
	}
	else
	{
		DisplayOptions();
	}
}

int main()
{
	cout << "Welcome to the Firstline Player!  Enter options to see menu options." << endl;
	cout << endl;

	string option;
	do
	{
		cout << "Enter your selection now: ";
		getline(cin, option);
		HandleOption(option);

	} while (option != "quit");

	cout << "Goodbye!" << endl; 
	return 0;
}

