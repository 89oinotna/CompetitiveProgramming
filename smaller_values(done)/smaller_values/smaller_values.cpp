// smaller_values.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include <stdlib.h>
#include <vector>
#include "../../library/library/fenwick_tree.cpp"
#include <tuple>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;



/*
    sort queries by increasing X
    sort the array with values

    use the fw: 
    - at each query it has the count af all the elements <= X
    - given a query while we have elements <= X add 1 in their position in ft
    - simply perform a range query to get the result 
*/
int main()
{
    auto cmp = [](tuple<int, int> a, tuple<int, int> b) { return get<1>(a) < get<1>(b); };
    int n,m;
    cin >> n>>m;
    vector<tuple<int,int>> v(n);
    vector<tuple<int, int, int, int>> q(m);
    for (int i = 0; i < n; i++) {
        int j;
        cin >> j;
        v[i]={ i,j };
    }
    for (int i = 0; i < m; i++) {
        int l, r, x;
        cin >> l>>r>>x;
        q[i] = { l,r,x, i };
    }
    /*sorto le query per il numero da cercare*/
    sort(q.begin(), q.end(), 
        [](const tuple<int, int, int, int> a, const tuple<int, int, int, int> b) {
            return get<2>(a) < get<2>(b);
        });
    /*deque cosi rimuovo facilmente in front*/
    deque<tuple<int, int>> elements;
    sort(v.begin(), v.end(), cmp);
    elements.assign(v.begin(), v.end());
    /*fw ha al suo interno ogni volta il numero 
    di elementi <= query_num*/
    fenwick_tree<int> fw(n);
    vector<int> res(m);
    for (int i = 0; i < m; i++) {
        int query_num = get<2>(q[i]);
        int j = 0;
        /*aggiungo tutti i numeri <=query num e li rimuovo dal deque*/
        while ( !elements.empty() && get<1>(*elements.begin()) <= query_num) {
            fw.add(get<0>(*elements.begin())+1, 1);
            elements.pop_front();
        }
        res[get<3>(q[i])]=fw.range_sum(get<0>(q[i])+1, get<1>(q[i])+1);
    }
    for (auto i : res) cout << i << endl;
}

