UtPod
Jaime Tan Leon

I. Program Description
----------------------
The program will allow you add songs, remove songs, shuffle, show the song list, sort the song list, memory data from the songs by using classes

II. File list
------------
UtPodDriver.cpp 
UtPod.cpp
UtPod.h
song.cpp
song.h	
README.txt	Instructions and comments on the program

III. How to run the driver:
--------------------------
After you unzip the file, you will have 6 file in which you will need in order to run the program.

You need the file to be in the same directory. While in Kamek, you use the command "make" without the quotes. 
This will create an exctuable file named test. 

You can type the following command line (requires the executable name)":

  ./test

There are 7 functions implemeneted in the UtPod.

You can add songs by passing a song using, "addSong(song data);"
Song data refers to the artist, title, and size

You can remove songs by passing a song using, "removeSong(song data);"
Song data refers to the artist, title, and size

You can shuffle the song list by "shuffle();"

You can show the song list by "showSongList();"

You can get the total memory  of the UtPod by using "getTotalMemory();"

You can get the remaining memory of the UtPod by using "getRemainingMemory();"

To create songs, you use song(artist, title, size); with their respective data