// knapsack.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include<tuple>
using namespace std;

/*
    knapsack:
    - if i==0 || j==0 => 0
    - if (w(ei) > j) element cant be put in => just carry the left value
    - if we can take it => check if it's better to take it or not
                            max(left (not taking), m[i-1][j-w(ei)]+val(e1) this means the sack with enough space to contain it)

*/

int main()
{
    int s, n;
    cin >> s>> n;
    vector<tuple<int, int>> items(n);
    for (int i = 0; i < n; i++) {
        int w, v;
        cin >> w>>v;
        items[i] = make_tuple(w,v);
    }
    vector<vector<int>> m(n + 1);
    for (int i = 0; i < n + 1; i++) {
        m[i].resize(s + 1);
        for (int j = 0; j < s + 1; j++) {
            if (i == 0 || j == 0) m[i][j] = 0;
            else if (get<0>(items[i - 1]) > j) m[i][j] = m[i - 1][j];
            else {
                m[i][j] = max(get<1>(items[i - 1]) + m[i - 1][j - get<0>(items[i - 1])], m[i - 1][j]);
            }
        }
    }
    cout<< m[n][s];
}

