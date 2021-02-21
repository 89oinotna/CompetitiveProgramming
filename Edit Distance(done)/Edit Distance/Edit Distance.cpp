// Edit Distance.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;

/*
    matrix:
    - row char s+1
    - column char t+1

    m[i][j]= - i==0 || j==0 => i+j
            - equal char dont contribute to ed so take min topleft
            - different chars contribute to ed => take 1+min(topleft (substitution), left(deleting/inserting left), top(deleting/inserting top))
    
*/

int editDistance(string s, string t) {
    vector<vector<int>> m(s.size() + 1);

    for (int i = 0; i < s.size() + 1; i++) {
        m[i].resize(t.size() + 1);
        for (int j =0 ; j < t.size() + 1; j++) {
            if (i == 0 || j == 0) m[i][j] = i+j;
            else {
                if (s[i - 1] == t[j - 1]) m[i][j] = m[i - 1][j - 1];
                else {
                    m[i][j] = min({ m[i - 1][j], m[i][j - 1], m[i - 1][j - 1] }) + 1;
                }
            }
        }
    }
    return m[s.size()][t.size()];
}

int main()
{
    int n;
}

