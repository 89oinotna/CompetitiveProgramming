
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

int lcs(int x, int y, string s1, string s2) {
    vector<vector<int>> matrix(x+1);
    for (int i = 0; i <= x; i++) {
        matrix[i].resize(y + 1);
        for (int j = 0; j <= y; j++) {
            if (i == 0 || j == 0) //empty
                matrix[i][j]=0;
            else if (s1[i-1] == s2[j-1]) { //if the chars are the same add
                matrix[i][j] = 1 + matrix[i - 1][j - 1];
            }
            else { //if chars are different then (remove) carry max of previous lcs
                matrix[i][j] = max(matrix[i-1][j], matrix[i][j-1]);
            }
        }
    }
    return matrix[x][y];
}


int main()
{
    int n, m;
    cin >> n >> m;
    string s1, s2;
    cin >> s1 >> s2;
    cout << lcs(n,m,s1,s2);
}

