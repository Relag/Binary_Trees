#pragma once
#include "Node.h"
#include <ctime>
#include <random>
#include <iostream>
#include <vector>
#define EASY 3
#define MEDIUM 4
#define HARD 5

class Tree
{
public:
	Tree();
	~Tree();
	
	int TreeGeneration(int depth, Node* current);
	void goLeft(Node* currentNode);
	void goRight(Node* currentNode);
	void goPrevious(Node* currentNode);
	Node* getCurrentNode() { return currentNode; }
	void CreateTree();
	void KillTree();
	void DisplayTree(Node* node);
	Node* rootNode;
	int ShowTree(Node* node, int depth);
	int SearchTree(Node* node, int depth, std::vector<Node*>& vector);
private:
	void DestroyTree(Node* node);
	std::vector<Node*> nodeVector;
	Node* currentNode;
	
	int numberOfNodes;

};

