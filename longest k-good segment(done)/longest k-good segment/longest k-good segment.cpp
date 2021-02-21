// longest k-good segment.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <map>
using namespace std;

/*
use a dynamic sliding window also using a map to keep track of the values count
keep track of the max size of the window

when we enlarge to right:
    - if new element is already in map => increase its counter
    - otherwise:
        - if we have less than k (map size) just insert it
        - otherwise resize left also removing elements from the map


*/
int main()
{
    unsigned int n = 0, k = 0;
    cin >> n>>k;
    vector<int> vect(n);
    map<int, int> distinct;
    for (int i = 0; i < n; i++) {
        scanf("%d", &vect[i]);
    }
    unsigned int l = 0, r = 0, max_segment_len = 0, maxl=0, maxr=0;
    while (r<vect.size()) {
        auto find = distinct.find(vect[r]);
  
        if (find!=distinct.end()) { //se presente aumento il contatore
            find->second++;
        }
        else { //altrimenti se non presente
            if (distinct.size()<k) { //se ho meno di k numeri diversi allora posso aggiungerlo
                distinct.insert(pair<int, int>(vect[r], 1));
            }
            else { //altrimenti devo spostare l finché distinct size<k
                while (distinct.size() == k) {
                    auto f = distinct.find(vect[l]);
                    if (f->second > 1) f->second--;
                    else distinct.erase(f);
                    l++;
                }
                distinct.insert(pair<int, int>(vect[r], 1));
            }
        }

        if (r - l > max_segment_len) {
            max_segment_len = r - l;
            maxr = r;
            maxl = l;
        }
        r++;

    }
    cout << maxl+1 << " " << maxr+1;

}

