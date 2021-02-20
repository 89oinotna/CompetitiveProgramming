// leaders in array.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

/*
- scan right to left
- store the max element seen and use it to check if the current element is a leader 
(so rgeater than max)
*/


int main()
{
    int T = 0;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int n = 0;
        cin >> n;
        vector<int> v(n);
        for (int j = 0; j < n; j++) {
            cin >> v[j];
        }
        int max = 0;
        stack<int> leaders;
        for (int j = n - 1; j >= 0; j--) {
            if (v[j] >= max) {
                leaders.push(v[j]);
                max = v[j];
            }
        }
        while (!leaders.empty()) {
            cout << leaders.top() << " ";
            leaders.pop();
        }
        cout << endl;
    }
}



