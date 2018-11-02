//
// Created by Admin on 10/28/2018.
//

#ifndef UTPODFINAL_SONG_H
#define UTPODFINAL_SONG_H

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class Song {

private:
    string songTitle;
    string songArtist;
    int songSize;

public:
    //Default constructor
    //set the artist and title to blank and size to 0.
    Song();

    //Constructor
    //set the artist, title, and size to passed values
    Song(string artist, string title, int size);

    /* FUNCTION - void setTitle
     * sets the songTitle to the passed title
     *
     input parms - song title

     output parms - none
    */
    void setTitle(string title);
    /* FUNCTION - void setArtist
     * sets the songArtist to the passed artist
     *
     input parms - song artist

     output parms - none
    */
    void setArtist(string artist);

    /* FUNCTION - void setSize
     * sets the songSize to the passed size
     *
     input parms - song size

     output parms - none
    */
    void setSize(int size);

    /* FUNCTION - string getTitle
    * returns the songTitle

    input parms - none

    output parms - song title
   */
    string getTitle() const;

    /* FUNCTION - string getArtist
    * returns the songArtist
    *
    input parms - none

    output parms - song artist
   */
    string getArtist() const;

    /* FUNCTION - int getSize
    * returns the songSize
    *
    input parms - none

    output parms - song size
   */
    int getSize() const;

    // for < and > use artist, then title, then size to determine their superiorty over the other
    // Takes two songs RHS and LHS to compare.
    bool operator >(Song const &rhs);       //These are the operator overloads
    bool operator <(Song const &rhs);

    // Takes two songs RHS and LHS to compare.
    // == is overloaded to see if the song is the same
    bool operator ==(Song const &rhs);


};

#endif