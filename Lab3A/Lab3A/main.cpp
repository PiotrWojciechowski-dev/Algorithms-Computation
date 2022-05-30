#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;

void printer(vector<string> shoppingList);

void printer(list<string> shoppingList);

int main()
{
    vector<string> shoppingList;
    printer(shoppingList);
    shoppingList.push_back("eggs");
    shoppingList.push_back("milk");
    shoppingList.push_back("sugar");
    shoppingList.push_back("chocolate");
    shoppingList.push_back("flour");
    printer(shoppingList);
    shoppingList.pop_back();
    printer(shoppingList);
    shoppingList.push_back("coffee");
    printer(shoppingList);
    for (string& item : shoppingList) {
        if (item == "sugar") {
            item = "honey";
            break;
        }
    }
    printer(shoppingList);
    for (vector<string>::iterator vit = shoppingList.begin(); vit != shoppingList.end(); vit++) {
        if (*vit == "milk") {
            vit = shoppingList.erase(vit);
            break;
        }
    }
    printer(shoppingList);
    cout << endl;

    list<string> shoppingList2;
    shoppingList2.push_back("eggs");
    shoppingList2.push_back("milk");
    shoppingList2.push_back("sugar");
    shoppingList2.push_back("chocolate");
    shoppingList2.push_back("flour");
    printer(shoppingList2);
    shoppingList2.pop_front();
    printer(shoppingList2);
    shoppingList2.push_front("coffee");
    printer(shoppingList2);
    for (string& item : shoppingList2) {
        if (item == "sugar") {
            item = "honey";
            break;
        }
    }
    printer(shoppingList2);
    for (list<string>::iterator lit = shoppingList2.begin(); lit != shoppingList2.end(); lit++) {
        if (*lit == "milk") {
            shoppingList2.insert(lit, "baking powder");
            break;
        }
    }
    printer(shoppingList2);
}

void printer(vector<string> shoppingList)
{
    vector<string>::iterator vit = shoppingList.begin();
    vector<string>::iterator end = shoppingList.end();
    cout << "Shopping List: ";
    // Changed from a range-based for-loop
    // Using an iterator for loop to print out a comma seperated vector
    for (vit; vit != end; vit++) {
        if (vit != shoppingList.begin()) {
            cout << ", ";
        }
        cout << *vit;
    }
    cout << endl;
}

void printer(list<string> shoppingList)
{
    list<string>::iterator lit = shoppingList.begin();
    list<string>::iterator end = shoppingList.end();
    cout << "Shopping List: ";
    // Changed from a range-based for-loop
    // Using an iterator for loop to print out a comma seperated vector
    for (lit; lit != end; lit++) {
        if (lit != shoppingList.begin()) {
            cout << ", ";
        }
        cout << *lit;
    }
    cout << endl;
}
