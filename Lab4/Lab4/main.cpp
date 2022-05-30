#include <iostream>
#include <forward_list>
#include <Windows.h>

using namespace std;

void SquidGame(forward_list<int> &players, int k, int index, int size);
void CrabGame(forward_list<int> players, int k, int index, int size);
double get_wall_time();
double get_cpu_time();

// Driver Program to test above function
int main()
{
    // n = number of people playing
    int n = 14;
    // k = amount of steps to take before killing someone
    int k = 2;
    // (k-1)th person will be killed
    k--;
    // The index where the person which will die
    int index = 0;

    forward_list<int> players, players2;
    // before_begin gives back an iterator to the element before the first element of the container. Which is a placeholder.
    forward_list<int>::iterator fli = players.before_begin();
    // fill the person list
    for (int i = 1; i <= n; i++) {
        fli = players.emplace_after(fli, i);
    }
    // copy players list to other players list
    players2 = players;
    //  Start Timers
    double wall0 = get_wall_time();
    double cpu0 = get_cpu_time();
    SquidGame(players, k, index, n);
    //  Stop timers
    double wall1 = get_wall_time();
    double cpu1 = get_cpu_time();
    cout << "Wall Time = " << wall1 - wall0 << endl;
    cout << "CPU Time  = " << cpu1 - cpu0 << endl;
    cout << endl;
    //  Start Timers
    //wall0 = get_wall_time();
    //cpu0 = get_cpu_time();
    //CrabGame(players2, k, index, n);
    ////  Stop timers
    //wall1 = get_wall_time();
    //cpu1 = get_cpu_time();
    //cout << "Wall Time = " << wall1 - wall0 << endl;
    //cout << "CPU Time  = " << cpu1 - cpu0 << endl;
    return 0;
}

void SquidGame(forward_list<int> &players, int k, int index, int size)
{
    //int size = distance(players.begin(), players.end());
    // Once the size is 1 exit the recursion
    if (size == 1) {
        cout << "Player " << *players.begin() << " survives!" << endl;
        return;
    }
    // find the index of the person which will die
    index = ((index + k) % size);
    // If the index is 0 that means we remove the person at the start of the list
    if (index == 0) {
        players.pop_front();
    }
    else {
        // temp can either be 0 or >= 1
        // it can never be -1
        int temp = index - 1;
        // get the nth successor of iterator
        // can get iterator of element at index 0
        auto fli = next(players.begin(), temp);
        // delete the element after the current iterator
        players.erase_after(fli);
    }
    // recursion
    return SquidGame(players, k, index, size-1);
}

void CrabGame(forward_list<int> players, int k, int index, int size)
{
    // get iterator at index 0
    forward_list<int>::iterator fli = players.begin();
    while (size != 1) // Loop continues till n-1 person dies.
    {
        // find the index of the person which will die
        index = ((index + k) % size);
        // If the index is 0 that means we remove the person at the start of the list
        // set the iterator to the start of the list 
        if (index == 0) {
            players.pop_front();
            fli = players.begin();
        }
        else {
            // get the nth successor of iterator
            // can get iterator of element at index 0
            int temp = index - 1;
            fli = next(players.begin(), temp);
            // delete the element after the current iterator
            players.erase_after(fli);
        }
        // Decrease the size of the list
        size--;
    }
    // Print the player at the front of the list ie. the survivor
    cout << "Player " << *players.begin() << " survives!" << endl;
    return;
}

double get_wall_time() {
    LARGE_INTEGER time, freq;
    if (!QueryPerformanceFrequency(&freq)) {
        //  Handle error
        return 0;
    }
    if (!QueryPerformanceCounter(&time)) {
        //  Handle error
        return 0;
    }
    return (double)time.QuadPart / freq.QuadPart;
}

double get_cpu_time() {
    FILETIME a, b, c, d;
    if (GetProcessTimes(GetCurrentProcess(), &a, &b, &c, &d) != 0) {
        //  Returns total user time.
        //  Can be tweaked to include kernel times as well.
        return
            (double)(d.dwLowDateTime |
                ((unsigned long long)d.dwHighDateTime << 32)) * 0.0000001;
    }
    else {
        //  Handle error
        return 0;
    }
}
