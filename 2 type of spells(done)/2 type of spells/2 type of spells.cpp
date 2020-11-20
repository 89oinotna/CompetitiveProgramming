// 2 type of spells.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <set>

using namespace std;

struct Spell {
    int value;
    int type; //true if light

    bool operator<(const Spell& s) const
    {
        return value < s.value;
    }

};

int main()
{
    int n = 0, k = 0;
    long long int sum = 0, non_top_sum = 0; //the number of changes to the spell set.
    cin >> n;
    set<Spell> top;
    set<Spell> non_top;
    int top_fire=0;
    int tp = 0;
    int d = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &tp, &d);
        if (d>0) {
            k += tp;
            if (!top.empty() && top.begin()->value<d) {
                if (tp == 0) top_fire++;//top_fire.insert({ d, tp });
                top.insert({d, tp});
                sum += d;
            }
            else {
                non_top.insert({d, tp});
                non_top_sum += d;
            }
        }
        else {
            k -= tp;
            if (!top.empty() && top.begin()->value <= -d) {
                if (tp == 0) top_fire--;//top_fire.erase({ -d, tp });
                top.erase({ -d, tp });
                sum += d;
            }
            else {
                non_top.erase({ -d, tp });
                non_top_sum += d;
            }
        }
        while (top.size() < k) {
            //aggiungi max non top a top
            top.insert(*non_top.rbegin());
            sum += non_top.rbegin()->value;
            if (!non_top.rbegin()->type) top_fire++;// top_fire.insert(*non_top.rbegin());
            non_top_sum -= non_top.rbegin()->value;
            non_top.erase(*non_top.rbegin());
        }
        while (top.size() > k) {
            //rimuovi da top e metti in non top
            non_top.insert(*top.begin());
            sum -= top.begin()->value;
            if (!top.begin()->type) top_fire--;//top_fire.erase(*top.begin());
            non_top_sum += top.begin()->value;
            top.erase(*top.begin());
        }
        if (top_fire/*.size()*/ > 0) {
            cout << (sum<<1) + non_top_sum<<endl;
        }
        else {
            long long int res = 0;
            if (top.empty()) {
                res=non_top_sum;
            }
            else {
                if (non_top.empty()) {
                    res = (sum << 1) - top.begin()->value;
                }
                else {
                    res = (sum << 1) - top.begin()->value + non_top_sum + non_top.rbegin()->value;
                }
            }
            cout << res << endl;
            //cout << ((top.empty()) ? non_top_sum : (non_top.empty()) ? 2 * sum - top.begin()->value : 2 * (sum - top.begin()->value  ) + non_top_sum + non_top.rbegin()->value) << endl; ;
        }
        
    }
    
}

