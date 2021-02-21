#include <iostream>
#include <stdlib.h>
#include <vector>
#include <tuple>
#include <algorithm>
#include "../../library/library/segment_tree.cpp"
#include <functional> 
using namespace std;

/* 

ordino i segmenti per starting point
salvo gli endpoint nel segment tree
devo contare gli ednpoint che trovo prima dell'endpoint del segmento visitato
ogni volta che controllo per un segmento poi lo elimino

*/



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

    

    for (int i = 0; i < n; i++) {
        all_points.push_back({ get<0>(segments[i]), i, false });
        all_points.push_back({ get<1>(segments[i]), i, true });
    }

    //remap
    sort(all_points.begin(), all_points.end(), 
        [](const tuple<int, int, bool>& a, const tuple<int, int, bool>& b) {
            return get<0>(a) < get<0>(b);
        });
    vector<int> endpoints(2 * n);
    for (int i = 0; i < 2*n; i++) {
        int seg_num = get<1>(all_points[i]);
         get<0>(all_points[i]) = i;
        if (get<2>(all_points[i])) { //se è right end
            get<1>(segments[seg_num]) = i; 
            endpoints[i] = 1;
        }
        else {
            get<0>(segments[seg_num]) = i;
            endpoints[i] = 0;
        }
    }

    //sort by starting point
    sort(segments.begin(), segments.end(),
        [](const tuple<int, int>& a, const tuple<int, int>& b) {
            return get<0>(a) < get<0>(b);
        });

    /*usa il segment tree contando solo endpoints*/
    segment_tree<int, std::plus<int> >::type_traits t;
    t.invalid = 0;
    segment_tree<int, std::plus<int> > st(endpoints, t);
    

    for (auto it:segments) {
        segment_tree<int, std::plus<int> >::range r(get<0>(it), get<1>(it));
        st.update((size_t)get<1>(it), -1);
        cout<<st.get(r)<<endl;
    }
}
