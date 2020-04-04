// CreateRandomBinaryTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Tree.h"
#include <vector>

int main()
{
	Tree tree;
	tree.CreateTree();
	tree.DisplayTree(tree.rootNode);
	std::cout << std::endl << std::endl;
	

	std::vector<Node*> nodeVector;
	
	//tree.SearchTree(tree.rootNode, 5, nodeVector);
	tree.ShowTree(tree.rootNode, 5);
	tree.ShowTree(tree.rootNode, 4);
	tree.ShowTree(tree.rootNode, 3);
	tree.ShowTree(tree.rootNode, 2);
	tree.ShowTree(tree.rootNode, 1);
	tree.ShowTree(tree.rootNode, 0);
	/*or (int i = 0; i < nodeVector.size(); i++) {
		std::cout << nodeVector[i]->getDepth() << " ";
	}*/
}
