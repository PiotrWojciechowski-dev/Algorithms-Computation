#include "BinarySearchTree.h"
#include <iostream>
#include <string>
#define NULL nullptr
using namespace std;

BinarySearchTree::BinarySearchTree() {}

BinarySearchTree::~BinarySearchTree() {
    delete head;  // will recursively delete all nodes below it as well
}

void BinarySearchTree::add(int toadd) {
    TreeNode* temp = new TreeNode(toadd);

    if (head == nullptr) {
        head = temp;
        return;
    }

    add(temp, head);
}

// slides
void BinarySearchTree::add(TreeNode* toAdd, TreeNode* addHere) {
    if (toAdd->data < addHere->data) {
        if (addHere->left == nullptr) {
            addHere->left = toAdd;
            return;
        }
        add(toAdd, addHere->left);
    }
    else if (toAdd->data >= addHere->data) {
        if (addHere->right == nullptr) {
            addHere->right = toAdd;
            return;
        }
        add(toAdd, addHere->right);
    }
}

int BinarySearchTree::height() { return height(head); }

// https://www.geeksforgeeks.org/write-a-c-program-to-find-the-maximum-depth-or-height-of-a-tree/
// Accessed on 08/03/20022
int BinarySearchTree::height(TreeNode* head) {
    if (head == nullptr)
        return -1;
    else {
        /* compute the depth of each subtree */

        int lDepth = height(head->left);
        int rDepth = height(head->right);

        /* use the larger one */
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}

void BinarySearchTree::remove(int toremove) {
    if (head == nullptr) return;

    this->remove(head, toremove);
}

// https://www.gormanalysis.com/blog/making-a-binary-search-tree-in-cpp/#draft-4
// Accessed on 08/03/20022
void BinarySearchTree::remove(TreeNode*& node, int toremove) {
    if (node == nullptr) {
        // Case: nullptr
        cout << "Data with value " << toremove << " not found in tree" << endl;
    }
    else if (toremove == node->data) {
        // Found value
        if (node->left == nullptr && node->right == nullptr) {
            // Case: node is a leaf
            node = nullptr;
        }
        else if (node->left != nullptr && node->right == nullptr) {
            // Case: node has a left subtree (but not right)
            // Point node's parent at node's left subtree
            node = node->left;
        }
        else if (node->left == nullptr && node->right != nullptr) {
            // Case: node has a right subtree (but not left)
            node = node->right;
        }
        else {
            // Case: node has left and right subtrees
            TreeNode* minNode = FindMinKey(node->right); 
            node->data = minNode->data;
            this->remove(minNode, minNode->data);
        }

    }
    else if (toremove < node->data) {
        // If data at left node is less than toremove value, that value must be in
        // the left subtree, so recursively call the remove function.
        this->remove(node->left, toremove);
    }
    else {
        // Otherwise the value must me present in the right subtree
        this->remove(node->right, toremove);
    }
}

// Search the subtree starting at node and return a pointer to the minimum-value node on the left
TreeNode* BinarySearchTree::FindMinKey(TreeNode* node) {
    if (node->left == nullptr) {
        return node;
    }
    else {
        return this->FindMinKey(node->left);
    }
}


/*
void BinarySearchTree::remove(TreeNode*& node, int toremove) {
    if (node == nullptr) {
        // Case: nullptr
        std::cout << "Key " << toremove << " not found in tree" << std::endl;
        return;
    }
    if (node->data < toremove) {
        this->remove(node->right, toremove);
    }
    else if (node->data > toremove) {
        this->remove(node->left, toremove);
    }
    else {
        // Case 1: Leaf Node
        if (node->left == nullptr && node->right == nullptr) {
            node = NULL;
        }
        //Case 2: Node has left child.
        else if (node->left != nullptr && node->right == nullptr)
        {
            node = node->left;
        }
        //Case 3: Node has right child.
        else if (node->left == nullptr && node->right != nullptr)
        {
            node = node->right;
        }
        // Case 4: Node has left and right children
        TreeNode* minNode = this->FindMinKey(node->right);
        node->data = minNode->data;
        this->remove(minNode, minNode->data);
    }
}
*/