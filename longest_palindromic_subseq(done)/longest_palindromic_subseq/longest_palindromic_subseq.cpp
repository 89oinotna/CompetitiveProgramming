// longest_palindromic_subseq.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include <stdlib.h>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
/* lcs over the string and its reverse */
int lcs(int x, int y, string s1, string s2) {

    vector<vector<int>> matrix(x + 1);
    for (int i = 0; i <= x; i++) {
        matrix[i].resize(y + 1);
        for (int j = 0; j <= y; j++) {
            if (i == 0 || j == 0)
                matrix[i][j] = 0;
            else if (s1[i - 1] == s2[j - 1]) {
                matrix[i][j] = 1 + matrix[i - 1][j - 1];
            }
            else {
                matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1]);
            }
        }
    }
    return matrix[x][y];
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        string s1 = s;
        reverse(s1.begin(), s1.end());
        cout << lcs(s.length(), s.length(), s, s1) << endl;
    }
    return 0;
}