// Ilya and Queries.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
using namespace std;

/*
create an array sum storing all previus match + 1 if s[i - 1] == s[i]

answer each query subtracting the sum to left end at the sum until right end

*/

int main()
{
    string s;
    cin >> s;
    int q=0;
    cin >> q;
    vector<pair<int, int>> queries(q);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        queries[i]={l, r};
    }
    vector<int> sum(s.length(), 0);
    for (int i = 1; i < s.length(); i++) {
        sum[i] = sum[i - 1] + (s[i - 1] == s[i] ? 1 : 0);
    }
   
    
    for (pair<int, int> query : queries) {
        cout << sum[query.second - 1] - sum[query.first - 1] << endl;

    }
}
