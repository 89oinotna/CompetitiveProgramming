#include <vector>

template <typename T> 
class fenwick_tree {
    std::vector<T> ft;
public:
    fenwick_tree(int n) : ft(n + 1, 0) {}

    void add(int l, T x) {
        while (l < ft.size()) {
            ft[l] += x;
            l += l & -l;
        }
    }

    void range_add(int l, int r, T x) {
        add(l, x);
        if (r < ft.size()) {
            add(r + 1, -x);
        }
    }

    T sum(int i) {
        T s = 0;
        while (i > 0) {
            s += ft[i];
            i -= i & -i;
        }
        return s;
    }
    
    T range_sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    

};
