#ifndef PLAYLISTNODE_H
#define PLAYLISTNODE_H
#include <string>

class PlaylistNode {
private:
	std::string uniqueID{};
	std::string songName{};
	std::string artistName{};
	int songLength{};
	PlaylistNode* nextNodePtr{};

public:
	PlaylistNode()
		: uniqueID{"none"}
		, songName{"none"}
		, artistName{"none"}
		, songLength{}
		, nextNodePtr{}{}
	PlaylistNode(const std::string& uniqueID, const std::string& songName, const std::string& artistName, int songLength)
		: this->uniqueID{uniqueID}
		, this->songName{songName}
		, this->artistName{artistName}
		, this->songLength{songLength}{}

	void InsertAfter();
	void SetNext(PlaylistNode* nextNodePtr);
	std::string GetID() const;
	std::string GetSongName() const;
	std::string GetArtistName() const;
	int GetSongLength() const;
	PlaylistNode* GetNext() const;
};

#endif
