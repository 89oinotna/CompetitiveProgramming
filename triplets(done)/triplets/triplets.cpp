// triplets.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include "../../library/library/fenwick_tree.cpp"

using namespace std;
template<typename T>
void remap(vector<T>& a) {
    vector<T> tmp(a.size());
    copy(a.begin(), a.end(), tmp.begin());
    sort(tmp.begin(), tmp.end());
    size_t sz = distance(tmp.begin(), unique(tmp.begin(), tmp.end()));
    tmp.resize(sz);

    for (auto& x : a)
        x = distance(tmp.begin(), lower_bound(tmp.begin(), tmp.end(), x));
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    remap<int>(v);
    int max = *max_element(v.begin(), v.end());
    /* guardo quelli minori in un punto j*/
    fenwick_tree<int> minor(max+1);
    vector<int> count_i(n);
    for (int i = 0; i < n; i++) {
        
        if (i > 0) {
            count_i[i] = minor.sum(v[i]);
        }
        else {
            count_i[i] = 0;
        }
        minor.add(v[i] + 1, 1);
        
    }
    /* guardo quelli maggiori in un punto j*/
    fenwick_tree<int> greater(max+1);
    reverse(v.begin(), v.end());
    vector<int> count_k(n);
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            count_k[i] = greater.sum(max + 1) - greater.sum(v[i]+1);
        }
        else
            count_k[i] = 0;
        greater.add(v[i] + 1, 1);
    }
    int res = 0;
    reverse(count_k.begin(), count_k.end());
    for (int i = 1; i < n-1; i++) {
        res+=count_i[i] * count_k[i];
    }
    cout << res;
}

