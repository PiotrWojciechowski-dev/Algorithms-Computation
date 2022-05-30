#include "TreeNode.h"
#define NULL nullptr

TreeNode::TreeNode() {}

TreeNode::TreeNode(int dataIn) {
	data = dataIn; 
}

TreeNode::~TreeNode() {
	delete left;
	delete right;
}