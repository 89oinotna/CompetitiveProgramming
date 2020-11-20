// frogs and mosquitoes.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include <stdlib.h>
#include <set>
#include <algorithm>
using namespace std;

struct Frog {
    int pos;
    int t_len;
    int m_eaten;
    
    // This function is used by set to order 
    // elements of Test. 
    bool operator<(const Frog &f) const
    {
        return (pos < f.pos);
    }
};

struct Mosquitoes {
    int pos;
    int size;
    bool operator<(const Mosquitoes& m) const
    {
        return (pos < m.pos);
    }
};


void insert(set<Frog> &frogs, int pos, int t_len, int m_eaten) {
    if (frogs.empty()) 
        frogs.insert({ pos, t_len, m_eaten });
    auto p = frogs.lower_bound({ pos, t_len, m_eaten })--;
    while (p!=frogs.end()) {
        if ( p->pos > pos+t_len) break;
        
        if (pos < p->pos) {
            if () {}
        }
        else {
            if (pos > p->pos + p->t_len) p++;
            else {
                t_len -= p->pos + p->t_len + 1 - pos;
                pos = p->pos + p->t_len + 1;
            }
        }
    }
}


int main()
{
    int n, m;
    cin >> n >> m;
    set<Frog> frogs; 
    set<Mosquitoes> mosquitoes;
    for (int i = 0; i < n; i++) {
        int pos, tongue_len;
        cin >> pos >> tongue_len;
        insert(frogs, pos, tongue_len, 0);
    }

    for (auto f:frogs) {
        cout << f.pos << " "<<f.t_len<<" ";
    }

    for (int i = 0; i < m; i++) {
        bool eaten = false;
        int pos = 0, size=0;
        cin >> pos >> size;
        do {
            eaten = false;
            auto p=frogs.lower_bound({pos});
            if (p->pos == pos) {// eat
                int newtlen = p->t_len + size;
                int eaten = p->m_eaten + 1;
                int frog_pos = p->pos;
                frogs.erase(p);
                //insert(frogs, pos, newtlen, eaten);
                //check for reachable mosquitoes
                auto mm = mosquitoes.lower_bound({ pos, 0 });
                while (mm->pos <= frog_pos+ newtlen) {
                    newtlen += mm->size;
                    mm++;
                }
                insert(frogs, frog_pos, newtlen, eaten);
                eaten = true;
            }
            else {
                //check prec
                auto prec=--p;
                if (pos < prec->pos && prec->pos + prec->t_len >= pos) {
                    int newtlen = p->t_len + size;
                    int eaten = p->m_eaten + 1;
                    int frog_pos = prec->pos;
                    frogs.erase(p);
                    //insert(frogs, frog_pos, newtlen, eaten);
                    //check for reachable mosquitoes
                    auto mm = mosquitoes.lower_bound({ pos, 0 });
                    while (mm->pos <= frog_pos + newtlen) {
                        newtlen += mm->size;
                        mm++;
                    }
                    insert(frogs, frog_pos, newtlen, eaten);
                    eaten = true;
                }
                else {
                    mosquitoes.insert({pos, size});
                }
                
            }
        } while (eaten);
    }
    
}
