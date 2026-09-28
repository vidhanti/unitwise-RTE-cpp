#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Base class
class Media {
protected:
    string title;
    string fileName;

public:
    // Constructor
    Media(string t, string f) {
        title = t;
        fileName = f;
    }

    // Virtual functions
    virtual void play() {
        cout << "Playing media...\n";
    }

    virtual void pause() {
        cout << "Media paused.\n";
    }

    virtual void stop() {
        cout << "Media stopped.\n";
    }

    virtual void showDetails() {
        cout << "Title      : " << title << endl;
        cout << "File Name  : " << fileName << endl;
    }

    // Virtual destructor
    virtual ~Media() {}
};


// Audio class
class Audio : public Media {
private:
    string artist;

public:
    Audio(string t, string f, string a)
        : Media(t, f) {
        artist = a;
    }

    void play() override {
        cout << "Playing audio: " << title << endl;
    }

    void pause() override {
        cout << "Audio paused: " << title << endl;
    }

    void stop() override {
        cout << "Audio stopped: " << title << endl;
    }

    void showDetails() override {
        cout << "\n----------------------------------\n";
        cout << "Media Type : Audio\n";
        cout << "Title      : " << title << endl;
        cout << "File Name  : " << fileName << endl;
        cout << "Artist     : " << artist << endl;
    }
};


// Video class
class Video : public Media {
private:
    string resolution;

public:
    Video(string t, string f, string r)
        : Media(t, f) {
        resolution = r;
    }

    void play() override {
        cout << "Playing video: " << title << endl;
    }

    void pause() override {
        cout << "Video paused: " << title << endl;
    }

    void stop() override {
        cout << "Video stopped: " << title << endl;
    }

    void showDetails() override {
        cout << "\n----------------------------------\n";
        cout << "Media Type : Video\n";
        cout << "Title      : " << title << endl;
        cout << "File Name  : " << fileName << endl;
        cout << "Resolution : " << resolution << endl;
    }
};


// Image class
class Image : public Media {
private:
    string dimensions;

public:
    Image(string t, string f, string d)
        : Media(t, f) {
        dimensions = d;
    }

    void play() override {
        cout << "Displaying image: " << title << endl;
    }

    void pause() override {
        cout << "Image viewing paused: " << title << endl;
    }

    void stop() override {
        cout << "Stopped viewing image: " << title << endl;
    }

    void showDetails() override {
        cout << "\n----------------------------------\n";
        cout << "Media Type : Image\n";
        cout << "Title      : " << title << endl;
        cout << "File Name  : " << fileName << endl;
        cout << "Dimensions : " << dimensions << endl;
    }
};


// Main function
int main() {

    // Collection of base-class pointers
    vector<Media*> mediaList;

    // Create media objects
    mediaList.push_back(
        new Audio("Believer", "believer.mp3", "Imagine Dragons")
    );

    mediaList.push_back(
        new Video("Avengers Trailer", "avengers.mp4", "1920x1080")
    );

    mediaList.push_back(
        new Image("Nature", "nature.jpg", "4000x3000")
    );

    int choice;
    int mediaChoice;

    do {

        cout << "\n\n========== MEDIA PLAYER ==========\n";
        cout << "1. Show All Media\n";
        cout << "2. Play Media\n";
        cout << "3. Pause Media\n";
        cout << "4. Stop Media\n";
        cout << "5. Show Media Details\n";
        cout << "6. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;


        switch (choice) {

        // Display all media
        case 1:

            cout << "\n========== MEDIA LIST ==========\n";

            for (int i = 0; i < mediaList.size(); i++) {

                cout << "\nMedia " << i + 1 << ":\n";

                mediaList[i]->showDetails();
            }

            break;


        // Play media
        case 2:

            cout << "\nSelect Media:\n";
            cout << "1. Audio\n";
            cout << "2. Video\n";
            cout << "3. Image\n";

            cout << "Enter choice: ";
            cin >> mediaChoice;

            if (mediaChoice >= 1 && mediaChoice <= 3) {

                mediaList[mediaChoice - 1]->play();

            } else {

                cout << "Invalid media choice!\n";
            }

            break;


        // Pause media
        case 3:

            cout << "\nSelect Media:\n";
            cout << "1. Audio\n";
            cout << "2. Video\n";
            cout << "3. Image\n";

            cout << "Enter choice: ";
            cin >> mediaChoice;

            if (mediaChoice >= 1 && mediaChoice <= 3) {

                mediaList[mediaChoice - 1]->pause();

            } else {

                cout << "Invalid media choice!\n";
            }

            break;


        // Stop media
        case 4:

            cout << "\nSelect Media:\n";
            cout << "1. Audio\n";
            cout << "2. Video\n";
            cout << "3. Image\n";

            cout << "Enter choice: ";
            cin >> mediaChoice;

            if (mediaChoice >= 1 && mediaChoice <= 3) {

                mediaList[mediaChoice - 1]->stop();

            } else {

                cout << "Invalid media choice!\n";
            }

            break;


        // Show details
        case 5:

            cout << "\nSelect Media:\n";
            cout << "1. Audio\n";
            cout << "2. Video\n";
            cout << "3. Image\n";

            cout << "Enter choice: ";
            cin >> mediaChoice;

            if (mediaChoice >= 1 && mediaChoice <= 3) {

                mediaList[mediaChoice - 1]->showDetails();

            } else {

                cout << "Invalid media choice!\n";
            }

            break;


        case 6:

            cout << "\nExiting Media Player...\n";

            break;


        default:

            cout << "Invalid choice!\n";
        }

    } while (choice != 6);


    // Free dynamically allocated memory
    for (Media* media : mediaList) {
        delete media;
    }

    return 0;
}