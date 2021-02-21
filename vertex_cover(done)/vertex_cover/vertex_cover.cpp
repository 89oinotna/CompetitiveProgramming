// vertex_cover.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
/*
    check recursively if we should take or not a node
    memorize for each node the minimum cover for its subtree (this avoids useless multiple recursion)
    the minimum cover is computed by chosing or not to take the current node
        if we chose to take the node then we dont care about children (we can take or not them)
            so we add to our counter min(cover taking the node, cover not taking)
        if we chose to not take this node then all children must be chosen
            so we are constrained to take each child

*/
size_t cover_vertex(vector<vector<size_t>>&m, vector<vector<int>>& tree, int parent, int i, bool taken) {
    if (m[i][taken] != 0) return m[i][taken];
    size_t counter = taken ? 1 : 0; //contributo nodo
    for (auto const& n : tree[i]) {
        if (n != parent) {
            //if we cover this => dont care about child just take their min
            if (taken) {
                counter +=min(cover_vertex(m, tree, i, n, true), cover_vertex(m, tree, i, n, false));
            }
            //if not covered => all child must be covered
            else {
                counter += cover_vertex(m, tree, i, n, true);
            }
            
        }
    }
    return m[i][taken] = counter;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> tree(n);
    int edges = 0;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        edges++;
        tree[a-1].push_back(b-1);
        tree[b-1].push_back(a-1);
    }
    //should i take the node or not??? see how many edges are covered if taken or not (also memorize this)
    vector<vector<size_t>> m(edges + 1, vector<size_t>(2, 0));
    cout<<min(cover_vertex(m, tree, -1, 0, false), cover_vertex(m, tree, -1, 0, true));
}

