//October 30: Created class for testing purposes.
//November 11: added room pointer for enemies.
//November 16: tied time of day into node creation.
#include "Node.h"

Node::Node(int depth, bool isNight) {
	//Pointers to the left, right and previous nodes allow the player to navigate.
	//Depth number gives player's their bearings, and sense of how dangerous this might be.
	//Room objects hold an enemy. Was to hold treasure as well, but I ran out of time.
	nodeDepth = depth;
	LeftNode = nullptr;
	RightNode = nullptr;
	PreviousNode = nullptr;
	roomType = new Room(depth, isNight);
	
}