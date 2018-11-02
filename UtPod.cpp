//
// Created by Admin on 10/28/2018.
//
#include <cstdlib>
#include <iostream>
#include <ctime>
#include "song.h"
#include "UtPod.h"

using namespace std;

//Default constructor setting the pointer to null and having 512 MB.
UtPod::UtPod(){
    songs = NULL;
    memSize = MAX_MEMORY;

    //sets the seed
    unsigned int currentTime =  (unsigned)time(NULL);
    srand(currentTime); //Grabs the current time in milliseconds
}
//Constructor where the user inputs their own memory
UtPod::UtPod(int size) {
    songs = NULL;
    if(size > 512 || size <= 0){
        memSize = MAX_MEMORY;
    }else
        memSize = size;

    //sets the seed
    unsigned int currentTime =  (unsigned)time(NULL);
    srand(currentTime); //Grabs the current time in milliseconds
}

//Adds the song to the head of the songs. If there is not enough memory, returns NO_MEMORY.
int UtPod::addSong(Song const &s){
    if(getRemainingMemory() >= s.getSize()){ //Only adds if there is enough size
        SongNode *temp = new SongNode;
        temp->s = s;
        //Adds to head of songs.
        if(songs == NULL){ //First song, beginning of node
            songs = temp;
            temp->next = NULL;

        }
        else{   //adds the song after the first song is added
            temp->next = songs;
            songs = temp;
        }

        return SUCCESS;

    }else
        return NO_MEMORY;
}

//Removes the selected song from the linked list
int UtPod::removeSong(Song const &s){
    //If the number of songs is zero, there is nothing to remove
    if (getNumSongs() == 0){
        return NOT_FOUND;
    }

    //First case where the deleted song is the first song of the linked list
    SongNode *firstSong = songs;
    if(firstSong->s == s){
        songs = firstSong -> next;
        delete(firstSong);
        return SUCCESS;
    }else{
        //Searches through the rest of the linked list
        SongNode *current = songs;  //Uses to two pointers to keep track of the tail to relink the list.
        SongNode *previous = songs;
        while(current != NULL){
            if(current->s == s){
                previous->next = current->next;
                delete(current);
                return SUCCESS;
            }else{
                previous = current;
                current = current -> next;
            }
        }
    }

    return NOT_FOUND; //If the song does not exist
}

//Shuffles the song list 2n times where n is the number of songs to allow for good randomization.
void UtPod::shuffle(){
    if(getNumSongs() > 2){
        SongNode* randSong1; SongNode* randSong2;
        int randSong1Position = 0, randSong2Position = 0;
        int shuffleTimes = 2*getNumSongs();

        while(shuffleTimes != 0){

            randSong1 = songs;
            randSong2 = songs;

            //randomizes a random position for the song
            randSong1Position = (rand() % getNumSongs());
            randSong2Position = (rand() % getNumSongs());

            //Grabs the song at that certain pointer
            for(int i = 0; i < randSong1Position; i++){
                if(randSong1->next != NULL) //So it does not encounter a situation where randomized value is the last song and it points at NULL
                    randSong1 = randSong1->next;
            }

            for(int j = 0; j < randSong2Position; j++){
                if(randSong2->next != NULL)
                    randSong2 = randSong2->next;
            }

            swapSongs(randSong1,randSong2); //Swaps the two pointers
            shuffleTimes--;
        }
    }



}

//Prints out the song list in certain format.
void UtPod::showSongList(){
    int numTracker = 1;
    if(songs == NULL) {
        cout << "Song list is empty!" << endl;
    }
    else{
        cout << "#=======Song Name==========Artist=======================Size==============" << endl;

        SongNode* head = songs;
        while(head != NULL){
            cout << numTracker << "\t" << head->s.getTitle()<< "\t \t" << head->s.getArtist() << "\t \t" << head->s.getSize() << endl;
            head = head->next;
            numTracker++;
        }
        cout << "==========================================================================";
    }
    cout << endl;
}

//Swaps the two pointers passed for shuffle
void UtPod::swapSongs(SongNode* ptr1, SongNode* ptr2){
    Song temp = ptr1->s;         //Swap two songs
    ptr1->s = ptr2->s;
    ptr2->s = temp;
}

//Sorts the song with bubble sort
void UtPod::sortSongList(){
    SongNode* currentPointer;
    SongNode* tailPointer;
    if (getNumSongs() >= 2) {
        for (int i = 0; i < getNumSongs() - 1; i++) {
            tailPointer = songs; //Starts at the beginning when it finishes the first bubble sort, etc.
            currentPointer = songs->next;
            while(tailPointer->next != NULL) { //Has two pointers to compare and then swap if the statement is true.
                if (tailPointer->s > currentPointer ->s){
                    Song temp = currentPointer ->s;
                    currentPointer->s = tailPointer ->s;
                    tailPointer->s = temp;
                }
                currentPointer = currentPointer->next; //Moves onto the next two to compare
                tailPointer = tailPointer->next;
            }
        }
    }
}

//Tranverses through the linked list adding up all the memory used
int UtPod::getUsedMemory() {
    int usedMem = 0;

    SongNode* temp;
    temp = songs;

    while (temp != NULL){
        usedMem = usedMem + temp ->s.getSize();
        temp = temp->next;
    }

    return usedMem;
}
//Tranverses through the linked list, counting how many songs there are in the linked list
int UtPod::getNumSongs(){
    int numSongs = 0;

    SongNode* temp;
    temp = songs;

    while (temp != NULL){
        numSongs++;
        temp = temp->next;
    }

    return numSongs;
}

//Subtracts UsedMemory from TotalMemory
int UtPod::getRemainingMemory(){
    return getTotalMemory() - getUsedMemory();
}

//Deletes each song in the linked list
void UtPod::clearMemory(){
    while(songs != NULL){
        SongNode* temp = songs;
        songs = temp->next;
        delete(temp);
    }
}

//Calls clearMemory() to delete each song in thee linked list
UtPod::~UtPod(){
    clearMemory();
}