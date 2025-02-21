#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Song {
    char title[100];
    struct Song* next;
} Song;

typedef struct Playlist {
    Song* head;
    Song* current;
} Playlist;

// Function to create a new song
Song* createSong(const char* title) {
    Song* newSong = (Song*)malloc(sizeof(Song));
    strcpy(newSong->title, title);
    newSong->next = NULL;
    return newSong;
}

// Function to initialize the playlist
void initPlaylist(Playlist* playlist) {
    playlist->head = NULL;
    playlist->current = NULL;
}

// Function to add a song to the playlist
void addSong(Playlist* playlist, const char* title) {
    Song* newSong = createSong(title);
    if (playlist->head == NULL) {
        playlist->head = newSong;
        newSong->next = newSong; // Point to itself to make it circular
    } else {
        Song* temp = playlist->head;
        while (temp->next != playlist->head) {
            temp = temp->next;
        }
        temp->next = newSong;
        newSong->next = playlist->head; // Make it circular
    }
}

// Function to play the next song
void playNextSong(Playlist* playlist) {
    if (playlist->current == NULL) {
        playlist->current = playlist->head; // Start from the head if current is NULL
    } else {
        playlist->current = playlist->current->next; // Move to the next song
    }
}

// Function to display the currently playing song
void displayCurrentSong(Playlist* playlist) {
    if (playlist->current != NULL) {
        printf("Current Song: %s\n", playlist->current->title);
    } else {
        printf("No songs in the playlist.\n");
    }
}

int main() {
    Playlist playlist;
    initPlaylist(&playlist);

    // Adding songs to the playlist
    addSong(&playlist, "Song A");
    addSong(&playlist, "Song B");
    addSong(&playlist, "Song C");

    // Playing songs in the playlist
    for (int i = 0; i < 5; i++) { // Play 5 times to demonstrate looping
        displayCurrentSong(&playlist);
        playNextSong(&playlist);
    }

    return 0;
}
