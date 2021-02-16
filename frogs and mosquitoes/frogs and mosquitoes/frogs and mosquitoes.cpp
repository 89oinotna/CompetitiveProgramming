// frogs and mosquitoes.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include <stdlib.h>
#include <set>
#include <algorithm>
#include <tuple>
#include <vector>
#include <deque>
using namespace std;

struct Frog {
    long long int start;
    long long int end;
    int index;
    
    // This function is used by set to order 
    bool operator<( Frog const& f) const
    {
        return (end < f.end);
    }
};

struct Mosquitoes {
    long long int pos;
    long long int size;
    bool operator<( Mosquitoes const& m) const
    {
        return (pos < m.pos);
    }
};



template <typename Iterator>
//frogs are already non overlapped
void resize(set<Frog>& frogs, Iterator it, Frog& f) {
    it=frogs.erase(it);
    //resize
    while(it != frogs.end() && it->start <= f.end ) {
        //full overlapped -> remove
        if (it->end <= f.end) {
            it=frogs.erase(it);
        }
        //partial -> resize
        else {
            Frog newF = { f.end + 1, it->end, it->index };
            frogs.erase(it);
            frogs.insert(newF);
            it= frogs.end();
        }
    }
    frogs.insert(f);
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<tuple<int, long long int>> res(n);
    set<Frog> frogs;
    vector< Frog > f(n);
    multiset<Mosquitoes> mosquitoes;
    for (int i = 0; i < n; i++) {
        long long int pos, tongue_len;
        cin >> pos >> tongue_len;
        f[i] = { pos, pos + tongue_len, i };
        res[i] = { 0, tongue_len };
    }
    //sort by start
    sort(f.begin(), f.end(), [](Frog const& a, Frog const& b) {return a.start < b.start; });
    Frog* prec=&f[0];
    frogs.insert(f[0]);
    for (int i = 1; i < n; i++) {
        Frog* curr = &f[i];
        //need to resize
        if (curr->start <= prec->end ) {
            //partial
            if (curr->end > prec->end) {
                curr->start=prec->end+1;
                frogs.insert(f[i]);
                prec = curr;
            }
            //else full overlap -> do not insert
        }
        else {
            frogs.insert(f[i]);
            prec = curr;
        }
        
    }

    

    for (int i = 0; i < m; i++) {
        long long int pos, size;
        cin >> pos >> size;
        auto it = frogs.lower_bound({ 0, pos, 0 });

        //is in frog range
        if (it != frogs.end() && it->start <= pos) {
            Frog frog = *it;
            //eat it
            get<0>(res[frog.index])++;
            get<1>(res[frog.index]) += size;
            frog.end += size;
            //select mosquito from set
            auto mosquito = mosquitoes.lower_bound({ it->start, 0 });
            while (mosquito != mosquitoes.end() && mosquito->pos <= frog.end) {
                //eat it
                get<0>(res[frog.index])++;
                get<1>(res[frog.index]) += mosquito->size;
                frog.end += mosquito->size;
                mosquito = mosquitoes.erase(mosquito);
            }
            resize(frogs, it, frog);
        }
        else {
            //add to set
            mosquitoes.insert({ pos, size });
        }
    }

    for (int i = 0; i < n; i++) {
        cout<< get<0>(res[i])<<" "<<get<1>(res[i]) <<endl;
    }
    
}
