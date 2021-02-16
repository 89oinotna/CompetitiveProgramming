#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
#include <functional> 
/*
    An array representation of tree is used to represent Segment Trees.
    For each node at index i,
    the left child is at index 2*i+1,
    right child at 2*i+2 and the parent is at
*/
#define LEFT(i)     2 * i + 1
#define RIGHT(i)    2 * i + 2
#define PARENT(i) (i - 1) / 2


using namespace std;
template <typename T, typename BinaryFunct = binary_function <T, T, T>>
class segment_tree {
public:
    struct type_traits {
        T invalid;
        BinaryFunct funct; //merging
    };
    struct range {
        size_t l, r;
        range(size_t ll, size_t rr)
            : l(ll), r(rr)
        {}
    };
   private:
	    vector<T> st;
        type_traits m_traits; 

        // A recursive function that constructs Segment Tree 
        //for array[l..r].  
        // si is index of current node in segment tree st  
        void build(vector<T> const leaves, size_t  l, size_t  r, size_t  pos)
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
            size_t mid = (l + r) / 2;
            build(leaves, l, mid, LEFT(pos));
            build(leaves, mid + 1, r, RIGHT(pos));
            st[pos] = m_traits.funct(st[LEFT(pos)], st[RIGHT(pos)]);
        }


        T get(range const& q, range node_segment, size_t pos) {
            // If segment of this node is a part of given range, then return  
            // the sum of the segment  
            if (q.l <= node_segment.l && q.r >= node_segment.r)
                return st[pos];

            // If segment of this node is outside the given range  
            if (node_segment.r < q.l || node_segment.l > q.r)
                return m_traits.invalid;

            // If a part of this segment overlaps with the given range  
            // partial overlap
            size_t mid = (node_segment.l + node_segment.r) / 2;
            return m_traits.funct(
                get(q, { node_segment.l, mid }, LEFT(pos)),
                get(q, { mid + 1, node_segment.r }, RIGHT(pos))
            );
        }

        void update(size_t i, range r, size_t pos, T val) {
            // Base Case: If the input index lies outside the range of  
            // this segment  
            if (i < r.l || i > r.r)
                return;

            // If the input index is in range of this node, then update  
            // the value of the node and its children  
            st[pos] = m_traits.funct(st[pos], val);
            if (r.l != r.r)
            {
                size_t mid = (r.l+r.r)/2;
                update(i, { r.l, mid }, LEFT(pos), val);
                update(i, { mid+1, r.r }, RIGHT(pos), val);
            }
        }

    public:
	    segment_tree(vector<T> const& leaves, type_traits t) : m_traits(t){
            size_t n = leaves.size();
            // round up to the next power of 2
            size_t m = size_t(1) << static_cast<size_t>(ceil(log2(n)));
            st.resize(2 * m - 1, m_traits.invalid);
            build(leaves, 0, n - 1, 0);
	    }

        size_t size() {
            return st.size()/2 + 1;
        }

        range root() {
            return { 0, size() - 1 };
        }

        T get(range const& query) {
            return get(query, root(), 0);
        }

        void update(size_t i, T val) {
            update(i, root(), 0, val);
        }


};