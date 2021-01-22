#pragma once
#include "Room.h"

class Node
{
private:

	int nodeDepth;
	Room* roomType;
	
public:
	Node(int depth, bool isNight);	//Also add roomtype

	Node* PreviousNode;
	Node* LeftNode;
	Node* RightNode;
	int getDepth() { return nodeDepth; }
	Room* getRoom() { return roomType; }



	Node* GetPrevious() {
		return PreviousNode;
	}
	Node* GetLeft() {
		return LeftNode;
	}
	Node* GetRight() {
		return RightNode;
	}
};


