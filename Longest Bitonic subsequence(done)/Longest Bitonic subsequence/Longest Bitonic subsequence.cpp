
#include <iostream>
#include <set>
#include <tuple>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;

struct elem {
    int val;
    int pos;


    bool operator<(const elem& s) const
    {
        return val < s.val;
    }

};
int* longestSubsequence(int n, vector<int> a)
{
    int* ls = new int[n];
    set<elem> s;
    int max = 0;
    for (int i = 0; i < n; i++) {
        int val = a[i];
        auto l = s.lower_bound({ val, 0 });
        if (l == s.end()) {
            if (s.empty()) {
                s.insert({ val, 1 });
                ls[i] = 1;
            }
            else {
                auto max = *(s.rbegin());
                s.insert({ val, max.pos + 1 });
                ls[i] = max.pos + 1;
            }
        }
        else {
            int pos = (*l).pos;
            s.erase(l);
            s.insert({ val, pos });
            ls[i] = pos;
        }
    }
    return ls;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    auto inc = longestSubsequence(nums.size(), nums);
    reverse(nums.begin(), nums.end());
    auto dec = longestSubsequence(nums.size(), nums);
    reverse(dec, dec + nums.size());
    int max = 0;
    for (int i = 0; i < nums.size(); i++) {
        int v = inc[i] + dec[i] -1;
        if (v > max) max = v;
    }
    cout << max;


}
