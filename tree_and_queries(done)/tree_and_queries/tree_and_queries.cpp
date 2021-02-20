// tree_and_queries.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <tuple>
#include <algorithm>
#include <functional>
#include <cmath>

/*
    Flatten the tree with a preorder dfs
    remap queries on the ranges of the nodes (given by the traversal)
    apply mo's with
    use colors to count a type of color
    use at_least_k to count the number of colors
    add: we add a color so we need to increment its count in color and increment 
        the new contribution of the color in at_least_k
    remove: remove color so remove its contrib in at_least_k and decrease its count in color

*/

using namespace std;

tuple<vector<int>,vector<tuple<int, int>>> transform(vector<tuple< vector<int >, int>>& vertex) {
    vector<bool> visited(vertex.size());
    vector<int> flattered(vertex.size());
    vector<tuple<int, int>> ranges(vertex.size());
    int time = -1;
    function<void(int)> dfs = [&](int i) {
        time++;
        /*if (visited[i])
            return;**/
        visited[i] = true;
        flattered[time] = get<1>(vertex[i]);//colore
        get<0>(ranges[i]) = time;//left
        
        for (auto const& edge : get<0>(vertex[i])) {
            if (!visited[edge])
                dfs(edge);
        }
        get<1>(ranges[i]) = time;//right
    };
    dfs(0);
    return { flattered, ranges };
}




int main()
{
    int n = 0, q = 0;
    cin >> n >> q;
    vector <tuple< vector<int >, int>> vertex(n);
    
    for (int i = 0; i < n; i++) {
        int c = 0;
        cin >> c;
        get<1>(vertex[i]) = c;
    }
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        get<0>(vertex[a-1]).push_back(b-1);
        get<0>(vertex[b - 1]).push_back(a - 1);
    }

    vector < tuple<int, int, int>> queries(q);
    for (int i = 0; i < q; i++) {
        int v, k;
        cin >> v >> k;
        queries[i] = { v-1,k, i };
    }
    auto res= transform(vertex);
    vector<int> v = get<0>(res);
    vector<tuple<int, int>> ranges = get<1>(res);
    vector<tuple<int, int, int, int>> queries_on_array; //l,r,i,k
    for (auto const& query: queries) {
        auto r = ranges[get<0>(query)];
        queries_on_array.push_back({get<0>(r), get<1>(r), get<2>(query), get<1>(query)});
    }

    //map queries to buckets
    double bucket = sqrt(v.size());
    sort(queries_on_array.begin(), queries_on_array.end(), [&](const auto& a, const auto& b) {
        return get<0>(a) / bucket < get<0>(b) / bucket
            || (!(get<0>(b) / bucket < get<0>(a) / bucket) && get<1>(a) < get<1>(b));
        });
    int l = 0, r = 0;
    vector<long long int> answers(queries.size());
    //vector<int> remapped = remap(v);
    vector<int> colors(100001, 0);
    vector<int> at_least_k(1000001, 0); //
    //at_least_k[0]= count colors

    const auto Add = [&](size_t i) {
        colors[v[i]]++;
        at_least_k[colors[v[i]]]++;
    };
    const auto Remove = [&](size_t i) {
        at_least_k[colors[v[i]]]--;
        colors[v[i]]--;
    };

    Add(l);
    for (const auto& query : queries_on_array) {
        while (l < get<0>(query))
            Remove(l++);
        while (l > get<0>(query))
            Add(--l);
        while (r < get<1>(query))
            Add(++r);
        while (r > get<1>(query))
            Remove(r--);
        answers[get<2>(query)] = at_least_k[get<3>(query)];
    }

    for (auto& ans : answers)
        printf("%I64d\n", ans);
}


