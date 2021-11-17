#include <bits/stdc++.h> 

using namespace std; 

int main() { 
    vector<string> songs = {"A", "B", "C", "D", "E"};

    while (true) {
        int b, n;
        cin >> b >> n;

        if (b == 4 && n == 1) {
            for (string song : songs) {
                cout << song << " ";
            }
            break;
        }

        if (b == 1) {
            for (int i = 0; i < n; i++) {
                string song = songs[0];
                songs.erase(songs.begin());
                songs.push_back(song);
            }
            
        } else if (b == 2) {
            for (int i = 0; i < n; i++) {
                string song = songs[4];
                songs.erase(songs.end());
                songs.insert(songs.begin(), song);
            }
        } else if (b == 3) {
            for (int i = 0; i < n; i++) {
                string firstSong = songs[0];
                string secondSong = songs[1];
                songs[0] = secondSong;
                songs[1] = firstSong;
            }
        }   
    }
} 