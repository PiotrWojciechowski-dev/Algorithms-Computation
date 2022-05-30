#pragma once
#include "TreeNode.h"
class BinarySearchTree {

public:
	BinarySearchTree();
	void add(char key);
	bool search(char key);
	void printinAscendingOrder();
	void printPreOrder();
	void printPostOrder();

private:
	void add(TreeNode* toAdd, TreeNode* addHere);
	bool search(char key, TreeNode* node);
	void AscendingOrder(TreeNode* node);
	void PreOrder(TreeNode* node);
	void PostOrder(TreeNode* node);
	TreeNode* root;
};