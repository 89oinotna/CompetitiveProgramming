#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;

struct team_strenght {
    int p1;
    int p2;
    int value;

    bool operator<(const team_strenght& rhs) {
        if (rhs.value > value) return true;
        return false;
    }
};

/*
Every contestant hopes that he can find a teammate so that their team’s strength is as high as possible.

1) sort couples of teams dec
2) loop on the sorted list marking when we form a team

we form a team when each of the member of the couple is not taken. (this for sure is the best for both now)
- we store the teammate for each member of the allowed couple(this also ensures that it has already a team)
*/

int main()
{

    int n = 0;
    cin >> n;
    vector<team_strenght> v;
    v.reserve(sizeof(int) * 2 * n - 1);
    for (int i = 1; i < 2 * n; i++) {
        for (int j = 0; j < i; j++) {
            int s = 0;
            cin >> s;
            v.push_back({ i, j, s });
        }
    }
    sort(v.begin(), v.end(), [](team_strenght& lhs, team_strenght& rhs) {
        return lhs < rhs;
        });
    vector<int> found(2 * n, -1);
    while (!v.empty()) {
        team_strenght t = v.back();
        v.pop_back();
        if (found[t.p1] == -1 && found[t.p2] == -1) {
            found[t.p1] = t.p2;
            found[t.p2] = t.p1;
        }
    }
    for (auto x : found) {
        cout << x + 1 << " ";
    }
}
