#include "PlaylistNode.h"

void PlaylistNode::InsertAfter(){

}

void PlaylistNode::SetNext(PlaylistNode* nextNodePtr){
	this->nextNodePtr = nextNodePtr;
}

std::string PlaylistNode::GetID() const{
	return uniqueID;
}

std::string PlaylistNode::GetSongName() const{
	return songName;
}

std::string PlaylistNode::GetArtistName() const{
	return artistName;
}

int PlaylistNode::GetSongLength() const{
	return songLength;
}

PlaylistNode* PlaylistNode::GetNext() const{
	return nextNodePtr;
}
