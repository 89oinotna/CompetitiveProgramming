#include <iostream>
#include <stdlib.h>
#include <vector>
#include <tuple>
#include <algorithm>
#include <functional> 
#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
#include <stdio.h>
#include <string.h>
/*
    An array representation of tree is used to represent Segment Trees.
    For each node at index i,
    the left child is at index 2*i+1,
    right child at 2*i+2 and the parent is at
*/
#define LEFT(i)      (i<<1) + 1
#define RIGHT(i)    (i<<1) + 2


using namespace std;
template <typename T>
class segment_tree {

private:
    vector<T> st;
    vector<T> lazy; //used to propagate range updates
    int _size;

     
    void build(vector<T> const& leaves, int  l, int  r, int  pos)
    {
        // If there is one element in array, store it in current node of  
        // segment tree and return  
        if (l == r)
        {
            st[pos] = leaves[l];
            return;
        }

        // If there are more than one elements, then recur for left and  
        // right subtrees and store the sum of values in this node  
        int mid = (l + r) >>1;
        build(leaves, l, mid, LEFT(pos));
        build(leaves, mid + 1, r, RIGHT(pos));
        st[pos] = min(st[LEFT(pos)], st[RIGHT(pos)]);
    }


    T get(int ql, int qr, int ll, int rr, int pos) {
        
        lazy_updates(ll, rr, pos);
        // If segment of this node is a part of given range, then return it
        if (ql <= ll && rr <= qr )
            return st[pos];

        // If segment of this node is outside the given range  
        if (rr < ql || ll > qr )
            return LLONG_MAX;

        // partial overlap
        int mid = (ll + rr) >>1;
        return min(
            get(ql, qr, ll, mid, LEFT(pos)),
            get(ql, qr, mid + 1, rr, RIGHT(pos))
        );
    }
    
    
    void lazy_updates(int ll, int rr, int pos) {
        if (lazy[pos] != 0) {
            // is lazy -> update
            st[pos] += lazy[pos];
            if (ll != rr) {
                //propagate to leaves
                lazy[LEFT(pos)] += lazy[pos];
                lazy[RIGHT(pos)] += lazy[pos];
            }
            
            lazy[pos] = 0;
        }
    }
    // update in [ql, qr] by val
    void update_range(int ql, int qr, T val, int ll, int rr, int pos) {
        lazy_updates(ll, rr, pos);
        if (ll > qr || rr < ql )
            return;
        
        
        //full overlap
        if (ql <= ll && rr <= qr) {
            st[pos]  += val;
            if (ll != rr) {
                lazy[LEFT(pos)] += val;
                lazy[RIGHT(pos)] += val;
            }
        }
        //partial overlap
        else {
            int mid = (ll + rr) / 2;
            update_range(ql, qr, val, ll,     mid , LEFT(pos));
            update_range(ql, qr, val, mid + 1, rr , RIGHT(pos));
            st[pos] = min(st[LEFT(pos)], st[RIGHT(pos)]);
        }
    }



public:
    segment_tree(vector<T> const& leaves) {
        int n = leaves.size();
        // round up to the next power of 2
        int m = int(1) << static_cast<int>(ceil(log2(n)));
        _size = n;
        st.resize(2 * m - 1, INT_MAX);
        lazy.resize(2 * m - 1, 0);
        build(leaves, 0, n-1, 0);
    }

    int size() {
        return _size;
    }


    T get(int ql, int qr) {
        return get(ql, qr, 0, size() - 1, 0);
    }

    void update_range(int ql, int qr, T val) {
        update_range(ql, qr, val, 0, size() - 1, 0);
    }


};
using namespace std;


int main()
{
    int n;
    cin >> n;
    vector<long long int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    segment_tree<long long int> st(v);
    int m;
    cin >> m;
    
    while (getchar() != '\n');
    for (int i = 0; i < m; i++) {
        string s;
        getline(cin, s);
        char* line= const_cast<char*>(s.c_str());
        int l = atoi(strtok(line, " "));
        int r = atoi(strtok(NULL, " "));
        char* val = strtok(NULL, " ");
        if (val == NULL) {
            if (l <= r) {
                cout << st.get(l,r) << endl;
            }
            else {
                cout << min(st.get(l, st.size() - 1), st.get(0, r)) << endl;
            }
        }
            
        else {
            if (l <= r) {
                st.update_range(l,r, atoi(val));
            }
            else {
                st.update_range(l, st.size() - 1, stoll(val));
                st.update_range(0, r, stoll(val));
            }
        }
    }



}
