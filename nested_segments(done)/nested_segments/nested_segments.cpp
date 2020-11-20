// nested_segments.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

void add(vector<int>& v, int l, int x) {
    while (l < (int)v.size()) {
        v[l] += x;
        l += l & -l;
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

int main()
{
    int n, l, r;
    cin >> n;
    vector<tuple<int, int, int>> segments;
    vector<tuple<int,int, bool>> all_points;
    for (int i = 0; i < n; i++) {
        cin >> l >> r;
        segments.push_back({ l, r, i });
        all_points.push_back({l, i, false});
        all_points.push_back({r, i, true});
    }

    sort(all_points.begin(), all_points.end(), [](const tuple<int, int, bool>&a, const tuple<int, int, bool>& b ) {
        return get<0>(a)< get<0>(b);
        });

    for (int i = 0; i < 2*n; i++) {
        int j=get<1>(all_points[i]); //prendo l'indice
        if (get<2>(all_points[i])) { //destro
            get<1>(segments[j]) = i;
        }
        else {
            get<0>(segments[j]) = i;
        }
    }

    vector<int> fw(2*n);
    for (int i = 0; i < n; i++) {
        add(fw, get<1>(segments[i]), 1);
    }

    //sorto i segmenti
    sort(segments.begin(), segments.end(), [](const tuple<int, int, bool>& a, const tuple<int, int, bool>& b) {
        return get<0>(a) < get<0>(b);
        });

    //sweeping line e rimuovo quelli visti
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        res[get<2>(segments[i])]=sum(fw, get<1>(segments[i]))-1;
        add(fw, get<1>(segments[i]), -1);
        
    }

    for (int i = 0; i < n; i++) {
        cout << res[i] << endl;
    }

}
