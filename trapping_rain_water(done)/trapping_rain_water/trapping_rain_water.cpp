
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
/*
store for each index how much water it can contain using left and right height.
1) left -> right max for each index
2) right -> left max for each index
3) use the min(maxl, maxr) and subtract to it the height
- if greater than 0 then add to the water sum.
*/


int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int n;
        cin >>n;
        vector<int> v(n);
        for (int j=0; j < n; j++) {
            cin >> v[j];
        }
        vector<int> maxl(n);
        int max = 0;
        for (int j=0; j < n; j++) {
            maxl[j] = max;
            if (v[j] > max) max = v[j];
        }
        vector<int> maxr(n);
        max = 0;
        for (int j=n-1; j>=0; j--) {
            maxr[j] = max;
            if (v[j] > max) max = v[j];
        }
        int totalWater = 0;
        for (int j = 1; j < n-1; j++) {
            int water = 0;
            if (maxl[j] > maxr[j])
                water = maxr[j];
            else
                water = maxl[j];
            water -= v[j];
            if (water > 0) totalWater += water;
        }
        cout << totalWater << endl;
    }
}