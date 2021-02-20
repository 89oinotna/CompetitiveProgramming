// maximum of all subarray of size k.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>
using namespace std;

struct num {
    int value;
    int index;
};

/*
Given an array arr[] of size N and an integer K. 
Find the maximum for each and every contiguous subarray of size K.

Use a deque for the max and window

we always have the leader in front
1) remove from the front all elements out of the window
2) remove from the back all the elements lower than current (they cant be leaders now)
3) insert current in the deque
*/


int main()
{
    int T = 0;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int n = 0, k = 0;
        cin >> n;
        cin >> k;
        vector<int> v(n);
        for (int j = 0; j < n; j++) {
            cin >> v[j];
        }
        deque<num> d(k);
        for (int j = 0; j < k; j++) {
            //remove if out of the window
            while (!d.empty() && d.front().index <= j - k) {
                d.pop_front();
            }
            //remove if lower than current element
            while (!d.empty() && d.back().value <= v[j]) {
                d.pop_back();
            }
            d.push_back({ v[j], j });
            
        }
        cout << d.front().value << " ";
        for (int j = k; j < n; j++) {
            while (!d.empty() && d.front().index<=j-k) {
                d.pop_front();
            }
            while (!d.empty() && d.back().value <= v[j]) {
                d.pop_back();
            }
            d.push_back({ v[j], j });
            cout << d.front().value<<" ";
        }
        cout << endl;
    }
}

