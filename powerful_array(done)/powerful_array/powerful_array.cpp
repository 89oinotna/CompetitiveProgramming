// powerful_array.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <tuple>
#include <cmath>
using namespace std;
template<typename T>
vector<T>  remap(vector<T> a) {
    vector<T> tmp(a.size());
    copy(a.begin(), a.end(), tmp.begin());
    sort(tmp.begin(), tmp.end());
    size_t sz = distance(tmp.begin(), unique(tmp.begin(), tmp.end()));
    tmp.resize(sz);

    for (auto& x : a)
        x = distance(tmp.begin(), lower_bound(tmp.begin(), tmp.end(), x));
    return a;
}

/*
    sort queries into buckets
    remap values in v
    mo's algorithm:
        counter to store frequencies of the numbers in current range
        add: remove previous contribution from ans
             increase freq
             add new contribution to ans
        remove: remove previous contribution from ans
                decrease freq
                add new contribution to ans
*/

int main()
{
    size_t n = 0, q=0;
    cin >> n >> q;
    vector<int64_t> v(n);
    for (size_t i = 0; i < n; i++) {
        scanf("%I64d", &v[i]);
    }
    vector<tuple<int64_t, int64_t, size_t>> queries(q);
    for (size_t i = 0; i < q; i++) {
        size_t l, r;
        scanf("%I64d%I64d", &l, &r);
        queries[i] = make_tuple( l-1,r-1, i );
    }

    //map queries to buckets
    int64_t bucket=sqrt(v.size());
    sort(queries.begin(), queries.end(), [&](const auto & a, const auto &b) {
        return get<0>(a) / bucket < get<0>(b) /bucket
            || (!(get<0>(b) /bucket < get<0>(a) / bucket) && get<1>(a) < get<1>(b));
       });

    size_t l = 0, r = 0;
    vector<int64_t> answers(queries.size());
    vector<int64_t> remapped = remap(v);
    vector<int64_t> counter(v.size(), 0);
    //vector<int64_t> counter(1000001, 0);
    int64_t ans = 0; //

    const auto add_ = [&](size_t i) {
        ans -= counter[/*v*/remapped[i]] * counter[remapped[i]] * v[i];
        counter[remapped[i]] ++;
        ans += counter[remapped[i]] * counter[remapped[i]] * v[i];
    };

    const auto remove_ = [&](size_t i) {
        ans -= counter[remapped[i]] * counter[remapped[i]] * v[i];
        counter[remapped[i]]--;
        ans += counter[remapped[i]] * counter[remapped[i]] * v[i];
    };


    add_(l);
    for (const auto& query : queries) {
        while (l < get<0>(query))
            remove_(l++);
        while (l > get<0>(query))
            add_( --l);
        while (r < get<1>(query))
            add_(++r);
        while (r > get<1>(query))
            remove_(r--);
        answers[get<2>(query)] = ans;
    }

    for (auto& ans : answers)
        printf("%I64d\n", ans);

}

