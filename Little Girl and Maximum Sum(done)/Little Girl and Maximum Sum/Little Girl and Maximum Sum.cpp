// Little Girl and Maximum Sum.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

void add(vector<int>& v, int l, int r, int x) {
    while (l < v.size()) {
        v[l] += x;
        l += l & -l;
    }
    while (r < v.size()) {
        v[r] -= x;
        r += r & -r;
    }
}

int sum(vector<int>& v, int i) {
    int s = 0;
    while (i > 0) {
        s += v[i];
        i -= i & -i;
    }
    return s;
}

/*
    sort the array a

    use fw tree to count for every position how many query has it
    then create an array with elements as the value of such counters (using fw sum)

    now sort the array b (decreasing)

    for the result just parallel loop on a,b multiplying their values ai*bi
    
 */

int main()
{
    std::ios::sync_with_stdio(false);
    int n, q;
    cin >> n>>q;
    vector<long long int> v(n);
    //vector<pair<int, int>> queries(q);
    vector<int> count(n + 1, 0);
    vector<int> b(n + 1);
    for (int i = 0; i < n; i++) {
        //scanf("%lld", &v[i]);
        cin >> v[i];
    }
    sort(v.rbegin(), v.rend());
    int l, r;
    for (int i = 0; i < q; i++) {
        //scanf("%d", &l);
        //scanf("%d", &r);
        //queries[i] = { l, r };
        cin >> l>>r;
        add(count, l, r + 1, 1);
    }
    //vector<long long int> count(n+1, 0);
    /*for (auto p : queries) {
        add(count, p.first, p.second+1, 1);
    }*/

    
    
    for (int i = 1; i < n+1; i++) {
       b[i] = sum(count, i);
    }
    sort(b.rbegin(), b.rend());

    long long int res = 0;
    
    for (int i = 0; i < n; i++) {
        res += (long long int)v[i] * b[i];
        //cout << v[i]<<"*"<< b[i]<<"/"<<res << endl;
    }

    cout << res << endl;

    return 0;

    

}
