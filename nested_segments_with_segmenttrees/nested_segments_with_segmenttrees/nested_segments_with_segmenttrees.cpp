#include <iostream>
#include <stdlib.h>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

typedef struct st_node {
    st_node* left;
    st_node* right;
    st_node* parent;
    int value;
} st_node;

typedef struct st_leaf {
    st_node* parent;
    tuple<int, int, int> value;
} st_leaf;

void build_st(vector<tuple<int, int, bool>>& all_points) {
    vector<st_leaf> leaves(all_points.size());
    for (auto it: all_points) {
        leaves.push_back({ NULL,  it });
    }
    
}

int main()
{
    int n;
    cin >> n;
    vector<tuple<int, int>> segments;
    vector<tuple<int, int, bool>> all_points;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        segments.push_back({l, r});
    }

    //sort by starting point
    sort(segments.begin(), segments.end(),
        [](const tuple<int, int>& a, const tuple<int, int>& b) {
            return get<0>(a) < get<0>(b);
        });

    for (int i = 0; i < n; i++) {
        all_points.push_back({ get<0>(segments[i]), i, false });
        all_points.push_back({ get<1>(segments[i]), i, true });
    }

    //need to remap values
    sort(all_points.begin(), all_points.end(), 
        [](const tuple<int, int, bool>& a, const tuple<int, int, bool>& b) {
            return get<0>(a) < get<0>(b);
        });

    for (int i = 0; i < 2*n; i++) {
        int seg_num = get<1>(all_points[i]);
         get<0>(all_points[i]) = i;
        if (get<2>(all_points[i])) { //se è right end
            get<1>(segments[seg_num]) = i; 
        }
        else {
            get<0>(segments[seg_num]) = i;
        }
    }

    //build_st(all_points);
}
