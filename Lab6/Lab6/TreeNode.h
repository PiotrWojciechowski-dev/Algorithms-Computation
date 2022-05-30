#pragma once

class TreeNode {
public:
	TreeNode();
	TreeNode(int data);
	~TreeNode();
	friend class BinarySearchTree;

private:
	int data;
	TreeNode* left;
	TreeNode* right;
};