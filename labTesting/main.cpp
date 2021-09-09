#include <iostream>
#include <vector>
#include <algorithm>
#include "PlaylistNode.h"

using namespace std;

void PrintMenu(const string playlistTitle) {
	cout << playlistTitle << " PLAYLIST MENU" << endl;
	cout << "a - Add song" << endl;
	cout << "d - Remove song" << endl;
	cout << "c - Change position of song" << endl;
	cout << "s - Output songs by specific artist" << endl;
	cout << "t - Output total time of playlist(in seconds)" << endl;
	cout << "o - Output full playlist" << endl;
	cout << "q - Quit" << endl;

}

PlaylistNode* ExecuteMenu(char option, string playlistTitle, PlaylistNode* headNode) {
	PlaylistNode* currentNode = headNode;
	PlaylistNode* previousNode{};
	PlaylistNode* temp{};
	int counter{};

	string id, songName, artistName;
	int length{}, oldPosition{}, newPosition{};

	switch (option) {
		case 'a':
			cout << "ADD SONG" << endl;
			cout << "Enter song's unique ID:" << endl;
			cin >> id;
			cout << "Enter song's name:" << endl;
			cin >> songName;
			cout << "Enter artist's name:" << endl;
			cin >> artistName;
			cout << "Enter song's length (in seconds):" << endl;
			cin >> length;

			PlaylistNode* newNode = new PlaylistNode(id, songName, artistName, length);

			while (currentNode->GetNext() != nullptr)
				currentNode = currentNode->GetNext();

			currentNode->SetNext(newNode);

			break;

		case 'd':
			cout << "REMOVE SONG" << endl;
			cout << "Enter song's unique ID:" << endl;
			cin >> id;

			while (currentNode) {
				if (currentNode->GetID() == id) {
					cout << "\"" << currentNode->GetSongName() << "\" removed." << endl;
					if (currentNode == headNode) {
						headNode = currentNode->GetNext();
						delete currentNode;
					}
					else {
						previousNode->SetNext(currentNode->GetNext());
						delete currentNode;
					}

				}
				else {
					previousNode = currentNode;
					currentNode = currentNode->GetNext();
				}
			}

			break;

		case 'c':
			cout << "CHANGE POSITION OF SONG" << endl;
			cout << "Enter song's current position:" << endl;
			cin >> oldPosition;
			cout << "Enter new position for song:" << endl;
			cin >> newPosition;

			if (oldPosition < 1)
				oldPosition = 1;
			if (newPosition < 1)
				newPosition = 1;

			while ((++counter < oldPosition) && currentNode->GetNext()) {
				previousNode = currentNode;
				currentNode = currentNode->GetNext();
			}

			if (currentNode == headNode) {
				temp = headNode;
				headNode = headNode->GetNext();
			} else {
				temp = currentNode;
				previousNode->SetNext(currentNode->GetNext());
			}

			counter = 0;

			break;

		case 's':

			break;

		case 't':

			break;

		case 'o':
			while (currentNode) {
				cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl;
				cout << counter++ << "." << endl;
				cout << "Unique ID: " << currentNode->GetID() << endl;
				cout << "Artist Name: " << currentNode->GetArtistName() << endl;
				cout << "Song Length (in seconds): " << currentNode->GetSongLength() << endl;
				cout << endl;

				currentNode = currentNode->GetNext();
			}
			break;

		case 'q':
			exit(0);
			break;
	}

	return headNode;
}

int main() {
	vector<char> validChoices{ 'a','d','c','s','t','o','q' };
	string playlistTitle;
	char input{};
	PlaylistNode* headPtr{}, tailPtrP{};
	
	cout << "Enter Playlist's title:" << endl;
	cin >> playlistTitle;
	PrintMenu(playlistTitle);
	cout << endl;

	do {
		cout << "Choose an option:";
		cin	>> input;
	} while (!count(validChoices.begin(), validChoices.end(), input));

	headPtr = ExecuteMenu(input, playlistTitle, headPtr);

	return 0;
}

