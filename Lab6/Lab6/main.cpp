#include "BinarySearchTree.h"
#include <iostream>
using namespace std;

int main()
{
    BinarySearchTree bst;
    bst.add(1);
    bst.add(2);
    bst.add(3);
    bst.add(4);
    bst.add(5);
    bst.add(4);
    bst.add(1);
    bst.add(6);
    bst.add(5);
    bst.add(7);
    bst.add(8);
    cout << endl;
    cout << "Current height of the tree is " << bst.height() << endl;

    bst.remove(5);
    bst.remove(4);
    bst.remove(6);
    bst.remove(7);
    bst.remove(8);
    cout << endl;
    cout << "Current height of the tree is " << bst.height() << endl;
}
