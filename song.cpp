//
// Created by Admin on 10/28/2018.
//

//
// Created by Admin on 10/28/2018.
//

#include <cstdlib>
#include <iostream>
#include <string>
#include "song.h"

using namespace std;

//Default constructor
Song::Song(){
    setTitle("");
    setArtist("");
    setSize(0);
}
//Constructor with artist, title, and size
Song::Song(string artist, string title, int size) {
    songTitle = title;
    songArtist = artist;
    songSize = size;
}

//Sets the song title
void Song::setTitle(string title) {
    songTitle = title;
}

//Sets the song artist
void Song::setArtist(string artist) {
    songArtist = artist;
}

//Sets the song size
void Song::setSize(int size) {
    songSize = size;
}

//Returns the song title
string Song::getTitle() const {
    return songTitle;
}

//Returns the song artist
string Song::getArtist() const {
    return songArtist;
}

//Returns the song size
int Song::getSize() const {
    return songSize;
}

//Checks if the song are the same depending on the title, artist, and size
bool Song::operator ==(Song const &rhs){
    return (songTitle == rhs.songTitle &&
            songArtist == rhs.songArtist &&
            songSize == rhs.songSize);
}
//Checks if a song is < than the other depending on the title, artist, and size
bool Song::operator <(Song const &rhs) {
    if (this -> songArtist == rhs.songArtist) {
        if (this -> songTitle == rhs.songTitle) {
            if (this -> songSize == rhs.songSize) {
                return false;
            } else
                return this -> songSize < rhs.songSize;
        } else
            return this -> songTitle < rhs.songTitle;
    } else
        return this -> songArtist < rhs.songArtist;
}

//Checks if a song is > than the other depending on the title, artist, and size
bool Song::operator >(Song const &rhs){
    if(this -> songArtist == rhs.songArtist){
        if(this -> songTitle == rhs.songTitle){
            if(this -> songSize == rhs.songSize){
                return false;
            }else
                return this -> songSize > rhs.songSize;
        }else
            return this -> songTitle > rhs.songTitle;
    }else
        return this -> songArtist > rhs.songArtist;
}
