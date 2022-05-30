#pragma once
#include "TreeNode.h"
class BinarySearchTree {
	friend class TreeNode;

public:
	BinarySearchTree(); // constructor
	~BinarySearchTree();
	// both the add and height methods are
	// implemented by a private recursive method
	void add(int toadd);
	int height();
	void remove(int toremove);

private:
	void add(TreeNode* toAdd, TreeNode* addHere);
	void remove(TreeNode*& toRemove, int toremove);
	TreeNode* FindMinKey(TreeNode* node);
	int height(TreeNode* node);
	TreeNode* head;
};
