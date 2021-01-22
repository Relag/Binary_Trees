//October 30: created testing program for tree.
// November 10: Abandoned tree display idea
//November 16: tied time of day into node creation.

#pragma once
#include "Node.h"
#include <ctime>
#include <random>
#include <iostream>
#include <vector>

class Tree
{
public:
	Tree();
	~Tree();

	void TreeGeneration(int depth, Node* current, bool isNight);
	void CreateTree(bool isNight);
	void DisplayTree(Node* node);
	Node* rootNode;
	int SearchTree(Node* node, int depth, std::vector<Node*>& vector);
private:
	void DestroyTree(Node* node);
	std::vector<Node*> nodeVector;
};

