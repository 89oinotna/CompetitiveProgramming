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
            while (!d.empty() && d.front().index <= j - k) {
                d.pop_front();
            }
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

