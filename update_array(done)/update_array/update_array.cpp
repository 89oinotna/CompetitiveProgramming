// update_array.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

void add(vector<int> &v, int l, int x) {
    while (l < v.size()) {
        v[l] += x;
        l+=l&-l;
    }
}

int sum(vector<int>& v, int i) {
    int s = 0;
    while (i>0) {
        s += v[i];
        i -= i & -i;
    }
    return s;
}

int main()
{
    int t, n, u;
    cin >> t>>n>>u;
    vector<int> fw_tree(n+1, 0);

    for (int i = 0; i < u; i++) {
        int l, r, x;
        cin >> l >> r>>x;
        add(fw_tree, l+1, x);
        add(fw_tree, r + 2, -x);
    }
    int q;
    cin >> q;
    vector<int> v_q(q);
    for (int i = 0; i < q; i++) {
        cin >> v_q[i];
        
    }
    for (int i = 0; i < q; i++) {
        cout << sum(fw_tree, v_q[i]+1) << endl;
    }
    
}

