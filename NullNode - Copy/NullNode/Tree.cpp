#include "Tree.h"
#include "Tree.h"

Tree::Tree() {
	rootNode = nullptr;
}

Tree::~Tree() {
	DestroyTree(rootNode);
}
//Recursive function to delete all nodes and rooms.
void Tree::DestroyTree(Node* node) {
	if (node != NULL) {
		if (node->GetLeft() != nullptr)
			DestroyTree(node->GetLeft());
		if (node->GetRight() != nullptr)
			DestroyTree(node->GetRight());
		if (node->getRoom()->host != nullptr) {
			delete node->getRoom()->host;
			node->getRoom()->host = nullptr;
		}
		delete node;
	}
}
//Function for initial tree creation
void Tree::CreateTree(bool isNight) {
	int nodesInDepth = 2;
	rootNode = new Node(0, isNight);
	int currentDepth = 1;
	srand(time(0));
	rootNode->LeftNode = new Node(1, isNight);
	rootNode->LeftNode->PreviousNode = rootNode;
	rootNode->RightNode = new Node(1, isNight);
	rootNode->RightNode->PreviousNode = rootNode;
	Node* current = rootNode;
	Node* previous = rootNode;
	//Call a recursive function to create the tree.
	if (current->GetLeft() != NULL) {
		TreeGeneration(2, current->GetLeft(), isNight);
	}
	if (current->GetRight() != NULL) {
		TreeGeneration(2, current->GetRight(), isNight);
	}
}

void Tree::TreeGeneration(int depth, Node* current, bool isNight) {
	if (depth <= 5) {
		//Create a node on the left or right of current node. Chance of node creation decreases by depth.
		//Set created node's previous node to current node. Recursively call TreeGeneration on new node.
		if ((rand() % 100) + (depth * 5) < 80) {
			current->LeftNode = new Node(depth, isNight);
			depth = current->GetLeft()->getDepth();
			current->LeftNode->PreviousNode = current;
			TreeGeneration(depth + 1, current->GetLeft(), isNight);
		}
		if ((rand() % 100) + (depth * 10) < 80) {
			current->RightNode = new Node(depth, isNight);
			depth = current->GetRight()->getDepth();
			current->RightNode->PreviousNode = current;
			TreeGeneration(depth + 1, current->GetRight(), isNight);
		}
	}
}
//A failed attempt at displaying the tree to the screen.
//It was to look upright, like an actual tree; however proved too difficult.
void Tree::DisplayTree(Node* node) {

	if (node->GetLeft() != NULL)
		DisplayTree(node->GetLeft());
	if (node->GetRight() != NULL)
		DisplayTree(node->GetRight());
	nodeVector.push_back(node);
	//Fill vector with tree from top left to bottom.
	//Then print out the tree.
	Node* prev = node;
	std::cout << "\t" << node->getDepth();
	while (prev->GetPrevious() != NULL) {
		prev = prev->GetPrevious();
		std::cout << "\t" << prev->getDepth();
	}
	std::cout << std::endl;
}


int Tree::SearchTree(Node* node, int depth, std::vector<Node*>& vector) {
	if (node->getDepth() == depth) {
		vector.push_back(node);
		return 0;
	}
	if (node->GetLeft() != NULL)
		SearchTree(node->GetLeft(), depth, vector);
	if (node->GetRight() != NULL) {
		std::cout << "\t";
		SearchTree(node->GetRight(), depth, vector);
	}
}

