

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
