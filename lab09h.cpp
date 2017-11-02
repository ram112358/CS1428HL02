#include <iostream>
#include <iomanip>

using namespace std;

bool menu();
void displayMenu();
void newSong();
void deleteSong();
void displaySongs(bool favorites);
void editSong();

struct song{
    string title;
    string file;
    string genre;
    int track;
    bool fav;
};
song TxstPod[100];
int numSongs = 0;

int main(){
    while (menu()){
        numSongs = 0;
        for(int i = 0; i < 100; i++){
            if (TxstPod[i].track != -1){
                numSongs++;
            }
        }
    }

    cout << endl << "GOODBYE!";
    return 0;
}

void displayMenu(){
    cout.setf(ios::left | ios::showpoint | ios::fixed);
    cout << setprecision(2);

    cout.fill('*');
    cout << setw(34) << '*' << endl;

    cout.unsetf(ios::right);
    cout.setf(ios::left);

    cout.fill(' ');
    cout << "*" << setw(32) << "" << "*" << endl;
    cout << "*" << setw(32) << " 1) Add New Song" << "*" << endl;
    cout << "*" << setw(32) << " 2) Delete Song" << "*" << endl;
    cout << "*" << setw(32) << " 3) Display Songs" << "*" << endl;
    cout << "*" << setw(32) << " 4) Edit Song" << "*" << endl;
    cout << "*" << setw(32) << " 5) Display Favorites" << "*" << endl;
    cout << "*" << setw(32) << " 6) Exit" << "*" << endl;
    cout << "*" << setw(32) << "" << "*" << endl;

    cout.fill('*');
    cout << setw(34) << '*' << endl;
}

bool menu() {
    int choice = 0;
    displayMenu();
    cout << "Enter choice: ";
    cin >> choice;
    while (choice < 1 || choice > 6){
        cout << endl << endl << "Invalid Option -- Try Again" << endl;
        displayMenu();
        cout << "Enter choice: ";
        cin >> choice;
    }
    switch (choice) {
        case 1: newSong();
                break;
        case 2: deleteSong();
                break;
        case 3: displaySongs(false);
                break;
        case 4: editSong();
                break;
        case 5: displaySongs(true);
                break;
        default:return false;
    }
    return true;
}

void newSong(){
    if (numSongs > 100){
        cout << "There are too many songs, you must delete a song to continue";
        return;
    }
    int index;
    for (int i = 0; i < 100; i++){
        if (TxstPod[i].track != -1)
            index = i;
    }
    cout << "Enter new song title: ";
    cin >> TxstPod[index].title;
    cout << "Enter new song file name: ";
    cin >> TxstPod[index].file;
    cout << "Enter new song genre: ";
    cin >> TxstPod[index].genre;
    cout << "Enter new song track: ";
    cin >> TxstPod[index].track;
    cout << "Is this a favorite? (yes = 1/no = 0)";
    cin >> TxstPod[index].fav;
}

void deleteSong(){
    int index;
    cout << "Enter the index of the track you wish to delete: ";
    cin >> index;
    TxstPod[index].track = -1;
}

void displaySongs(bool favorites){
    favorites = !favorites;
    for (int i = 0; i < 100; i++){
        if ((TxstPod[i].track != -1) && (favorites || TxstPod[i].fav))
            cout << "Index: " << i << endl;
            cout << "Title: " << TxstPod[i].title << endl;
            cout << "File Name: " << TxstPod[i].file << endl;
            cout << "Genre: " << TxstPod[i].genre << endl;
            cout << "Track: " << TxstPod[i].track << endl;
            cout << "Favorite: " << TxstPod[i].fav << endl << endl;
    }
}

void editSong(){
    int index;
    cout << "Enter the index of the track you wish to edit: ";
    cin >> index;

    cout << "Enter edited song title: ";
    cin >> TxstPod[index].title;
    cout << "Enter edited song file name: ";
    cin >> TxstPod[index].file;
    cout << "Enter edited song genre: ";
    cin >> TxstPod[index].genre;
    cout << "Enter edited song track: ";
    cin >> TxstPod[index].track;
    cout << "Is this a favorite? (yes = 1/no = 0)";
    cin >> TxstPod[index].fav;
}
