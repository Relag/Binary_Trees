#include "Tree.h"

Tree::Tree() {
	rootNode = nullptr;
}

Tree::~Tree() {
	DestroyTree(rootNode);
}

void Tree::DestroyTree(Node* node) {
	if (node != nullptr) {
		DestroyTree(node->GetLeft());
		DestroyTree(node->GetRight());
		delete node;
	}
}

void Tree::CreateTree() {
	int nodesInDepth = 2;
	bool tree[EASY];
	rootNode = new Node(0);
	int currentDepth = 1;
	srand(time(0));
	rootNode->LeftNode = new Node(1);
	rootNode->LeftNode->PreviousNode = rootNode;
	rootNode->RightNode =new Node(1);
	rootNode->RightNode->PreviousNode = rootNode;
	Node* current = rootNode;
	Node* previous = rootNode;
	numberOfNodes = 3;

	if (current->GetLeft() != NULL) {
		numberOfNodes += TreeGeneration(2, current->GetLeft());
	}
	if (current->GetRight() != NULL) {
		numberOfNodes += TreeGeneration(2, current->GetRight());
	}
}

int Tree::TreeGeneration(int depth, Node* current) {
	int returnValue = 0;
	if (depth <= 5) {
		if ((rand() % 100) + (depth * 10) < 80) {
			current->LeftNode = new Node(depth);
			depth = current->GetLeft()->getDepth();
			current->LeftNode->PreviousNode = current;
			returnValue += TreeGeneration(depth + 1, current->GetLeft());
			numberOfNodes++;
			returnValue += 1;
		}
		if ((rand() % 100) + (depth * 10) < 80) {
			current->RightNode = new Node(depth);
			depth = current->GetRight()->getDepth();
			current->RightNode->PreviousNode = current;
			returnValue += TreeGeneration(depth + 1, current->GetRight());
			numberOfNodes++;
			returnValue += 1;
		}
	}
	return returnValue;
}

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

/*int Tree::SearchTree(Node* node, int depth, std::vector<Node*>& vector) {
	if (node->getDepth() == depth) {
		vector.push_back(node);
		return 0;
	}
	if (node->GetLeft() != NULL)
		SearchTree(node->GetLeft(), depth, vector);
	if (node->GetRight() != NULL)
		SearchTree(node->GetRight(), depth, vector);
}*/

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


int Tree::ShowTree(Node* node, int depth) {
	if (node->getDepth() == depth) {
		if (node->GetPrevious()->GetRight() != NULL &&
			node->GetPrevious()->GetRight() == node)
			std::cout << "-";
		std::cout << node->getDepth();
		if (node->GetPrevious()->GetLeft() != NULL &&
			node->GetPrevious()->GetLeft() == node)
			std::cout << "-";
		/*for (int i = 0; i < 8 - depth; i++)
			std::cout << " ";*/
		return 0;
	}
	if (node->GetLeft() != NULL) {
		ShowTree(node->GetLeft(), depth);
		for (int i = 0; i < 10/depth; i++)
			std::cout << " ";
	}
	if (node->GetRight() != NULL) {
		for (int i = 0; i < (16-depth) /(depth+3); i++)
			std::cout << " ";
		ShowTree(node->GetRight(), depth);
	}
}

