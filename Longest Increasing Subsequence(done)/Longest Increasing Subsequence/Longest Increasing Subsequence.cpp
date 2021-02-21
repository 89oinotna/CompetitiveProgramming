

#include <iostream>
#include <set>
#include <tuple>
#include <stdlib.h>
#include <algorithm>
using namespace std;

struct elem {
    int val;
    int pos;
    

    bool operator<(const elem& s) const
    {
        return val < s.val;
    }

};

/*
    use a set to store the dominating position
    using lower_bound get the >= element in set:
    - if there isnt => insert it with dominating position as the max dominating+1
    - otherwise if there is i st i>=j then j dominates the position of i => insert j (with dom pos of i) and remove i

    this way we can build a serie of lis in the set which each lis is represented by a dominating position

    at the end the sie of the set will be the lis 
    
*/

int longestSubsequence(int n, int a[])
{
    set<elem> s;
    int max = 0;
    for (int i = 0; i < n; i++) {
        int val = a[i];
        auto l=s.lower_bound({ val, 0 });
        if (l==s.end()) {
            if (s.empty()) s.insert({val, 1});
            else {
                auto max = *(s.rbegin());
                s.insert({val, max.pos + 1});
            }
        }
        else {
            int pos = (*l).pos;
            s.erase(l);
            s.insert({ val, pos });
        }
    }
    return s.size();
}

int main()
{
    int n;
    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << longestSubsequence(n, a);

    
}
