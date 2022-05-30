#include <iostream>
#include<map>
using namespace std;

// References used:
// https://www.geeksforgeeks.org/boyer-moore-algorithm-for-pattern-searching/
// Accessed on: 03/04/2022

void indexPattern(string pattern, map<char, int>& themap);
int matchPattern(string text, string pattern, map<char, int> theMap);
bool mismatchFound(int& mismatch, int textIndex, string text, string pattern);

int main()
{
    map<char, int > themap;
    string text = "peter piper picked a peck of pickled pepper";
    string pattern = "pickle";
    indexPattern(pattern, themap);
    int patternIndex = matchPattern(text, pattern, themap);
    cout << "Text index starts at: " << patternIndex << endl;
    return 0;
}


void indexPattern(string pattern, map<char, int>& themap) {

    map<char, int >::iterator itr;
    for (long i = 0; i < pattern.length(); i++)
        themap[pattern[i]] = i;

    cout << "Index Pattern:\n";
    for (itr = themap.begin(); itr != themap.end(); itr++)
        cout << itr->first << " - " << itr->second << endl;

    cout << endl;
}

int matchPattern(string text, string pattern, map<char, int> theMap) {
    int textLength = text.length();
    int patternLength = pattern.length();
    int mismatch = 0;
    int i = 0;
    while (i <= (textLength - patternLength)) {
        if (!mismatchFound(mismatch, i, text, pattern)) {
            return i;
        }
        if (theMap.find(text[i + mismatch]) == theMap.end())
        {
            i += patternLength;
        }
        else {
            i += max(1, mismatch - theMap[text[i + mismatch]]);
        }
        
    }
    return textLength;
}

bool mismatchFound(int& mismatch, int textIndex, string text, string pattern) {
    int j = pattern.length() - 1;
    while (j >= 0 && pattern[j] == text[textIndex + j]) {
        j--;
    }
    if (j < 0) return false;
    
    mismatch = j;
    return true;
}