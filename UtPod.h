//
// Created by Admin on 10/28/2018.
//

#ifndef UTPODFINAL_UTPOD_H
#define UTPODFINAL_UTPOD_H

//DOCUMENT HERE

#include "song.h"

//UtPod class declaration
class UtPod
{
private:
    static const int MAX_MEMORY = 512;
    static const int SUCCESS = 0;
    static const int NO_MEMORY = -1;
    static const int NOT_FOUND = -2;

    struct SongNode
    {
        Song s;
        SongNode *next;
    };

    SongNode *songs;  //the head pointer

    int memSize;

    /* FUNCTION - int swapSongs
     * swaps the two pointers inside the song linked list

     input parms - two SongNode pointers

     output parms - swapped pointers
    */
    void swapSongs(SongNode* ptr1, SongNode* ptr2);

    /* FUNCTION - int getUsedMemory
     * Transverses through the linked list and adds up the memory occupied

     input parms - none

     output parms - memory used up
    */
    int getUsedMemory();

    /* FUNCTION - int getUsedMemory
     * Tranverses through the linked list and adds up the number of songs

     input parms - none

     output parms - number of songs
    */
    int getNumSongs();

public:
    //Default constructor
    //set the memory size to MAX_MEMORY
    UtPod();

    //Constructor with size parameter
    //The user of the class will pass in a size.
    //If the size is greater than MAX_MEMORY or less than or equal to 0,
    //set the size to MAX_MEMORY.
    UtPod(int size);

    /* FUNCTION - int addSong
     * attempts to add a new song to the UtPod
         o returns a 0 if successful
         o returns -1 if not enough memory to add the song

     precondition: s is a valid Song

     input parms - the song to to be added

     output parms - adds the song to the linked list
    */

    int addSong(Song const &s);


    /* FUNCTION - int removeSong
     * attempts to remove a song from the UtPod
     * removes the first instance of a song that is in the the UtPod multiple times
         o returns 0 if successful
         o returns -1 if nothing is removed

       input parms - song to remove

       output parms - removes the song from the linked list, fixes the linked list and frees the memory
    */

    int removeSong(Song const &s);


    /* FUNCTION - void shuffle
     *  shuffles the songs into random order
        o will do nothing if there are less than two songs in the current list

       input parms - none

       output parms - none, just shuffles the linked list
    */

    void shuffle();


    /* FUNCTION - void showSongList
     * prints the current list of songs in order from first to last to standard output
     * format - Title, Artist, size in MB (one song per line)

       input parms - none

       output parms - prints the title, artist and size of song in MB
    */


    void showSongList();


    /* FUNCTION - void sortSongList
     *  sorts the songs in ascending order
        o will do nothing if there are less than two songs in the current list

       input parms - none

       output parms - none, sorts the linked list alphabetically on artist first, then song title then size.
    */

    void sortSongList();

    /* FUNCTION - void clearMemory
     * clears all the songs from memory

       input parms - none

       output parms - none, but deletes every node of a song in the linked list
    */
    void clearMemory();


    /* FUNCTION - int getTotalMemory
     *  returns the total amount of memory in the UtPod
        o will do nothing if there are less than two songs in the current list

       input parms - none

       output parms - returns memory size of UtPod
    */

    int getTotalMemory() {
        return memSize;
    }



    /* FUNCTION - int getRemainingMemory
     *  returns the amount of memory available for adding new songs

       input parms - none

       output parms - returns total memory - used memory
    */

    int getRemainingMemory();

    ~UtPod();

};



#endif