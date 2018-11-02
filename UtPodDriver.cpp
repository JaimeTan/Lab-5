/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include "UtPod.h"

#include "song.h"
using namespace std;

int main(int argc, char *argv[])
{
    cout << "=========================Testing Song Class=========================" << endl;
    cout << "Testing default Song constructor" << endl;
    Song song1;
    cout << song1.getArtist() << song1.getTitle() << song1.getSize() << endl << endl;

    cout << "Testing Song constructor with the get functions" << endl;
    Song song2("Justin Bieber", "Mistletoe", 4);
    cout << song2.getArtist() << "     " << song2.getTitle() << "     " << song2.getSize() << endl << endl;

    cout << "Tesing the set functions by setting the elements in the song created by the default constructor" << endl;
    song1.setArtist("Michael Buble");
    song1.setTitle("Holly Jolly Christmas");
    song1.setSize(20);
    cout << song1.getArtist() << "     " << song1.getTitle() << "     " << song1.getSize() << endl << endl;

    cout << "Testing boolean operators of Song class using: " << endl;
    cout << "LHS: " << song2.getArtist() << "     " << song2.getTitle() << "     " << song2.getSize() << endl;
    cout << "RHS: " << song1.getArtist() << "     " << song1.getTitle() << "     " << song1.getSize() << endl;

    cout << "Testing LHS < RHS" << endl;
    if(song2 < song1){
        cout << "True" << endl;
    }
    else cout << "False" << endl;

    cout << "Testing LHS > RHS" << endl;
    if(song2 > song1){
        cout << "True" << endl;
    }
    else cout << "False" << endl;

    cout << "Testing LHS == RHS" << endl;
    if(song2 == song1){
        cout << "True" << endl;
    }
    else cout << "False" << endl;

    cout << "Testing LHS = LHS" << endl;
    if(song2 == song2){
        cout << "True" << endl;
    }
    else cout << "False" << endl;


    cout << "=========================Testing UtPod Class=========================" << endl;
    UtPod t;
    int memory = t.getRemainingMemory();

    cout <<"Default Constructor Memory: " << memory << endl;

    UtPod t2(-1);
    memory = t2.getRemainingMemory();
    cout << "Constructor Memory when size -1 is passed : " << memory << endl;

    UtPod t3(513);
    memory = t3.getRemainingMemory();
    cout << "Constructor Memory when size > 512 is passed  : " << memory << endl;

    UtPod t4(256);
    memory = t4.getRemainingMemory();
    cout << "Constructor Memory when size 256 is passed: " << memory << endl;

    cout << endl << "Adding the song, S. O. S. by ABBA with size 4 MB." << endl;
    Song s1("ABBA","S. O. S.", 4);
    int result = t.addSong(s1);
    cout << "result = " << result << endl;
    t.showSongList();

    cout << endl << "Adding the song, Mamma Mia by ABBA with size 5 MB." << endl;
    Song s2("ABBA","Mamma Mia", 5);
    result = t.addSong(s2);
    cout << "result = " << result << endl;
    t.showSongList();

    cout << endl << "Adding the song, Mamma Mia by ABBA with size 8 MB." << endl;
    Song s3("ABBA","Mamma Mia", 8);
    result = t.addSong(s3);
    cout << "result = " << result << endl;
    t.showSongList();

    cout << endl << "Adding the song,I Gotta Feeling by Black Eyed Peas with size 20 MB." << endl;
    Song s4("Black Eyed Peas", "I Gotta Feeling", 20);
    result = t.addSong(s4);
    cout << "result = " << result << endl;
    t.showSongList();

    cout << endl << "Adding the song, Mamma Mia by GLEE Peas with size 7 MB." << endl;
    Song s5("GLEE", "Mamma Mia", 7);
    result = t.addSong(s5);
    cout << "result = " << result << endl;
    t.showSongList();

    cout << endl << "Shuffling Songs . . ." << endl;
    t.shuffle();
    t.showSongList();

    cout << endl << "Shuffling Songs . . ." << endl;
    t.shuffle();
    t.showSongList();

    cout << endl << "Sorting Songs . . . " << endl;
    t.sortSongList();
    t.showSongList();

    memory = t.getRemainingMemory();
    cout << endl << "Remaining Memory = " << memory << endl;

    cout << endl << "Adding a song greater than " << memory << " MB" << endl;
    Song s6("AAA", "Mamma Mia", 469);
    result = t.addSong(s6);
    cout << "result = " << result << endl;
    t.showSongList();

    cout << endl << "Adding the song, Mamma Mia by AAA with size 468 MB." << endl;
    Song s7("AAA", "Mamma Mia", 468);
    result = t.addSong(s7);
    cout << "result = " << result << endl;
    t.showSongList();

    cout << "Shuffling Songs . . ." << endl;
    t.shuffle();
    t.showSongList();

    cout << "Sorting Songs . . . " << endl;
    t.sortSongList();
    t.showSongList();


    memory = t.getRemainingMemory();
    cout << "Remaining Memory = " << memory << endl << endl;

    cout <<  "Removing I Gotta Feeling by Black Eyed Peas with size 20" << endl;
    result = t.removeSong(s4);
    cout << "result = " << result << endl;
    t.showSongList();

    cout << endl << "Removing I Gotta Feeling by Black Eyed Peas with size 20" << endl;
    result = t.removeSong(s4);
    cout << "result = " << result << endl;
    t.showSongList();

    cout << endl << "Removing first song of the list" << endl;
    result = t.removeSong(s7);
    cout << "result = " << result << endl;
    t.showSongList();

    cout << endl << "Removing last song of the list" << endl;
    result = t.removeSong(s5);
    cout << "result = " << result << endl;
    t.showSongList();

    cout << endl << "Adding the same song twice: " << endl;
    result = t.addSong(s2);
    cout << "result = " << result << endl;
    t.showSongList();

    cout << endl << "Removing the first instance of : Mamma Mia by ABBA with size 5 " << endl;
    result = t.removeSong(s2);
    cout << "result = " << result << endl;
    t.showSongList();

    cout << endl << "Testing remaining memory" << endl;
    cout << "Total Memory: " << t.getTotalMemory() << endl;
    cout << "Remaining Memory: " << t.getRemainingMemory() << endl;

    cout << endl << "Testing clearing memory function" << endl;
    t.clearMemory();
    cout << "Total Memory: " << t.getTotalMemory() << endl;
    cout << "Remaining Memory: " << t.getRemainingMemory() << endl;

    cout << endl << "Trying to remove a song from an empty list " << endl;
    result = t.removeSong(s2);
    cout << "result = " << result << endl;
    t.showSongList();

    cout << endl << "Readding songs to test destructor" << endl;

    t.addSong(s1);
    t.addSong(s2);
    t.addSong(s3);
    t.addSong(s4);
    t.addSong(s5);
    t.addSong(s7);

    t.showSongList();
    cout << "Memory before destructor" << endl;
    cout << "Total Memory: " << t.getTotalMemory() << endl;
    cout << "Remaining Memory: " << t.getRemainingMemory() << endl;
    t.~UtPod();
    cout << endl << "Memory after destructor" << endl;
    cout << "Total Memory: " << t.getTotalMemory() << endl;
    cout << "Remaining Memory: " << t.getRemainingMemory() << endl;

}