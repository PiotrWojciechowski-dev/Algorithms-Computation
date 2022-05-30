#include "BinarySearchTree.h"
#include <iostream>
using namespace std;

int main()
{
	BinarySearchTree bst;
	bst.add('A');
	bst.add('G');
	bst.add('J');
	bst.add('K');
	bst.add('L');
	bst.add('I');
	bst.add('R');
	bst.add('O');

	cout << "Ascending order:" << endl;
	bst.printinAscendingOrder();
	cout << endl << endl;
	cout << "Pre order:" << endl;
	bst.printPreOrder();
	cout << endl << endl;
	cout << "Post order:" << endl;
	bst.printPostOrder();
	cout << endl << endl;

	cout << "Is the letter G in the tree? " << boolalpha << bst.search('G') << endl;
	cout << "Is the letter B in the tree? " << boolalpha << bst.search('B') << endl;
}
