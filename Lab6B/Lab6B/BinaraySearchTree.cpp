#include "BinarySearchTree.h"
#include <iostream>
using namespace std;

BinarySearchTree::BinarySearchTree() {}

void BinarySearchTree::add(char c) {
    TreeNode* node = new TreeNode(c);
    if (root == nullptr) {
        root = new TreeNode(c);
        return;
    }
    add(node, root);
}

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

void BinarySearchTree::printinAscendingOrder() { AscendingOrder(root); }

void BinarySearchTree::AscendingOrder(TreeNode* node) {
    if (node == nullptr) {
        return;
    }
    // recur on the left child
    AscendingOrder(node->left);
    // print data of the node
    cout << node->data << " ";
    // recur on the right child
    AscendingOrder(node->right);

}

void BinarySearchTree::printPreOrder() { PreOrder(root); }

void BinarySearchTree::PreOrder(TreeNode* node) {
    if (node == nullptr) {
        return;
    }
    // print data of node
    cout << node->data << " ";
    // recur on the left child
    PreOrder(node->left);
    // recur on the right child
    PreOrder(node->right);
}

void BinarySearchTree::printPostOrder() { PostOrder(root); }

void BinarySearchTree::PostOrder(TreeNode* node) {
    if (node == nullptr) {
        return;
    }
    // recur on the left child
    PostOrder(node->left);
    // recur on the right child
    PostOrder(node->right);
    // print data of node
    cout << node->data << " ";
}

bool BinarySearchTree::search(char key) { return search(key, root); }

bool BinarySearchTree::search(char key, TreeNode* node) {
    if (node == nullptr) {
        return false;
    }
    if (node->data == key) {
        return true;
    }

    if (node->data > key) {
        return search(key, node->left);
    }
    else {
        return search(key, node->right);
    }
}