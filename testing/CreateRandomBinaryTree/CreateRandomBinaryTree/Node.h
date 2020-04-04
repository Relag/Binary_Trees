#pragma once

class Node
{
private:
	
	int nodeDepth;
	char roomType;
	//Add RoomTypePointer
	//Add EnemyPointer
public:
	Node(int depth) { nodeDepth = depth; }	//Also add roomtype

	Node* PreviousNode;
	Node* LeftNode;
	Node* RightNode;
	int getDepth() { return nodeDepth; }
	char getRoom() { return roomType; }



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



