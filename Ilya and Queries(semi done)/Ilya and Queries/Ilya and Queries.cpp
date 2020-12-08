// Ilya and Queries.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
using namespace std;
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
    for (int i = 0; i < s.length()-1; i++) {
        if (s[i] == s[i + 1]) {
            if (i != 0)
                sum[i] = sum[i - 1] + 1;
            else
                sum[i] = 1;
        }
        else {
            if (i != 0) sum[i] = sum[i - 1];
        } 
    }
    if(true)
        if(true) false; 
        else false;
    if(s.length()>1)
        sum[s.length() - 1] = sum[s.length() - 2];
    for (pair<int, int> query : queries) {
        if (query.first - 2 >= 0)
            cout << sum[query.second - 1] - sum[query.first - 2] << endl;
        else
            cout << sum[query.second - 1] << endl;

    }
}
