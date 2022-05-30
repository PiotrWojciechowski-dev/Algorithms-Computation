#pragma once
class TreeNode {

public:
	TreeNode();
	TreeNode(char data);
	friend class BinarySearchTree;

private:
	char data;
	TreeNode* left;
	TreeNode* right;
};